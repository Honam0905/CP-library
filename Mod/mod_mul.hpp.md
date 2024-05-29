---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mod/mod_mul.hpp\"\nll modmul(ll a, ll b,ll mod) {\n    ll\
    \ ans = 0;\n    while (b) {\n        if (b & 1)\n            (ans += a) %= mod;\n\
    \        (a *= 2) %= mod;\n        b /= 2;\n    }\n    return ans;\n}\n \nll modpow(ll\
    \ a, ll n,ll mod) {\n    ll ans = 1;\n    for (; n; n /= 2, a = modmul(a, a, mod))\n\
    \        if (n & 1)\n            ans = modmul(ans, a, mod);\n    return ans;\n\
    }\n//or\n//only good for long long or int64_t\nlong long modmul2(long long a,long\
    \ long b,long long mod){\n   return (a*b)%mod;\n}\n"
  code: "#pragma once\nll modmul(ll a, ll b,ll mod) {\n    ll ans = 0;\n    while\
    \ (b) {\n        if (b & 1)\n            (ans += a) %= mod;\n        (a *= 2)\
    \ %= mod;\n        b /= 2;\n    }\n    return ans;\n}\n \nll modpow(ll a, ll n,ll\
    \ mod) {\n    ll ans = 1;\n    for (; n; n /= 2, a = modmul(a, a, mod))\n    \
    \    if (n & 1)\n            ans = modmul(ans, a, mod);\n    return ans;\n}\n\
    //or\n//only good for long long or int64_t\nlong long modmul2(long long a,long\
    \ long b,long long mod){\n   return (a*b)%mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mod/mod_mul.hpp
  requiredBy: []
  timestamp: '2024-05-29 10:28:49+07:00'
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

