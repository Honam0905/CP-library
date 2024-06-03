---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Modint/Barrett_2.hpp
    title: Modint/Barrett_2.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - Modint/Barrett_2.hpp
  timestamp: '2024-05-29 09:05:18+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mod/mod_inv.hpp
layout: document
redirect_from:
- /library/Mod/mod_inv.hpp
- /library/Mod/mod_inv.hpp.html
title: Mod/mod_inv.hpp
---
