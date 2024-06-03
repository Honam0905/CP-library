---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Misc/debug.hpp
    title: Misc/debug.hpp
  - icon: ':question:'
    path: Misc/marco.hpp
    title: Misc/marco.hpp
  - icon: ':x:'
    path: Mod/Primitive_root.hpp
    title: Mod/Primitive_root.hpp
  - icon: ':x:'
    path: Mod/mod_inv.hpp
    title: Mod/mod_inv.hpp
  - icon: ':x:'
    path: Modint/Barrett_2.hpp
    title: Modint/Barrett_2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primitive_root
    links:
    - https://judge.yosupo.jp/problem/primitive_root
  bundledCode: "#line 1 \"test/yosupo/Math/primitive_root_yosupo.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\n#line 2 \"Misc/marco.hpp\"\
    \n// Judges with GCC >= 12 only needs Ofast\n// #pragma GCC optimize(\"O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize\"\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Math/primitive_root_yosupo.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Mod/mod_inv.hpp\"\n\n#line 4 \"Mod/mod_inv.hpp\"\
    \n#include <type_traits>\nusing namespace std;\n\n// gcd(a, m) != 1 return -1\
    \ \ntemplate <typename T>\nT inv_mod(T a, T m) {\n  if (m == 1) return 0;\n  if\
    \ (a >= m) a %= m;\n  if (a < 0) a += m;\n  if(__gcd(a,m)!=1) return -1;\n  T\
    \ b = m, s = 1, t = 0;\n  while (true) {\n    if (a == 1) return s;\n    t -=\
    \ b / a * s;\n    b %= a;\n    if (b == 1) return t + m;\n    s -= a / b * t;\n\
    \    a %= b;\n  }\n}\n#line 3 \"Modint/Barrett_2.hpp\"\nstruct Barrett_u32 {\n\
    \    u64 m, m2, im;\n    u64 div, rem;\n\n    void set(u64 mod) {\n        m =\
    \ mod;\n        m2 = mod << 1;\n        im = ((((u128)(1ull) << 64)) + mod - 1)\
    \ / mod;\n        div = 0;\n        rem = 0;\n    }\n\n    void reduce(u64 a)\
    \ {\n        u64 x = (u64)(((u128)(a) * im) >> 64);\n        u64 y = x * m;\n\
    \        unsigned long long z;\n        u32 w = __builtin_usubll_overflow(a, y,\
    \ &z) ? m : 0;\n        div = x;\n        rem = z + w;\n    }\n\n    u32 add(u32\
    \ a, u32 b) {\n        a += b;\n        a -= (a >= (u32)m ? (u32)m : 0);\n   \
    \     return a;\n    }\n\n    u32 sub(u32 a, u32 b) {\n        a += (a < b ? (u32)m\
    \ : 0);\n        a -= b;\n        return a;\n    }\n\n    u32 min(u32 a) {\n \
    \       return sub(0, a);\n    }\n\n    u32 shl(u32 a) {\n        return (a <<=\
    \ 1) >= m ? a - m : a;\n    }\n\n    u32 shr(u32 a) {\n        return (a & 1)\
    \ ? ((a >> 1) + (m >> 1) + 1) : (a >> 1);\n    }\n};\n\nstruct Barrett_u64 {\n\
    \    u128 m, m2, im;\n    u128 div, rem;\n\n    void set(u128 mod) {\n       \
    \ m = mod;\n        m2 = mod << 1;\n        im = (~((u128)0ull)) / mod;\n    \
    \    div = 0;\n        rem = 0;\n    }\n\n    void reduce(u128 x) {\n        if\
    \ (m == 1) {\n            div = x;\n            rem = 0;\n            return;\n\
    \        }\n        uint8_t  f;\n        u128 a = x >> 64;\n        u128 b = x\
    \ & 0xffffffffffffffffull;\n        u128 c = im >> 64;\n        u128 d = im &\
    \ 0xffffffffffffffffull;\n        u128 ac = a * c;\n        u128 bd = (b * d)\
    \ >> 64;\n        u128 ad = a * d;\n        u128 bc = b * c;\n        f = (ad\
    \ > ((u128)((i128)(-1L)) - bd));\n        bd += ad;\n        ac += f;\n      \
    \  f = (bc > ((u128)((i128)(-1L)) - bd));\n        bd += bc;\n        ac += f;\n\
    \        u128 q = ac + (bd >> 64);\n        u128 r = x - q * m;\n        if (m\
    \ <= r) {\n            r -= m;\n            q += 1;\n        }\n        div =\
    \ q;\n        rem = r;\n    }\n\n    u64 add(u64 a, u64 b) {\n        a += b;\n\
    \        a -= (a >= (u64)m ? (u64)m : 0);\n        return a;\n    }\n\n    u64\
    \ sub(u64 a, u64 b) {\n        a += (a < b ? (u64)m : 0);\n        a -= b;\n \
    \       return a;\n    }\n\n    u64 min(u64 a) {\n        return sub(0, a);\n\
    \    }\n\n    u64 shl(u64 a) {\n        return (a <<= 1) >= m ? a - m : a;\n \
    \   }\n\n    u64 shr(u64 a) {\n        return (a & 1) ? ((a >> 1) + (m >> 1) +\
    \ 1) : (a >> 1);\n    }\n};\n// Barrett reduction - 32-bit\nu32 mul_b32(struct\
    \ Barrett_u32 *b, u32 a, u32 x) {\n    b->reduce((u64)a * x);\n    return (u32)b->rem;\n\
    }\n\nu32 div_b32(struct Barrett_u32 *b, u32 a, u32 x) {\n    b->reduce((u64)a\
    \ << 32);\n    return (u32)(b->div * inv_mod(x,(u32)b->m));\n}\n\nu32 pow_b32(struct\
    \ Barrett_u32 *b, u32 a, u64 k) {\n    u32 ret = 1u;\n    u64 deg = k;\n    while\
    \ (deg > 0) {\n        if (deg & 1) {\n            ret = mul_b32(b, ret, a);\n\
    \        }\n        a = mul_b32(b, a, a);\n        deg >>= 1;\n    }\n    return\
    \ ret;\n}\n\n// Barrett reduction - 64-bit\nu64 mul_b64(struct Barrett_u64 *b,\
    \ u64 a, u64 x) {\n    b->reduce((u128)a * x);\n    return (u64)b->rem;\n}\n\n\
    u64 div_b64(struct Barrett_u64 *b, u64 a, u64 x) {\n    b->reduce((u128)a << 64);\n\
    \    return (u64)(b->div * inv_mod(x,(u64)b->m));\n}\n\nu64 pow_b64(struct Barrett_u64\
    \ *b, u64 a, u64 k) {\n    u64 ret = 1ull, deg = k;\n    while (deg > 0) {\n \
    \       if (deg & 1) {\n            ret = mul_b64(b, ret, a);\n        }\n   \
    \     a = mul_b64(b, a, a);\n        deg >>= 1;\n    }\n    return ret;\n}\n#line\
    \ 3 \"Mod/Primitive_root.hpp\"\nll primitive_root (ll p) {\n    if(p==2) return\
    \ 1;\n    vector<ll> fact;\n    Barrett_u64 br;\n    br.set(p);\n    ll phi =\
    \ p-1,  n = phi;\n    for (int i=2; i*i<=n; ++i)\n        if (n % i == 0) {\n\
    \            fact.push_back (i);\n            while (n % i == 0)\n           \
    \     n /= i;\n        }\n    if (n > 1)\n        fact.push_back (n);\n    for\
    \ (int res=2; res<=p; ++res) {\n        bool ok = true;\n        for (size_t i=0;\
    \ i<fact.size() && ok; ++i)\n            ok &= pow_b64(&br,res, phi / fact[i])\
    \ != 1;\n        if (ok)  return res;\n    }\n    return -1;\n}\n#line 8 \"test/yosupo/Math/primitive_root_yosupo.test.cpp\"\
    \n\nint main() {\n    FT;\n    int t; cin>>t;\n    while(t--){\n      ll n; cin>>n;\n\
    \      cout<<primitive_root(n)<<'\\n';\n    } \n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\n#include\
    \ \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll\
    \ INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"Mod/Primitive_root.hpp\"\n\nint main() {\n    FT;\n    int t; cin>>t;\n\
    \    while(t--){\n      ll n; cin>>n;\n      cout<<primitive_root(n)<<'\\n';\n\
    \    } \n   return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - Mod/Primitive_root.hpp
  - Modint/Barrett_2.hpp
  - Mod/mod_inv.hpp
  isVerificationFile: true
  path: test/yosupo/Math/primitive_root_yosupo.test.cpp
  requiredBy: []
  timestamp: '2024-06-03 13:13:59+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Math/primitive_root_yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/primitive_root_yosupo.test.cpp
- /verify/test/yosupo/Math/primitive_root_yosupo.test.cpp.html
title: test/yosupo/Math/primitive_root_yosupo.test.cpp
---
