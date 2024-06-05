---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mod/Primitive_root.hpp
    title: Mod/Primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_2.hpp
    title: Modint/Barrett_2.hpp
  - icon: ':heavy_check_mark:'
    path: NT/prime/factorize.hpp
    title: NT/prime/factorize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/factorize_yosupo.test.cpp
    title: test/yosupo/Math/factorize_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/primitive_root.test.cpp
    title: test/yosupo/Math/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mod/mod_inv.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    \n// gcd(a, m) != 1 return -1 \ntemplate <typename T>\nT inv_mod(T a, T m) {\n\
    \  if (m == 1) return 0;\n  if (a >= m) a %= m;\n  if (a < 0) a += m;\n  if(__gcd(a,m)!=1)\
    \ return -1;\n  T b = m, s = 1, t = 0;\n  while (true) {\n    if (a == 1) return\
    \ s;\n    t -= b / a * s;\n    b %= a;\n    if (b == 1) return t + m;\n    s -=\
    \ a / b * t;\n    a %= b;\n  }\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <type_traits>\n\n// gcd(a, m)\
    \ != 1 return -1 \ntemplate <typename T>\nT inv_mod(T a, T m) {\n  if (m == 1)\
    \ return 0;\n  if (a >= m) a %= m;\n  if (a < 0) a += m;\n  if(__gcd(a,m)!=1)\
    \ return -1;\n  T b = m, s = 1, t = 0;\n  while (true) {\n    if (a == 1) return\
    \ s;\n    t -= b / a * s;\n    b %= a;\n    if (b == 1) return t + m;\n    s -=\
    \ a / b * t;\n    a %= b;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mod/mod_inv.hpp
  requiredBy:
  - NT/prime/factorize.hpp
  - Mod/Primitive_root.hpp
  - Modint/Barrett_2.hpp
  timestamp: '2024-06-05 18:50:12+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/factorize_yosupo.test.cpp
  - test/yosupo/Math/primitive_root.test.cpp
documentation_of: Mod/mod_inv.hpp
layout: document
redirect_from:
- /library/Mod/mod_inv.hpp
- /library/Mod/mod_inv.hpp.html
title: Mod/mod_inv.hpp
---
