---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Graph/Eulerian_trail\
    \ (directed).hpp: line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_undirected\"\
    \n#include \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\n\
    const ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"Graph/Eulerian_trail (directed).hpp\"\nint main(){\n  int t; cin>>t;\n\
    \  while(t--){\n    int n,m; cin>>n>>m;\n    eulerian_trail<int,false>et(n,m);\n\
    \    rep(i,m){\n        int u,v; cin>>u>>v;\n        et.add_edge(u,v,i);\n   \
    \ }\n     if(!et.get_trail()){\n        cout<<\"No\"<<'\\n';\n     }else{\n  \
    \      cout<<\"Yes\"<<'\\n';\n        rep(i,(int)et.path.size()){\n          \
    \  cout<<et.path[i]<<(i+1<(int)et.path.size()?' ':'\\n');\n        }\n       \
    \ if(m==0){\n            cout<<'\\n';\n        }else{\n            For(i,1,(int)et.edge_path.size()){\n\
    \                cout<<et.edge_path[i]<<(i+1<(int)et.edge_path.size()?' ':'\\\
    n');\n            }\n        }\n     }\n   }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/Graph/Eulerian_trail_undirected_yosupo.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Graph/Eulerian_trail_undirected_yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Graph/Eulerian_trail_undirected_yosupo.test.cpp
- /verify/test/yosupo/Graph/Eulerian_trail_undirected_yosupo.test.cpp.html
title: test/yosupo/Graph/Eulerian_trail_undirected_yosupo.test.cpp
---
