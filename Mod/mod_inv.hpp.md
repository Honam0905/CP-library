---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mod/Primitive_root.hpp
    title: Mod/Primitive_root.hpp
  - icon: ':x:'
    path: Modint/Barrett_2.hpp
    title: Modint/Barrett_2.hpp
  - icon: ':warning:'
    path: Modint/montgomery_multiplication.hpp
    title: Modint/montgomery_multiplication.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: primitive_root_yosupo.test.cpp
    title: primitive_root_yosupo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mod/mod_inv.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    using namespace std;\n\n// gcd(a, m) != 1 return -1 \ntemplate <typename T>\n\
    T inv_mod(T a, T m) {\n  if (m == 1) return 0;\n  if (a >= m) a %= m;\n  if (a\
    \ < 0) a += m;\n  if(__gcd(a,m)!=1) return -1;\n  T b = m, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + m;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <type_traits>\nusing namespace\
    \ std;\n\n// gcd(a, m) != 1 return -1 \ntemplate <typename T>\nT inv_mod(T a,\
    \ T m) {\n  if (m == 1) return 0;\n  if (a >= m) a %= m;\n  if (a < 0) a += m;\n\
    \  if(__gcd(a,m)!=1) return -1;\n  T b = m, s = 1, t = 0;\n  while (true) {\n\
    \    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if (b == 1)\
    \ return t + m;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mod/mod_inv.hpp
  requiredBy:
  - Mod/Primitive_root.hpp
  - Modint/Barrett_2.hpp
  - Modint/montgomery_multiplication.hpp
  timestamp: '2024-05-29 09:05:18+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - primitive_root_yosupo.test.cpp
documentation_of: Mod/mod_inv.hpp
layout: document
redirect_from:
- /library/Mod/mod_inv.hpp
- /library/Mod/mod_inv.hpp.html
title: Mod/mod_inv.hpp
---
