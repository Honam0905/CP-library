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
    path: Mod/mod_inv.hpp
    title: Mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: NT/Fast_NT/fast_modinv.hpp
    title: NT/Fast_NT/fast_modinv.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/yosupo/Sample/fast_modinv.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"Misc/marco.hpp\"\n// Judges\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Sample/fast_modinv.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Mod/mod_inv.hpp\"\n\n#line 4 \"Mod/mod_inv.hpp\"\
    \n#include <type_traits>\n\n// gcd(a, m) != 1 return -1 \ntemplate <typename T>\n\
    T inv_mod(T a, T m) {\n  if (m == 1) return 0;\n  if (a >= m) a %= m;\n  if (a\
    \ < 0) a += m;\n  if(__gcd(a,m)!=1) return -1;\n  T b = m, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + m;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n#line 3 \"\
    NT/Fast_NT/fast_modinv.hpp\"\n \nstruct fast_modinv {\n  using u32 = unsigned\
    \ int;\n  using u64 = unsigned long long;\n \n  u32 mod;\n  u32 ipow2[64], pre[2048\
    \ / 2];\n \n  fast_modinv(u32 m) : mod(m), ipow2(), pre() {\n    assert(mod %\
    \ 2 == 1 && mod < (1LL << 30));\n \n    // Precompute ipow2\n    ipow2[0] = 1\
    \ % mod;\n    for (int i = 1; i < 64; i++) {\n      ipow2[i] = u64(ipow2[i - 1])\
    \ * ((mod + 1) / 2) % mod;\n    }\n \n    // Precompute pre for odd numbers\n\
    \    pre[0] = 1 % mod;\n    for (int i = 3; i < 2048; i += 2) {\n      pre[i >>\
    \ 1] = [this, i]() -> int {\n        int x = i, y = mod, u = 1, v = 0, t = 0,\
    \ tmp = 0;\n        while (y > 0) {\n          t = x / y;\n          x -= t *\
    \ y, u -= t * v;\n          tmp = x, x = y, y = tmp;\n          tmp = u, u = v,\
    \ v = tmp;\n        }\n        return u < 0 ? u + mod : u;\n      }();\n    }\n\
    \  }\n \n  bool is_prime(u32 n) const {\n    if (n == 1) return false;\n    for\
    \ (int p = 3; p * p <= n; p += 2) {\n      if (n % p == 0) return false;\n   \
    \ }\n    return true;\n  }\n \n  u32 inv(u32 a) const {\n    if (mod == 1) {\n\
    \      return 0;\n    }\n \n    u32 b = mod, s = 1, t = 0;\n    int n = __builtin_ctz(a);\n\
    \    a >>= n;\n \n    while (a - b != 0) {\n      if (is_prime(mod)) {\n     \
    \   if (a < 2048) break;\n      }\n      int m = __builtin_ctz(a - b);\n     \
    \ bool f = a > b;\n      n += m;\n      a = f ? (a - b) >> m : a;\n      b = f\
    \ ? b : -(a - b) >> m;\n      u32 u = f ? s - t : s << m;\n      t = f ? t <<\
    \ m : -(s - t);\n      s = u;\n    }\n    return u64(s) * pre[a >> 1] % mod *\
    \ ipow2[n] % mod;\n  }\n \n  u32 operator()(u32 a) const { return inv(a); }\n\
    };\n#line 9 \"test/yosupo/Sample/fast_modinv.test.cpp\"\nvoid benchmark() {\n\
    \   const int MOD1 = 998244353;  \n  const int MOD2 = 1000000007; \n  \n  fast_modinv\
    \ fmi1(MOD1);\n  fast_modinv fmi2(MOD2);\n  \n  vector<int> test_cases;\n  mt19937\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\n  uniform_int_distribution<int>\
    \ dist(1, 10000000000);\n  for (int i = 0; i < 5; i++) {\n    test_cases.push_back(dist(rng));\n\
    \  }\n  \n  \n  cerr << \"Benchmarking fast_modinv:\\n\";\n  for (int tc : test_cases)\
    \ {\n    auto start = chrono::high_resolution_clock::now();\n    int res1 = fmi1(tc);\n\
    \    int res2 = fmi2(tc);\n    auto end = chrono::high_resolution_clock::now();\n\
    \    assert(res1 == inv_mod(tc, MOD1));\n    assert(res2 == inv_mod(tc, MOD2));\n\
    \    cerr << \"Input: \" << tc << \", Time: \" << chrono::duration_cast<chrono::nanoseconds>(end\
    \ - start).count() << \" ns\\n\";\n  }\n  \n  cerr << \"\\nBenchmarking inv_mod:\\\
    n\";\n  for (int tc : test_cases) {\n    auto start = chrono::high_resolution_clock::now();\n\
    \    int res1 = inv_mod(tc, MOD1);\n    int res2 = inv_mod(tc, MOD2);\n    auto\
    \ end = chrono::high_resolution_clock::now();\n    cerr << \"Input: \" << tc <<\
    \ \", Time: \" << chrono::duration_cast<chrono::nanoseconds>(end - start).count()\
    \ << \" ns\\n\";\n  }\n}\n\nint main() {\n    FT;\n    benchmark();\n    int a,b;\
    \ cin>>a>>b;\n    cout<<a+b<<'\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"Misc/marco.hpp\"\
    \n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author:\
    \ Nguyen Ho Nam,UIT, Saigon-----------------\n#include \"Mod/mod_inv.hpp\"\n#include\
    \ \"NT/Fast_NT/fast_modinv.hpp\"\nvoid benchmark() {\n   const int MOD1 = 998244353;\
    \  \n  const int MOD2 = 1000000007; \n  \n  fast_modinv fmi1(MOD1);\n  fast_modinv\
    \ fmi2(MOD2);\n  \n  vector<int> test_cases;\n  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  uniform_int_distribution<int> dist(1, 10000000000);\n  for (int i = 0; i <\
    \ 5; i++) {\n    test_cases.push_back(dist(rng));\n  }\n  \n  \n  cerr << \"Benchmarking\
    \ fast_modinv:\\n\";\n  for (int tc : test_cases) {\n    auto start = chrono::high_resolution_clock::now();\n\
    \    int res1 = fmi1(tc);\n    int res2 = fmi2(tc);\n    auto end = chrono::high_resolution_clock::now();\n\
    \    assert(res1 == inv_mod(tc, MOD1));\n    assert(res2 == inv_mod(tc, MOD2));\n\
    \    cerr << \"Input: \" << tc << \", Time: \" << chrono::duration_cast<chrono::nanoseconds>(end\
    \ - start).count() << \" ns\\n\";\n  }\n  \n  cerr << \"\\nBenchmarking inv_mod:\\\
    n\";\n  for (int tc : test_cases) {\n    auto start = chrono::high_resolution_clock::now();\n\
    \    int res1 = inv_mod(tc, MOD1);\n    int res2 = inv_mod(tc, MOD2);\n    auto\
    \ end = chrono::high_resolution_clock::now();\n    cerr << \"Input: \" << tc <<\
    \ \", Time: \" << chrono::duration_cast<chrono::nanoseconds>(end - start).count()\
    \ << \" ns\\n\";\n  }\n}\n\nint main() {\n    FT;\n    benchmark();\n    int a,b;\
    \ cin>>a>>b;\n    cout<<a+b<<'\\n';\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - Mod/mod_inv.hpp
  - NT/Fast_NT/fast_modinv.hpp
  isVerificationFile: true
  path: test/yosupo/Sample/fast_modinv.test.cpp
  requiredBy: []
  timestamp: '2024-06-05 19:06:59+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Sample/fast_modinv.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Sample/fast_modinv.test.cpp
- /verify/test/yosupo/Sample/fast_modinv.test.cpp.html
title: test/yosupo/Sample/fast_modinv.test.cpp
---
