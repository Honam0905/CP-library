---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aizu/disjointset.test.cpp
    title: test/aizu/disjointset.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Ds/unionfind_yosupo.test.cpp
    title: test/yosupo/Ds/unionfind_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/MST_yosupo.test.cpp
    title: test/yosupo/Graph/MST_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DS/DSU.hpp\"\nstruct DSU {\n\tvector<int> e; void init(int\
    \ N) { e = vector<int>(N,-1); }\n\tint get(int x) { return e[x] < 0 ? x : e[x]\
    \ = get(e[x]); } \n\tbool same(int a, int b) { return get(a) == get(b); }\n\t\
    int size(int x) { return -e[get(x)]; }\n\tbool unite(int x, int y) { // union\
    \ by size\n\t\tx = get(x), y = get(y); if (x == y) return 0;\n\t\tif (e[x] > e[y])\
    \ swap(x,y);\n\t\te[x] += e[y]; e[y] = x; return 1;\n\t}\n};\n"
  code: "#pragma once\nstruct DSU {\n\tvector<int> e; void init(int N) { e = vector<int>(N,-1);\
    \ }\n\tint get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } \n\tbool same(int\
    \ a, int b) { return get(a) == get(b); }\n\tint size(int x) { return -e[get(x)];\
    \ }\n\tbool unite(int x, int y) { // union by size\n\t\tx = get(x), y = get(y);\
    \ if (x == y) return 0;\n\t\tif (e[x] > e[y]) swap(x,y);\n\t\te[x] += e[y]; e[y]\
    \ = x; return 1;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DS/DSU.hpp
  requiredBy: []
  timestamp: '2024-05-22 23:19:36+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Ds/unionfind_yosupo.test.cpp
  - test/yosupo/Graph/MST_yosupo.test.cpp
  - test/aizu/disjointset.test.cpp
documentation_of: DS/DSU.hpp
layout: document
title: DSU
---

## Description:
Disjoint Set Union with path compression 
and union by size. Add edges and test connectivity. 
Use for Kruskal's or Boruvka's minimum spanning tree.

## Usage:

* DSU d;
* d.init(size)

## Time:

* $O(\alpha(N))$
