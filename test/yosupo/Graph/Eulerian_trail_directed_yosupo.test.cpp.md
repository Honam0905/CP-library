---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Eulerian_trail (directed).hpp
    title: Graph/Eulerian_trail (directed).hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_directed
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_directed
  bundledCode: "#line 1 \"test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\n\
    #line 2 \"Misc/marco.hpp\"\n// Judges with GCC >= 12 only needs Ofast\n// #pragma\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Graph/Eulerian_trail (directed).hpp\"\ntemplate<typename\
    \ T,bool directed>\nstruct eulerian_trail {\n    int n, m, E, ptr = 0;\n    vector<int>head,\
    \ link, to, eid, it_prev, it_cur;\n    vector<bool>used;\n    vector<T>path;\n\
    \    vector<int>edge_path;\n\n    eulerian_trail(int _n, int _m) : n(_n), m(_m)\
    \ {\n        E = directed ? m : 2*m;\n        head.assign(n, 0);\n        link.assign(E+1,\
    \ 0);\n        to.assign(E+1, 0);\n        eid.assign(E+1, 0);\n        used.assign(m,\
    \ false);\n        it_prev.assign(n, 0);\n        it_cur.assign(n, 0);\n    }\n\
    \n    void add_edge(int u, int v, int id) {\n        auto ins = [&](int U, int\
    \ V, int EID){\n            int idx = ++ptr;\n            to[idx] = V;\n     \
    \       eid[idx] = EID;\n            int old = head[U];\n            link[idx]\
    \ = 0 ^ old;\n            if(old) link[old] ^= 0 ^ idx;\n            head[U] =\
    \ idx;\n        };\n        if constexpr(directed) ins(u, v, id);\n        else\
    \ { ins(u, v, id); ins(v, u, id); }\n    }\n\n    bool is_eulerian() {\n     \
    \   if constexpr(directed) {\n            int start=0, end=0;\n            vector<int>in(n,0),\
    \ out(n,0);\n            for(int u=0; u<n; u++){\n                int prev=0,\
    \ cur=head[u];\n                while(cur){\n                    out[u]++; in[to[cur]]++;\n\
    \                    int nxt = prev ^ link[cur];\n                    prev = cur;\
    \ cur = nxt;\n                }\n            }\n            for(int i=0;i<n;i++){\n\
    \                int d = out[i] - in[i];\n                if(d==1) start++;\n\
    \                else if(d==-1) end++;\n                else if(d!=0) return false;\n\
    \            }\n            return (start==1&&end==1) || (start==0&&end==0);\n\
    \        } else {\n            int odd=0;\n            for(int u=0;u<n;u++){\n\
    \                int deg=0, prev=0, cur=head[u];\n                while(cur){\n\
    \                    deg++;\n                    int nxt = prev ^ link[cur];\n\
    \                    prev = cur; cur = nxt;\n                }\n             \
    \   if(deg%2) odd++;\n                if(odd>2) return false;\n            }\n\
    \            return odd==0 || odd==2;\n        }\n    }\n\n    T find_start()\
    \ {\n        if constexpr(directed) {\n            vector<int>in(n,0), out(n,0);\n\
    \            for(int u=0;u<n;u++){\n                int prev=0, cur=head[u];\n\
    \                while(cur){\n                    out[u]++; in[to[cur]]++;\n \
    \                   int nxt=prev^link[cur];\n                    prev=cur; cur=nxt;\n\
    \                }\n            }\n            for(int i=0;i<n;i++)\n        \
    \        if(out[i]-in[i]==1) return i;\n            for(int i=0;i<n;i++)\n   \
    \             if(out[i]>0) return i;\n            return 0;\n        } else {\n\
    \            for(int u=0;u<n;u++){\n                int deg=0, prev=0, cur=head[u];\n\
    \                while(cur){\n                    deg++;\n                   \
    \ int nxt=prev^link[cur];\n                    prev=cur; cur=nxt;\n          \
    \      }\n                if(deg%2==1) return u;\n            }\n            for(int\
    \ u=0;u<n;u++)\n                if(head[u]!=0) return u;\n            return 0;\n\
    \        }\n    }\n\n    bool get_trail(){\n        if(!is_eulerian()) return\
    \ false;\n        for(int u=0;u<n;u++){\n            it_prev[u]=0;\n         \
    \   it_cur[u]=head[u];\n        }\n        stack<pair<T,int>>st;\n        st.emplace(find_start(),\
    \ -1);\n        while(!st.empty()){\n            auto [u, in_eid]=st.top();\n\
    \            int &prev=it_prev[u];\n            int &cur=it_cur[u];\n        \
    \    while(cur){\n                int idx=cur;\n                int nxt=prev^link[idx];\n\
    \                prev=idx;\n                cur=nxt;\n                int e=eid[idx];\n\
    \                if(!used[e]){\n                    used[e]=true;\n          \
    \          st.emplace(to[idx], e);\n                    goto CONTINUE;\n     \
    \           }\n            }\n            path.push_back(u);\n            edge_path.push_back(in_eid);\n\
    \            st.pop();\n            CONTINUE: ;\n        }\n        if((int)path.size()!=m+1)\n\
    \            return false;\n        reverse(path.begin(),path.end());\n      \
    \  reverse(edge_path.begin(),edge_path.end());\n        return true;\n    }\n\
    };\n#line 8 \"test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp\"\nint\
    \ main(){\n  int t; cin>>t;\n  while(t--){\n    int n,m; cin>>n>>m;\n    eulerian_trail<int,true>et(n,m);\n\
    \    rep(i,m){\n        int u,v; cin>>u>>v;\n        et.add_edge(u,v,i);\n   \
    \ }\n     if(!et.get_trail()){\n        cout<<\"No\"<<'\\n';\n     }else{\n  \
    \      cout<<\"Yes\"<<'\\n';\n        rep(i,(int)et.path.size()){\n          \
    \  cout<<et.path[i]<<(i+1<(int)et.path.size()?' ':'\\n');\n        }\n       \
    \ if(m==0){\n            cout<<'\\n';\n        }else{\n            For(i,1,(int)et.edge_path.size()){\n\
    \                cout<<et.edge_path[i]<<(i+1<(int)et.edge_path.size()?' ':'\\\
    n');\n            }\n        }\n     }\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\
    \n#include \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\n\
    const ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"Graph/Eulerian_trail (directed).hpp\"\nint main(){\n  int t; cin>>t;\n\
    \  while(t--){\n    int n,m; cin>>n>>m;\n    eulerian_trail<int,true>et(n,m);\n\
    \    rep(i,m){\n        int u,v; cin>>u>>v;\n        et.add_edge(u,v,i);\n   \
    \ }\n     if(!et.get_trail()){\n        cout<<\"No\"<<'\\n';\n     }else{\n  \
    \      cout<<\"Yes\"<<'\\n';\n        rep(i,(int)et.path.size()){\n          \
    \  cout<<et.path[i]<<(i+1<(int)et.path.size()?' ':'\\n');\n        }\n       \
    \ if(m==0){\n            cout<<'\\n';\n        }else{\n            For(i,1,(int)et.edge_path.size()){\n\
    \                cout<<et.edge_path[i]<<(i+1<(int)et.edge_path.size()?' ':'\\\
    n');\n            }\n        }\n     }\n   }\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - Graph/Eulerian_trail (directed).hpp
  isVerificationFile: true
  path: test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp
  requiredBy: []
  timestamp: '2025-04-30 09:19:38+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp
- /verify/test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp.html
title: test/yosupo/Graph/Eulerian_trail_directed_yosupo.test.cpp
---
