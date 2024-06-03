---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mod/mod_mul.hpp
    title: Mod/mod_mul.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: NT/prime/factorize.hpp
    title: NT/prime/factorize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/factorize_yosupo.test.cpp
    title: test/yosupo/Math/factorize_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/prime_test_yosupo.test.cpp
    title: test/yosupo/Math/prime_test_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mod/mod_mul.hpp\"\nu64 get_nr(u64 M) {\n    u64 IV = 2 -\
    \ M;\n    for (int i = 0; i < 5; ++i) {\n        IV *= 2 - M * IV;\n    }\n  \
    \  return IV;\n}\n\nu64 modmul(u64 x, u64 y, u64 M) {\n    u64 IV=get_nr(M);\n\
    \    auto t = u128(x) * y;\n    u64 lo = t, hi = t >> 64;\n    return (hi + M)\
    \ - u64((u128(lo * IV) * M) >> 64);\n}\n \nu64 modpow(u64 a, u64 b, u64 M) {\n\
    \    u64 res = 1;\n    u64 IV = get_nr(M);\n    while (b) {\n        if (b & 1)\
    \ {\n            res = modmul(res, a, M);\n        }\n        a = modmul(a, a,\
    \ M);\n        b >>= 1;\n    }\n    return res;\n}\n//or\n//only good for long\
    \ long or int64_t\nlong long modmul2(long long a,long long b,long long mod){\n\
    \   return (a*b)%mod;\n}\n#line 3 \"NT/prime/prime_test.hpp\"\nbool isPrime(u64\
    \ x) {\n    if (x < 64) {\n        return (u64(1) << x) & 0x28208a20a08a28ac;\n\
    \    }\n    if (x % 2 == 0) {\n        return false;\n    }\n    const int k =\
    \ __builtin_ctzll(x - 1);\n    const u64 d = (x - 1) >> k, IV = get_nr(x), R =\
    \ (-x) % x, R2 = (-u128(x)) % x, nR = x - R;\n    auto mr7 = [&](u64 t1, u64 t2,\
    \ u64 t3, u64 t4, u64 t5, u64 t6, u64 t7) {\n        u64 r1 = R, r2 = R, r3 =\
    \ R, r4 = R, r5 = R, r6 = R, r7 = R;\n        t1 = modmul(t1, R2, x), t2 = modmul(t2,\
    \ R2, x), t3 = modmul(t3, R2, x);\n        t4 = modmul(t4, R2, x), t5 = modmul(t5,\
    \ R2, x), t6 = modmul(t6, R2, x), t7 = modmul(t7, R2, x);\n        for (u64 b\
    \ = d; b; b >>= 1) {\n            if (b & 1) {\n                r1 = modmul(r1,\
    \ t1, x), r2 = modmul(r2, t2, x), r3 = modmul(r3, t3, x);\n                r4\
    \ = modmul(r4, t4, x), r5 = modmul(r5, t5, x), r6 = modmul(r6, t6, x), r7 = modmul(r7,\
    \ t7, x);\n            }\n            t1 = modmul(t1, t1, x), t2 = modmul(t2,\
    \ t2, x), t3 = modmul(t3, t3, x);\n            t4 = modmul(t4, t4, x), t5 = modmul(t5,\
    \ t5, x), t6 = modmul(t6, t6, x), t7 = modmul(t7, t7, x);\n        }\n       \
    \ r1 = min(r1, r1 - x), r2 = min(r2, r2 - x), r3 = min(r3, r3 - x);\n        r4\
    \ = min(r4, r4 - x), r5 = min(r5, r5 - x), r6 = min(r6, r6 - x), r7 = min(r7,\
    \ r7 - x);\n        int res1 = (r1 == R) | (r1 == nR), res2 = (r2 == R) | (r2\
    \ == nR), res3 = (r3 == R) | (r3 == nR);\n        int res4 = (r4 == R) | (r4 ==\
    \ nR), res5 = (r5 == R) | (r5 == nR), res6 = (r6 == R) | (r6 == nR), res7 = (r7\
    \ == R) | (r7 == nR);\n        for (int j = 0; j < k - 1; ++j) {\n           \
    \ r1 = modmul(r1, r1, x), r2 = modmul(r2, r2, x), r3 = modmul(r3, r3, x);\n  \
    \          r4 = modmul(r4, r4, x), r5 = modmul(r5, r5, x), r6 = modmul(r6, r6,\
    \ x), r7 = modmul(r7, r7, x);\n            res1 |= (min(r1, r1 - x) == nR), res2\
    \ |= (min(r2, r2 - x) == nR), res3 |= (min(r3, r3 - x) == nR);\n            res4\
    \ |= (min(r4, r4 - x) == nR), res5 |= (min(r5, r5 - x) == nR), res6 |= (min(r6,\
    \ r6 - x) == nR), res7 |= (min(r7, r7 - x) == nR);\n        }\n        return\
    \ res1 & res2 & res3 & res4 & res5 & res6 & res7;\n    };\n    if (x == 2 || x\
    \ == 3 || x == 5 || x == 13 || x == 19 || x == 73 || x == 193 || x == 407521 ||\
    \ x == 299210837) {\n        return true;\n    }\n    return mr7(2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022);\n}\n"
  code: "#pragma once\n#include \"Mod/mod_mul.hpp\"\nbool isPrime(u64 x) {\n    if\
    \ (x < 64) {\n        return (u64(1) << x) & 0x28208a20a08a28ac;\n    }\n    if\
    \ (x % 2 == 0) {\n        return false;\n    }\n    const int k = __builtin_ctzll(x\
    \ - 1);\n    const u64 d = (x - 1) >> k, IV = get_nr(x), R = (-x) % x, R2 = (-u128(x))\
    \ % x, nR = x - R;\n    auto mr7 = [&](u64 t1, u64 t2, u64 t3, u64 t4, u64 t5,\
    \ u64 t6, u64 t7) {\n        u64 r1 = R, r2 = R, r3 = R, r4 = R, r5 = R, r6 =\
    \ R, r7 = R;\n        t1 = modmul(t1, R2, x), t2 = modmul(t2, R2, x), t3 = modmul(t3,\
    \ R2, x);\n        t4 = modmul(t4, R2, x), t5 = modmul(t5, R2, x), t6 = modmul(t6,\
    \ R2, x), t7 = modmul(t7, R2, x);\n        for (u64 b = d; b; b >>= 1) {\n   \
    \         if (b & 1) {\n                r1 = modmul(r1, t1, x), r2 = modmul(r2,\
    \ t2, x), r3 = modmul(r3, t3, x);\n                r4 = modmul(r4, t4, x), r5\
    \ = modmul(r5, t5, x), r6 = modmul(r6, t6, x), r7 = modmul(r7, t7, x);\n     \
    \       }\n            t1 = modmul(t1, t1, x), t2 = modmul(t2, t2, x), t3 = modmul(t3,\
    \ t3, x);\n            t4 = modmul(t4, t4, x), t5 = modmul(t5, t5, x), t6 = modmul(t6,\
    \ t6, x), t7 = modmul(t7, t7, x);\n        }\n        r1 = min(r1, r1 - x), r2\
    \ = min(r2, r2 - x), r3 = min(r3, r3 - x);\n        r4 = min(r4, r4 - x), r5 =\
    \ min(r5, r5 - x), r6 = min(r6, r6 - x), r7 = min(r7, r7 - x);\n        int res1\
    \ = (r1 == R) | (r1 == nR), res2 = (r2 == R) | (r2 == nR), res3 = (r3 == R) |\
    \ (r3 == nR);\n        int res4 = (r4 == R) | (r4 == nR), res5 = (r5 == R) | (r5\
    \ == nR), res6 = (r6 == R) | (r6 == nR), res7 = (r7 == R) | (r7 == nR);\n    \
    \    for (int j = 0; j < k - 1; ++j) {\n            r1 = modmul(r1, r1, x), r2\
    \ = modmul(r2, r2, x), r3 = modmul(r3, r3, x);\n            r4 = modmul(r4, r4,\
    \ x), r5 = modmul(r5, r5, x), r6 = modmul(r6, r6, x), r7 = modmul(r7, r7, x);\n\
    \            res1 |= (min(r1, r1 - x) == nR), res2 |= (min(r2, r2 - x) == nR),\
    \ res3 |= (min(r3, r3 - x) == nR);\n            res4 |= (min(r4, r4 - x) == nR),\
    \ res5 |= (min(r5, r5 - x) == nR), res6 |= (min(r6, r6 - x) == nR), res7 |= (min(r7,\
    \ r7 - x) == nR);\n        }\n        return res1 & res2 & res3 & res4 & res5\
    \ & res6 & res7;\n    };\n    if (x == 2 || x == 3 || x == 5 || x == 13 || x ==\
    \ 19 || x == 73 || x == 193 || x == 407521 || x == 299210837) {\n        return\
    \ true;\n    }\n    return mr7(2, 325, 9375, 28178, 450775, 9780504, 1795265022);\n\
    }\n"
  dependsOn:
  - Mod/mod_mul.hpp
  isVerificationFile: false
  path: NT/prime/prime_test.hpp
  requiredBy:
  - NT/prime/factorize.hpp
  timestamp: '2024-05-30 11:12:13+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/factorize_yosupo.test.cpp
  - test/yosupo/Math/prime_test_yosupo.test.cpp
documentation_of: NT/prime/prime_test.hpp
layout: document
redirect_from:
- /library/NT/prime/prime_test.hpp
- /library/NT/prime/prime_test.hpp.html
title: NT/prime/prime_test.hpp
---
