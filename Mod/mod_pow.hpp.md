---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_reduction.hpp
    title: Modint/Barrett_reduction.hpp
  - icon: ':heavy_check_mark:'
    path: Modint/dynamic_modint.hpp
    title: Modint/dynamic_modint.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mod/mod_sqrt.hpp
    title: Mod/mod_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
    title: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
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
    };\n\n//u64 version:\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 rem(u128 x) {\n    u128 z = (x & u64(-1)) * ml;\n\
    \    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x >> 64) *\
    \ mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n  }\n\
    \n  u64 mul(u64 a, u64 b) { return rem(u128(a) * b); }\n};\n#line 3 \"Modint/dynamic_modint.hpp\"\
    \ntemplate <int id>\nstruct dynamic_modint {\n  int x;\n\n  dynamic_modint() :\
    \ x(0) {}\n\n  dynamic_modint(int64_t y) {\n    int z = y % get_mod();\n    if\
    \ (z < 0) z += get_mod();\n    x = z;\n  }\n\n  dynamic_modint &operator+=(const\
    \ dynamic_modint &p) {\n    if ((x += p.x) >= get_mod()) x -= get_mod();\n   \
    \ return *this;\n  }\n\n  dynamic_modint &operator-=(const dynamic_modint &p)\
    \ {\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n    return\
    \ *this;\n  }\n\n  dynamic_modint &operator*=(const dynamic_modint &p) {\n   \
    \ x = rem((unsigned long long)x * p.x);\n    return *this;\n  }\n\n  dynamic_modint\
    \ &operator/=(const dynamic_modint &p) {\n    *this *= p.inv();\n    return *this;\n\
    \  }\n\n  dynamic_modint operator-() const { return dynamic_modint(-x); }\n  dynamic_modint\
    \ operator+() const { return *this; }\n\n  dynamic_modint operator+(const dynamic_modint\
    \ &p) const {\n    return dynamic_modint(*this) += p;\n  }\n\n  dynamic_modint\
    \ operator-(const dynamic_modint &p) const {\n    return dynamic_modint(*this)\
    \ -= p;\n  }\n\n  dynamic_modint operator*(const dynamic_modint &p) const {\n\
    \    return dynamic_modint(*this) *= p;\n  }\n\n  dynamic_modint operator/(const\
    \ dynamic_modint &p) const {\n    return dynamic_modint(*this) /= p;\n  }\n\n\
    \  bool operator==(const dynamic_modint &p) const { return x == p.x; }\n\n  bool\
    \ operator!=(const dynamic_modint &p) const { return x != p.x; }\n\n  dynamic_modint\
    \ inv() const {\n    int a = x, b = get_mod(), u = 1, v = 0, t;\n    while (b\
    \ > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v,\
    \ v);\n    }\n    return dynamic_modint(u);\n  }\n\n  dynamic_modint pow(int64_t\
    \ n) const {\n    dynamic_modint ret(1), mul(x);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n\n  friend ostream &operator<<(ostream &os, const dynamic_modint &p) {\n\
    \    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is, dynamic_modint\
    \ &a) {\n    int64_t t;\n    is >> t;\n    a = dynamic_modint(t);\n    return\
    \ (is);\n  }\n\n  int get() const { return x; }\n\n  inline unsigned int rem(unsigned\
    \ long long p) { return barrett().rem(p); }\n\n  static inline Barrett &barrett()\
    \ {\n    static Barrett b;\n    return b;\n  }\n\n  static inline int &get_mod()\
    \ {\n    static int mod = 0;\n    return mod;\n  }\n\n  static void set_mod(int\
    \ md) {\n    assert(0 < md && md <= (1LL << 30) - 1);\n    get_mod() = md;\n \
    \   barrett() = Barrett(md);\n  }\n};\n\nusing modint = dynamic_modint<-1>;\n\
    #line 3 \"Mod/mod_pow.hpp\"\nu32 mod_pow(int a, ll n, int mod) {\n  assert(n >=\
    \ 0);\n  a = ((a %= mod) < 0 ? a + mod : a);\n  if ((mod & 1) && (mod < (1 <<\
    \ 30))) {\n    using mint = dynamic_modint<202311021>;\n    mint::set_mod(mod);\n\
    \    return mint(a).pow(n).get();\n  }\n  Barrett bt(mod);\n  int r = 1;\n  while\
    \ (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a, a), n >>= 1;\n  }\n\
    \  return r;\n}\n\nu64 mod_pow_64(ll a, ll n, u64 mod) {\n  assert(n >= 0);\n\
    \  a = ((a %= mod) < 0 ? a + mod : a);\n  if ((mod & 1) && (mod < (u64(1) << 62)))\
    \ {\n    using mint =dynamic_modint<202311021>;\n    mint::set_mod(mod);\n   \
    \ return mint(a).pow(n).get();\n  }\n  Barrett_64 bt(mod);\n  ll r = 1;\n  while\
    \ (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a, a), n >>= 1;\n  }\n\
    \  return r;\n}\n"
  code: "#pragma once\n#include \"Modint/dynamic_modint.hpp\"\nu32 mod_pow(int a,\
    \ ll n, int mod) {\n  assert(n >= 0);\n  a = ((a %= mod) < 0 ? a + mod : a);\n\
    \  if ((mod & 1) && (mod < (1 << 30))) {\n    using mint = dynamic_modint<202311021>;\n\
    \    mint::set_mod(mod);\n    return mint(a).pow(n).get();\n  }\n  Barrett bt(mod);\n\
    \  int r = 1;\n  while (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a,\
    \ a), n >>= 1;\n  }\n  return r;\n}\n\nu64 mod_pow_64(ll a, ll n, u64 mod) {\n\
    \  assert(n >= 0);\n  a = ((a %= mod) < 0 ? a + mod : a);\n  if ((mod & 1) &&\
    \ (mod < (u64(1) << 62))) {\n    using mint =dynamic_modint<202311021>;\n    mint::set_mod(mod);\n\
    \    return mint(a).pow(n).get();\n  }\n  Barrett_64 bt(mod);\n  ll r = 1;\n \
    \ while (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a, a), n >>= 1;\n\
    \  }\n  return r;\n}\n"
  dependsOn:
  - Modint/dynamic_modint.hpp
  - Modint/Barrett_reduction.hpp
  isVerificationFile: false
  path: Mod/mod_pow.hpp
  requiredBy:
  - Mod/mod_sqrt.hpp
  timestamp: '2024-05-29 22:35:44+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/mod_sqrt_yosupo.test.cpp
documentation_of: Mod/mod_pow.hpp
layout: document
redirect_from:
- /library/Mod/mod_pow.hpp
- /library/Mod/mod_pow.hpp.html
title: Mod/mod_pow.hpp
---
