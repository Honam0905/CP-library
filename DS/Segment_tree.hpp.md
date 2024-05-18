---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aizu/seg_tree.test.cpp
    title: test/aizu/seg_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DS/Segment_tree.hpp\"\ntemplate <class T> class SegTree\
    \ {\nprivate:\n    int n;  // array size\n    vector<T> t;\n\n    T op(T a, T\
    \ b) { //operation \n        return a+b;  \n    }\n\n    T e() { // modify depend\
    \ on the problem\n        return 0;  \n    }\n\npublic:\n    SegTree(int size)\
    \ {\n        n = size;\n        t.resize(4 * n);\n        for (int i = 0; i <\
    \ 4 * n; i++) {\n            t[i] = e();\n        }\n    }\n\n    void build()\
    \ { //not necessary\n        for (int i = n - 1; i > 0; --i) t[i] = op(t[i <<\
    \ 1], t[i << 1 | 1]);\n    }\n\n    void add(int p, T value) {\n        for (t[p\
    \ += n] += value; p > 1; p >>= 1)  t[p >> 1] = op(t[p], t[p ^ 1]);\n    }\n\n\
    \    void modify(int p, T value) {\n        for (t[p += n] = value; p > 1; p >>=\
    \ 1)  t[p >> 1] = op(t[p], t[p ^ 1]);\n    }\n\n    T query(int l, int r) {\n\
    \        T res = e();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) res = op(res, t[l++]);\n            if (r & 1) res = op(res,\
    \ t[--r]);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\ntemplate <class T> class SegTree {\nprivate:\n    int n;  //\
    \ array size\n    vector<T> t;\n\n    T op(T a, T b) { //operation \n        return\
    \ a+b;  \n    }\n\n    T e() { // modify depend on the problem\n        return\
    \ 0;  \n    }\n\npublic:\n    SegTree(int size) {\n        n = size;\n       \
    \ t.resize(4 * n);\n        for (int i = 0; i < 4 * n; i++) {\n            t[i]\
    \ = e();\n        }\n    }\n\n    void build() { //not necessary\n        for\
    \ (int i = n - 1; i > 0; --i) t[i] = op(t[i << 1], t[i << 1 | 1]);\n    }\n\n\
    \    void add(int p, T value) {\n        for (t[p += n] += value; p > 1; p >>=\
    \ 1)  t[p >> 1] = op(t[p], t[p ^ 1]);\n    }\n\n    void modify(int p, T value)\
    \ {\n        for (t[p += n] = value; p > 1; p >>= 1)  t[p >> 1] = op(t[p], t[p\
    \ ^ 1]);\n    }\n\n    T query(int l, int r) {\n        T res = e();\n       \
    \ for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) res\
    \ = op(res, t[l++]);\n            if (r & 1) res = op(res, t[--r]);\n        }\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DS/Segment_tree.hpp
  requiredBy: []
  timestamp: '2024-05-18 22:58:06+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aizu/seg_tree.test.cpp
documentation_of: DS/Segment_tree.hpp
layout: document
redirect_from:
- /library/DS/Segment_tree.hpp
- /library/DS/Segment_tree.hpp.html
title: DS/Segment_tree.hpp
---
