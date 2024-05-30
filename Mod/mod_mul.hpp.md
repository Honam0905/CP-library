---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: NT/prime/prime_test.hpp
    title: NT/prime/prime_test.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mod/mod_mul.hpp\"\nu64 get_nr(u64 M) {\n    u64 IV = 2 -\
    \ M;\n    for (int i = 0; i < 5; ++i) {\n        IV *= 2 - M * IV;\n    }\n  \
    \  return IV;\n}\n\nu64 modmul(u64 x, u64 y, u64 M) {\n    u64 IV=get_nr(M);\n\
    \    auto t = u128(x) * y;\n    u64 lo = t, hi = t >> 64;\n    return (hi + M)\
    \ - u64((u128(lo * IV) * M) >> 64);\n}\n \nu64 modpow(u64 a, u64 b, u64 M) {\n\
    \    u64 res = 1;\n    u64 IV = get_nr(M);\n    while (b) {\n        if (b & 1)\
    \ {\n            res = modmul(res, a, IV, M);\n        }\n        a = modmul(a,\
    \ a, IV, M);\n        b >>= 1;\n    }\n    return res;\n}\n//or\n//only good for\
    \ long long or int64_t\nlong long modmul2(long long a,long long b,long long mod){\n\
    \   return (a*b)%mod;\n}\n"
  code: "#pragma once\nu64 get_nr(u64 M) {\n    u64 IV = 2 - M;\n    for (int i =\
    \ 0; i < 5; ++i) {\n        IV *= 2 - M * IV;\n    }\n    return IV;\n}\n\nu64\
    \ modmul(u64 x, u64 y, u64 M) {\n    u64 IV=get_nr(M);\n    auto t = u128(x) *\
    \ y;\n    u64 lo = t, hi = t >> 64;\n    return (hi + M) - u64((u128(lo * IV)\
    \ * M) >> 64);\n}\n \nu64 modpow(u64 a, u64 b, u64 M) {\n    u64 res = 1;\n  \
    \  u64 IV = get_nr(M);\n    while (b) {\n        if (b & 1) {\n            res\
    \ = modmul(res, a, IV, M);\n        }\n        a = modmul(a, a, IV, M);\n    \
    \    b >>= 1;\n    }\n    return res;\n}\n//or\n//only good for long long or int64_t\n\
    long long modmul2(long long a,long long b,long long mod){\n   return (a*b)%mod;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mod/mod_mul.hpp
  requiredBy:
  - NT/prime/prime_test.hpp
  timestamp: '2024-05-30 10:59:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mod/mod_mul.hpp
layout: document
---

## Description:
There are some other version like:<br>
*Kactl version:https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h<br>
*Codeforces blog:https://codeforces.com/blog/entry/96759

