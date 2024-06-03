---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Mod/mod_inv.hpp
    title: Mod/mod_inv.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mod/mod_inv.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    using namespace std;\n\n// gcd(a, m) != 1 return -1 \ntemplate <typename T>\n\
    T inv_mod(T a, T m) {\n  if (m == 1) return 0;\n  if (a >= m) a %= m;\n  if (a\
    \ < 0) a += m;\n  if(__gcd(a,m)!=1) return -1;\n  T b = m, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + m;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n#line 3 \"\
    Mod/Barrett_2.hpp\"\nstruct Barrett_u32 {\n    u64 m, m2, im;\n    u64 div, rem;\n\
    \n    void set(u64 mod) {\n        m = mod;\n        m2 = mod << 1;\n        im\
    \ = ((((u128)(1ull) << 64)) + mod - 1) / mod;\n        div = 0;\n        rem =\
    \ 0;\n    }\n\n    void reduce(u64 a) {\n        u64 x = (u64)(((u128)(a) * im)\
    \ >> 64);\n        u64 y = x * m;\n        unsigned long long z;\n        u32\
    \ w = __builtin_usubll_overflow(a, y, &z) ? m : 0;\n        div = x;\n       \
    \ rem = z + w;\n    }\n\n    u32 add(u32 a, u32 b) {\n        a += b;\n      \
    \  a -= (a >= (u32)m ? (u32)m : 0);\n        return a;\n    }\n\n    u32 sub(u32\
    \ a, u32 b) {\n        a += (a < b ? (u32)m : 0);\n        a -= b;\n        return\
    \ a;\n    }\n\n    u32 min(u32 a) {\n        return sub(0, a);\n    }\n\n    u32\
    \ shl(u32 a) {\n        return (a <<= 1) >= m ? a - m : a;\n    }\n\n    u32 shr(u32\
    \ a) {\n        return (a & 1) ? ((a >> 1) + (m >> 1) + 1) : (a >> 1);\n    }\n\
    };\n\nstruct Barrett_u64 {\n    u128 m, m2, im;\n    u128 div, rem;\n\n    void\
    \ set(u128 mod) {\n        m = mod;\n        m2 = mod << 1;\n        im = (~((u128)0ull))\
    \ / mod;\n        div = 0;\n        rem = 0;\n    }\n\n    void reduce(u128 x)\
    \ {\n        if (m == 1) {\n            div = x;\n            rem = 0;\n     \
    \       return;\n        }\n        uint8_t  f;\n        u128 a = x >> 64;\n \
    \       u128 b = x & 0xffffffffffffffffull;\n        u128 c = im >> 64;\n    \
    \    u128 d = im & 0xffffffffffffffffull;\n        u128 ac = a * c;\n        u128\
    \ bd = (b * d) >> 64;\n        u128 ad = a * d;\n        u128 bc = b * c;\n  \
    \      f = (ad > ((u128)((i128)(-1L)) - bd));\n        bd += ad;\n        ac +=\
    \ f;\n        f = (bc > ((u128)((i128)(-1L)) - bd));\n        bd += bc;\n    \
    \    ac += f;\n        u128 q = ac + (bd >> 64);\n        u128 r = x - q * m;\n\
    \        if (m <= r) {\n            r -= m;\n            q += 1;\n        }\n\
    \        div = q;\n        rem = r;\n    }\n\n    u64 add(u64 a, u64 b) {\n  \
    \      a += b;\n        a -= (a >= (u64)m ? (u64)m : 0);\n        return a;\n\
    \    }\n\n    u64 sub(u64 a, u64 b) {\n        a += (a < b ? (u64)m : 0);\n  \
    \      a -= b;\n        return a;\n    }\n\n    u64 min(u64 a) {\n        return\
    \ sub(0, a);\n    }\n\n    u64 shl(u64 a) {\n        return (a <<= 1) >= m ? a\
    \ - m : a;\n    }\n\n    u64 shr(u64 a) {\n        return (a & 1) ? ((a >> 1)\
    \ + (m >> 1) + 1) : (a >> 1);\n    }\n};\n// Barrett reduction - 32-bit\nu32 mul_b32(struct\
    \ Barrett_u32 *b, u32 a, u32 x) {\n    b->reduce((u64)a * x);\n    return (u32)b->rem;\n\
    }\n\nu32 div_b32(struct Barrett_u32 *b, u32 a, u32 x) {\n    b->reduce((u64)a\
    \ << 32);\n    return (u32)(b->div * inv_mod(x,(u32)b->m));\n}\n\nu32 pow_b32(struct\
    \ Barrett_u32 *b, u32 a, u64 k) {\n    u32 ret = 1u;\n    u64 deg = k;\n    while\
    \ (deg > 0) {\n        if (deg & 1) {\n            ret = mul_b32(b, ret, a);\n\
    \        }\n        a = mul_b32(b, a, a);\n        deg >>= 1;\n    }\n    return\
    \ ret;\n}\n\n// Barrett reduction - 64-bit\nu64 mul_b64(struct Barrett_u64 *b,\
    \ u64 a, u64 x) {\n    b->reduce((u128)a * x);\n    return (u64)b->rem;\n}\n\n\
    u64 div_b64(struct Barrett_u64 *b, u64 a, u64 x) {\n    b->reduce((u128)a << 64);\n\
    \    return (u64)(b->div * inv_mod(x,(u64)b->m));\n}\n\nu64 pow_b64(struct Barrett_u64\
    \ *b, u64 a, u64 k) {\n    u64 ret = 1ull, deg = k;\n    while (deg > 0) {\n \
    \       if (deg & 1) {\n            ret = mul_b64(b, ret, a);\n        }\n   \
    \     a = mul_b64(b, a, a);\n        deg >>= 1;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"Mod/mod_inv.hpp\"\nstruct Barrett_u32 {\n    u64\
    \ m, m2, im;\n    u64 div, rem;\n\n    void set(u64 mod) {\n        m = mod;\n\
    \        m2 = mod << 1;\n        im = ((((u128)(1ull) << 64)) + mod - 1) / mod;\n\
    \        div = 0;\n        rem = 0;\n    }\n\n    void reduce(u64 a) {\n     \
    \   u64 x = (u64)(((u128)(a) * im) >> 64);\n        u64 y = x * m;\n        unsigned\
    \ long long z;\n        u32 w = __builtin_usubll_overflow(a, y, &z) ? m : 0;\n\
    \        div = x;\n        rem = z + w;\n    }\n\n    u32 add(u32 a, u32 b) {\n\
    \        a += b;\n        a -= (a >= (u32)m ? (u32)m : 0);\n        return a;\n\
    \    }\n\n    u32 sub(u32 a, u32 b) {\n        a += (a < b ? (u32)m : 0);\n  \
    \      a -= b;\n        return a;\n    }\n\n    u32 min(u32 a) {\n        return\
    \ sub(0, a);\n    }\n\n    u32 shl(u32 a) {\n        return (a <<= 1) >= m ? a\
    \ - m : a;\n    }\n\n    u32 shr(u32 a) {\n        return (a & 1) ? ((a >> 1)\
    \ + (m >> 1) + 1) : (a >> 1);\n    }\n};\n\nstruct Barrett_u64 {\n    u128 m,\
    \ m2, im;\n    u128 div, rem;\n\n    void set(u128 mod) {\n        m = mod;\n\
    \        m2 = mod << 1;\n        im = (~((u128)0ull)) / mod;\n        div = 0;\n\
    \        rem = 0;\n    }\n\n    void reduce(u128 x) {\n        if (m == 1) {\n\
    \            div = x;\n            rem = 0;\n            return;\n        }\n\
    \        uint8_t  f;\n        u128 a = x >> 64;\n        u128 b = x & 0xffffffffffffffffull;\n\
    \        u128 c = im >> 64;\n        u128 d = im & 0xffffffffffffffffull;\n  \
    \      u128 ac = a * c;\n        u128 bd = (b * d) >> 64;\n        u128 ad = a\
    \ * d;\n        u128 bc = b * c;\n        f = (ad > ((u128)((i128)(-1L)) - bd));\n\
    \        bd += ad;\n        ac += f;\n        f = (bc > ((u128)((i128)(-1L)) -\
    \ bd));\n        bd += bc;\n        ac += f;\n        u128 q = ac + (bd >> 64);\n\
    \        u128 r = x - q * m;\n        if (m <= r) {\n            r -= m;\n   \
    \         q += 1;\n        }\n        div = q;\n        rem = r;\n    }\n\n  \
    \  u64 add(u64 a, u64 b) {\n        a += b;\n        a -= (a >= (u64)m ? (u64)m\
    \ : 0);\n        return a;\n    }\n\n    u64 sub(u64 a, u64 b) {\n        a +=\
    \ (a < b ? (u64)m : 0);\n        a -= b;\n        return a;\n    }\n\n    u64\
    \ min(u64 a) {\n        return sub(0, a);\n    }\n\n    u64 shl(u64 a) {\n   \
    \     return (a <<= 1) >= m ? a - m : a;\n    }\n\n    u64 shr(u64 a) {\n    \
    \    return (a & 1) ? ((a >> 1) + (m >> 1) + 1) : (a >> 1);\n    }\n};\n// Barrett\
    \ reduction - 32-bit\nu32 mul_b32(struct Barrett_u32 *b, u32 a, u32 x) {\n   \
    \ b->reduce((u64)a * x);\n    return (u32)b->rem;\n}\n\nu32 div_b32(struct Barrett_u32\
    \ *b, u32 a, u32 x) {\n    b->reduce((u64)a << 32);\n    return (u32)(b->div *\
    \ inv_mod(x,(u32)b->m));\n}\n\nu32 pow_b32(struct Barrett_u32 *b, u32 a, u64 k)\
    \ {\n    u32 ret = 1u;\n    u64 deg = k;\n    while (deg > 0) {\n        if (deg\
    \ & 1) {\n            ret = mul_b32(b, ret, a);\n        }\n        a = mul_b32(b,\
    \ a, a);\n        deg >>= 1;\n    }\n    return ret;\n}\n\n// Barrett reduction\
    \ - 64-bit\nu64 mul_b64(struct Barrett_u64 *b, u64 a, u64 x) {\n    b->reduce((u128)a\
    \ * x);\n    return (u64)b->rem;\n}\n\nu64 div_b64(struct Barrett_u64 *b, u64\
    \ a, u64 x) {\n    b->reduce((u128)a << 64);\n    return (u64)(b->div * inv_mod(x,(u64)b->m));\n\
    }\n\nu64 pow_b64(struct Barrett_u64 *b, u64 a, u64 k) {\n    u64 ret = 1ull, deg\
    \ = k;\n    while (deg > 0) {\n        if (deg & 1) {\n            ret = mul_b64(b,\
    \ ret, a);\n        }\n        a = mul_b64(b, a, a);\n        deg >>= 1;\n   \
    \ }\n    return ret;\n}\n"
  dependsOn:
  - Mod/mod_inv.hpp
  isVerificationFile: false
  path: Mod/Barrett_2.hpp
  requiredBy: []
  timestamp: '2024-06-03 12:34:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mod/Barrett_2.hpp
layout: document
redirect_from:
- /library/Mod/Barrett_2.hpp
- /library/Mod/Barrett_2.hpp.html
title: Mod/Barrett_2.hpp
---
