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
  bundledCode: "#line 2 \"Segment_tree.hpp\"\ntemplate <class T> class SegTree {\n\
    private:\nconst T DEFAULT = 1; //change depend on the problem\n    int n;  //\
    \ array size\n    vector<T> t;\npublic:\n    SegTree(int size) {\n        n =\
    \ size;\n        t.resize(4 * n);\n    }\n\n    void build() {  // build the tree\n\
    \        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];\n    }\n\n\
    \    void modify(int p, T value) {  // set value at position p\n        for (t[p\
    \ += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];\n    }\n\n    T query(int\
    \ l, int r) {  // sum on interval [l, r)\n        T res = 0;\n        for (l +=\
    \ n, r += n; l < r; l >>= 1, r >>= 1) {\n            if (l&1) res += t[l++];\n\
    \            if (r&1) res += t[--r];\n        }\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\ntemplate <class T> class SegTree {\nprivate:\nconst T DEFAULT\
    \ = 1; //change depend on the problem\n    int n;  // array size\n    vector<T>\
    \ t;\npublic:\n    SegTree(int size) {\n        n = size;\n        t.resize(4\
    \ * n);\n    }\n\n    void build() {  // build the tree\n        for (int i =\
    \ n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];\n    }\n\n    void modify(int\
    \ p, T value) {  // set value at position p\n        for (t[p += n] = value; p\
    \ > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];\n    }\n\n    T query(int l, int r) {\
    \  // sum on interval [l, r)\n        T res = 0;\n        for (l += n, r += n;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l&1) res += t[l++];\n          \
    \  if (r&1) res += t[--r];\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Segment_tree.hpp
  requiredBy: []
  timestamp: '2024-05-18 22:25:43+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Segment_tree.hpp
layout: document
redirect_from:
- /library/Segment_tree.hpp
- /library/Segment_tree.hpp.html
title: Segment_tree.hpp
---
