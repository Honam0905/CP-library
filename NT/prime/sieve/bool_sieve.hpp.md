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
  bundledCode: "#line 2 \"NT/prime/sieve/bool_sieve.hpp\"\n// Prime -> {0, 0, 1, 1,\
    \ 0, 1, 0, 1, ...}\nvector<bool> prime_sieve(int N) {\n  vector<bool> sieve(max(1,\
    \ N) + 1, 1);\n  sieve[0] = sieve[1] = false;\n  for (int i = 2; i * i <= N; i++)\n\
    \    if (sieve[i] == true)\n      for (int j = i * i; j <= N; j += i) sieve[j]\
    \ = false;\n  return sieve;\n}\n"
  code: "#pragma once\n// Prime -> {0, 0, 1, 1, 0, 1, 0, 1, ...}\nvector<bool> prime_sieve(int\
    \ N) {\n  vector<bool> sieve(max(1, N) + 1, 1);\n  sieve[0] = sieve[1] = false;\n\
    \  for (int i = 2; i * i <= N; i++)\n    if (sieve[i] == true)\n      for (int\
    \ j = i * i; j <= N; j += i) sieve[j] = false;\n  return sieve;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/prime/sieve/bool_sieve.hpp
  requiredBy: []
  timestamp: '2024-06-01 22:35:41+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NT/prime/sieve/bool_sieve.hpp
layout: document
redirect_from:
- /library/NT/prime/sieve/bool_sieve.hpp
- /library/NT/prime/sieve/bool_sieve.hpp.html
title: NT/prime/sieve/bool_sieve.hpp
---
