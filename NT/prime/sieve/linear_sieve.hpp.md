---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_1.test.cpp
    title: test/yosupo/Math/enum_prime_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"NT/prime/sieve/linear_sieve.hpp\"\ntemplate<class T>\nvector<T>\
    \ sieve(T n) {\n    vector<bool> is_prime(n+1, true);\n    vector<T> primes;\n\
    \n    is_prime[0] = is_prime[1] = false;\n\n    for (T i = 2; i <= n; i++) {\n\
    \        if (is_prime[i]) {\n            primes.push_back(i);\n        }\n   \
    \     for (T j = 0; j < primes.size() && i * primes[j] <= n; j++) {\n        \
    \    is_prime[i * primes[j]] = false;\n            if (i % primes[j] == 0) {\n\
    \                break;\n            }\n        }\n    }\n\n    return primes;\n\
    }\n"
  code: "#pragma once\ntemplate<class T>\nvector<T> sieve(T n) {\n    vector<bool>\
    \ is_prime(n+1, true);\n    vector<T> primes;\n\n    is_prime[0] = is_prime[1]\
    \ = false;\n\n    for (T i = 2; i <= n; i++) {\n        if (is_prime[i]) {\n \
    \           primes.push_back(i);\n        }\n        for (T j = 0; j < primes.size()\
    \ && i * primes[j] <= n; j++) {\n            is_prime[i * primes[j]] = false;\n\
    \            if (i % primes[j] == 0) {\n                break;\n            }\n\
    \        }\n    }\n\n    return primes;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/prime/sieve/linear_sieve.hpp
  requiredBy: []
  timestamp: '2024-05-24 22:59:46+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/enum_prime_1.test.cpp
documentation_of: NT/prime/sieve/linear_sieve.hpp
layout: document
redirect_from:
- /library/NT/prime/sieve/linear_sieve.hpp
- /library/NT/prime/sieve/linear_sieve.hpp.html
title: NT/prime/sieve/linear_sieve.hpp
---
