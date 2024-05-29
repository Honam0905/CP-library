---
data:
  _extendedDependsOn: []
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Mod/mod_pow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"Mod/mod_pow.hpp\"\ntemplate <typename T>\nT mod_sqrt(const\
    \ T &a, const T &p) {\n  if (a == 0) return 0;\n  if (p == 2) return a;\n  if\
    \ (mod_pow_long(a, (p - 1) >> 1, p) != 1) return -1;\n  T b = 1;\n  while (mod_pow_long(b,\
    \ (p - 1) >> 1, p) == 1) ++b;\n  T e = 0, m = p - 1;\n  while (m % 2 == 0) m >>=\
    \ 1, ++e;\n  T x = mod_pow_long(a, (m - 1) >> 1, p);\n  T y = a * (x * x % p)\
    \ % p;\n  (x *= a) %= p;\n  T z = mod_pow_long(b, m, p);\n  while (y != 1) {\n\
    \    T j = 0, t = y;\n    while (t != 1) {\n      j += 1;\n      (t *= t) %= p;\n\
    \    }\n    z = mod_pow_long(z, T(1) << (e - j - 1), p);\n    (x *= z) %= p;\n\
    \    (z *= z) %= p;\n    (y *= z) %= p;\n    e = j;\n  }\n  return x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mod/mod_sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/Mod/mod_sqrt.hpp
- /library/Mod/mod_sqrt.hpp.html
title: Mod/mod_sqrt.hpp
---
