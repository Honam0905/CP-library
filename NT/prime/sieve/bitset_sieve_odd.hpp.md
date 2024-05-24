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
  bundledCode: "#line 2 \"NT/prime/sieve/bitset_sieve_odd.hpp\"\ntemplate<class T>\n\
    std::vector<T> sieve_bitset_odd(T n) {\n    const T S = sizeof(uint64_t) * 8;\n\
    \    std::vector<uint64_t> bitset((n / 2 + S - 1) / S, 0xFFFFFFFFFFFFFFFFULL);\n\
    \    std::vector<T> primes;\n\n    primes.push_back(2);\n    for (T i = 3; i *\
    \ i <= n; i += 2) {\n        if (bitset[i / 2 / S] & (1ULL << ((i / 2) % S)))\
    \ {\n            for (T j = i * i; j <= n; j += i * 2) {\n                bitset[j\
    \ / 2 / S] &= ~(1ULL << ((j / 2) % S));\n            }\n            primes.push_back(i);\n\
    \        }\n    }\n\n    for (T i = primes.back() + 2; i <= n; i += 2) {\n   \
    \     if (bitset[i / 2 / S] & (1ULL << ((i / 2) % S))) {\n            primes.push_back(i);\n\
    \        }\n    }\n\n    return primes;\n}\n"
  code: "#pragma once\ntemplate<class T>\nstd::vector<T> sieve_bitset_odd(T n) {\n\
    \    const T S = sizeof(uint64_t) * 8;\n    std::vector<uint64_t> bitset((n /\
    \ 2 + S - 1) / S, 0xFFFFFFFFFFFFFFFFULL);\n    std::vector<T> primes;\n\n    primes.push_back(2);\n\
    \    for (T i = 3; i * i <= n; i += 2) {\n        if (bitset[i / 2 / S] & (1ULL\
    \ << ((i / 2) % S))) {\n            for (T j = i * i; j <= n; j += i * 2) {\n\
    \                bitset[j / 2 / S] &= ~(1ULL << ((j / 2) % S));\n            }\n\
    \            primes.push_back(i);\n        }\n    }\n\n    for (T i = primes.back()\
    \ + 2; i <= n; i += 2) {\n        if (bitset[i / 2 / S] & (1ULL << ((i / 2) %\
    \ S))) {\n            primes.push_back(i);\n        }\n    }\n\n    return primes;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/prime/sieve/bitset_sieve_odd.hpp
  requiredBy: []
  timestamp: '2024-05-24 13:30:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NT/prime/sieve/bitset_sieve_odd.hpp
layout: document
redirect_from:
- /library/NT/prime/sieve/bitset_sieve_odd.hpp
- /library/NT/prime/sieve/bitset_sieve_odd.hpp.html
title: NT/prime/sieve/bitset_sieve_odd.hpp
---
