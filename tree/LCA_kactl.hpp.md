---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"tree/LCA_kactl.hpp\"\nstruct LCA {\n\tint T = 0;\n\tvi time,\
    \ path, ret;\n\tsparsetable<int> rmq;\n\n\tLCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1),\
    \ ret)) {}\n\tvoid dfs(vector<vi>& C, int v, int par) {\n\t\ttime[v] = T++;\n\t\
    \tfor (int y : C[v]) if (y != par) {\n\t\t\tpath.push_back(v), ret.push_back(time[v]);\n\
    \t\t\tdfs(C, y, v);\n\t\t}\n\t}\n\n\tint lca(int a, int b) {\n\t\tif (a == b)\
    \ return a;\n\t\ttie(a, b) = minmax(time[a], time[b]);\n\t\treturn path[rmq.query(a,\
    \ b)];\n\t}\n\t//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}\n\
    };\n"
  code: "#pragma once\nstruct LCA {\n\tint T = 0;\n\tvi time, path, ret;\n\tsparsetable<int>\
    \ rmq;\n\n\tLCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}\n\tvoid\
    \ dfs(vector<vi>& C, int v, int par) {\n\t\ttime[v] = T++;\n\t\tfor (int y : C[v])\
    \ if (y != par) {\n\t\t\tpath.push_back(v), ret.push_back(time[v]);\n\t\t\tdfs(C,\
    \ y, v);\n\t\t}\n\t}\n\n\tint lca(int a, int b) {\n\t\tif (a == b) return a;\n\
    \t\ttie(a, b) = minmax(time[a], time[b]);\n\t\treturn path[rmq.query(a, b)];\n\
    \t}\n\t//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/LCA_kactl.hpp
  requiredBy: []
  timestamp: '2024-05-20 12:58:32+07:00'
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
