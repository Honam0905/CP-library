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
  bundledCode: "#line 2 \"NT/prime/block_sieve.hpp\"\ntemplate<class T>\nvector<T>\
    \ block_sieve(T L, T R) {\n    T lim = sqrt(R);\n    vector<char> mark(lim + 1,\
    \ false);\n    vector<T> primes;\n\n    for (T i = 2; i <= lim; ++i) {\n     \
    \   if (!mark[i]) {\n            primes.emplace_back(i);\n            for (T j\
    \ = i * i; j <= lim; j += i)\n                mark[j] = true;\n        }\n   \
    \ }\n\n    vector<T> isPrime;\n    vector<char> block(R - L + 1, true);\n\n  \
    \  for (T i : primes) {\n        for (T j = max(i * i, (L + i - 1) / i * i); j\
    \ <= R; j += i)\n            block[j - L] = false;\n    }\n\n    if (L == 1)\n\
    \        block[0] = false;\n\n    for (T i = L; i <= R; ++i) {\n        if (block[i\
    \ - L])\n            isPrime.emplace_back(i);\n    }\n\n    return isPrime;\n\
    }\n"
  code: "#pragma once\ntemplate<class T>\nvector<T> block_sieve(T L, T R) {\n    T\
    \ lim = sqrt(R);\n    vector<char> mark(lim + 1, false);\n    vector<T> primes;\n\
    \n    for (T i = 2; i <= lim; ++i) {\n        if (!mark[i]) {\n            primes.emplace_back(i);\n\
    \            for (T j = i * i; j <= lim; j += i)\n                mark[j] = true;\n\
    \        }\n    }\n\n    vector<T> isPrime;\n    vector<char> block(R - L + 1,\
    \ true);\n\n    for (T i : primes) {\n        for (T j = max(i * i, (L + i - 1)\
    \ / i * i); j <= R; j += i)\n            block[j - L] = false;\n    }\n\n    if\
    \ (L == 1)\n        block[0] = false;\n\n    for (T i = L; i <= R; ++i) {\n  \
    \      if (block[i - L])\n            isPrime.emplace_back(i);\n    }\n\n    return\
    \ isPrime;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/prime/block_sieve.hpp
  requiredBy: []
  timestamp: '2024-05-24 22:25:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NT/prime/block_sieve.hpp
layout: document
redirect_from:
- /library/NT/prime/block_sieve.hpp
- /library/NT/prime/block_sieve.hpp.html
title: NT/prime/block_sieve.hpp
---
