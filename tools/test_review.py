#!/usr/bin/env python3
"""Replay reviewed program inputs and bounded self-checks against saved Java output."""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import json,os,shlex,subprocess,tempfile,re
root=Path(__file__).resolve().parents[1]
flags=['-std=c++17','-fwrapv','-O1','-Wno-deprecated-declarations']+shlex.split(os.environ.get('CXXFLAGS',''))
compiler=os.environ.get('CXX','clang++')
spec=json.loads((root/'tests/review_selfchecks.json').read_text());jobs=[]
for x in spec:jobs.append(('selfcheck',x['file'],x))
for d in sorted((root/'tests/review_programs').glob('*/*')):
 if d.is_dir():jobs.append(('stdin','src/'+str(d.relative_to(root/'tests/review_programs'))+'.cpp',d))
with tempfile.TemporaryDirectory(prefix='review-cpp-') as temp:
 def run(item):
  index,(kind,file,info)=item;exe=str(Path(temp)/str(index));source=root/file
  if kind=='selfcheck':
   s=source.read_text();position=s.index('static void java_main')
   for name,(old,new) in info['parameters'].items():s=s[:position]+re.sub(r'\b'+re.escape(name)+r'\s*=\s*'+old+r'\b',name+' = '+new,s[position:],count=1)
   s=s.replace('#include "../../include/jcompat.hpp"','#include "'+str(root/'include/jcompat.hpp')+'"').replace('using namespace j;', 'using namespace j;\ndouble review_random(){static std::uint32_t state=1729;state=state*1664525U+1013904223U;return double(state)/4294967296.0;}').replace('j::random()', 'review_random()')
   source=Path(temp)/(str(index)+'.cpp');source.write_text(s);inputs=[('',info['expected'])]
  else:inputs=[(p.read_text(),p.with_suffix('.out').read_text()) for p in sorted(info.glob('*.in'))]
  z=subprocess.run([compiler,*flags,str(source),'-o',exe],capture_output=True,text=True)
  if z.returncode:return {'file':file,'kind':kind,'passed':False,'diagnostics':z.stderr[-3000:]}
  for data,expected in inputs:
   try:r=subprocess.run([exe],input=data,capture_output=True,text=True,timeout=45)
   except subprocess.TimeoutExpired:return {'file':file,'kind':kind,'passed':False,'error':'timeout'}
   if r.returncode or r.stdout!=expected:return {'file':file,'kind':kind,'passed':False,'exit_code':r.returncode,'actual':r.stdout[-2000:],'stderr':r.stderr[-2000:]}
  return {'file':file,'kind':kind,'passed':True,'cases':len(inputs)}
 with ThreadPoolExecutor(max_workers=4) as pool:
  results=[]
  for x in pool.map(run,enumerate(jobs)):results.append(x);print(x['file'],x['kind'],x['passed'],flush=True)
(root/'validation/review-replay.json').write_text(json.dumps(results,ensure_ascii=False,indent=2)+'\n')
raise SystemExit(any(not x['passed'] for x in results))
