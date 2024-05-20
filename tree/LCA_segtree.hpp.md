---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/LCA_yosupo.test.cpp
    title: test/yosupo/LCA_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cp-algorithms.com/graph/lca.html
  bundledCode: "#line 2 \"tree/LCA_segtree.hpp\"\n/*\n  LCA -O(logN) query and O(n)\
    \ preprocessing\n  @see https://cp-algorithms.com/graph/lca.html\n*/\nstruct LCA\
    \ {\n    vector<int> height, euler, first, segtree;\n    vector<bool> visited;\n\
    \    int n;\n\n    LCA(vector<vector<int>> &adj, int root = 0) {\n        n =\
    \ adj.size();\n        height.resize(n);\n        first.resize(n);\n        euler.reserve(n\
    \ * 2);\n        visited.assign(n, false);\n        dfs(adj, root);\n        int\
    \ m = euler.size();\n        segtree.resize(m * 4);\n        build(1, 0, m - 1);\n\
    \    }\n\n    void dfs(vector<vector<int>> &adj, int node, int h = 0) {\n    \
    \    visited[node] = true;\n        height[node] = h;\n        first[node] = euler.size();\n\
    \        euler.push_back(node);\n        for (auto to : adj[node]) {\n       \
    \     if (!visited[to]) {\n                dfs(adj, to, h + 1);\n            \
    \    euler.push_back(node);\n            }\n        }\n    }\n\n    void build(int\
    \ node, int b, int e) {\n        if (b == e) {\n            segtree[node] = euler[b];\n\
    \        } else {\n            int mid = (b + e) / 2;\n            build(node\
    \ << 1, b, mid);\n            build(node << 1 | 1, mid + 1, e);\n            int\
    \ l = segtree[node << 1], r = segtree[node << 1 | 1];\n            segtree[node]\
    \ = (height[l] < height[r]) ? l : r;\n        }\n    }\n\n    int query(int node,\
    \ int b, int e, int L, int R) {\n        if (b > R || e < L)\n            return\
    \ -1;\n        if (b >= L && e <= R)\n            return segtree[node];\n    \
    \    int mid = (b + e) >> 1;\n\n        int left = query(node << 1, b, mid, L,\
    \ R);\n        int right = query(node << 1 | 1, mid + 1, e, L, R);\n        if\
    \ (left == -1) return right;\n        if (right == -1) return left;\n        return\
    \ height[left] < height[right] ? left : right;\n    }\n\n    int lca(int u, int\
    \ v) {\n        int left = first[u], right = first[v];\n        if (left > right)\n\
    \            swap(left, right);\n        return query(1, 0, euler.size() - 1,\
    \ left, right);\n    }\n};\n"
  code: "#pragma once\n/*\n  LCA -O(logN) query and O(n) preprocessing\n  @see https://cp-algorithms.com/graph/lca.html\n\
    */\nstruct LCA {\n    vector<int> height, euler, first, segtree;\n    vector<bool>\
    \ visited;\n    int n;\n\n    LCA(vector<vector<int>> &adj, int root = 0) {\n\
    \        n = adj.size();\n        height.resize(n);\n        first.resize(n);\n\
    \        euler.reserve(n * 2);\n        visited.assign(n, false);\n        dfs(adj,\
    \ root);\n        int m = euler.size();\n        segtree.resize(m * 4);\n    \
    \    build(1, 0, m - 1);\n    }\n\n    void dfs(vector<vector<int>> &adj, int\
    \ node, int h = 0) {\n        visited[node] = true;\n        height[node] = h;\n\
    \        first[node] = euler.size();\n        euler.push_back(node);\n       \
    \ for (auto to : adj[node]) {\n            if (!visited[to]) {\n             \
    \   dfs(adj, to, h + 1);\n                euler.push_back(node);\n           \
    \ }\n        }\n    }\n\n    void build(int node, int b, int e) {\n        if\
    \ (b == e) {\n            segtree[node] = euler[b];\n        } else {\n      \
    \      int mid = (b + e) / 2;\n            build(node << 1, b, mid);\n       \
    \     build(node << 1 | 1, mid + 1, e);\n            int l = segtree[node << 1],\
    \ r = segtree[node << 1 | 1];\n            segtree[node] = (height[l] < height[r])\
    \ ? l : r;\n        }\n    }\n\n    int query(int node, int b, int e, int L, int\
    \ R) {\n        if (b > R || e < L)\n            return -1;\n        if (b >=\
    \ L && e <= R)\n            return segtree[node];\n        int mid = (b + e) >>\
    \ 1;\n\n        int left = query(node << 1, b, mid, L, R);\n        int right\
    \ = query(node << 1 | 1, mid + 1, e, L, R);\n        if (left == -1) return right;\n\
    \        if (right == -1) return left;\n        return height[left] < height[right]\
    \ ? left : right;\n    }\n\n    int lca(int u, int v) {\n        int left = first[u],\
    \ right = first[v];\n        if (left > right)\n            swap(left, right);\n\
    \        return query(1, 0, euler.size() - 1, left, right);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/LCA_segtree.hpp
  requiredBy: []
  timestamp: '2024-05-20 13:04:46+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/LCA_yosupo.test.cpp
documentation_of: tree/LCA_segtree.hpp
layout: document
redirect_from:
- /library/tree/LCA_segtree.hpp
- /library/tree/LCA_segtree.hpp.html
title: tree/LCA_segtree.hpp
---
