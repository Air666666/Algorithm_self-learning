#!/usr/bin/env python3
"""Compile each independent solution as a C++17 translation unit."""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import subprocess, json, os
root=Path(__file__).resolve().parents[1]
compiler=os.environ.get('CXX','clang++')
def check(p):
    run=subprocess.run([compiler,'-std=c++17','-fsyntax-only',str(p)],capture_output=True,text=True)
    return {'file':str(p.relative_to(root)),'passed':run.returncode==0,'diagnostics':run.stderr}
with ThreadPoolExecutor(max_workers=6) as pool:
    results=list(pool.map(check,sorted((root/'src').rglob('*.cpp'))))
(root/'compile-report.json').write_text(json.dumps(results,ensure_ascii=False,indent=2)+'\n')
print(f"Compiled {len(results)} files; passed {sum(r['passed'] for r in results)}")
for r in results:
    if not r['passed']: print(r['file'],r['diagnostics'][:2000])
raise SystemExit(any(not r['passed'] for r in results))
