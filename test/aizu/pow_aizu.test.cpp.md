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
    path: Modint/montgomery_modint.hpp
    title: montgomery modint(static modint)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"test/aizu/pow_aizu.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/aizu/pow_aizu.test.cpp\"\n\
    const int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Modint/montgomery_modint.hpp\"\n/*\n   @brief\
    \ montgomery modint(static modint)\n*/\ntemplate <uint32_t mod_, bool fast = false>\n\
    struct mod_int {\n private:\n  using mint = mod_int;\n  using i32 = int32_t;\n\
    \  using i64 = int64_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod_;\n    for (i32 i = 0; i\
    \ < 4; i++) ret *= 2 - mod_ * ret;\n    return ret;\n  }\n\n  static constexpr\
    \ u32 r = get_r();\n\n  static constexpr u32 n2 = -u64(mod_) % mod_;\n\n  static_assert(r\
    \ * mod_ == 1, \"invalid, r * mod != 1\");\n  static_assert(mod_ < (1 << 30),\
    \ \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod_ & 1) == 1, \"invalid, mod\
    \ % 2 == 0\");\n\n  u32 x;\n\n public:\n  mod_int() : x{} {}\n\n  mod_int(const\
    \ i64 &a)\n      : x(reduce(u64(fast ? a : (a % mod() + mod())) * n2)) {}\n\n\
    \  static constexpr u32 reduce(const u64 &b) {\n    return u32(b >> 32) + mod()\
    \ - u32((u64(u32(b) * r) * mod()) >> 32);\n  }\n\n  mint &operator+=(const mint\
    \ &p) {\n    if (i32(x += p.x - 2 * mod()) < 0) x += 2 * mod();\n    return *this;\n\
    \  }\n\n  mint &operator-=(const mint &p) {\n    if (i32(x -= p.x) < 0) x += 2\
    \ * mod();\n    return *this;\n  }\n\n  mint &operator*=(const mint &p) {\n  \
    \  x = reduce(u64(x) * p.x);\n    return *this;\n  }\n\n  mint &operator/=(const\
    \ mint &p) {\n    *this *= p.inv();\n    return *this;\n  }\n\n  mint operator-()\
    \ const { return mint() - *this; }\n\n  mint operator+(const mint &p) const {\
    \ return mint(*this) += p; }\n\n  mint operator-(const mint &p) const { return\
    \ mint(*this) -= p; }\n\n  mint operator*(const mint &p) const { return mint(*this)\
    \ *= p; }\n\n  mint operator/(const mint &p) const { return mint(*this) /= p;\
    \ }\n\n  bool operator==(const mint &p) const {\n    return (x >= mod() ? x -\
    \ mod() : x) == (p.x >= mod() ? p.x - mod() : p.x);\n  }\n\n  bool operator!=(const\
    \ mint &p) const {\n    return (x >= mod() ? x - mod() : x) != (p.x >= mod() ?\
    \ p.x - mod() : p.x);\n  }\n\n  u32 val() const {\n    u32 ret = reduce(x);\n\
    \    return ret >= mod() ? ret - mod() : ret;\n  }\n\n  mint pow(u64 n) const\
    \ {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n      if (n & 1) ret *=\
    \ mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  mint\
    \ inv() const { return pow(mod() - 2); }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &p) {\n    return os << p.val();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &a) {\n    i64 t;\n    is >> t;\n    a = mint(t);\n    return is;\n\
    \  }\n\n  static constexpr u32 mod() { return mod_; }\n};\n\ntemplate <uint32_t\
    \ mod>\nusing modint = mod_int<mod>;\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1000000007>;\n#line 8 \"test/aizu/pow_aizu.test.cpp\"\
    \nusing mint=modint1000000007;\n\nint main() {\n   ll a,b; cin>>a>>b;\n   mint\
    \ ans=mint(a).pow(b);\n   cout<<ans<<'\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n#include \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\n\
    const ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"Modint/montgomery_modint.hpp\"\nusing mint=modint1000000007;\n\nint\
    \ main() {\n   ll a,b; cin>>a>>b;\n   mint ans=mint(a).pow(b);\n   cout<<ans<<'\\\
    n';\n    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - Modint/montgomery_modint.hpp
  isVerificationFile: true
  path: test/aizu/pow_aizu.test.cpp
  requiredBy: []
  timestamp: '2024-05-22 19:46:35+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aizu/pow_aizu.test.cpp
layout: document
redirect_from:
- /verify/test/aizu/pow_aizu.test.cpp
- /verify/test/aizu/pow_aizu.test.cpp.html
title: test/aizu/pow_aizu.test.cpp
---
