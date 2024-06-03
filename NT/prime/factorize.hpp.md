---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mod/mod_inv.hpp
    title: Mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: Mod/mod_mul.hpp
    title: Mod/mod_mul.hpp
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_2.hpp
    title: Modint/Barrett_2.hpp
  - icon: ':heavy_check_mark:'
    path: NT/prime/prime_test.hpp
    title: NT/prime/prime_test.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mod/Primitive_root.hpp
    title: Mod/Primitive_root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/factorize_yosupo.test.cpp
    title: test/yosupo/Math/factorize_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mod/mod_inv.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    using namespace std;\n\n// gcd(a, m) != 1 return -1 \ntemplate <typename T>\n\
    T inv_mod(T a, T m) {\n  if (m == 1) return 0;\n  if (a >= m) a %= m;\n  if (a\
    \ < 0) a += m;\n  if(__gcd(a,m)!=1) return -1;\n  T b = m, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + m;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n#line 3 \"\
    Modint/Barrett_2.hpp\"\nstruct Barrett_u32 {\n    u64 m, m2, im;\n    u64 div,\
    \ rem;\n\n    void set(u64 mod) {\n        m = mod;\n        m2 = mod << 1;\n\
    \        im = ((((u128)(1ull) << 64)) + mod - 1) / mod;\n        div = 0;\n  \
    \      rem = 0;\n    }\n\n    void reduce(u64 a) {\n        u64 x = (u64)(((u128)(a)\
    \ * im) >> 64);\n        u64 y = x * m;\n        unsigned long long z;\n     \
    \   u32 w = __builtin_usubll_overflow(a, y, &z) ? m : 0;\n        div = x;\n \
    \       rem = z + w;\n    }\n\n    u32 add(u32 a, u32 b) {\n        a += b;\n\
    \        a -= (a >= (u32)m ? (u32)m : 0);\n        return a;\n    }\n\n    u32\
    \ sub(u32 a, u32 b) {\n        a += (a < b ? (u32)m : 0);\n        a -= b;\n \
    \       return a;\n    }\n\n    u32 min(u32 a) {\n        return sub(0, a);\n\
    \    }\n\n    u32 shl(u32 a) {\n        return (a <<= 1) >= m ? a - m : a;\n \
    \   }\n\n    u32 shr(u32 a) {\n        return (a & 1) ? ((a >> 1) + (m >> 1) +\
    \ 1) : (a >> 1);\n    }\n};\n\nstruct Barrett_u64 {\n    u128 m, m2, im;\n   \
    \ u128 div, rem;\n\n    void set(u128 mod) {\n        m = mod;\n        m2 = mod\
    \ << 1;\n        im = (~((u128)0ull)) / mod;\n        div = 0;\n        rem =\
    \ 0;\n    }\n\n    void reduce(u128 x) {\n        if (m == 1) {\n            div\
    \ = x;\n            rem = 0;\n            return;\n        }\n        uint8_t\
    \  f;\n        u128 a = x >> 64;\n        u128 b = x & 0xffffffffffffffffull;\n\
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
    \ }\n    return ret;\n}\n#line 2 \"Mod/mod_mul.hpp\"\nu64 get_nr(u64 M) {\n  \
    \  u64 IV = 2 - M;\n    for (int i = 0; i < 5; ++i) {\n        IV *= 2 - M * IV;\n\
    \    }\n    return IV;\n}\n\nu64 modmul(u64 x, u64 y, u64 M) {\n    u64 IV=get_nr(M);\n\
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
    \ 28178, 450775, 9780504, 1795265022);\n}\n#line 4 \"NT/prime/factorize.hpp\"\n\
    u64 pollard(u64 n) {\n  Barrett_u64 br;\n  br.set(n);\n\tu64 x = 0, y = 0, t =\
    \ 30, prd = 2, i = 1, q;\n\tauto f = [&](u64 x) { return mul_b64(&br,x, x) + i;\
    \ };\n\twhile (t++ % 40 || __gcd(prd, n) == 1) {\n\t\tif (x == y) x = ++i, y =\
    \ f(x);\n\t\tif ((q = mul_b64(&br,prd, max(x,y) - min(x,y)))) prd = q;\n\t\tx\
    \ = f(x), y = f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\nvector<u64> factor(u64\
    \ n) {\n\tif (n == 1) return {};\n\tif (isPrime(n)) return {n};\n\tu64 x = pollard(n);\n\
    \tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(), all(r));\n\treturn\
    \ l;\n}\n"
  code: "#pragma once\n#include \"Modint/Barrett_2.hpp\"\n#include \"NT/prime/prime_test.hpp\"\
    \nu64 pollard(u64 n) {\n  Barrett_u64 br;\n  br.set(n);\n\tu64 x = 0, y = 0, t\
    \ = 30, prd = 2, i = 1, q;\n\tauto f = [&](u64 x) { return mul_b64(&br,x, x) +\
    \ i; };\n\twhile (t++ % 40 || __gcd(prd, n) == 1) {\n\t\tif (x == y) x = ++i,\
    \ y = f(x);\n\t\tif ((q = mul_b64(&br,prd, max(x,y) - min(x,y)))) prd = q;\n\t\
    \tx = f(x), y = f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\nvector<u64> factor(u64\
    \ n) {\n\tif (n == 1) return {};\n\tif (isPrime(n)) return {n};\n\tu64 x = pollard(n);\n\
    \tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(), all(r));\n\treturn\
    \ l;\n}\n"
  dependsOn:
  - Modint/Barrett_2.hpp
  - Mod/mod_inv.hpp
  - NT/prime/prime_test.hpp
  - Mod/mod_mul.hpp
  isVerificationFile: false
  path: NT/prime/factorize.hpp
  requiredBy:
  - Mod/Primitive_root.hpp
  timestamp: '2024-06-03 16:24:06+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/factorize_yosupo.test.cpp
documentation_of: NT/prime/factorize.hpp
layout: document
redirect_from:
- /library/NT/prime/factorize.hpp
- /library/NT/prime/factorize.hpp.html
title: NT/prime/factorize.hpp
---
