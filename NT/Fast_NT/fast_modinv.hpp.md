---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Sample/fast_modinv.test.cpp
    title: test/yosupo/Sample/fast_modinv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"NT/Fast_NT/fast_modinv.hpp\"\n#include <cassert>\n \nstruct\
    \ fast_modinv {\n  using u32 = unsigned int;\n  using u64 = unsigned long long;\n\
    \ \n  u32 mod;\n  u32 ipow2[64], pre[2048 / 2];\n \n  fast_modinv(u32 m) : mod(m),\
    \ ipow2(), pre() {\n    assert(mod % 2 == 1 && mod < (1LL << 30));\n \n    //\
    \ Precompute ipow2\n    ipow2[0] = 1 % mod;\n    for (int i = 1; i < 64; i++)\
    \ {\n      ipow2[i] = u64(ipow2[i - 1]) * ((mod + 1) / 2) % mod;\n    }\n \n \
    \   // Precompute pre for odd numbers\n    pre[0] = 1 % mod;\n    for (int i =\
    \ 3; i < 2048; i += 2) {\n      pre[i >> 1] = [this, i]() -> int {\n        int\
    \ x = i, y = mod, u = 1, v = 0, t = 0, tmp = 0;\n        while (y > 0) {\n   \
    \       t = x / y;\n          x -= t * y, u -= t * v;\n          tmp = x, x =\
    \ y, y = tmp;\n          tmp = u, u = v, v = tmp;\n        }\n        return u\
    \ < 0 ? u + mod : u;\n      }();\n    }\n  }\n \n  bool is_prime(u32 n) const\
    \ {\n    if (n == 1) return false;\n    for (int p = 3; p * p <= n; p += 2) {\n\
    \      if (n % p == 0) return false;\n    }\n    return true;\n  }\n \n  u32 inv(u32\
    \ a) const {\n    if (mod == 1) {\n      return 0;\n    }\n \n    u32 b = mod,\
    \ s = 1, t = 0;\n    int n = __builtin_ctz(a);\n    a >>= n;\n \n    while (a\
    \ - b != 0) {\n      if (is_prime(mod)) {\n        if (a < 2048) break;\n    \
    \  }\n      int m = __builtin_ctz(a - b);\n      bool f = a > b;\n      n += m;\n\
    \      a = f ? (a - b) >> m : a;\n      b = f ? b : -(a - b) >> m;\n      u32\
    \ u = f ? s - t : s << m;\n      t = f ? t << m : -(s - t);\n      s = u;\n  \
    \  }\n    return u64(s) * pre[a >> 1] % mod * ipow2[n] % mod;\n  }\n \n  u32 operator()(u32\
    \ a) const { return inv(a); }\n};\n"
  code: "#pragma once\n#include <cassert>\n \nstruct fast_modinv {\n  using u32 =\
    \ unsigned int;\n  using u64 = unsigned long long;\n \n  u32 mod;\n  u32 ipow2[64],\
    \ pre[2048 / 2];\n \n  fast_modinv(u32 m) : mod(m), ipow2(), pre() {\n    assert(mod\
    \ % 2 == 1 && mod < (1LL << 30));\n \n    // Precompute ipow2\n    ipow2[0] =\
    \ 1 % mod;\n    for (int i = 1; i < 64; i++) {\n      ipow2[i] = u64(ipow2[i -\
    \ 1]) * ((mod + 1) / 2) % mod;\n    }\n \n    // Precompute pre for odd numbers\n\
    \    pre[0] = 1 % mod;\n    for (int i = 3; i < 2048; i += 2) {\n      pre[i >>\
    \ 1] = [this, i]() -> int {\n        int x = i, y = mod, u = 1, v = 0, t = 0,\
    \ tmp = 0;\n        while (y > 0) {\n          t = x / y;\n          x -= t *\
    \ y, u -= t * v;\n          tmp = x, x = y, y = tmp;\n          tmp = u, u = v,\
    \ v = tmp;\n        }\n        return u < 0 ? u + mod : u;\n      }();\n    }\n\
    \  }\n \n  bool is_prime(u32 n) const {\n    if (n == 1) return false;\n    for\
    \ (int p = 3; p * p <= n; p += 2) {\n      if (n % p == 0) return false;\n   \
    \ }\n    return true;\n  }\n \n  u32 inv(u32 a) const {\n    if (mod == 1) {\n\
    \      return 0;\n    }\n \n    u32 b = mod, s = 1, t = 0;\n    int n = __builtin_ctz(a);\n\
    \    a >>= n;\n \n    while (a - b != 0) {\n      if (is_prime(mod)) {\n     \
    \   if (a < 2048) break;\n      }\n      int m = __builtin_ctz(a - b);\n     \
    \ bool f = a > b;\n      n += m;\n      a = f ? (a - b) >> m : a;\n      b = f\
    \ ? b : -(a - b) >> m;\n      u32 u = f ? s - t : s << m;\n      t = f ? t <<\
    \ m : -(s - t);\n      s = u;\n    }\n    return u64(s) * pre[a >> 1] % mod *\
    \ ipow2[n] % mod;\n  }\n \n  u32 operator()(u32 a) const { return inv(a); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/Fast_NT/fast_modinv.hpp
  requiredBy: []
  timestamp: '2024-06-05 18:52:37+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Sample/fast_modinv.test.cpp
documentation_of: NT/Fast_NT/fast_modinv.hpp
layout: document
title: fast mod_inv
---

## Description:
-Optimized version of normal modulo inverse, notice the modulus is odd and less than 2^30<br>
-AC in problem normal modulo inverse: a⋅x≡1(mod m)<br>
-Not all cases faster than normal mod_inv but still good for big number than normal mod_inv
## Usage:

* fast_modinv inve(mod);
* inve.inv(a)

