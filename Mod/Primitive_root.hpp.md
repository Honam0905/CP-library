---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mod/mod_inv.hpp
    title: Mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: Mod/mod_mul.hpp
    title: Mod/mod_mul.hpp
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_2.hpp
    title: Modint/Barrett_2.hpp
  - icon: ':heavy_check_mark:'
    path: NT/prime/factorize.hpp
    title: NT/prime/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: NT/prime/prime_test.hpp
    title: NT/prime/prime_test.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Mod/Primitive_root.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"NT/prime/factorize.hpp\"\n#pragma once\nu64 PrimitiveRoot(u64\
    \ p){\n   u64 x=0;\n   auto mi=factor(p-1);\n   sort(all(mi));\n   Barrett_u64\
    \ br;\n   br.set(p);\n   mi.resize(unique(all(mi))-mi.begin());\n   for(int i=0;!i;){\n\
    \      i=1; ++x;\n      for(u64 f:mi){\n         if(pow_b64(&br,x,(p-1)/f)==1){\n\
    \            i=0; \n            break;\n         }\n      }\n   }\n   return x;\n\
    }\n"
  dependsOn:
  - NT/prime/factorize.hpp
  - Modint/Barrett_2.hpp
  - Mod/mod_inv.hpp
  - NT/prime/prime_test.hpp
  - Mod/mod_mul.hpp
  isVerificationFile: false
  path: Mod/Primitive_root.hpp
  requiredBy: []
  timestamp: '2024-06-03 16:32:37+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mod/Primitive_root.hpp
layout: document
redirect_from:
- /library/Mod/Primitive_root.hpp
- /library/Mod/Primitive_root.hpp.html
title: Mod/Primitive_root.hpp
---
