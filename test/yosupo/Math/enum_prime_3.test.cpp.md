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
    path: NT/prime/sieve/fast_sieve.hpp
    title: NT/prime/sieve/fast_sieve.hpp
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
  bundledCode: "#line 1 \"test/yosupo/Math/enum_prime_3.test.cpp\"\n#define PROBLEM\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Math/enum_prime_3.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"NT/prime/sieve/fast_sieve.hpp\"\nconst int\
    \ WHEEL = 3 * 5 * 7 * 11 * 13;\nconst int N_SMALL_PRIMES = 6536; // cnt primes\
    \ less than 2^16\nconst int SIEVE_SPAN = WHEEL * 64; // one iteration of segmented\
    \ sieve\nconst int SIEVE_SIZE = SIEVE_SPAN / 128 + 1;\n\nuint64_t ONES[64]; //\
    \ ONES[i] = 1<<i\nint small_primes[N_SMALL_PRIMES]; // primes less than 2^16\n\
    \n// each element of sieve is a 64-bit bitmask.\n// Each bit (0/1) stores whether\
    \ the corresponding element is a prime number.\n// We only need to store odd numbers\n\
    // -> 1st bitmask stores 3, 5, 7, 9, ...\nuint64_t si[SIEVE_SIZE];\n\n// for each\
    \ 'wheel', we store the sieve pattern (i.e. what numbers cannot\n// be primes)\n\
    uint64_t pattern[WHEEL];\n\ninline void mark(uint64_t* s, int o) { s[o >> 6] |=\
    \ ONES[o & 63]; }\ninline int test(uint64_t* s, int o) { return (s[o >> 6] & ONES[o\
    \ & 63]) == 0; }\n\n// update_sieve {{{\nvoid update_sieve(int offset) {\n   \
    \ // copy each wheel pattern to sieve\n    for (int i = 0, k; i < SIEVE_SIZE;\
    \ i += k) {\n        k = std::min(WHEEL, SIEVE_SIZE - i);\n        memcpy(si +\
    \ i, pattern, sizeof(*pattern) * k);\n    }\n\n    // Correctly mark 1, 3, 5,\
    \ 7, 11, 13 as not prime / primes\n    if (offset == 0) {\n        si[0] |= ONES[0];\n\
    \        si[0] &= ~(ONES[1] | ONES[2] | ONES[3] | ONES[5] | ONES[6]);\n    }\n\
    \n    // sieve for primes >= 17 (stored in `small_primes`)\n    for (int i = 0;\
    \ i < N_SMALL_PRIMES; ++i) {\n        int j = small_primes[i] * small_primes[i];\n\
    \        if (j > offset + SIEVE_SPAN - 1) break;\n        if (j > offset) j =\
    \ (j - offset) >> 1;\n        else {\n            j = small_primes[i] - offset\
    \ % small_primes[i];\n            if ((j & 1) == 0) j += small_primes[i];\n  \
    \          j >>= 1;\n        }\n        while (j < SIEVE_SPAN / 2) {\n       \
    \     mark(si, j);\n            j += small_primes[i];\n        }\n    }\n}\n//\
    \ }}}\n\ntemplate<class T>\nstd::vector<T> sieve_3(T MAX) {\n    std::vector<T>\
    \ primes;\n\n    // init small primes {{{\n    for (int i = 0; i < 64; ++i) ONES[i]\
    \ = 1ULL << i;\n\n    // sieve to find small primes\n    for (int i = 3; i < 256;\
    \ i += 2) {\n        if (test(si, i >> 1)) {\n            for (int j = i*i / 2;\
    \ j < 32768; j += i) mark(si, j);\n        }\n    }\n\n    // store primes >=\
    \ 17 in `small_primes` (we will sieve differently\n    // for primes 2, 3, 5,\
    \ 7, 11, 13)\n    {\n        int m = 0;\n        for (int i = 8; i < 32768; ++i)\
    \ {\n            if (test(si, i)) small_primes[m++] = i*2 + 1;\n        }\n  \
    \      assert(m == N_SMALL_PRIMES);\n    }\n    // }}}\n\n    // For primes 3,\
    \ 5, 7, 11, 13: we initialize wheel pattern..\n    for (int i = 1; i < WHEEL *\
    \ 64; i += 3) mark(pattern, i);\n    for (int i = 2; i < WHEEL * 64; i += 5) mark(pattern,\
    \ i);\n    for (int i = 3; i < WHEEL * 64; i += 7) mark(pattern, i);\n    for\
    \ (int i = 5; i < WHEEL * 64; i += 11) mark(pattern, i);\n    for (int i = 6;\
    \ i < WHEEL * 64; i += 13) mark(pattern, i);\n\n    primes.push_back(2);\n\n \
    \   // Segmented sieve\n    for (int offset = 0; offset < MAX; offset += SIEVE_SPAN)\
    \ {\n        update_sieve(offset);\n        for (uint32_t j = 0; j < SIEVE_SIZE;\
    \ j++) {\n            uint64_t x = ~si[j];\n            while (x) {\n        \
    \        uint32_t p = offset + (j << 7) + (__builtin_ctzll(x) << 1) + 1;\n   \
    \             if (p > offset + SIEVE_SPAN - 1) break;\n                if (p <=\
    \ MAX) {\n                    primes.push_back(p);\n                }\n      \
    \          x ^= (-x & x);\n            }\n        }\n    }\n\n    return primes;\n\
    }\n#line 8 \"test/yosupo/Math/enum_prime_3.test.cpp\"\npair<int, vector<int>>\
    \ enum_prime(int n) {\n    if (n <= 1) return {0, {}};\n    auto primes = sieve_3(n);\n\
    \    int dem = primes.size();\n    return {dem, primes};\n}\n\nint main() {\n\
    \    int n, a, b; cin>>n>>a>>b;\n    auto [cnt, primes] = enum_prime(n);\n   \
    \ cout<<cnt<<\" \";\n    int x = 0;\n    for (int i = b; i < primes.size(); i\
    \ += a) {\n        x++;\n    }\n    cout<<x<<'\\n';\n    for (int i = b; i < primes.size();\
    \ i += a) {\n        cout<<primes[i]<<\" \";\n    }\n    cout<<'\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll\
    \ INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"NT/prime/sieve/fast_sieve.hpp\"\npair<int, vector<int>> enum_prime(int\
    \ n) {\n    if (n <= 1) return {0, {}};\n    auto primes = sieve_3(n);\n    int\
    \ dem = primes.size();\n    return {dem, primes};\n}\n\nint main() {\n    int\
    \ n, a, b; cin>>n>>a>>b;\n    auto [cnt, primes] = enum_prime(n);\n    cout<<cnt<<\"\
    \ \";\n    int x = 0;\n    for (int i = b; i < primes.size(); i += a) {\n    \
    \    x++;\n    }\n    cout<<x<<'\\n';\n    for (int i = b; i < primes.size();\
    \ i += a) {\n        cout<<primes[i]<<\" \";\n    }\n    cout<<'\\n';\n    return\
    \ 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - NT/prime/sieve/fast_sieve.hpp
  isVerificationFile: true
  path: test/yosupo/Math/enum_prime_3.test.cpp
  requiredBy: []
  timestamp: '2024-05-24 23:31:35+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/enum_prime_3.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/enum_prime_3.test.cpp
- /verify/test/yosupo/Math/enum_prime_3.test.cpp.html
title: test/yosupo/Math/enum_prime_3.test.cpp
---
