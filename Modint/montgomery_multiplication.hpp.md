---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/mod_inv.test.cpp
    title: test/yosupo/Math/mod_inv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cp-algorithms.com/algebra/montgomery_multiplication.html
    - https://en.wikipedia.org/wiki/Montgomery_modular_multiplication
    - https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp
  bundledCode: "#line 1 \"Modint/montgomery_multiplication.hpp\"\n/*\n  inv_mod from\
    \ atcoder library\n  reference:https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp\n\
    */\ntemplate<class T>\nconstexpr T safe_mod(T x, T m) {\n    x %= m;\n    if (x\
    \ < 0) x += m;\n    return x;\n}\ntemplate<class T>\nconstexpr std::pair<T, T>\
    \ inv_gcd(T a, T b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\
    \n    T s = b, t = a;\n    T m0 = 0, m1 = 1;\n\n    while (t) {\n        T u =\
    \ s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        auto tmp = s;\n\
    \        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n     \
    \   m1 = tmp;\n    }\n\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    template<class T>\nT mod_inv(T x, T m) {\n    assert(1 <= m);\n    auto z = inv_gcd(x,\
    \ m);\n    assert(z.first == 1);\n    return z.second;\n}\n/*\n  montgomery multiplication\n\
    \  @see https://en.wikipedia.org/wiki/Montgomery_modular_multiplication\n  @see\
    \ https://cp-algorithms.com/algebra/montgomery_multiplication.html\n*/\nstruct\
    \ Montgomery_u32 {\n    u32 n, n2, ni, r1, r2, r3;\n\n    void set(u32 mod) {\n\
    \        n = mod;\n        n2 = mod << 1;\n        ni = mod;\n        ni *= 2\
    \ - ni * mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n    \
    \    ni *= 2 - ni * mod;\n        r1 = (u32)(int32_t)-1 % mod + 1;\n        r2\
    \ = (u64)(int64_t)-1 % mod + 1;\n        r3 = (u32)(((u64)r1 * (u64)r2) % mod);\n\
    \    }\n\n    u32 reduce(u64 a) {\n        u32 y = (u32)(a >> 32) - (u32)(((u64)((u32)a\
    \ * ni) * n) >> 32);\n        return (int32_t)y < 0 ? y + n : y;\n    }\n\n  \
    \  u32 to(u32 a) {\n        return reduce((u64)a * r2);\n    }\n\n    u32 from(u32\
    \ a) {\n        return reduce((u64)a);\n    }\n\n    u32 add(u32 a, u32 b) {\n\
    \        a += b;\n        a -= (a >= n ? n : 0);\n        return a;\n    }\n\n\
    \    u32 sub(u32 a, u32 b) {\n        a += (a < b ? n : 0);\n        a -= b;\n\
    \        return a;\n    }\n\n    u32 min(u32 a) {\n        return sub(0, a);\n\
    \    }\n\n    u32 shl(u32 a) {\n        return (a <<= 1) >= n ? a - n : a;\n \
    \   }\n\n    u32 shr(u32 a) {\n        return (a & 1) ? ((a >> 1) + (n >> 1) +\
    \ 1) : (a >> 1);\n    }\n\n    u32 inv(u32 a) {\n        return reduce((u64)r3\
    \ * mod_inv(a, n));\n    }\n};\n\nstruct Montgomery_u64 {\n    u64 n, n2, ni,\
    \ r1, r2, r3;\n\n    void set(u64 mod) {\n        n = mod;\n        n2 = mod <<\
    \ 1;\n        ni = mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n\
    \        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni\
    \ * mod;\n        r1 = (u64)(int64_t)-1 % mod + 1;\n        r2 = (u128)(i128)-1\
    \ % mod + 1;\n        r3 = (u64)(((u128)r1 * (u128)r2) % mod);\n    }\n\n    u64\
    \ reduce(u128 a) {\n        u64 y = (u64)(a >> 64) - (u64)(((u128)((u64)a * ni)\
    \ * n) >> 64);\n        return (int64_t)y < 0 ? y + n : y;\n    }\n\n    u64 to(u64\
    \ a) {\n        return reduce((u128)a * r2);\n    }\n\n    u64 from(u64 a) {\n\
    \        return reduce((u128)a);\n    }\n\n    u64 add(u64 a, u64 b) {\n     \
    \   a += b;\n        a -= (a >= n ? n : 0);\n        return a;\n    }\n\n    u64\
    \ sub(u64 a, u64 b) {\n        a += (a < b ? n : 0);\n        a -= b;\n      \
    \  return a;\n    }\n\n    u64 min(u64 a) {\n        return sub(0, a);\n    }\n\
    \n    u64 shl(u64 a) {\n        return (a <<= 1) >= n ? a - n : a;\n    }\n\n\
    \    u64 shr(u64 a) {\n        return (a & 1) ? ((a >> 1) + (n >> 1) + 1) : (a\
    \ >> 1);\n    }\n\n    u64 inv(u64 a) {\n        return reduce((u128)r3 * mod_inv(a,\
    \ n));\n    }\n};\n// Montgomery multiplication - 32-bit\nu32 mul_m32(struct Montgomery_u32\
    \ *m, u32 a, u32 b) {\n    return m->reduce((u64)a * b);\n}\n\nu32 div_m32(struct\
    \ Montgomery_u32 *m, u32 a, u32 b) {\n    return mul_m32(m, a, m->inv(b));\n}\n\
    \nu32 pow_m32(struct Montgomery_u32 *m, u32 a, u64 k) {\n    u32 ret = m->r1;\n\
    \    u64 deg = k;\n    while (deg > 0) {\n        if (deg & 1) {\n           \
    \ ret = mul_m32(m, ret, a);\n        }\n        a = mul_m32(m, a, a);\n      \
    \  deg >>= 1;\n    }\n    return m->from(ret);\n}\n\n// Montgomery multiplication\
    \ - 64-bit\nu64 mul_m64(struct Montgomery_u64 *m, u64 a, u64 b) {\n    return\
    \ m->reduce((u128)a * b);\n}\n\nu64 div_m64(struct Montgomery_u64 *m, u64 a, u64\
    \ b) {\n    return mul_m64(m, a, m->inv(b));\n}\n\nu64 pow_m64(struct Montgomery_u64\
    \ *m, u64 a, u64 k) {\n    u64 ret = m->r1, deg = k;\n    while (deg > 0) {\n\
    \        if (deg & 1) {\n            ret = mul_m64(m, ret, a);\n        }\n  \
    \      a = mul_m64(m, a, a);\n        deg >>= 1;\n    }\n    return m->from(ret);\n\
    }\n"
  code: "/*\n  inv_mod from atcoder library\n  reference:https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp\n\
    */\ntemplate<class T>\nconstexpr T safe_mod(T x, T m) {\n    x %= m;\n    if (x\
    \ < 0) x += m;\n    return x;\n}\ntemplate<class T>\nconstexpr std::pair<T, T>\
    \ inv_gcd(T a, T b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\
    \n    T s = b, t = a;\n    T m0 = 0, m1 = 1;\n\n    while (t) {\n        T u =\
    \ s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        auto tmp = s;\n\
    \        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n     \
    \   m1 = tmp;\n    }\n\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    template<class T>\nT mod_inv(T x, T m) {\n    assert(1 <= m);\n    auto z = inv_gcd(x,\
    \ m);\n    assert(z.first == 1);\n    return z.second;\n}\n/*\n  montgomery multiplication\n\
    \  @see https://en.wikipedia.org/wiki/Montgomery_modular_multiplication\n  @see\
    \ https://cp-algorithms.com/algebra/montgomery_multiplication.html\n*/\nstruct\
    \ Montgomery_u32 {\n    u32 n, n2, ni, r1, r2, r3;\n\n    void set(u32 mod) {\n\
    \        n = mod;\n        n2 = mod << 1;\n        ni = mod;\n        ni *= 2\
    \ - ni * mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n    \
    \    ni *= 2 - ni * mod;\n        r1 = (u32)(int32_t)-1 % mod + 1;\n        r2\
    \ = (u64)(int64_t)-1 % mod + 1;\n        r3 = (u32)(((u64)r1 * (u64)r2) % mod);\n\
    \    }\n\n    u32 reduce(u64 a) {\n        u32 y = (u32)(a >> 32) - (u32)(((u64)((u32)a\
    \ * ni) * n) >> 32);\n        return (int32_t)y < 0 ? y + n : y;\n    }\n\n  \
    \  u32 to(u32 a) {\n        return reduce((u64)a * r2);\n    }\n\n    u32 from(u32\
    \ a) {\n        return reduce((u64)a);\n    }\n\n    u32 add(u32 a, u32 b) {\n\
    \        a += b;\n        a -= (a >= n ? n : 0);\n        return a;\n    }\n\n\
    \    u32 sub(u32 a, u32 b) {\n        a += (a < b ? n : 0);\n        a -= b;\n\
    \        return a;\n    }\n\n    u32 min(u32 a) {\n        return sub(0, a);\n\
    \    }\n\n    u32 shl(u32 a) {\n        return (a <<= 1) >= n ? a - n : a;\n \
    \   }\n\n    u32 shr(u32 a) {\n        return (a & 1) ? ((a >> 1) + (n >> 1) +\
    \ 1) : (a >> 1);\n    }\n\n    u32 inv(u32 a) {\n        return reduce((u64)r3\
    \ * mod_inv(a, n));\n    }\n};\n\nstruct Montgomery_u64 {\n    u64 n, n2, ni,\
    \ r1, r2, r3;\n\n    void set(u64 mod) {\n        n = mod;\n        n2 = mod <<\
    \ 1;\n        ni = mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n\
    \        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni\
    \ * mod;\n        r1 = (u64)(int64_t)-1 % mod + 1;\n        r2 = (u128)(i128)-1\
    \ % mod + 1;\n        r3 = (u64)(((u128)r1 * (u128)r2) % mod);\n    }\n\n    u64\
    \ reduce(u128 a) {\n        u64 y = (u64)(a >> 64) - (u64)(((u128)((u64)a * ni)\
    \ * n) >> 64);\n        return (int64_t)y < 0 ? y + n : y;\n    }\n\n    u64 to(u64\
    \ a) {\n        return reduce((u128)a * r2);\n    }\n\n    u64 from(u64 a) {\n\
    \        return reduce((u128)a);\n    }\n\n    u64 add(u64 a, u64 b) {\n     \
    \   a += b;\n        a -= (a >= n ? n : 0);\n        return a;\n    }\n\n    u64\
    \ sub(u64 a, u64 b) {\n        a += (a < b ? n : 0);\n        a -= b;\n      \
    \  return a;\n    }\n\n    u64 min(u64 a) {\n        return sub(0, a);\n    }\n\
    \n    u64 shl(u64 a) {\n        return (a <<= 1) >= n ? a - n : a;\n    }\n\n\
    \    u64 shr(u64 a) {\n        return (a & 1) ? ((a >> 1) + (n >> 1) + 1) : (a\
    \ >> 1);\n    }\n\n    u64 inv(u64 a) {\n        return reduce((u128)r3 * mod_inv(a,\
    \ n));\n    }\n};\n// Montgomery multiplication - 32-bit\nu32 mul_m32(struct Montgomery_u32\
    \ *m, u32 a, u32 b) {\n    return m->reduce((u64)a * b);\n}\n\nu32 div_m32(struct\
    \ Montgomery_u32 *m, u32 a, u32 b) {\n    return mul_m32(m, a, m->inv(b));\n}\n\
    \nu32 pow_m32(struct Montgomery_u32 *m, u32 a, u64 k) {\n    u32 ret = m->r1;\n\
    \    u64 deg = k;\n    while (deg > 0) {\n        if (deg & 1) {\n           \
    \ ret = mul_m32(m, ret, a);\n        }\n        a = mul_m32(m, a, a);\n      \
    \  deg >>= 1;\n    }\n    return m->from(ret);\n}\n\n// Montgomery multiplication\
    \ - 64-bit\nu64 mul_m64(struct Montgomery_u64 *m, u64 a, u64 b) {\n    return\
    \ m->reduce((u128)a * b);\n}\n\nu64 div_m64(struct Montgomery_u64 *m, u64 a, u64\
    \ b) {\n    return mul_m64(m, a, m->inv(b));\n}\n\nu64 pow_m64(struct Montgomery_u64\
    \ *m, u64 a, u64 k) {\n    u64 ret = m->r1, deg = k;\n    while (deg > 0) {\n\
    \        if (deg & 1) {\n            ret = mul_m64(m, ret, a);\n        }\n  \
    \      a = mul_m64(m, a, a);\n        deg >>= 1;\n    }\n    return m->from(ret);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Modint/montgomery_multiplication.hpp
  requiredBy: []
  timestamp: '2024-06-04 11:24:19+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/mod_inv.test.cpp
documentation_of: Modint/montgomery_multiplication.hpp
layout: document
redirect_from:
- /library/Modint/montgomery_multiplication.hpp
- /library/Modint/montgomery_multiplication.hpp.html
title: Modint/montgomery_multiplication.hpp
---
