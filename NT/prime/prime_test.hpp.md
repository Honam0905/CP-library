---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test
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
  code: "#pragma once\n/*\n   Primality tests by CP algorithms with higher bases\n\
    \   @see https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test\n\
    */\n#include \"Mod/mod_pow.hpp\"\nbool check_composite(u64 n, u64 a, u64 d, int\
    \ s) {\n    u64 x = mod_pow_long(a, d, n);\n    if (x == 1 || x == n - 1)\n  \
    \      return false;\n    for (int r = 1; r < s; r++) {\n        x = (u128)x *\
    \ x % n;\n        if (x == n - 1)\n            return false;\n    }\n    return\
    \ true;\n}\n\nbool MillerRabin(u64 n) {\n    if (n < 2)\n        return false;\n\
    \n    // Small primes to check divisibility\n    for (u64 a : {2, 3, 5, 13, 19,\
    \ 73, 193, 407521, 299210837}) {\n        if (n % a == 0)\n            return\
    \ n == a;\n    }\n\n    int r = 0;\n    u64 d = n - 1;\n    while ((d & 1) ==\
    \ 0) {\n        d >>= 1;\n        r++;\n    }\n\n    // Larger bases for checking\
    \ primality\n    for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n        if (n == a)\n            return true;\n        if (check_composite(n,\
    \ a, d, r))\n            return false;\n    }\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/prime/prime_test.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NT/prime/prime_test.hpp
layout: document
redirect_from:
- /library/NT/prime/prime_test.hpp
- /library/NT/prime/prime_test.hpp.html
title: NT/prime/prime_test.hpp
---
