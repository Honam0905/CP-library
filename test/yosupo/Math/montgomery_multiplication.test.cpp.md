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
    path: Modint/montgomery_multiplication.hpp
    title: Modint/montgomery_multiplication.hpp
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
  bundledCode: "#line 1 \"test/yosupo/Math/montgomery_multiplication.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#line 2 \"\
    Misc/marco.hpp\"\n// Judges with GCC >= 12 only needs Ofast\n// #pragma GCC optimize(\"\
    O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize\")\n// MLE optimization\n\
    // #pragma GCC optimize(\"conserve-stack\")\n// Old judges\n// #pragma GCC target(\"\
    sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2\")\n// New judges. Test with assert(__builtin_cpu_supports(\"\
    avx2\"));\n// #pragma GCC target(\"avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native\"\
    )\n// Atcoder\n// #pragma GCC target(\"avx2,popcnt,lzcnt,abm,bmi,bmi2,fma\")\n\
    /*\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\ntypedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>\
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
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 4 \"test/yosupo/Math/montgomery_multiplication.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Modint/montgomery_multiplication.hpp\"\n\
    /*\n  inv_mod from atcoder library\n  reference:https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp\n\
    */\ntemplate<class T>\nconstexpr T safe_mod(T x, T m) {\n    x %= m;\n    if (x\
    \ < 0) x += m;\n    return x;\n}\ntemplate<class T>\nconstexpr std::pair<T, T>\
    \ inv_gcd(T a, T b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\
    \n    T s = b, t = a;\n    T m0 = 0, m1 = 1;\n\n    while (t) {\n        T u =\
    \ s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        auto tmp = s;\n\
    \        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n     \
    \   m1 = tmp;\n    }\n\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    template<class T>\nT mod_inv(T x, T m) {\n    assert(1 <= m);\n    auto z = inv_gcd(x,\
    \ m);\n    assert(z.first == 1);\n    return z.second;\n}\n/*\n  montgomery multiplication\n\
    \  @see https://en.wikipedia.org/wiki/Montgomery_modular_multiplication\n  @see\
    \ https://cp-algorithms.com/algebra/montgomery_multiplication.html\n*/\nstruct\
    \ Montgomery_u32 {\n    u32 n, n2, ni, r1, r2, r3;\n\n    void set(u32 mod) {\n\
    \        n = mod;\n        n2 = mod << 1;\n        ni = mod;\n        ni *= 2\
    \ - ni * mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n    \
    \    ni *= 2 - ni * mod;\n        r1 = (u32)(int32_t)-1 % mod + 1;\n        r2\
    \ = (u64)(int64_t)-1 % mod + 1;\n        r3 = (u32)(((u64)r1 * (u64)r2) % mod);\n\
    \    }\n\n    u32 reduce(u64 a) {\n        u32 y = (u32)(a >> 32) - (u32)(((u64)((u32)a\
    \ * ni) * n) >> 32);\n        return (int32_t)y < 0 ? y + n : y;\n    }\n\n  \
    \  u32 to(u32 a) {\n        return reduce((u64)a * r2);\n    }\n\n    u32 from(u32\
    \ a) {\n        return reduce((u64)a);\n    }\n\n    u32 add(u32 a, u32 b) {\n\
    \        a += b;\n        a -= (a >= n ? n : 0);\n        return a;\n    }\n\n\
    \    u32 sub(u32 a, u32 b) {\n        a += (a < b ? n : 0);\n        a -= b;\n\
    \        return a;\n    }\n\n    u32 min(u32 a) {\n        return sub(0, a);\n\
    \    }\n\n    u32 shl(u32 a) {\n        return (a <<= 1) >= n ? a - n : a;\n \
    \   }\n\n    u32 shr(u32 a) {\n        return (a & 1) ? ((a >> 1) + (n >> 1) +\
    \ 1) : (a >> 1);\n    }\n\n    u32 inv(u32 a) {\n        return reduce((u64)r3\
    \ * mod_inv(a, n));\n    }\n};\n\nstruct Montgomery_u64 {\n    u64 n, n2, ni,\
    \ r1, r2, r3;\n\n    void set(u64 mod) {\n        n = mod;\n        n2 = mod <<\
    \ 1;\n        ni = mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n\
    \        ni *= 2 - ni * mod;\n        ni *= 2 - ni * mod;\n        ni *= 2 - ni\
    \ * mod;\n        r1 = (u64)(int64_t)-1 % mod + 1;\n        r2 = (u128)(i128)-1\
    \ % mod + 1;\n        r3 = (u64)(((u128)r1 * (u128)r2) % mod);\n    }\n\n    u64\
    \ reduce(u128 a) {\n        u64 y = (u64)(a >> 64) - (u64)(((u128)((u64)a * ni)\
    \ * n) >> 64);\n        return (int64_t)y < 0 ? y + n : y;\n    }\n\n    u64 to(u64\
    \ a) {\n        return reduce((u128)a * r2);\n    }\n\n    u64 from(u64 a) {\n\
    \        return reduce((u128)a);\n    }\n\n    u64 add(u64 a, u64 b) {\n     \
    \   a += b;\n        a -= (a >= n ? n : 0);\n        return a;\n    }\n\n    u64\
    \ sub(u64 a, u64 b) {\n        a += (a < b ? n : 0);\n        a -= b;\n      \
    \  return a;\n    }\n\n    u64 min(u64 a) {\n        return sub(0, a);\n    }\n\
    \n    u64 shl(u64 a) {\n        return (a <<= 1) >= n ? a - n : a;\n    }\n\n\
    \    u64 shr(u64 a) {\n        return (a & 1) ? ((a >> 1) + (n >> 1) + 1) : (a\
    \ >> 1);\n    }\n\n    u64 inv(u64 a) {\n        return reduce((u128)r3 * mod_inv(a,\
    \ n));\n    }\n};\n// Montgomery multiplication - 32-bit\nu32 mul_m32(struct Montgomery_u32\
    \ *m, u32 a, u32 b) {\n    return m->reduce((u64)a * b);\n}\n\nu32 div_m32(struct\
    \ Montgomery_u32 *m, u32 a, u32 b) {\n    return mul_m32(m, a, m->inv(b));\n}\n\
    \nu32 pow_m32(struct Montgomery_u32 *m, u32 a, u64 k) {\n    u32 ret = m->r1;\n\
    \    u64 deg = k;\n    while (deg > 0) {\n        if (deg & 1) {\n           \
    \ ret = mul_m32(m, ret, a);\n        }\n        a = mul_m32(m, a, a);\n      \
    \  deg >>= 1;\n    }\n    return m->from(ret);\n}\n\n// Montgomery multiplication\
    \ - 64-bit\nu64 mul_m64(struct Montgomery_u64 *m, u64 a, u64 b) {\n    return\
    \ m->reduce((u128)a * b);\n}\n\nu64 div_m64(struct Montgomery_u64 *m, u64 a, u64\
    \ b) {\n    return mul_m64(m, a, m->inv(b));\n}\n\nu64 pow_m64(struct Montgomery_u64\
    \ *m, u64 a, u64 k) {\n    u64 ret = m->r1, deg = k;\n    while (deg > 0) {\n\
    \        if (deg & 1) {\n            ret = mul_m64(m, ret, a);\n        }\n  \
    \      a = mul_m64(m, a, a);\n        deg >>= 1;\n    }\n    return m->from(ret);\n\
    }\n#line 8 \"test/yosupo/Math/montgomery_multiplication.test.cpp\"\nbool isPrime(u64\
    \ x) {\n    if (x < 64) {\n        return (u64(1) << x) & 0x28208a20a08a28ac;\n\
    \    }\n    if (x % 2 == 0) {\n        return false;\n    }\n    \n    Montgomery_u64\
    \ m;\n    m.set(x);\n    \n    const int k = __builtin_ctzll(x - 1);\n    const\
    \ u64 d = (x - 1) >> k, IV = m.ni, R = m.r1, R2 = m.r2, nR = m.min(R);\n    \n\
    \    auto mr7 = [&](u64 t1, u64 t2, u64 t3, u64 t4, u64 t5, u64 t6, u64 t7) {\n\
    \        u64 r1 = R, r2 = R, r3 = R, r4 = R, r5 = R, r6 = R, r7 = R;\n       \
    \ t1 = mul_m64(&m, t1, R2), t2 = mul_m64(&m, t2, R2), t3 = mul_m64(&m, t3, R2);\n\
    \        t4 = mul_m64(&m, t4, R2), t5 = mul_m64(&m, t5, R2), t6 = mul_m64(&m,\
    \ t6, R2), t7 = mul_m64(&m, t7, R2);\n        for (u64 b = d; b; b >>= 1) {\n\
    \            if (b & 1) {\n                r1 = mul_m64(&m, r1, t1), r2 = mul_m64(&m,\
    \ r2, t2), r3 = mul_m64(&m, r3, t3);\n                r4 = mul_m64(&m, r4, t4),\
    \ r5 = mul_m64(&m, r5, t5), r6 = mul_m64(&m, r6, t6), r7 = mul_m64(&m, r7, t7);\n\
    \            }\n            t1 = mul_m64(&m, t1, t1), t2 = mul_m64(&m, t2, t2),\
    \ t3 = mul_m64(&m, t3, t3);\n            t4 = mul_m64(&m, t4, t4), t5 = mul_m64(&m,\
    \ t5, t5), t6 = mul_m64(&m, t6, t6), t7 = mul_m64(&m, t7, t7);\n        }\n  \
    \      r1 = min(r1, m.sub(r1,x)), r2 = min(r2, m.sub(r2,x)), r3 = min(r3, m.sub(r3,x));\n\
    \        r4 = min(r4, m.sub(r4,x)), r5 = min(r5, m.sub(r5,x)), r6 = min(r6, m.sub(r6,x)),\
    \ r7 = min(r7, m.sub(r7,x));\n        int res1 = (r1 == R) | (r1 == nR), res2\
    \ = (r2 == R) | (r2 == nR), res3 = (r3 == R) | (r3 == nR);\n        int res4 =\
    \ (r4 == R) | (r4 == nR), res5 = (r5 == R) | (r5 == nR), res6 = (r6 == R) | (r6\
    \ == nR), res7 = (r7 == R) | (r7 == nR);\n        for (int j = 0; j < k - 1; ++j)\
    \ {\n            r1 = mul_m64(&m, r1, r1), r2 = mul_m64(&m, r2, r2), r3 = mul_m64(&m,\
    \ r3, r3);\n            r4 = mul_m64(&m, r4, r4), r5 = mul_m64(&m, r5, r5), r6\
    \ = mul_m64(&m, r6, r6), r7 = mul_m64(&m, r7, r7);\n            res1 |= (min(r1,\
    \ m.sub(r1,x)) == nR), res2 |= (min(r2, m.sub(r2,x)) == nR), res3 |= (min(r3,\
    \ m.sub(r3,x)) == nR);\n            res4 |= (min(r4, m.sub(r4,x)) == nR), res5\
    \ |= (min(r5, m.sub(r5,x)) == nR), res6 |= (min(r6, m.sub(r6,x)) == nR), res7\
    \ |= (min(r7, m.sub(r7,x)) == nR);\n        }\n        return res1 & res2 & res3\
    \ & res4 & res5 & res6 & res7;\n    };\n    if (x == 2 || x == 3 || x == 5 ||\
    \ x == 13 || x == 19 || x == 73 || x == 193 || x == 407521 || x == 299210837)\
    \ {\n        return true;\n    }\n    return mr7(2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022);\n}\n\nint main() {\n    int t; cin>>t;\n    while(t--){\n\
    \      u64 n; cin>>n;\n      cout<<(isPrime(n)?\"Yes\":\"No\")<<'\\n';\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include\
    \ \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\nconst int INF=1e9;\nconst ll\
    \ INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------\n\
    #include \"Modint/montgomery_multiplication.hpp\"\nbool isPrime(u64 x) {\n   \
    \ if (x < 64) {\n        return (u64(1) << x) & 0x28208a20a08a28ac;\n    }\n \
    \   if (x % 2 == 0) {\n        return false;\n    }\n    \n    Montgomery_u64\
    \ m;\n    m.set(x);\n    \n    const int k = __builtin_ctzll(x - 1);\n    const\
    \ u64 d = (x - 1) >> k, IV = m.ni, R = m.r1, R2 = m.r2, nR = m.min(R);\n    \n\
    \    auto mr7 = [&](u64 t1, u64 t2, u64 t3, u64 t4, u64 t5, u64 t6, u64 t7) {\n\
    \        u64 r1 = R, r2 = R, r3 = R, r4 = R, r5 = R, r6 = R, r7 = R;\n       \
    \ t1 = mul_m64(&m, t1, R2), t2 = mul_m64(&m, t2, R2), t3 = mul_m64(&m, t3, R2);\n\
    \        t4 = mul_m64(&m, t4, R2), t5 = mul_m64(&m, t5, R2), t6 = mul_m64(&m,\
    \ t6, R2), t7 = mul_m64(&m, t7, R2);\n        for (u64 b = d; b; b >>= 1) {\n\
    \            if (b & 1) {\n                r1 = mul_m64(&m, r1, t1), r2 = mul_m64(&m,\
    \ r2, t2), r3 = mul_m64(&m, r3, t3);\n                r4 = mul_m64(&m, r4, t4),\
    \ r5 = mul_m64(&m, r5, t5), r6 = mul_m64(&m, r6, t6), r7 = mul_m64(&m, r7, t7);\n\
    \            }\n            t1 = mul_m64(&m, t1, t1), t2 = mul_m64(&m, t2, t2),\
    \ t3 = mul_m64(&m, t3, t3);\n            t4 = mul_m64(&m, t4, t4), t5 = mul_m64(&m,\
    \ t5, t5), t6 = mul_m64(&m, t6, t6), t7 = mul_m64(&m, t7, t7);\n        }\n  \
    \      r1 = min(r1, m.sub(r1,x)), r2 = min(r2, m.sub(r2,x)), r3 = min(r3, m.sub(r3,x));\n\
    \        r4 = min(r4, m.sub(r4,x)), r5 = min(r5, m.sub(r5,x)), r6 = min(r6, m.sub(r6,x)),\
    \ r7 = min(r7, m.sub(r7,x));\n        int res1 = (r1 == R) | (r1 == nR), res2\
    \ = (r2 == R) | (r2 == nR), res3 = (r3 == R) | (r3 == nR);\n        int res4 =\
    \ (r4 == R) | (r4 == nR), res5 = (r5 == R) | (r5 == nR), res6 = (r6 == R) | (r6\
    \ == nR), res7 = (r7 == R) | (r7 == nR);\n        for (int j = 0; j < k - 1; ++j)\
    \ {\n            r1 = mul_m64(&m, r1, r1), r2 = mul_m64(&m, r2, r2), r3 = mul_m64(&m,\
    \ r3, r3);\n            r4 = mul_m64(&m, r4, r4), r5 = mul_m64(&m, r5, r5), r6\
    \ = mul_m64(&m, r6, r6), r7 = mul_m64(&m, r7, r7);\n            res1 |= (min(r1,\
    \ m.sub(r1,x)) == nR), res2 |= (min(r2, m.sub(r2,x)) == nR), res3 |= (min(r3,\
    \ m.sub(r3,x)) == nR);\n            res4 |= (min(r4, m.sub(r4,x)) == nR), res5\
    \ |= (min(r5, m.sub(r5,x)) == nR), res6 |= (min(r6, m.sub(r6,x)) == nR), res7\
    \ |= (min(r7, m.sub(r7,x)) == nR);\n        }\n        return res1 & res2 & res3\
    \ & res4 & res5 & res6 & res7;\n    };\n    if (x == 2 || x == 3 || x == 5 ||\
    \ x == 13 || x == 19 || x == 73 || x == 193 || x == 407521 || x == 299210837)\
    \ {\n        return true;\n    }\n    return mr7(2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022);\n}\n\nint main() {\n    int t; cin>>t;\n    while(t--){\n\
    \      u64 n; cin>>n;\n      cout<<(isPrime(n)?\"Yes\":\"No\")<<'\\n';\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - Modint/montgomery_multiplication.hpp
  isVerificationFile: true
  path: test/yosupo/Math/montgomery_multiplication.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 14:27:49+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/montgomery_multiplication.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/montgomery_multiplication.test.cpp
- /verify/test/yosupo/Math/montgomery_multiplication.test.cpp.html
title: test/yosupo/Math/montgomery_multiplication.test.cpp
---
