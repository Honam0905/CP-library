---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Misc/debug.hpp
    title: Misc/debug.hpp
  - icon: ':question:'
    path: Misc/marco.hpp
    title: Misc/marco.hpp
  - icon: ':heavy_check_mark:'
    path: Mod/mod_mul.hpp
    title: Mod/mod_mul.hpp
  - icon: ':heavy_check_mark:'
    path: NT/prime/prime_test.hpp
    title: NT/prime/prime_test.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/yosupo/Math/prime_test_yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/primality_test\"\n#line 2 \"Misc/marco.hpp\"\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Math/prime_test_yosupo.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Mod/mod_mul.hpp\"\nu64 get_nr(u64 M) {\n\
    \    u64 IV = 2 - M;\n    for (int i = 0; i < 5; ++i) {\n        IV *= 2 - M *\
    \ IV;\n    }\n    return IV;\n}\n\nu64 modmul(u64 x, u64 y, u64 M) {\n    u64\
    \ IV=get_nr(M);\n    auto t = u128(x) * y;\n    u64 lo = t, hi = t >> 64;\n  \
    \  return (hi + M) - u64((u128(lo * IV) * M) >> 64);\n}\n \nu64 modpow(u64 a,\
    \ u64 b, u64 M) {\n    u64 res = 1;\n    u64 IV = get_nr(M);\n    while (b) {\n\
    \        if (b & 1) {\n            res = modmul(res, a, M);\n        }\n     \
    \   a = modmul(a, a, M);\n        b >>= 1;\n    }\n    return res;\n}\n//or\n\
    //only good for long long or int64_t\nlong long modmul2(long long a,long long\
    \ b,long long mod){\n   return (a*b)%mod;\n}\n#line 3 \"NT/prime/prime_test.hpp\"\
    \nbool isPrime(u64 x) {\n    if (x < 64) {\n        return (u64(1) << x) & 0x28208a20a08a28ac;\n\
    \    }\n    if (x % 2 == 0) {\n        return false;\n    }\n    const int k =\
    \ __builtin_ctzll(x - 1);\n    const u64 d = (x - 1) >> k, IV = get_nr(x), R =\
    \ (-x) % x, R2 = (-u128(x)) % x, nR = x - R;\n    auto mr7 = [&](u64 t1, u64 t2,\
    \ u64 t3, u64 t4, u64 t5, u64 t6, u64 t7) {\n        u64 r1 = R, r2 = R, r3 =\
    \ R, r4 = R, r5 = R, r6 = R, r7 = R;\n        t1 = modmul(t1, R2, x), t2 = modmul(t2,\
    \ R2, x), t3 = modmul(t3, R2, x);\n        t4 = modmul(t4, R2, x), t5 = modmul(t5,\
    \ R2, x), t6 = modmul(t6, R2, x), t7 = modmul(t7, R2, x);\n        for (u64 b\
    \ = d; b; b >>= 1) {\n            if (b & 1) {\n                r1 = modmul(r1,\
    \ t1, x), r2 = modmul(r2, t2, x), r3 = modmul(r3, t3, x);\n                r4\
    \ = modmul(r4, t4, x), r5 = modmul(r5, t5, x), r6 = modmul(r6, t6, x), r7 = modmul(r7,\
    \ t7, x);\n            }\n            t1 = modmul(t1, t1, x), t2 = modmul(t2,\
    \ t2, x), t3 = modmul(t3, t3, x);\n            t4 = modmul(t4, t4, x), t5 = modmul(t5,\
    \ t5, x), t6 = modmul(t6, t6, x), t7 = modmul(t7, t7, x);\n        }\n       \
    \ r1 = min(r1, r1 - x), r2 = min(r2, r2 - x), r3 = min(r3, r3 - x);\n        r4\
    \ = min(r4, r4 - x), r5 = min(r5, r5 - x), r6 = min(r6, r6 - x), r7 = min(r7,\
    \ r7 - x);\n        int res1 = (r1 == R) | (r1 == nR), res2 = (r2 == R) | (r2\
    \ == nR), res3 = (r3 == R) | (r3 == nR);\n        int res4 = (r4 == R) | (r4 ==\
    \ nR), res5 = (r5 == R) | (r5 == nR), res6 = (r6 == R) | (r6 == nR), res7 = (r7\
    \ == R) | (r7 == nR);\n        for (int j = 0; j < k - 1; ++j) {\n           \
    \ r1 = modmul(r1, r1, x), r2 = modmul(r2, r2, x), r3 = modmul(r3, r3, x);\n  \
    \          r4 = modmul(r4, r4, x), r5 = modmul(r5, r5, x), r6 = modmul(r6, r6,\
    \ x), r7 = modmul(r7, r7, x);\n            res1 |= (min(r1, r1 - x) == nR), res2\
    \ |= (min(r2, r2 - x) == nR), res3 |= (min(r3, r3 - x) == nR);\n            res4\
    \ |= (min(r4, r4 - x) == nR), res5 |= (min(r5, r5 - x) == nR), res6 |= (min(r6,\
    \ r6 - x) == nR), res7 |= (min(r7, r7 - x) == nR);\n        }\n        return\
    \ res1 & res2 & res3 & res4 & res5 & res6 & res7;\n    };\n    if (x == 2 || x\
    \ == 3 || x == 5 || x == 13 || x == 19 || x == 73 || x == 193 || x == 407521 ||\
    \ x == 299210837) {\n        return true;\n    }\n    return mr7(2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022);\n}\n#line 8 \"test/yosupo/Math/prime_test_yosupo.test.cpp\"\
    \n\nint main() {\n    int t; cin>>t;\n    while(t--){\n     u64 n; cin>>n;\n \
    \    cout<<(isPrime(n)?\"Yes\":\"No\")<<'\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include\
    \ \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll\
    \ INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"NT/prime/prime_test.hpp\"\n\nint main() {\n    int t; cin>>t;\n   \
    \ while(t--){\n     u64 n; cin>>n;\n     cout<<(isPrime(n)?\"Yes\":\"No\")<<'\\\
    n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - NT/prime/prime_test.hpp
  - Mod/mod_mul.hpp
  isVerificationFile: true
  path: test/yosupo/Math/prime_test_yosupo.test.cpp
  requiredBy: []
  timestamp: '2024-05-30 11:16:41+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/prime_test_yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/prime_test_yosupo.test.cpp
- /verify/test/yosupo/Math/prime_test_yosupo.test.cpp.html
title: test/yosupo/Math/prime_test_yosupo.test.cpp
---
