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
    path: Mod/mod_pow.hpp
    title: Mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: Mod/mod_sqrt.hpp
    title: Mod/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: Modint/Barrett_reduction.hpp
    title: Modint/Barrett_reduction.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo/Math/mod_sqrt_yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#line 2 \"Misc/marco.hpp\"\n//\
    \ Judges with GCC >= 12 only needs Ofast\n// #pragma GCC optimize(\"O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize\"\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Math/mod_sqrt_yosupo.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Modint/Barrett_reduction.hpp\"\n/*\n  @see\
    \ https://nyaannyaan.github.io/library/modint/barrett-reduction.hpp\n  @see https://en.wikipedia.org/wiki/Barrett_reduction\n\
    */\nstruct Barrett {\n  using u32 = unsigned int;\n  using i64 = long long;\n\
    \  using u64 = unsigned long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im()\
    \ {}\n  Barrett(int n) : m(n), im(u64(-1) / m + 1) {}\n  constexpr inline i64\
    \ quo(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n -\
    \ x * m;\n    return m <= r ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64\
    \ n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n\
    \    return m <= r ? r + m : r;\n  }\n  constexpr inline pair<i64, int> quorem(u64\
    \ n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n\
    \    if (m <= r) return {x - 1, r + m};\n    return {x, r};\n  }\n  constexpr\
    \ inline i64 pow(u64 n, i64 p) {\n    u32 a = rem(n), r = m == 1 ? 0 : 1;\n  \
    \  while (p) {\n      if (p & 1) r = rem(u64(r) * a);\n      a = rem(u64(a) *\
    \ a);\n      p >>= 1;\n    }\n    return r;\n  }\n  constexpr inline u32 mul(u32\
    \ a, u32 b) {\n    return rem(u64(a) * b);\n  }\n};\n#line 3 \"Mod/mod_pow.hpp\"\
    \n// int\nll mod_pow(ll a, ll n, int mod) {\n  a %= mod;\n  Barrett bt(mod);\n\
    \  ll p = a;\n  ll v = 1;\n  while (n) {\n    if (n & 1) v = bt.mul(v, p);\n \
    \   p = bt.mul(p, p);\n    n >>= 1;\n  }\n  return v;\n}\n//long long \nll mod_pow_long(ll\
    \ a, ll n, ll mod) {\n  a %= mod;\n  ll p = a;\n  ll v = 1;\n  while (n) {\n \
    \   if (n & 1) v = i128(v) * p % mod;\n    p = i128(p) * p % mod;\n    n >>= 1;\n\
    \  }\n  return v;\n}\n#line 3 \"Mod/mod_sqrt.hpp\"\ntemplate <typename T>\nT mod_sqrt(const\
    \ T &a, const T &p) {\n  if (a == 0) return 0;\n  if (p == 2) return a;\n  if\
    \ (mod_pow_long(a, (p - 1) >> 1, p) != 1) return -1;\n  T b = 1;\n  while (mod_pow_long(b,\
    \ (p - 1) >> 1, p) == 1) ++b;\n  T e = 0, m = p - 1;\n  while (m % 2 == 0) m >>=\
    \ 1, ++e;\n  T x = mod_pow_long(a, (m - 1) >> 1, p);\n  T y = a * (x * x % p)\
    \ % p;\n  (x *= a) %= p;\n  T z = mod_pow_long(b, m, p);\n  while (y != 1) {\n\
    \    T j = 0, t = y;\n    while (t != 1) {\n      j += 1;\n      (t *= t) %= p;\n\
    \    }\n    z = mod_pow_long(z, T(1) << (e - j - 1), p);\n    (x *= z) %= p;\n\
    \    (z *= z) %= p;\n    (y *= z) %= p;\n    e = j;\n  }\n  return x;\n}\n#line\
    \ 8 \"test/yosupo/Math/mod_sqrt_yosupo.test.cpp\"\n\nint main() {\n    int t;\
    \ cin>>t;\n    while(t--){\n       ll a,b; cin>>a>>b;\n       cout<<mod_sqrt(a,b)<<'\\\
    n';\n    } \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include \"\
    Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll INFI=1e15;\n\
    //----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n#include \"Mod/mod_sqrt.hpp\"\
    \n\nint main() {\n    int t; cin>>t;\n    while(t--){\n       ll a,b; cin>>a>>b;\n\
    \       cout<<mod_sqrt(a,b)<<'\\n';\n    } \n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - Mod/mod_sqrt.hpp
  - Mod/mod_pow.hpp
  - Modint/Barrett_reduction.hpp
  isVerificationFile: true
  path: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
  requiredBy: []
  timestamp: '2024-05-22 10:47:25+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/mod_sqrt_yosupo.test.cpp
- /verify/test/yosupo/Math/mod_sqrt_yosupo.test.cpp.html
title: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
---
