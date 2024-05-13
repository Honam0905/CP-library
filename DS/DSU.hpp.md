---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind_yosupo.test.cpp
    title: test/yosupo/unionfind_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DS/DSU.hpp\"\n/**\n * Description: Disjoint Set Union with\
    \ path compression\n \t* and union by size. Add edges and test connectivity. \n\
    \ \t* Use for Kruskal's or Boruvka's minimum spanning tree.\n * Time: O(\\alpha(N))\n\
    \ * Source: CSAcademy, KACTL\n * Verification: *\n */\nstruct DSU {\n\tvector<int>\
    \ e; void init(int N) { e = vector<int>(N,-1); }\n\tint get(int x) { return e[x]\
    \ < 0 ? x : e[x] = get(e[x]); } \n\tbool same(int a, int b) { return get(a) ==\
    \ get(b); }\n\tint size(int x) { return -e[get(x)]; }\n\tbool unite(int x, int\
    \ y) { // union by size\n\t\tx = get(x), y = get(y); if (x == y) return 0;\n\t\
    \tif (e[x] > e[y]) swap(x,y);\n\t\te[x] += e[y]; e[y] = x; return 1;\n\t}\n};\n"
  code: "#pragma once\n/**\n * Description: Disjoint Set Union with path compression\n\
    \ \t* and union by size. Add edges and test connectivity. \n \t* Use for Kruskal's\
    \ or Boruvka's minimum spanning tree.\n * Time: O(\\alpha(N))\n * Source: CSAcademy,\
    \ KACTL\n * Verification: *\n */\nstruct DSU {\n\tvector<int> e; void init(int\
    \ N) { e = vector<int>(N,-1); }\n\tint get(int x) { return e[x] < 0 ? x : e[x]\
    \ = get(e[x]); } \n\tbool same(int a, int b) { return get(a) == get(b); }\n\t\
    int size(int x) { return -e[get(x)]; }\n\tbool unite(int x, int y) { // union\
    \ by size\n\t\tx = get(x), y = get(y); if (x == y) return 0;\n\t\tif (e[x] > e[y])\
    \ swap(x,y);\n\t\te[x] += e[y]; e[y] = x; return 1;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DS/DSU.hpp
  requiredBy: []
  timestamp: '2024-05-13 13:03:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind_yosupo.test.cpp
documentation_of: DS/DSU.hpp
layout: document
redirect_from:
- /library/DS/DSU.hpp
- /library/DS/DSU.hpp.html
title: DS/DSU.hpp
---
