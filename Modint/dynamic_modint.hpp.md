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
  bundledCode: "#line 2 \"Modint/dynamic_modint.hpp\"\ntemplate <int id>\nstruct dynamic_modint\
    \ {\n  int x;\n\n  dynamic_modint() : x(0) {}\n\n  dynamic_modint(int64_t y) {\n\
    \    int z = y % get_mod();\n    if (z < 0) z += get_mod();\n    x = z;\n  }\n\
    \n  dynamic_modint &operator+=(const dynamic_modint &p) {\n    if ((x += p.x)\
    \ >= get_mod()) x -= get_mod();\n    return *this;\n  }\n\n  dynamic_modint &operator-=(const\
    \ dynamic_modint &p) {\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n\
    \    return *this;\n  }\n\n  dynamic_modint &operator*=(const dynamic_modint &p)\
    \ {\n    x = rem((unsigned long long)x * p.x);\n    return *this;\n  }\n\n  dynamic_modint\
    \ &operator/=(const dynamic_modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n\n  dynamic_modint operator-() const { return dynamic_modint(-x);\
    \ }\n  dynamic_modint operator+() const { return *this; }\n\n  dynamic_modint\
    \ operator+(const dynamic_modint &p) const {\n    return dynamic_modint(*this)\
    \ += p;\n  }\n\n  dynamic_modint operator-(const dynamic_modint &p) const {\n\
    \    return dynamic_modint(*this) -= p;\n  }\n\n  dynamic_modint operator*(const\
    \ dynamic_modint &p) const {\n    return dynamic_modint(*this) *= p;\n  }\n\n\
    \  dynamic_modint operator/(const dynamic_modint &p) const {\n    return dynamic_modint(*this)\
    \ /= p;\n  }\n\n  bool operator==(const dynamic_modint &p) const { return x ==\
    \ p.x; }\n\n  bool operator!=(const dynamic_modint &p) const { return x != p.x;\
    \ }\n\n  dynamic_modint inv() const {\n    int a = x, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n\
    \      swap(u -= t * v, v);\n    }\n    return dynamic_modint(u);\n  }\n\n  dynamic_modint\
    \ pow(int64_t n) const {\n    dynamic_modint ret(1), mul(x);\n    while (n > 0)\
    \ {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const dynamic_modint\
    \ &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is,\
    \ dynamic_modint &a) {\n    int64_t t;\n    is >> t;\n    a = dynamic_modint(t);\n\
    \    return (is);\n  }\n\n  int get() const { return x; }\n\n  inline unsigned\
    \ int rem(unsigned long long p) { return barrett().rem(p); }\n\n  static inline\
    \ Barrett &barrett() {\n    static Barrett b;\n    return b;\n  }\n\n  static\
    \ inline int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\n \
    \ static void set_mod(int md) {\n    assert(0 < md && md <= (1LL << 30) - 1);\n\
    \    get_mod() = md;\n    barrett() = Barrett(md);\n  }\n};\n\nusing modint =\
    \ dynamic_modint<-1>;\n"
  code: "#pragma once\ntemplate <int id>\nstruct dynamic_modint {\n  int x;\n\n  dynamic_modint()\
    \ : x(0) {}\n\n  dynamic_modint(int64_t y) {\n    int z = y % get_mod();\n   \
    \ if (z < 0) z += get_mod();\n    x = z;\n  }\n\n  dynamic_modint &operator+=(const\
    \ dynamic_modint &p) {\n    if ((x += p.x) >= get_mod()) x -= get_mod();\n   \
    \ return *this;\n  }\n\n  dynamic_modint &operator-=(const dynamic_modint &p)\
    \ {\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n    return\
    \ *this;\n  }\n\n  dynamic_modint &operator*=(const dynamic_modint &p) {\n   \
    \ x = rem((unsigned long long)x * p.x);\n    return *this;\n  }\n\n  dynamic_modint\
    \ &operator/=(const dynamic_modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n\n  dynamic_modint operator-() const { return dynamic_modint(-x);\
    \ }\n  dynamic_modint operator+() const { return *this; }\n\n  dynamic_modint\
    \ operator+(const dynamic_modint &p) const {\n    return dynamic_modint(*this)\
    \ += p;\n  }\n\n  dynamic_modint operator-(const dynamic_modint &p) const {\n\
    \    return dynamic_modint(*this) -= p;\n  }\n\n  dynamic_modint operator*(const\
    \ dynamic_modint &p) const {\n    return dynamic_modint(*this) *= p;\n  }\n\n\
    \  dynamic_modint operator/(const dynamic_modint &p) const {\n    return dynamic_modint(*this)\
    \ /= p;\n  }\n\n  bool operator==(const dynamic_modint &p) const { return x ==\
    \ p.x; }\n\n  bool operator!=(const dynamic_modint &p) const { return x != p.x;\
    \ }\n\n  dynamic_modint inv() const {\n    int a = x, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n\
    \      swap(u -= t * v, v);\n    }\n    return dynamic_modint(u);\n  }\n\n  dynamic_modint\
    \ pow(int64_t n) const {\n    dynamic_modint ret(1), mul(x);\n    while (n > 0)\
    \ {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const dynamic_modint\
    \ &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is,\
    \ dynamic_modint &a) {\n    int64_t t;\n    is >> t;\n    a = dynamic_modint(t);\n\
    \    return (is);\n  }\n\n  int get() const { return x; }\n\n  inline unsigned\
    \ int rem(unsigned long long p) { return barrett().rem(p); }\n\n  static inline\
    \ Barrett &barrett() {\n    static Barrett b;\n    return b;\n  }\n\n  static\
    \ inline int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\n \
    \ static void set_mod(int md) {\n    assert(0 < md && md <= (1LL << 30) - 1);\n\
    \    get_mod() = md;\n    barrett() = Barrett(md);\n  }\n};\n\nusing modint =\
    \ dynamic_modint<-1>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Modint/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2024-05-21 20:52:09+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Modint/dynamic_modint.hpp
layout: document
redirect_from:
- /library/Modint/dynamic_modint.hpp
- /library/Modint/dynamic_modint.hpp.html
title: Modint/dynamic_modint.hpp
---
