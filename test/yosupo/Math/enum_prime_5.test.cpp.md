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
    path: NT/prime/sieve/bool_sieve.hpp
    title: NT/prime/sieve/bool_sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo/Math/enum_prime_5.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#line 2 \"Misc/marco.hpp\"\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Math/enum_prime_5.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"NT/prime/sieve/bool_sieve.hpp\"\n// Prime\
    \ -> {0, 0, 1, 1, 0, 1, 0, 1, ...}\nvector<bool> prime_sieve(int N) {\n  vector<bool>\
    \ sieve(max(1, N) + 1, 1);\n  sieve[0] = sieve[1] = false;\n  for (int i = 2;\
    \ i * i <= N; i++)\n    if (sieve[i] == true)\n      for (int j = i * i; j <=\
    \ N; j += i) sieve[j] = false;\n  return sieve;\n}\n#line 8 \"test/yosupo/Math/enum_prime_5.test.cpp\"\
    \npair<int, vector<int>> enum_prime(int n) {\n    if (n <= 1) return {0, {}};\n\
    \    auto is_prime = prime_sieve(n);\n    vector<int> primes;\n    for (int i\
    \ = 2; i <= n; i++) {\n        if (is_prime[i]) {\n            primes.push_back(i);\n\
    \        }\n    }\n    int dem = primes.size();\n    return {dem, primes};\n}\n\
    int main() {\n    int n, a, b; cin>>n>>a>>b;\n    auto [cnt, primes] = enum_prime(n);\n\
    \    cout<<cnt<<\" \";\n    int x = 0;\n    for (int i = b; i < primes.size();\
    \ i += a) {\n        x++;\n    }\n    cout<<x<<'\\n';\n    for (int i = b; i <\
    \ primes.size(); i += a) {\n        cout<<primes[i]<<\" \";\n    }\n    cout<<'\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll\
    \ INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"NT/prime/sieve/bool_sieve.hpp\"\npair<int, vector<int>> enum_prime(int\
    \ n) {\n    if (n <= 1) return {0, {}};\n    auto is_prime = prime_sieve(n);\n\
    \    vector<int> primes;\n    for (int i = 2; i <= n; i++) {\n        if (is_prime[i])\
    \ {\n            primes.push_back(i);\n        }\n    }\n    int dem = primes.size();\n\
    \    return {dem, primes};\n}\nint main() {\n    int n, a, b; cin>>n>>a>>b;\n\
    \    auto [cnt, primes] = enum_prime(n);\n    cout<<cnt<<\" \";\n    int x = 0;\n\
    \    for (int i = b; i < primes.size(); i += a) {\n        x++;\n    }\n    cout<<x<<'\\\
    n';\n    for (int i = b; i < primes.size(); i += a) {\n        cout<<primes[i]<<\"\
    \ \";\n    }\n    cout<<'\\n';\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - NT/prime/sieve/bool_sieve.hpp
  isVerificationFile: true
  path: test/yosupo/Math/enum_prime_5.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 22:51:21+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/enum_prime_5.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/enum_prime_5.test.cpp
- /verify/test/yosupo/Math/enum_prime_5.test.cpp.html
title: test/yosupo/Math/enum_prime_5.test.cpp
---
