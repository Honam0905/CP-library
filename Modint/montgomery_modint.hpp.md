---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aizu/pow_aizu.test.cpp
    title: test/aizu/pow_aizu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: montgomery modint(static modint)
    links: []
  bundledCode: "#line 2 \"Modint/montgomery_modint.hpp\"\n/*\n   @brief montgomery\
    \ modint(static modint)\n*/\ntemplate <uint32_t mod_, bool fast = false>\nstruct\
    \ mod_int {\n private:\n  using mint = mod_int;\n  using i32 = int32_t;\n  using\
    \ i64 = int64_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static\
    \ constexpr u32 get_r() {\n    u32 ret = mod_;\n    for (i32 i = 0; i < 4; i++)\
    \ ret *= 2 - mod_ * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \n  static constexpr u32 n2 = -u64(mod_) % mod_;\n\n  static_assert(r * mod_ ==\
    \ 1, \"invalid, r * mod != 1\");\n  static_assert(mod_ < (1 << 30), \"invalid,\
    \ mod >= 2 ^ 30\");\n  static_assert((mod_ & 1) == 1, \"invalid, mod % 2 == 0\"\
    );\n\n  u32 x;\n\n public:\n  mod_int() : x{} {}\n\n  mod_int(const i64 &a)\n\
    \      : x(reduce(u64(fast ? a : (a % mod() + mod())) * n2)) {}\n\n  static constexpr\
    \ u32 reduce(const u64 &b) {\n    return u32(b >> 32) + mod() - u32((u64(u32(b)\
    \ * r) * mod()) >> 32);\n  }\n\n  mint &operator+=(const mint &p) {\n    if (i32(x\
    \ += p.x - 2 * mod()) < 0) x += 2 * mod();\n    return *this;\n  }\n\n  mint &operator-=(const\
    \ mint &p) {\n    if (i32(x -= p.x) < 0) x += 2 * mod();\n    return *this;\n\
    \  }\n\n  mint &operator*=(const mint &p) {\n    x = reduce(u64(x) * p.x);\n \
    \   return *this;\n  }\n\n  mint &operator/=(const mint &p) {\n    *this *= p.inv();\n\
    \    return *this;\n  }\n\n  mint operator-() const { return mint() - *this; }\n\
    \n  mint operator+(const mint &p) const { return mint(*this) += p; }\n\n  mint\
    \ operator-(const mint &p) const { return mint(*this) -= p; }\n\n  mint operator*(const\
    \ mint &p) const { return mint(*this) *= p; }\n\n  mint operator/(const mint &p)\
    \ const { return mint(*this) /= p; }\n\n  bool operator==(const mint &p) const\
    \ {\n    return (x >= mod() ? x - mod() : x) == (p.x >= mod() ? p.x - mod() :\
    \ p.x);\n  }\n\n  bool operator!=(const mint &p) const {\n    return (x >= mod()\
    \ ? x - mod() : x) != (p.x >= mod() ? p.x - mod() : p.x);\n  }\n\n  u32 val()\
    \ const {\n    u32 ret = reduce(x);\n    return ret >= mod() ? ret - mod() : ret;\n\
    \  }\n\n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n\n  mint inv() const { return pow(mod() - 2); }\n\n\
    \  friend ostream &operator<<(ostream &os, const mint &p) {\n    return os <<\
    \ p.val();\n  }\n\n  friend istream &operator>>(istream &is, mint &a) {\n    i64\
    \ t;\n    is >> t;\n    a = mint(t);\n    return is;\n  }\n\n  static constexpr\
    \ u32 mod() { return mod_; }\n};\n\ntemplate <uint32_t mod>\nusing modint = mod_int<mod>;\n\
    using modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n"
  code: "#pragma once\n/*\n   @brief montgomery modint(static modint)\n*/\ntemplate\
    \ <uint32_t mod_, bool fast = false>\nstruct mod_int {\n private:\n  using mint\
    \ = mod_int;\n  using i32 = int32_t;\n  using i64 = int64_t;\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n    u32 ret = mod_;\n\
    \    for (i32 i = 0; i < 4; i++) ret *= 2 - mod_ * ret;\n    return ret;\n  }\n\
    \n  static constexpr u32 r = get_r();\n\n  static constexpr u32 n2 = -u64(mod_)\
    \ % mod_;\n\n  static_assert(r * mod_ == 1, \"invalid, r * mod != 1\");\n  static_assert(mod_\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod_ & 1) == 1,\
    \ \"invalid, mod % 2 == 0\");\n\n  u32 x;\n\n public:\n  mod_int() : x{} {}\n\n\
    \  mod_int(const i64 &a)\n      : x(reduce(u64(fast ? a : (a % mod() + mod()))\
    \ * n2)) {}\n\n  static constexpr u32 reduce(const u64 &b) {\n    return u32(b\
    \ >> 32) + mod() - u32((u64(u32(b) * r) * mod()) >> 32);\n  }\n\n  mint &operator+=(const\
    \ mint &p) {\n    if (i32(x += p.x - 2 * mod()) < 0) x += 2 * mod();\n    return\
    \ *this;\n  }\n\n  mint &operator-=(const mint &p) {\n    if (i32(x -= p.x) <\
    \ 0) x += 2 * mod();\n    return *this;\n  }\n\n  mint &operator*=(const mint\
    \ &p) {\n    x = reduce(u64(x) * p.x);\n    return *this;\n  }\n\n  mint &operator/=(const\
    \ mint &p) {\n    *this *= p.inv();\n    return *this;\n  }\n\n  mint operator-()\
    \ const { return mint() - *this; }\n\n  mint operator+(const mint &p) const {\
    \ return mint(*this) += p; }\n\n  mint operator-(const mint &p) const { return\
    \ mint(*this) -= p; }\n\n  mint operator*(const mint &p) const { return mint(*this)\
    \ *= p; }\n\n  mint operator/(const mint &p) const { return mint(*this) /= p;\
    \ }\n\n  bool operator==(const mint &p) const {\n    return (x >= mod() ? x -\
    \ mod() : x) == (p.x >= mod() ? p.x - mod() : p.x);\n  }\n\n  bool operator!=(const\
    \ mint &p) const {\n    return (x >= mod() ? x - mod() : x) != (p.x >= mod() ?\
    \ p.x - mod() : p.x);\n  }\n\n  u32 val() const {\n    u32 ret = reduce(x);\n\
    \    return ret >= mod() ? ret - mod() : ret;\n  }\n\n  mint pow(u64 n) const\
    \ {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n      if (n & 1) ret *=\
    \ mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  mint\
    \ inv() const { return pow(mod() - 2); }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &p) {\n    return os << p.val();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &a) {\n    i64 t;\n    is >> t;\n    a = mint(t);\n    return is;\n\
    \  }\n\n  static constexpr u32 mod() { return mod_; }\n};\n\ntemplate <uint32_t\
    \ mod>\nusing modint = mod_int<mod>;\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1000000007>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Modint/montgomery_modint.hpp
  requiredBy: []
  timestamp: '2024-05-22 19:41:34+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aizu/pow_aizu.test.cpp
documentation_of: Modint/montgomery_modint.hpp
layout: document
redirect_from:
- /library/Modint/montgomery_modint.hpp
- /library/Modint/montgomery_modint.hpp.html
title: montgomery modint(static modint)
---
