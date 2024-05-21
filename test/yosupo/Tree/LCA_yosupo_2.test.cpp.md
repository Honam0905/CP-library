---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DS/Sparse_table.hpp
    title: DS/Sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: Misc/debug.hpp
    title: Misc/debug.hpp
  - icon: ':heavy_check_mark:'
    path: Misc/marco.hpp
    title: Misc/marco.hpp
  - icon: ':heavy_check_mark:'
    path: tree/LCA_kactl.hpp
    title: tree/LCA_kactl.hpp
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
  bundledCode: "#line 1 \"test/yosupo/Tree/LCA_yosupo_2.test.cpp\"\n#define PROBLEM\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Tree/LCA_yosupo_2.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#define sz(a) ((int) (a).size())\n#line 2 \"DS/Sparse_table.hpp\"\
    \n/**\n * Author: Johan Sannemo, pajenegod\n * Date: 2015-02-06\n * License: CC0\n\
    \ * Source: Folklore\n * Description: Range Minimum Queries on an array. Returns\n\
    \ * min(V[a], V[a + 1], ... V[b - 1]) in constant time.\n * Usage:\n *  RMQ rmq(values);\n\
    \ *  rmq.query(inclusive, exclusive);\n * Time: $O(|V| \\log |V| + Q)$\n * Status:\
    \ stress-tested\n */\n\ntemplate<class T>\nstruct sparsetable {\n\tvector<vector<T>>\
    \ jmp;\n\tsparsetable(const vector<T>& V) : jmp(1, V) {\n\t\tfor (int pw = 1,\
    \ k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {\n\t\t\tjmp.emplace_back(V.size()\
    \ - pw * 2 + 1);\n\t\t\trep(j,jmp[k].size())\n\t\t\t\tjmp[k][j] = min(jmp[k -\
    \ 1][j], jmp[k - 1][j + pw]);\n\t\t}\n\t}\n\tT query(int a, int b) {\n\t\tassert(a\
    \ < b); // or return inf if a == b\n\t\tint dep = 31 - __builtin_clz(b - a);\n\
    \t\treturn min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\t}\n};\n#line 2 \"tree/LCA_kactl.hpp\"\
    \nstruct LCA {\n\tint T = 0;\n\tvi time, path, ret;\n\tsparsetable<int> rmq;\n\
    \n\tLCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}\n\tvoid dfs(vector<vi>&\
    \ C, int v, int par) {\n\t\ttime[v] = T++;\n\t\tfor (int y : C[v]) if (y != par)\
    \ {\n\t\t\tpath.push_back(v), ret.push_back(time[v]);\n\t\t\tdfs(C, y, v);\n\t\
    \t}\n\t}\n\n\tint lca(int a, int b) {\n\t\tif (a == b) return a;\n\t\ttie(a, b)\
    \ = minmax(time[a], time[b]);\n\t\treturn path[rmq.query(a, b)];\n\t}\n\t//dist(a,b){return\
    \ depth[a] + depth[b] - 2*depth[lca(a,b)];}\n};\n#line 10 \"test/yosupo/Tree/LCA_yosupo_2.test.cpp\"\
    \n\nint main() {\n    int n,q,u,v,x; cin>>n>>q;\n    vvc<int>g(n);\n    For(i,1,n){\n\
    \        cin>>x;\n        g[i].push_back(x);\n        g[x].push_back(i);\n   \
    \ }\n    LCA lca(g);\n    while(q--){\n        cin>>u>>v;\n        cout<<lca.lca(u,v)<<'\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"Misc/marco.hpp\"\
    \n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author:\
    \ Nguyen Ho Nam,UIT, Saigon-----------------\n#define sz(a) ((int) (a).size())\n\
    #include \"DS/Sparse_table.hpp\"\n#include \"tree/LCA_kactl.hpp\"\n\nint main()\
    \ {\n    int n,q,u,v,x; cin>>n>>q;\n    vvc<int>g(n);\n    For(i,1,n){\n     \
    \   cin>>x;\n        g[i].push_back(x);\n        g[x].push_back(i);\n    }\n \
    \   LCA lca(g);\n    while(q--){\n        cin>>u>>v;\n        cout<<lca.lca(u,v)<<'\\\
    n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - DS/Sparse_table.hpp
  - tree/LCA_kactl.hpp
  isVerificationFile: true
  path: test/yosupo/Tree/LCA_yosupo_2.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 09:47:57+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Tree/LCA_yosupo_2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Tree/LCA_yosupo_2.test.cpp
- /verify/test/yosupo/Tree/LCA_yosupo_2.test.cpp.html
title: test/yosupo/Tree/LCA_yosupo_2.test.cpp
---
