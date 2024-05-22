---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/debug.hpp
    title: Misc/debug.hpp
  - icon: ':heavy_check_mark:'
    path: Misc/marco.hpp
    title: Misc/marco.hpp
  - icon: ':heavy_check_mark:'
    path: tree/LCA_segtree.hpp
    title: tree/LCA_segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/Tree/LCA_yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"Misc/marco.hpp\"\n// Judges\
    \ with GCC >= 12 only needs Ofast\n// #pragma GCC optimize(\"O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize\"\
    )\n// MLE optimization\n// #pragma GCC optimize(\"conserve-stack\")\n// Old judges\n\
    // #pragma GCC target(\"sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2\")\n// New judges.\
    \ Test with assert(__builtin_cpu_supports(\"avx2\"));\n// #pragma GCC target(\"\
    avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native\")\n// Atcoder\n// #pragma GCC\
    \ target(\"avx2,popcnt,lzcnt,abm,bmi,bmi2,fma\")\n/*\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\ntypedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>\
    \ ods;\n- insert(x),erase(x)\n- find_by_order(k): return iterator to the k-th\
    \ smallest element\n- order_of_key(x): the number of elements that are strictly\
    \ smaller\n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\nusing ld = long\
    \ double;\nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n \n \n#define pii pair<int,int>\n#define pll pair<ll,ll>\n \n\
    #define all(x) (x).begin(),(x).end()\n#define rall(x) (x).rbegin(),(x).rend()\n\
    #define ars(x) (x),(x+n)\n \n#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)\n\
    \ \n#define For(i,a,b) for (int i=(a); i<(b); i++)\n#define rep(i,a) For(i,0,a)\n\
    #define rev(i,a,b) for (int i=(a); i>(b); i--)\n#define FOR(i,a,b) for (int i=(a);\
    \ i<=(b); i++)\n#define REP(i,a) FOR(i,1,a)\n#define REV(i,a,b) for (int i=(a);\
    \ i>=(b); i--)\n \n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define fi first\n#define se second\n#define FT ios_base::sync_with_stdio(false);\
    \ cin.tie(nullptr);\n \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nusing vi=vector<int>;\nusing vll = vector<ll>;\ntemplate <class T>\nusing vc\
    \ = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n \n//template <class T>\n//using ods =\n//   tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n \ntemplate\
    \ <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}\ntemplate <typename\
    \ T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}\n \ntemplate<class T> using pq\
    \ = priority_queue<T>;\ntemplate<class T> using pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n#line 1 \"Misc/debug.hpp\"\nvoid __print(int x) {cerr << x;}\n\
    void __print(long x) {cerr << x;}\nvoid __print(long long x) {cerr << x;}\nvoid\
    \ __print(unsigned x) {cerr << x;}\nvoid __print(unsigned long x) {cerr << x;}\n\
    void __print(unsigned long long x) {cerr << x;}\nvoid __print(float x) {cerr <<\
    \ x;}\nvoid __print(double x) {cerr << x;}\nvoid __print(long double x) {cerr\
    \ << x;}\nvoid __print(char x) {cerr << '\\'' << x << '\\'';}\nvoid __print(const\
    \ char *x) {cerr << '\\\"' << x << '\\\"';}\nvoid __print(const string &x) {cerr\
    \ << '\\\"' << x << '\\\"';}\nvoid __print(bool x) {cerr << (x ? \"true\" : \"\
    false\");}\n\ntemplate<typename T, typename V>\nvoid __print(const pair<T, V>\
    \ &x) {cerr << '{'; __print(x.first); cerr << \", \"; __print(x.second); cerr\
    \ << '}';}\ntemplate<typename T>\nvoid __print(const T &x) {int f = 0; cerr <<\
    \ '{'; for (auto &i: x) cerr << (f++ ? \", \" : \"\"), __print(i); cerr << \"\
    }\";}\ntemplate<>\nvoid __print(const vector<bool> &x) {int f = 0; cerr << '{';\
    \ for (size_t i = 0; i < x.size(); ++i) cerr << (f++ ? \", \" : \"\"), __print(x[i]);\
    \ cerr << \"}\";}\nvoid _print() {cerr << \"]\\n\";}\ntemplate <typename T, typename...\
    \ V>\nvoid _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << \", \";\
    \ _print(v...);}\n\nvoid dbg_out() { cerr << endl; }\ntemplate<typename Head,\
    \ typename... Tail> void dbg_out(Head H, Tail... T) { __print(H); if (sizeof...(T))\
    \ cerr << \", \"; dbg_out(T...); }\n#define dbg(...) cerr << \"[\" << #__VA_ARGS__\
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Tree/LCA_yosupo.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"tree/LCA_segtree.hpp\"\n/*\n  LCA -O(logN)\
    \ query and O(n) preprocessing\n  @see https://cp-algorithms.com/graph/lca.html\n\
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
    \        return query(1, 0, euler.size() - 1, left, right);\n    }\n};\n#line\
    \ 8 \"test/yosupo/Tree/LCA_yosupo.test.cpp\"\nint main() {\n int n,q,x; cin>>n>>q;\n\
    \ vvc<int>adj(n); \n For(i,1,n){\n    cin>>x;\n    adj[x].push_back(i);\n }\n\
    \ LCA lca(adj);\n for(;q--;){\n    int u,v; cin>>u>>v;\n    cout<<lca.lca(u,v)<<'\\\
    n';\n }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"Misc/marco.hpp\"\
    \n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author:\
    \ Nguyen Ho Nam,UIT, Saigon-----------------\n#include \"tree/LCA_segtree.hpp\"\
    \nint main() {\n int n,q,x; cin>>n>>q;\n vvc<int>adj(n); \n For(i,1,n){\n    cin>>x;\n\
    \    adj[x].push_back(i);\n }\n LCA lca(adj);\n for(;q--;){\n    int u,v; cin>>u>>v;\n\
    \    cout<<lca.lca(u,v)<<'\\n';\n }\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - tree/LCA_segtree.hpp
  isVerificationFile: true
  path: test/yosupo/Tree/LCA_yosupo.test.cpp
  requiredBy: []
  timestamp: '2024-05-20 13:19:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Tree/LCA_yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Tree/LCA_yosupo.test.cpp
- /verify/test/yosupo/Tree/LCA_yosupo.test.cpp.html
title: test/yosupo/Tree/LCA_yosupo.test.cpp
---
