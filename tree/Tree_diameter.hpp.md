---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter_yosupo.test.cpp
    title: test/yosupo/tree_diameter_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/Tree_diameter.hpp\"\n/*\n   @brief:Tree-Diameter\n\
    \   author:Kiffaz\n*/\ntemplate<typename T> struct tree_diameter {\n    struct\
    \ Edge {\n        int to;\n        T weight;\n    };\n\n    int n;\n    std::vector<std::vector<Edge>>\
    \ adj;\n\n    tree_diameter(int size) : n(size), adj(size) {}\n\n    void add_edge(int\
    \ s, int t, T w, bool use_weight) {\n        if (use_weight) {\n            adj[s].push_back(Edge{t,\
    \ w});\n            adj[t].push_back(Edge{s, w});\n        } else {\n        \
    \    adj[s].push_back(Edge{t, 1}); \n            adj[t].push_back(Edge{s, 1});\n\
    \        }\n    }\n\n    std::pair<T, int> dfs(int v, int parent) {\n        T\
    \ max_dist = 0;\n        int farthest_node = v;\n        for (auto& edge : adj[v])\
    \ {\n            if (edge.to != parent) {\n                auto sub = dfs(edge.to,\
    \ v);\n                T dist = sub.first + edge.weight;\n                if (dist\
    \ > max_dist) {\n                    max_dist = dist;\n                    farthest_node\
    \ = sub.second;\n                }\n            }\n        }\n        return {max_dist,\
    \ farthest_node};\n    }\n\n    std::pair<T, std::vector<int>> get_diameter()\
    \ {\n        auto [_, first_farthest] = dfs(0, -1); \n        auto [max_dist,\
    \ second_farthest] = dfs(first_farthest, -1); \n\n        std::vector<int> path;\n\
    \        std::vector<bool> visited(n, false);\n        std::function<bool(int,\
    \ int)> find_path = [&](int current, int target) -> bool {\n            visited[current]\
    \ = true;\n            path.push_back(current);\n            if (current == target)\
    \ return true;\n            for (auto& edge : adj[current]) {\n              \
    \  if (!visited[edge.to] && find_path(edge.to, target)) {\n                  \
    \  return true;\n                }\n            }\n            path.pop_back();\n\
    \            return false;\n        };\n\n        find_path(second_farthest, first_farthest);\n\
    \n        return {max_dist, path};\n    }\n};\n"
  code: "/*\n   @brief:Tree-Diameter\n   author:Kiffaz\n*/\ntemplate<typename T> struct\
    \ tree_diameter {\n    struct Edge {\n        int to;\n        T weight;\n   \
    \ };\n\n    int n;\n    std::vector<std::vector<Edge>> adj;\n\n    tree_diameter(int\
    \ size) : n(size), adj(size) {}\n\n    void add_edge(int s, int t, T w, bool use_weight)\
    \ {\n        if (use_weight) {\n            adj[s].push_back(Edge{t, w});\n  \
    \          adj[t].push_back(Edge{s, w});\n        } else {\n            adj[s].push_back(Edge{t,\
    \ 1}); \n            adj[t].push_back(Edge{s, 1});\n        }\n    }\n\n    std::pair<T,\
    \ int> dfs(int v, int parent) {\n        T max_dist = 0;\n        int farthest_node\
    \ = v;\n        for (auto& edge : adj[v]) {\n            if (edge.to != parent)\
    \ {\n                auto sub = dfs(edge.to, v);\n                T dist = sub.first\
    \ + edge.weight;\n                if (dist > max_dist) {\n                   \
    \ max_dist = dist;\n                    farthest_node = sub.second;\n        \
    \        }\n            }\n        }\n        return {max_dist, farthest_node};\n\
    \    }\n\n    std::pair<T, std::vector<int>> get_diameter() {\n        auto [_,\
    \ first_farthest] = dfs(0, -1); \n        auto [max_dist, second_farthest] = dfs(first_farthest,\
    \ -1); \n\n        std::vector<int> path;\n        std::vector<bool> visited(n,\
    \ false);\n        std::function<bool(int, int)> find_path = [&](int current,\
    \ int target) -> bool {\n            visited[current] = true;\n            path.push_back(current);\n\
    \            if (current == target) return true;\n            for (auto& edge\
    \ : adj[current]) {\n                if (!visited[edge.to] && find_path(edge.to,\
    \ target)) {\n                    return true;\n                }\n          \
    \  }\n            path.pop_back();\n            return false;\n        };\n\n\
    \        find_path(second_farthest, first_farthest);\n\n        return {max_dist,\
    \ path};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/Tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-05-13 22:13:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/tree_diameter_yosupo.test.cpp
documentation_of: tree/Tree_diameter.hpp
layout: document
redirect_from:
- /library/tree/Tree_diameter.hpp
- /library/tree/Tree_diameter.hpp.html
title: tree/Tree_diameter.hpp
---
