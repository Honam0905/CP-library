---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mod/mod_pow.hpp
    title: Mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_reduction.hpp
    title: Modint/Barrett_reduction.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/prime_test.test.cpp
    title: test/yosupo/Math/prime_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test
  bundledCode: "#line 2 \"NT/prime/prime_test.hpp\"\n/*\n   Primality tests by CP\
    \ algorithms with higher bases\n   @see https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test\n\
    */\n#line 2 \"Modint/Barrett_reduction.hpp\"\n/*\n  @see https://nyaannyaan.github.io/library/modint/barrett-reduction.hpp\n\
    \  @see https://en.wikipedia.org/wiki/Barrett_reduction\n*/\nstruct Barrett {\n\
    \  using u32 = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n)\
    \ : m(n), im(u64(-1) / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64\
    \ x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n    return m\
    \ <= r ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n\
    \  constexpr inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n\
    \    return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32\
    \ a = rem(n), r = m == 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r)\
    \ * a);\n      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n\
    \  constexpr inline u32 mul(u32 a, u32 b) {\n    return rem(u64(a) * b);\n  }\n\
    };\n\n//u64 version:\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 rem(u128 x) {\n    u128 z = (x & u64(-1)) * ml;\n\
    \    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x >> 64) *\
    \ mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n  }\n\
    \n  u64 mul(u64 a, u64 b) { return rem(u128(a) * b); }\n};\n#line 3 \"Mod/mod_pow.hpp\"\
    \n// int\nll mod_pow(ll a, ll n, int mod) {\n  a %= mod;\n  Barrett bt(mod);\n\
    \  ll p = a;\n  ll v = 1;\n  while (n) {\n    if (n & 1) v = bt.mul(v, p);\n \
    \   p = bt.mul(p, p);\n    n >>= 1;\n  }\n  return v;\n}\n//long long \nll mod_pow_long(ll\
    \ a, ll n, ll mod) {\n  a %= mod;\n  ll p = a;\n  ll v = 1;\n  while (n) {\n \
    \   if (n & 1) v = i128(v) * p % mod;\n    p = i128(p) * p % mod;\n    n >>= 1;\n\
    \  }\n  return v;\n}\n#line 7 \"NT/prime/prime_test.hpp\"\nbool check_composite(u64\
    \ n, u64 a, u64 d, int s) {\n    u64 x = mod_pow_long(a, d, n);\n    if (x ==\
    \ 1 || x == n - 1)\n        return false;\n    for (int r = 1; r < s; r++) {\n\
    \        x = (u128)x * x % n;\n        if (x == n - 1)\n            return false;\n\
    \    }\n    return true;\n}\n\nbool MillerRabin(u64 n) {\n    if (n < 2)\n   \
    \     return false;\n\n    // Small primes to check divisibility\n    for (u64\
    \ a : {2, 3, 5, 13, 19, 73, 193, 407521, 299210837}) {\n        if (n % a == 0)\n\
    \            return n == a;\n    }\n\n    int r = 0;\n    u64 d = n - 1;\n   \
    \ while ((d & 1) == 0) {\n        d >>= 1;\n        r++;\n    }\n\n    // Larger\
    \ bases for checking primality\n    for (u64 a : {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\n        if (n == a)\n            return true;\n   \
    \     if (check_composite(n, a, d, r))\n            return false;\n    }\n   \
    \ return true;\n}\n"
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
  dependsOn:
  - Mod/mod_pow.hpp
  - Modint/Barrett_reduction.hpp
  isVerificationFile: false
  path: NT/prime/prime_test.hpp
  requiredBy: []
  timestamp: '2024-05-29 22:19:57+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/prime_test.test.cpp
documentation_of: NT/prime/prime_test.hpp
layout: document
redirect_from:
- /library/NT/prime/prime_test.hpp
- /library/NT/prime/prime_test.hpp.html
title: NT/prime/prime_test.hpp
---
