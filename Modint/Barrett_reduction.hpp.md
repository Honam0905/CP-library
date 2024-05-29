---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mod/mod_pow.hpp
    title: Mod/mod_pow.hpp
  - icon: ':x:'
    path: Mod/mod_sqrt.hpp
    title: Mod/mod_sqrt.hpp
  - icon: ':question:'
    path: Modint/dynamic_modint.hpp
    title: Modint/dynamic_modint.hpp
  - icon: ':x:'
    path: NT/prime/prime_test.hpp
    title: NT/prime/prime_test.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/BC_prime_mod.test.cpp
    title: test/yosupo/Math/BC_prime_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
    title: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
  - icon: ':x:'
    path: test/yosupo/Math/prime_test.test.cpp
    title: test/yosupo/Math/prime_test.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Barrett_reduction
    - https://nyaannyaan.github.io/library/modint/barrett-reduction.hpp
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
    };\n\n//u64 version:\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 rem(u128 x) {\n    u128 z = (x & u64(-1)) * ml;\n\
    \    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x >> 64) *\
    \ mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n  }\n\
    \n  u64 mul(u64 a, u64 b) { return rem(u128(a) * b); }\n};\n"
  code: "#pragma once\n/*\n  @see https://nyaannyaan.github.io/library/modint/barrett-reduction.hpp\n\
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
    \n  u64 mul(u64 a, u64 b) { return rem(u128(a) * b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Modint/Barrett_reduction.hpp
  requiredBy:
  - NT/prime/prime_test.hpp
  - Mod/mod_pow.hpp
  - Mod/mod_sqrt.hpp
  - Modint/dynamic_modint.hpp
  timestamp: '2024-05-29 22:19:57+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Math/prime_test.test.cpp
  - test/yosupo/Math/mod_sqrt_yosupo.test.cpp
  - test/yosupo/Math/BC_prime_mod.test.cpp
documentation_of: Modint/Barrett_reduction.hpp
layout: document
redirect_from:
- /library/Modint/Barrett_reduction.hpp
- /library/Modint/Barrett_reduction.hpp.html
title: Modint/Barrett_reduction.hpp
---
