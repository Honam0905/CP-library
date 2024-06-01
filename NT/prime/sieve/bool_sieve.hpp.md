---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_5.test.cpp
    title: test/yosupo/Math/enum_prime_5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/enum_prime_5.test.cpp
documentation_of: NT/prime/sieve/bool_sieve.hpp
layout: document
---

## Description:
Prime sieve that return bool useful when to check number 
is prime or not

## Time:

* $O(Nloglog(N))$
