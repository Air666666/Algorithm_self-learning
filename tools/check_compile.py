#!/usr/bin/env python3
"""Check every independent C++17 translation unit; never link solutions together."""
import argparse, concurrent.futures, json, os, shlex, subprocess, tempfile
from pathlib import Path
root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--jobs', type=int, default=6)
parser.add_argument('--pch', action='store_true', help='Use a temporary precompiled header (Clang only)')
args = parser.parse_args()
compiler = os.environ.get('CXX', 'clang++')
flags = ['-std=c++17', '-fwrapv', '-Wno-deprecated-declarations'] + shlex.split(os.environ.get('CXXFLAGS', ''))
with tempfile.TemporaryDirectory(prefix='algorithm-cpp-check-') as tmp:
    pch_flags = []
    if args.pch:
        pch = str(Path(tmp) / 'compat.pch')
        subprocess.run([compiler, *flags, '-x', 'c++-header', str(root/'include/jcompat.hpp'), '-o', pch], check=True)
        pch_flags = ['-include-pch', pch]
    def check(p):
        # Existing standalone ports do not need or include the compatibility header.
        extra = pch_flags if 'include/jcompat.hpp' in p.read_text() else []
        run = subprocess.run([compiler, *flags, *extra, '-fsyntax-only', str(p)], capture_output=True, text=True)
        return {'file': str(p.relative_to(root)), 'passed': run.returncode == 0, 'diagnostics': run.stderr.replace(str(root)+'/', '')}
    results = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for i, result in enumerate(pool.map(check, sorted((root/'src').rglob('*.cpp'))), 1):
            results.append(result)
            if i % 100 == 0: print(f'{i} checked; {sum(x["passed"] for x in results)} passed', flush=True)
(root/'compile-report.json').write_text(json.dumps(results, ensure_ascii=False, indent=2)+'\n')
print(f'Compiled {len(results)} files; passed {sum(r["passed"] for r in results)}')
for r in results:
    if not r['passed']: print(r['file'], r['diagnostics'][:2000])
raise SystemExit(any(not r['passed'] for r in results))
