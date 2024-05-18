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
  bundledCode: "#line 2 \"DS/Segment_tree.hpp\"\ntemplate <class T> class SegTree\
    \ {\nprivate:\n    int n;  // array size\n    vector<T> t;\n    T (*op)(T, T);\n\
    \    T (*e)();\n\npublic:\n    SegTree(int size, T (*op)(T, T), T (*e)()) {\n\
    \        n = size;\n        this->op = op;\n        this->e = e;\n        t.resize(4\
    \ * n);\n        for (int i = 0; i < 4 * n; i++) {\n            t[i] = this->e();\n\
    \        }\n    }\n\n    void build() {\n        for (int i = n - 1; i > 0; --i)\
    \ t[i] = op(t[i << 1], t[i << 1 | 1]);\n    }\n\n    void modify(int p, T value)\
    \ {\n        for (t[p += n] = value; p > 1; p >>= 1)  t[p >> 1] = op(t[p], t[p\
    \ ^ 1]);\n    }\n\n    void add(int p, T value) {\n        for (t[p += n] += value;\
    \ p > 1; p >>= 1)  t[p >> 1] = op(t[p], t[p ^ 1]);\n    }\n\n    T query(int l,\
    \ int r) {\n        T res = e();\n        for (l += n, r += n; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (l & 1) res = op(res, t[l++]);\n            if (r\
    \ & 1) res = op(res, t[--r]);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\ntemplate <class T> class SegTree {\nprivate:\n    int n;  //\
    \ array size\n    vector<T> t;\n    T (*op)(T, T);\n    T (*e)();\n\npublic:\n\
    \    SegTree(int size, T (*op)(T, T), T (*e)()) {\n        n = size;\n       \
    \ this->op = op;\n        this->e = e;\n        t.resize(4 * n);\n        for\
    \ (int i = 0; i < 4 * n; i++) {\n            t[i] = this->e();\n        }\n  \
    \  }\n\n    void build() {\n        for (int i = n - 1; i > 0; --i) t[i] = op(t[i\
    \ << 1], t[i << 1 | 1]);\n    }\n\n    void modify(int p, T value) {\n       \
    \ for (t[p += n] = value; p > 1; p >>= 1)  t[p >> 1] = op(t[p], t[p ^ 1]);\n \
    \   }\n\n    void add(int p, T value) {\n        for (t[p += n] += value; p >\
    \ 1; p >>= 1)  t[p >> 1] = op(t[p], t[p ^ 1]);\n    }\n\n    T query(int l, int\
    \ r) {\n        T res = e();\n        for (l += n, r += n; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) res = op(res, t[l++]);\n            if (r & 1)\
    \ res = op(res, t[--r]);\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DS/Segment_tree.hpp
  requiredBy: []
  timestamp: '2024-05-18 23:16:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DS/Segment_tree.hpp
layout: document
redirect_from:
- /library/DS/Segment_tree.hpp
- /library/DS/Segment_tree.hpp.html
title: DS/Segment_tree.hpp
---
