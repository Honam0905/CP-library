---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary gcd
    links: []
  bundledCode: "#line 2 \"NT/Fast_NT/binary_gcd.hpp\"\n/*\n  @brief Binary gcd\n*/\n\
    #include <algorithm>\nusing namespace std;\n\nnamespace BinaryGCDImpl {\nusing\
    \ u64 = unsigned long long;\nusing i8 = char;\n\nu64 binary_gcd(u64 a, u64 b)\
    \ {\n  if (a == 0 || b == 0) return a + b;\n  i8 n = __builtin_ctzll(a);\n  i8\
    \ m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while (a\
    \ != b) {\n    u64 d = a - b;\n    i8 s = __builtin_ctzll(d);\n    bool f = a\
    \ > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a << n;\n\
    }\n\nusing u128 = __uint128_t;\n// a > 0\nint ctz128(u128 a) {\n  u64 lo = a &\
    \ u64(-1);\n  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a >> 64);\n\
    }\nu128 binary_gcd128(u128 a, u128 b) {\n  if (a == 0 || b == 0) return a + b;\n\
    \  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n  a >>= n;\n  b >>= m;\n  n = min(n,\
    \ m);\n  while (a != b) {\n    u128 d = a - b;\n    i8 s = ctz128(d);\n    bool\
    \ f = a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a\
    \ << n;\n}\n\n}  // namespace BinaryGCDImpl\n\nlong long binary_gcd(long long\
    \ a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));\n}\n\
    __int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a < 0) a = -a;\n\
    \  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a, b);\n}\n"
  code: "#pragma once\n/*\n  @brief Binary gcd\n*/\n#include <algorithm>\nusing namespace\
    \ std;\n\nnamespace BinaryGCDImpl {\nusing u64 = unsigned long long;\nusing i8\
    \ = char;\n\nu64 binary_gcd(u64 a, u64 b) {\n  if (a == 0 || b == 0) return a\
    \ + b;\n  i8 n = __builtin_ctzll(a);\n  i8 m = __builtin_ctzll(b);\n  a >>= n;\n\
    \  b >>= m;\n  n = min(n, m);\n  while (a != b) {\n    u64 d = a - b;\n    i8\
    \ s = __builtin_ctzll(d);\n    bool f = a > b;\n    b = f ? b : a;\n    a = (f\
    \ ? d : -d) >> s;\n  }\n  return a << n;\n}\n\nusing u128 = __uint128_t;\n// a\
    \ > 0\nint ctz128(u128 a) {\n  u64 lo = a & u64(-1);\n  return lo ? __builtin_ctzll(lo)\
    \ : 64 + __builtin_ctzll(a >> 64);\n}\nu128 binary_gcd128(u128 a, u128 b) {\n\
    \  if (a == 0 || b == 0) return a + b;\n  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n\
    \  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while (a != b) {\n    u128 d = a\
    \ - b;\n    i8 s = ctz128(d);\n    bool f = a > b;\n    b = f ? b : a;\n    a\
    \ = (f ? d : -d) >> s;\n  }\n  return a << n;\n}\n\n}  // namespace BinaryGCDImpl\n\
    \nlong long binary_gcd(long long a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a),\
    \ abs(b));\n}\n__int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a\
    \ < 0) a = -a;\n  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a,\
    \ b);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/Fast_NT/binary_gcd.hpp
  requiredBy: []
  timestamp: '2024-06-03 16:48:58+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NT/Fast_NT/binary_gcd.hpp
layout: document
redirect_from:
- /library/NT/Fast_NT/binary_gcd.hpp
- /library/NT/Fast_NT/binary_gcd.hpp.html
title: Binary gcd
---
