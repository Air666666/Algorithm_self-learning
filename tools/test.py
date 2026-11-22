#!/usr/bin/env python3
"""Run standalone regression tests and saved Java-reference fixtures."""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import json,os,shlex,subprocess,tempfile
root=Path(__file__).resolve().parents[1]
compiler=os.environ.get('CXX','clang++')
flags=['-std=c++17','-fwrapv','-O1','-g','-Wno-deprecated-declarations','-fsanitize=address,undefined']+shlex.split(os.environ.get('CXXFLAGS',''))
tests=list(sorted((root/'tests').glob('*.cpp')))+list(sorted((root/'tests/algorithm_differential').glob('*/check.cpp')))
with tempfile.TemporaryDirectory(prefix='algorithm-cpp-tests-') as tmp:
    def check(item):
        i,p=item;binary=str(Path(tmp)/str(i))
        build=subprocess.run([compiler,*flags,str(p),'-o',binary],capture_output=True,text=True)
        result={'file':str(p.relative_to(root)),'passed':False}
        if build.returncode:result['compile_error']=build.stderr[-4000:];return result
        try:
            run=subprocess.run([binary],capture_output=True,text=True,timeout=90)
            expected=p.parent/'expected.out'
            if p.name=='translator_regression.cpp':expected=p.with_suffix('.out')
            result.update(exit_code=run.returncode,passed=run.returncode==0 and (not expected.exists() or run.stdout==expected.read_text()))
            if not result['passed']:result.update(stdout=run.stdout[-2000:],stderr=run.stderr[-4000:])
            return result
        except subprocess.TimeoutExpired:return dict(result,error='timeout')
    with ThreadPoolExecutor(max_workers=4) as pool:
        results=[]
        for x in pool.map(check,enumerate(tests)):results.append(x);print(x['file'],x['passed'],flush=True)
(root/'validation/regression-report.json').write_text(json.dumps(results,ensure_ascii=False,indent=2)+'\n')
raise SystemExit(any(not x['passed'] for x in results))
