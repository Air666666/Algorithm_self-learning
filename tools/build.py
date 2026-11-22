#!/usr/bin/env python3
"""Build one standalone solution or test harness with the required C++17 flags."""
import argparse, os, shlex, subprocess
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('source');p.add_argument('-o','--output',default='solution')
a=p.parse_args()
raise SystemExit(subprocess.call([os.environ.get('CXX','clang++'),'-std=c++17','-O2','-fwrapv','-Wno-deprecated-declarations',*shlex.split(os.environ.get('CXXFLAGS','')),a.source,'-o',a.output]))
