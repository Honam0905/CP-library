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
  bundledCode: "#line 2 \"NT/Combinatorics/Comb_common.hpp\"\ntemplate<class T>\n\
    struct Comb {\n    int n;\n    vector<T> _fac;\n    vector<T> _invfac;\n    vector<T>\
    \ _inv;\n\n    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}\n    Comb(int n)\
    \ : Comb() { init(n); }\n\n    void init(int m) {\n        if (m <= n) return;\n\
    \        _fac.resize(m + 1);\n        _invfac.resize(m + 1);\n        _inv.resize(m\
    \ + 1);\n        for (int i = n + 1; i <= m; i++) {\n            _fac[i] = _fac[i\
    \ - 1] * i;\n        }\n        _invfac[m] = _fac[m].inv();\n        for (int\
    \ i = m; i > n; i--) {\n            _invfac[i - 1] = _invfac[i] * i;\n       \
    \     _inv[i] = _invfac[i] * _fac[i - 1];\n        }\n        n = m;\n    }\n\n\
    \    T fac(int m) {\n        if (m > n) init(m);\n        return _fac[m];\n  \
    \  }\n\n    T invfac(int m) {\n        if (m > n) init(m);\n        return _invfac[m];\n\
    \    }\n\n    T inv(int m) {\n        if (m > n) init(m);\n        return _inv[m];\n\
    \    }\n\n    T binom(int n, int m) {\n        if (n < m || m < 0) return 0;\n\
    \        return fac(n) * invfac(m) * invfac(n - m);\n    }\n};\n"
  code: "#pragma once\ntemplate<class T>\nstruct Comb {\n    int n;\n    vector<T>\
    \ _fac;\n    vector<T> _invfac;\n    vector<T> _inv;\n\n    Comb() : n{0}, _fac{1},\
    \ _invfac{1}, _inv{0} {}\n    Comb(int n) : Comb() { init(n); }\n\n    void init(int\
    \ m) {\n        if (m <= n) return;\n        _fac.resize(m + 1);\n        _invfac.resize(m\
    \ + 1);\n        _inv.resize(m + 1);\n        for (int i = n + 1; i <= m; i++)\
    \ {\n            _fac[i] = _fac[i - 1] * i;\n        }\n        _invfac[m] = _fac[m].inv();\n\
    \        for (int i = m; i > n; i--) {\n            _invfac[i - 1] = _invfac[i]\
    \ * i;\n            _inv[i] = _invfac[i] * _fac[i - 1];\n        }\n        n\
    \ = m;\n    }\n\n    T fac(int m) {\n        if (m > n) init(m);\n        return\
    \ _fac[m];\n    }\n\n    T invfac(int m) {\n        if (m > n) init(m);\n    \
    \    return _invfac[m];\n    }\n\n    T inv(int m) {\n        if (m > n) init(m);\n\
    \        return _inv[m];\n    }\n\n    T binom(int n, int m) {\n        if (n\
    \ < m || m < 0) return 0;\n        return fac(n) * invfac(m) * invfac(n - m);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: NT/Combinatorics/Comb_common.hpp
  requiredBy: []
  timestamp: '2024-05-25 08:47:49+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NT/Combinatorics/Comb_common.hpp
layout: document
redirect_from:
- /library/NT/Combinatorics/Comb_common.hpp
- /library/NT/Combinatorics/Comb_common.hpp.html
title: NT/Combinatorics/Comb_common.hpp
---
