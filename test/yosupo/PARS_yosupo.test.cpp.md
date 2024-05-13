---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DS/fenwick_tree.hpp
    title: DS/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: Misc/debug.hpp
    title: Misc/debug.hpp
  - icon: ':heavy_check_mark:'
    path: Misc/marco.hpp
    title: Misc/marco.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/PARS_yosupo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 2 \"Misc/marco.hpp\"\n// Judges with GCC >= 12 only needs Ofast\n// #pragma\
    \ GCC optimize(\"O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize\"\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/PARS_yosupo.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"DS/fenwick_tree.hpp\"\n\nstruct Fenwick{\n\
    \tvector<ll> s;\n    int n;\n\tFenwick(int n) : n(n),s(n+1,0) {}\n\tvoid update(int\
    \ pos, ll dif) { //a[pos]=a[pos]+dif\n        for (; pos <= n; pos += pos & -pos)\
    \ s[pos] += dif;\n    }\n    ll query(int pos) { //sum [1,pos]\n        ll res\
    \ = 0;\n        for (; pos > 0; pos -= pos & -pos) res += s[pos];\n        return\
    \ res;\n    }\n    ll prefix(int l,int r){ //sum [l+1,r]\n         if(l==r) return\
    \ 0;\n         return query(r)-query(l);\n    }\n\tint lower_bound(ll sum) {//\
    \ min pos st sum of [0, pos] >= sum\n\t\t// Returns n if no sum is >= sum, or\
    \ -1 if empty sum is.\n\t\tif (sum <= 0) return -1;\n\t\tint pos = 0;\n\t\tfor\
    \ (int pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw <= s.size() && s[pos\
    \ + pw-1] < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\t\t}\n\t\treturn pos;\n\
    \t}\n};\n#line 8 \"test/yosupo/PARS_yosupo.test.cpp\"\nint main() {\n    int n,q;\
    \ cin>>n>>q;\n    vector<ll> a(n);\n    rep(i,n) cin>>a[i];\n    Fenwick ft(n);\n\
    \    rep(i,n) ft.update(i+1,a[i]);\n    while (q--) {\n        int op; cin>>op;\n\
    \        if (op == 0) {\n            int p, x; cin>>p>>x;\n            ft.update(p\
    \ + 1, x);\n        } else {\n            int l, r; cin>>l>>r;\n            cout<<ft.prefix(l,r)<<'\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\n\
    const ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"DS/fenwick_tree.hpp\"\nint main() {\n    int n,q; cin>>n>>q;\n    vector<ll>\
    \ a(n);\n    rep(i,n) cin>>a[i];\n    Fenwick ft(n);\n    rep(i,n) ft.update(i+1,a[i]);\n\
    \    while (q--) {\n        int op; cin>>op;\n        if (op == 0) {\n       \
    \     int p, x; cin>>p>>x;\n            ft.update(p + 1, x);\n        } else {\n\
    \            int l, r; cin>>l>>r;\n            cout<<ft.prefix(l,r)<<'\\n';\n\
    \        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - DS/fenwick_tree.hpp
  isVerificationFile: true
  path: test/yosupo/PARS_yosupo.test.cpp
  requiredBy: []
  timestamp: '2024-05-13 19:11:44+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/PARS_yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/PARS_yosupo.test.cpp
- /verify/test/yosupo/PARS_yosupo.test.cpp.html
title: test/yosupo/PARS_yosupo.test.cpp
---
