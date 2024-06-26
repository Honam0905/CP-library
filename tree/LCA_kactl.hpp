#pragma once
#include "DS/Sparse_table.hpp"
struct LCA {
    int T = 0;
    vi time, path, ret, depth;
    sparsetable<int> rmq;

    LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C, 0, -1, 0), ret)) {}

    void dfs(vector<vi>& C, int v, int par, int d) {
        time[v] = T++;
        depth[v] = d;
        for (int y : C[v]) if (y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v, d + 1);
            path.push_back(v), ret.push_back(time[v]);
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }

    int dist(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
};
