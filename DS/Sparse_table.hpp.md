---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/LCA_kactl.hpp
    title: tree/LCA_kactl.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Ds/RMQ_yosupo.test.cpp
    title: test/yosupo/Ds/RMQ_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/LCA_yosupo_2.test.cpp
    title: test/yosupo/Tree/LCA_yosupo_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DS/Sparse_table.hpp\"\n\ntemplate<class T>\nstruct sparsetable\
    \ {\n\tvector<vector<T>> jmp;\n\tsparsetable(const vector<T>& V) : jmp(1, V) {\n\
    \t\tfor (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {\n\t\t\tjmp.emplace_back(V.size()\
    \ - pw * 2 + 1);\n\t\t\trep(j,jmp[k].size())\n\t\t\t\tjmp[k][j] = min(jmp[k -\
    \ 1][j], jmp[k - 1][j + pw]);\n\t\t}\n\t}\n\tT query(int a, int b) {\n\t\tassert(a\
    \ < b); // or return inf if a == b\n\t\tint dep = 31 - __builtin_clz(b - a);\n\
    \t\treturn min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T>\nstruct sparsetable {\n\tvector<vector<T>>\
    \ jmp;\n\tsparsetable(const vector<T>& V) : jmp(1, V) {\n\t\tfor (int pw = 1,\
    \ k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {\n\t\t\tjmp.emplace_back(V.size()\
    \ - pw * 2 + 1);\n\t\t\trep(j,jmp[k].size())\n\t\t\t\tjmp[k][j] = min(jmp[k -\
    \ 1][j], jmp[k - 1][j + pw]);\n\t\t}\n\t}\n\tT query(int a, int b) {\n\t\tassert(a\
    \ < b); // or return inf if a == b\n\t\tint dep = 31 - __builtin_clz(b - a);\n\
    \t\treturn min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DS/Sparse_table.hpp
  requiredBy:
  - tree/LCA_kactl.hpp
  timestamp: '2024-05-22 23:06:51+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Ds/RMQ_yosupo.test.cpp
  - test/yosupo/Tree/LCA_yosupo_2.test.cpp
documentation_of: DS/Sparse_table.hpp
layout: document
title: Sparse table(KACTL version)
---

## Description:
Range Minimum Queries on an array. Returns min(V[a], V[a + 1], ... V[b - 1]) in constant time.
Also work for max queries
## Usage:

*  RMQ rmq(values);
*  rmq.query(inclusive, exclusive);

## Time:
* $O(V\log(V)+Q)$
