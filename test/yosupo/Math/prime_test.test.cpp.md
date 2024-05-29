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
    path: Mod/mod_pow.hpp
    title: Mod/mod_pow.hpp
  - icon: ':question:'
    path: Modint/Barrett_reduction.hpp
    title: Modint/Barrett_reduction.hpp
  - icon: ':question:'
    path: Modint/dynamic_modint.hpp
    title: Modint/dynamic_modint.hpp
  - icon: ':x:'
    path: NT/prime/prime_test.hpp
    title: NT/prime/prime_test.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/yosupo/Math/prime_test.test.cpp\"\n#define PROBLEM\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Math/prime_test.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"NT/prime/prime_test.hpp\"\n/*\n   Primality\
    \ tests by CP algorithms with higher bases\n   @see https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test\n\
    */\n#line 2 \"Modint/Barrett_reduction.hpp\"\n/*\n  @see https://nyaannyaan.github.io/library/modint/barrett-reduction.hpp\n\
    \  @see https://en.wikipedia.org/wiki/Barrett_reduction\n*/\nstruct Barrett {\n\
    \  using u32 = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n)\
    \ : m(n), im(u64(-1) / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64\
    \ x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n    return m\
    \ <= r ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n\
    \  constexpr inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n\
    \    return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32\
    \ a = rem(n), r = m == 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r)\
    \ * a);\n      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n\
    \  constexpr inline u32 mul(u32 a, u32 b) {\n    return rem(u64(a) * b);\n  }\n\
    };\n\n//u64 version:\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 rem(u128 x) {\n    u128 z = (x & u64(-1)) * ml;\n\
    \    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x >> 64) *\
    \ mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n  }\n\
    \n  u64 mul(u64 a, u64 b) { return rem(u128(a) * b); }\n};\n#line 3 \"Modint/dynamic_modint.hpp\"\
    \ntemplate <int id>\nstruct dynamic_modint {\n  int x;\n\n  dynamic_modint() :\
    \ x(0) {}\n\n  dynamic_modint(int64_t y) {\n    int z = y % get_mod();\n    if\
    \ (z < 0) z += get_mod();\n    x = z;\n  }\n\n  dynamic_modint &operator+=(const\
    \ dynamic_modint &p) {\n    if ((x += p.x) >= get_mod()) x -= get_mod();\n   \
    \ return *this;\n  }\n\n  dynamic_modint &operator-=(const dynamic_modint &p)\
    \ {\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n    return\
    \ *this;\n  }\n\n  dynamic_modint &operator*=(const dynamic_modint &p) {\n   \
    \ x = rem((unsigned long long)x * p.x);\n    return *this;\n  }\n\n  dynamic_modint\
    \ &operator/=(const dynamic_modint &p) {\n    *this *= p.inv();\n    return *this;\n\
    \  }\n\n  dynamic_modint operator-() const { return dynamic_modint(-x); }\n  dynamic_modint\
    \ operator+() const { return *this; }\n\n  dynamic_modint operator+(const dynamic_modint\
    \ &p) const {\n    return dynamic_modint(*this) += p;\n  }\n\n  dynamic_modint\
    \ operator-(const dynamic_modint &p) const {\n    return dynamic_modint(*this)\
    \ -= p;\n  }\n\n  dynamic_modint operator*(const dynamic_modint &p) const {\n\
    \    return dynamic_modint(*this) *= p;\n  }\n\n  dynamic_modint operator/(const\
    \ dynamic_modint &p) const {\n    return dynamic_modint(*this) /= p;\n  }\n\n\
    \  bool operator==(const dynamic_modint &p) const { return x == p.x; }\n\n  bool\
    \ operator!=(const dynamic_modint &p) const { return x != p.x; }\n\n  dynamic_modint\
    \ inv() const {\n    int a = x, b = get_mod(), u = 1, v = 0, t;\n    while (b\
    \ > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v,\
    \ v);\n    }\n    return dynamic_modint(u);\n  }\n\n  dynamic_modint pow(int64_t\
    \ n) const {\n    dynamic_modint ret(1), mul(x);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n\n  friend ostream &operator<<(ostream &os, const dynamic_modint &p) {\n\
    \    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is, dynamic_modint\
    \ &a) {\n    int64_t t;\n    is >> t;\n    a = dynamic_modint(t);\n    return\
    \ (is);\n  }\n\n  int get() const { return x; }\n\n  inline unsigned int rem(unsigned\
    \ long long p) { return barrett().rem(p); }\n\n  static inline Barrett &barrett()\
    \ {\n    static Barrett b;\n    return b;\n  }\n\n  static inline int &get_mod()\
    \ {\n    static int mod = 0;\n    return mod;\n  }\n\n  static void set_mod(int\
    \ md) {\n    assert(0 < md && md <= (1LL << 30) - 1);\n    get_mod() = md;\n \
    \   barrett() = Barrett(md);\n  }\n};\n\nusing modint = dynamic_modint<-1>;\n\
    #line 3 \"Mod/mod_pow.hpp\"\nu32 mod_pow(int a, ll n, int mod) {\n  assert(n >=\
    \ 0);\n  a = ((a %= mod) < 0 ? a + mod : a);\n  if ((mod & 1) && (mod < (1 <<\
    \ 30))) {\n    using mint = dynamic_modint<202311021>;\n    mint::set_mod(mod);\n\
    \    return mint(a).pow(n).get();\n  }\n  Barrett bt(mod);\n  int r = 1;\n  while\
    \ (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a, a), n >>= 1;\n  }\n\
    \  return r;\n}\n\nu64 mod_pow_64(ll a, ll n, u64 mod) {\n  assert(n >= 0);\n\
    \  a = ((a %= mod) < 0 ? a + mod : a);\n  if ((mod & 1) && (mod < (u64(1) << 62)))\
    \ {\n    using mint =dynamic_modint<202311021>;\n    mint::set_mod(mod);\n   \
    \ return mint(a).pow(n).get();\n  }\n  Barrett_64 bt(mod);\n  ll r = 1;\n  while\
    \ (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a, a), n >>= 1;\n  }\n\
    \  return r;\n}\n#line 7 \"NT/prime/prime_test.hpp\"\nbool check_composite(u64\
    \ n, u64 a, u64 d, int s) {\n    u64 x = mod_pow_64(a, d, n);\n    if (x == 1\
    \ || x == n - 1)\n        return false;\n    for (int r = 1; r < s; r++) {\n \
    \       x = (u128)x * x % n;\n        if (x == n - 1)\n            return false;\n\
    \    }\n    return true;\n}\n\nbool MillerRabin(u64 n) {\n    if (n < 2)\n   \
    \     return false;\n\n    // Small primes to check divisibility\n    for (u64\
    \ a : {2, 3, 5, 13, 19, 73, 193, 407521, 299210837}) {\n        if (n % a == 0)\n\
    \            return n == a;\n    }\n\n    int r = 0;\n    u64 d = n - 1;\n   \
    \ while ((d & 1) == 0) {\n        d >>= 1;\n        r++;\n    }\n\n    // Larger\
    \ bases for checking primality\n    for (u64 a : {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\n        if (n == a)\n            return true;\n   \
    \     if (check_composite(n, a, d, r))\n            return false;\n    }\n   \
    \ return true;\n}\n#line 8 \"test/yosupo/Math/prime_test.test.cpp\"\n\nint main()\
    \ {\n    int t; cin>>t;\n    while(t--){\n      u64 n; cin>>n;\n      cout<<(MillerRabin(n)?\"\
    Yes\":\"No\")<<'\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include\
    \ \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll\
    \ INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"NT/prime/prime_test.hpp\"\n\nint main() {\n    int t; cin>>t;\n   \
    \ while(t--){\n      u64 n; cin>>n;\n      cout<<(MillerRabin(n)?\"Yes\":\"No\"\
    )<<'\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - NT/prime/prime_test.hpp
  - Mod/mod_pow.hpp
  - Modint/dynamic_modint.hpp
  - Modint/Barrett_reduction.hpp
  isVerificationFile: true
  path: test/yosupo/Math/prime_test.test.cpp
  requiredBy: []
  timestamp: '2024-05-29 22:38:42+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Math/prime_test.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/prime_test.test.cpp
- /verify/test/yosupo/Math/prime_test.test.cpp.html
title: test/yosupo/Math/prime_test.test.cpp
---
