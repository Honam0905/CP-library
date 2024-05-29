---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_reduction.hpp
    title: Modint/Barrett_reduction.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    };\n#line 3 \"Mod/mod_mul.hpp\"\nll modmul(ll a,ll b,ll mod){\n    Barrett br(mod);\n\
    \    return br.mul(a, b);\n}\n\nll mod_pow(ll a, ll n, ll mod) {\n  a %= mod;\n\
    \  Barrett bt(mod);\n  ll p = a;\n  ll v = 1;\n  while (n) {\n    if (n & 1) v\
    \ = bt.mul(v, p);\n    p = bt.mul(p, p);\n    n >>= 1;\n  }\n  return v;\n}\n\
    //or\n//only good for long long or int64_t\nlong long modmul2(long long a,long\
    \ long b,long long mod){\n   return (a*b)%mod;\n}\n"
  code: "#pragma once\n#include \"Modint/Barrett_reduction.hpp\"\nll modmul(ll a,ll\
    \ b,ll mod){\n    Barrett br(mod);\n    return br.mul(a, b);\n}\n\nll mod_pow(ll\
    \ a, ll n, ll mod) {\n  a %= mod;\n  Barrett bt(mod);\n  ll p = a;\n  ll v = 1;\n\
    \  while (n) {\n    if (n & 1) v = bt.mul(v, p);\n    p = bt.mul(p, p);\n    n\
    \ >>= 1;\n  }\n  return v;\n}\n//or\n//only good for long long or int64_t\nlong\
    \ long modmul2(long long a,long long b,long long mod){\n   return (a*b)%mod;\n\
    }\n"
  dependsOn:
  - Modint/Barrett_reduction.hpp
  isVerificationFile: false
  path: Mod/mod_mul.hpp
  requiredBy: []
  timestamp: '2024-05-29 09:32:46+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mod/mod_mul.hpp
layout: document
title: mod_mul
---

## Description:
There are some other version like:<br>
*Kactl version:https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h<br>
*Codeforces blog:https://codeforces.com/blog/entry/96759

