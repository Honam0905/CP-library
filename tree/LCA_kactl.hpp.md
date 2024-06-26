---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DS/Sparse_table.hpp
    title: Sparse table(KACTL version)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Tree/LCA_yosupo_2.test.cpp
    title: test/yosupo/Tree/LCA_yosupo_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DS/Sparse_table.hpp\"\n\ntemplate<class T>\nstruct sparsetable\
    \ {\n\tvector<vector<T>> jmp;\n\tsparsetable(const vector<T>& V) : jmp(1, V) {\n\
    \t\tfor (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {\n\t\t\tjmp.emplace_back(V.size()\
    \ - pw * 2 + 1);\n\t\t\trep(j,jmp[k].size())\n\t\t\t\tjmp[k][j] = min(jmp[k -\
    \ 1][j], jmp[k - 1][j + pw]);\n\t\t}\n\t}\n\tT query(int a, int b) {\n\t\tassert(a\
    \ < b); // or return inf if a == b\n\t\tint dep = 31 - __builtin_clz(b - a);\n\
    \t\treturn min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\t}\n};\n#line 3 \"tree/LCA_kactl.hpp\"\
    \nstruct LCA {\n    int T = 0;\n    vi time, path, ret, depth;\n    sparsetable<int>\
    \ rmq;\n\n    LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C, 0, -1,\
    \ 0), ret)) {}\n\n    void dfs(vector<vi>& C, int v, int par, int d) {\n     \
    \   time[v] = T++;\n        depth[v] = d;\n        for (int y : C[v]) if (y !=\
    \ par) {\n            path.push_back(v), ret.push_back(time[v]);\n           \
    \ dfs(C, y, v, d + 1);\n            path.push_back(v), ret.push_back(time[v]);\n\
    \        }\n    }\n\n    int lca(int a, int b) {\n        if (a == b) return a;\n\
    \        tie(a, b) = minmax(time[a], time[b]);\n        return path[rmq.query(a,\
    \ b)];\n    }\n\n    int dist(int a, int b) { return depth[a] + depth[b] - 2 *\
    \ depth[lca(a, b)]; }\n};\n"
  code: "#pragma once\n#include \"DS/Sparse_table.hpp\"\nstruct LCA {\n    int T =\
    \ 0;\n    vi time, path, ret, depth;\n    sparsetable<int> rmq;\n\n    LCA(vector<vi>&\
    \ C) : time(sz(C)), depth(sz(C)), rmq((dfs(C, 0, -1, 0), ret)) {}\n\n    void\
    \ dfs(vector<vi>& C, int v, int par, int d) {\n        time[v] = T++;\n      \
    \  depth[v] = d;\n        for (int y : C[v]) if (y != par) {\n            path.push_back(v),\
    \ ret.push_back(time[v]);\n            dfs(C, y, v, d + 1);\n            path.push_back(v),\
    \ ret.push_back(time[v]);\n        }\n    }\n\n    int lca(int a, int b) {\n \
    \       if (a == b) return a;\n        tie(a, b) = minmax(time[a], time[b]);\n\
    \        return path[rmq.query(a, b)];\n    }\n\n    int dist(int a, int b) {\
    \ return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }\n};\n"
  dependsOn:
  - DS/Sparse_table.hpp
  isVerificationFile: false
  path: tree/LCA_kactl.hpp
  requiredBy: []
  timestamp: '2024-06-26 10:37:02+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Tree/LCA_yosupo_2.test.cpp
documentation_of: tree/LCA_kactl.hpp
layout: document
redirect_from:
- /library/tree/LCA_kactl.hpp
- /library/tree/LCA_kactl.hpp.html
title: tree/LCA_kactl.hpp
---
