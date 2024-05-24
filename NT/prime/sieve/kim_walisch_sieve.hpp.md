---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_2.test.cpp
    title: test/yosupo/Math/enum_prime_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"NT/prime/sieve/kim_walisch_sieve.hpp\"\nusing BYTE=unsigned\
    \ char;\ntemplate<class T>\nstd::vector<T> sieve_2(T lim) {\n    std::vector<T>\
    \ primes;\n    primes.reserve(lim / std::log(lim));\n\n    if (lim >= 2) {\n \
    \       primes.push_back(2);\n    }\n\n    T sqrt = std::sqrt(lim);\n    int sieve_size\
    \ = std::max(sqrt, static_cast<T>(1 << 15));\n    int segment_size = sieve_size\
    \ * 16;\n    std::vector<BYTE> mark(sieve_size);\n    std::vector<BYTE> is_prime(sqrt\
    \ + 1, true);\n    std::vector<T> seg_prime;\n    std::vector<T> seg_multi;\n\n\
    \    for (T i = 3; i <= sqrt; i += 2) {\n        if (is_prime[i]) {\n        \
    \    for (T j = i * i; j <= sqrt; j += i) {\n                is_prime[j] = false;\n\
    \            }\n        }\n    }\n\n    int reset[16];\n    for (int i = 0; i\
    \ < 8; ++i) {\n        reset[2 * i] = reset[2 * i + 1] = ~(1 << i);\n    }\n\n\
    \    T s = 3;\n    for (T low = 0; low <= lim; low += segment_size) {\n      \
    \  std::fill(mark.begin(), mark.end(), 0xff);\n        T high = std::min(low +\
    \ segment_size - 1, lim);\n        sieve_size = (high - low) / 16 + 1;\n\n   \
    \     for (; s * s <= high; s += 2) {\n            if (is_prime[s]) {\n      \
    \          seg_prime.push_back(s);\n                seg_multi.push_back(s * s\
    \ - low);\n            }\n        }\n\n        for (size_t i = 0; i < seg_prime.size();\
    \ ++i) {\n            T j = seg_multi[i];\n            for (T k = seg_prime[i]\
    \ * 2; j < segment_size; j += k) {\n                mark[j >> 4] &= reset[j %\
    \ 16];\n            }\n            seg_multi[i] = j - segment_size;\n        }\n\
    \n        if (high == lim) {\n            int bits = 0xff << ((lim % 16) + 1)\
    \ / 2;\n            mark[sieve_size - 1] &= ~bits;\n        }\n\n        for (int\
    \ n = 0; n < sieve_size; n++) {\n            for (int i = 0; i < 8; i++) {\n \
    \               if (mark[n] & (1 << i)) {\n                    auto p = low +\
    \ n * 16 + i * 2 + 1;\n                    if (p > 2) {\n                    \
    \    primes.push_back(p);\n                    }\n                }\n        \
    \    }\n        }\n    }\n\n    return primes;\n}\n"
  code: "#pragma once\nusing BYTE=unsigned char;\ntemplate<class T>\nstd::vector<T>\
    \ sieve_2(T lim) {\n    std::vector<T> primes;\n    primes.reserve(lim / std::log(lim));\n\
    \n    if (lim >= 2) {\n        primes.push_back(2);\n    }\n\n    T sqrt = std::sqrt(lim);\n\
    \    int sieve_size = std::max(sqrt, static_cast<T>(1 << 15));\n    int segment_size\
    \ = sieve_size * 16;\n    std::vector<BYTE> mark(sieve_size);\n    std::vector<BYTE>\
    \ is_prime(sqrt + 1, true);\n    std::vector<T> seg_prime;\n    std::vector<T>\
    \ seg_multi;\n\n    for (T i = 3; i <= sqrt; i += 2) {\n        if (is_prime[i])\
    \ {\n            for (T j = i * i; j <= sqrt; j += i) {\n                is_prime[j]\
    \ = false;\n            }\n        }\n    }\n\n    int reset[16];\n    for (int\
    \ i = 0; i < 8; ++i) {\n        reset[2 * i] = reset[2 * i + 1] = ~(1 << i);\n\
    \    }\n\n    T s = 3;\n    for (T low = 0; low <= lim; low += segment_size) {\n\
    \        std::fill(mark.begin(), mark.end(), 0xff);\n        T high = std::min(low\
    \ + segment_size - 1, lim);\n        sieve_size = (high - low) / 16 + 1;\n\n \
    \       for (; s * s <= high; s += 2) {\n            if (is_prime[s]) {\n    \
    \            seg_prime.push_back(s);\n                seg_multi.push_back(s *\
    \ s - low);\n            }\n        }\n\n        for (size_t i = 0; i < seg_prime.size();\
    \ ++i) {\n            T j = seg_multi[i];\n            for (T k = seg_prime[i]\
    \ * 2; j < segment_size; j += k) {\n                mark[j >> 4] &= reset[j %\
    \ 16];\n            }\n            seg_multi[i] = j - segment_size;\n        }\n\
    \n        if (high == lim) {\n            int bits = 0xff << ((lim % 16) + 1)\
    \ / 2;\n            mark[sieve_size - 1] &= ~bits;\n        }\n\n        for (int\
    \ n = 0; n < sieve_size; n++) {\n            for (int i = 0; i < 8; i++) {\n \
    \               if (mark[n] & (1 << i)) {\n                    auto p = low +\
    \ n * 16 + i * 2 + 1;\n                    if (p > 2) {\n                    \
    \    primes.push_back(p);\n                    }\n                }\n        \
    \    }\n        }\n    }\n\n    return primes;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/prime/sieve/kim_walisch_sieve.hpp
  requiredBy: []
  timestamp: '2024-05-24 13:17:26+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/enum_prime_2.test.cpp
documentation_of: NT/prime/sieve/kim_walisch_sieve.hpp
layout: document
redirect_from:
- /library/NT/prime/sieve/kim_walisch_sieve.hpp
- /library/NT/prime/sieve/kim_walisch_sieve.hpp.html
title: NT/prime/sieve/kim_walisch_sieve.hpp
---
