---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_reduction.hpp
    title: Modint/Barrett_reduction.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mod/mod_sqrt.hpp
    title: Mod/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: NT/prime/prime_test.hpp
    title: NT/prime/prime_test.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
    title: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/prime_test.test.cpp
    title: test/yosupo/Math/prime_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Modint/Barrett_reduction.hpp\"\n/*\n  @see https://nyaannyaan.github.io/library/modint/barrett-reduction.hpp\n\
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
    };\n#line 3 \"Mod/mod_pow.hpp\"\n// int\nll mod_pow(ll a, ll n, int mod) {\n \
    \ a %= mod;\n  Barrett bt(mod);\n  ll p = a;\n  ll v = 1;\n  while (n) {\n   \
    \ if (n & 1) v = bt.mul(v, p);\n    p = bt.mul(p, p);\n    n >>= 1;\n  }\n  return\
    \ v;\n}\n//long long \nll mod_pow_long(ll a, ll n, ll mod) {\n  a %= mod;\n  ll\
    \ p = a;\n  ll v = 1;\n  while (n) {\n    if (n & 1) v = i128(v) * p % mod;\n\
    \    p = i128(p) * p % mod;\n    n >>= 1;\n  }\n  return v;\n}\n"
  code: "#pragma once\n#include \"Modint/Barrett_reduction.hpp\"\n// int\nll mod_pow(ll\
    \ a, ll n, int mod) {\n  a %= mod;\n  Barrett bt(mod);\n  ll p = a;\n  ll v =\
    \ 1;\n  while (n) {\n    if (n & 1) v = bt.mul(v, p);\n    p = bt.mul(p, p);\n\
    \    n >>= 1;\n  }\n  return v;\n}\n//long long \nll mod_pow_long(ll a, ll n,\
    \ ll mod) {\n  a %= mod;\n  ll p = a;\n  ll v = 1;\n  while (n) {\n    if (n &\
    \ 1) v = i128(v) * p % mod;\n    p = i128(p) * p % mod;\n    n >>= 1;\n  }\n \
    \ return v;\n}\n"
  dependsOn:
  - Modint/Barrett_reduction.hpp
  isVerificationFile: false
  path: Mod/mod_pow.hpp
  requiredBy:
  - NT/prime/prime_test.hpp
  - Mod/mod_sqrt.hpp
  timestamp: '2024-05-22 09:24:19+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/prime_test.test.cpp
  - test/yosupo/Math/mod_sqrt_yosupo.test.cpp
documentation_of: Mod/mod_pow.hpp
layout: document
redirect_from:
- /library/Mod/mod_pow.hpp
- /library/Mod/mod_pow.hpp.html
title: Mod/mod_pow.hpp
---
