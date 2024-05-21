---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DS/Sparse_table.hpp
    title: DS/Sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/LCA_yosupo_2.test.cpp
    title: test/yosupo/Tree/LCA_yosupo_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DS/Sparse_table.hpp\"\n/**\n * Author: Johan Sannemo, pajenegod\n\
    \ * Date: 2015-02-06\n * License: CC0\n * Source: Folklore\n * Description: Range\
    \ Minimum Queries on an array. Returns\n * min(V[a], V[a + 1], ... V[b - 1]) in\
    \ constant time.\n * Usage:\n *  RMQ rmq(values);\n *  rmq.query(inclusive, exclusive);\n\
    \ * Time: $O(|V| \\log |V| + Q)$\n * Status: stress-tested\n */\n\ntemplate<class\
    \ T>\nstruct sparsetable {\n\tvector<vector<T>> jmp;\n\tsparsetable(const vector<T>&\
    \ V) : jmp(1, V) {\n\t\tfor (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k)\
    \ {\n\t\t\tjmp.emplace_back(V.size() - pw * 2 + 1);\n\t\t\trep(j,jmp[k].size())\n\
    \t\t\t\tjmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);\n\t\t}\n\t}\n\tT query(int\
    \ a, int b) {\n\t\tassert(a < b); // or return inf if a == b\n\t\tint dep = 31\
    \ - __builtin_clz(b - a);\n\t\treturn min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\
    \t}\n};\n#line 3 \"tree/LCA_kactl.hpp\"\nstruct LCA {\n\tint T = 0;\n\tvi time,\
    \ path, ret;\n\tsparsetable<int> rmq;\n\n\tLCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1),\
    \ ret)) {}\n\tvoid dfs(vector<vi>& C, int v, int par) {\n\t\ttime[v] = T++;\n\t\
    \tfor (int y : C[v]) if (y != par) {\n\t\t\tpath.push_back(v), ret.push_back(time[v]);\n\
    \t\t\tdfs(C, y, v);\n\t\t}\n\t}\n\n\tint lca(int a, int b) {\n\t\tif (a == b)\
    \ return a;\n\t\ttie(a, b) = minmax(time[a], time[b]);\n\t\treturn path[rmq.query(a,\
    \ b)];\n\t}\n\t//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}\n\
    };\n"
  code: "#pragma once\n#include \"DS/Sparse_table.hpp\"\nstruct LCA {\n\tint T = 0;\n\
    \tvi time, path, ret;\n\tsparsetable<int> rmq;\n\n\tLCA(vector<vi>& C) : time(sz(C)),\
    \ rmq((dfs(C,0,-1), ret)) {}\n\tvoid dfs(vector<vi>& C, int v, int par) {\n\t\t\
    time[v] = T++;\n\t\tfor (int y : C[v]) if (y != par) {\n\t\t\tpath.push_back(v),\
    \ ret.push_back(time[v]);\n\t\t\tdfs(C, y, v);\n\t\t}\n\t}\n\n\tint lca(int a,\
    \ int b) {\n\t\tif (a == b) return a;\n\t\ttie(a, b) = minmax(time[a], time[b]);\n\
    \t\treturn path[rmq.query(a, b)];\n\t}\n\t//dist(a,b){return depth[a] + depth[b]\
    \ - 2*depth[lca(a,b)];}\n};\n"
  dependsOn:
  - DS/Sparse_table.hpp
  isVerificationFile: false
  path: tree/LCA_kactl.hpp
  requiredBy: []
  timestamp: '2024-05-21 21:24:29+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Tree/LCA_yosupo_2.test.cpp
documentation_of: tree/LCA_kactl.hpp
layout: document
redirect_from:
- /library/tree/LCA_kactl.hpp
- /library/tree/LCA_kactl.hpp.html
title: tree/LCA_kactl.hpp
---
