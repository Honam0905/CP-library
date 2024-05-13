---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Fenwick_tree.hpp
    title: Fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: marco.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"marco.hpp\"\n#include \"Fenwick_tree.hpp\"\n\nint main(){\nFT;\nint\
    \ t=1; \n//sc.read(t); int tc=0;\nwhile(t--)\n{\n//tc++;\n//cout << \"Case #\"\
    \ << tc << \": \";\n    int n,q; cin>>n>>q;\n    vector<ll> a(n);\n    rep(i,n)\
    \ cin>>a[i];\n    Fenwick ft(n);\n    rep(i,n) ft.update(i+1,a[i]);\n    while\
    \ (q--) {\n        int op; cin>>op;\n        if (op == 0) {\n            int p,\
    \ x; cin>>p>>x;\n            ft.update(p + 1, x);\n        } else {\n        \
    \    int l, r; cin>>l>>r;\n            cout<<ft.prefix(l,r)<<'\\n';\n        }\n\
    \    }\n// cerr << \"Time elapsed: \" << TIME << \" s.\\n\";\n}\n}\n"
  dependsOn:
  - Fenwick_tree.hpp
  isVerificationFile: true
  path: PARS_yosupo.test.cpp
  requiredBy: []
  timestamp: '2024-05-13 12:09:00+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: PARS_yosupo.test.cpp
layout: document
redirect_from:
- /verify/PARS_yosupo.test.cpp
- /verify/PARS_yosupo.test.cpp.html
title: PARS_yosupo.test.cpp
---
