---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: primitive_root_yosupo.test.cpp
    title: primitive_root_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aizu/1_seg_tree.test.cpp
    title: test/aizu/1_seg_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aizu/2_segment_tree.test.cpp
    title: test/aizu/2_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aizu/disjointset.test.cpp
    title: test/aizu/disjointset.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aizu/pow_aizu.test.cpp
    title: test/aizu/pow_aizu.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Ds/PARS_yosupo.test.cpp
    title: test/yosupo/Ds/PARS_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Ds/RMQ_yosupo.test.cpp
    title: test/yosupo/Ds/RMQ_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Ds/unionfind_yosupo.test.cpp
    title: test/yosupo/Ds/unionfind_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/MST_yosupo.test.cpp
    title: test/yosupo/Graph/MST_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/BC_prime_mod.test.cpp
    title: test/yosupo/Math/BC_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_1.test.cpp
    title: test/yosupo/Math/enum_prime_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_2.test.cpp
    title: test/yosupo/Math/enum_prime_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_3.test.cpp
    title: test/yosupo/Math/enum_prime_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_4.test.cpp
    title: test/yosupo/Math/enum_prime_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/enum_prime_5.test.cpp
    title: test/yosupo/Math/enum_prime_5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
    title: test/yosupo/Math/mod_sqrt_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/prime_test_yosupo.test.cpp
    title: test/yosupo/Math/prime_test_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/LCA_yosupo.test.cpp
    title: test/yosupo/Tree/LCA_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/LCA_yosupo_2.test.cpp
    title: test/yosupo/Tree/LCA_yosupo_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/tree_diameter_yosupo.test.cpp
    title: test/yosupo/Tree/tree_diameter_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/Zalgorithm.test.cpp
    title: test/yosupo/string/Zalgorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "Misc/debug.hpp"

    void __print(int x) {cerr << x;}

    void __print(long x) {cerr << x;}

    void __print(long long x) {cerr << x;}

    void __print(unsigned x) {cerr << x;}

    void __print(unsigned long x) {cerr << x;}

    void __print(unsigned long long x) {cerr << x;}

    void __print(float x) {cerr << x;}

    void __print(double x) {cerr << x;}

    void __print(long double x) {cerr << x;}

    void __print(char x) {cerr << ''\'''' << x << ''\'''';}

    void __print(const char *x) {cerr << ''\"'' << x << ''\"'';}

    void __print(const string &x) {cerr << ''\"'' << x << ''\"'';}

    void __print(bool x) {cerr << (x ? "true" : "false");}


    template<typename T, typename V>

    void __print(const pair<T, V> &x) {cerr << ''{''; __print(x.first); cerr << ",
    "; __print(x.second); cerr << ''}'';}

    template<typename T>

    void __print(const T &x) {int f = 0; cerr << ''{''; for (auto &i: x) cerr << (f++
    ? ", " : ""), __print(i); cerr << "}";}

    template<>

    void __print(const vector<bool> &x) {int f = 0; cerr << ''{''; for (size_t i =
    0; i < x.size(); ++i) cerr << (f++ ? ", " : ""), __print(x[i]); cerr << "}";}

    void _print() {cerr << "]\n";}

    template <typename T, typename... V>

    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


    void dbg_out() { cerr << endl; }

    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { __print(H);
    if (sizeof...(T)) cerr << ", "; dbg_out(T...); }

    #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:"; dbg_out(__VA_ARGS__);

    '
  code: 'void __print(int x) {cerr << x;}

    void __print(long x) {cerr << x;}

    void __print(long long x) {cerr << x;}

    void __print(unsigned x) {cerr << x;}

    void __print(unsigned long x) {cerr << x;}

    void __print(unsigned long long x) {cerr << x;}

    void __print(float x) {cerr << x;}

    void __print(double x) {cerr << x;}

    void __print(long double x) {cerr << x;}

    void __print(char x) {cerr << ''\'''' << x << ''\'''';}

    void __print(const char *x) {cerr << ''\"'' << x << ''\"'';}

    void __print(const string &x) {cerr << ''\"'' << x << ''\"'';}

    void __print(bool x) {cerr << (x ? "true" : "false");}


    template<typename T, typename V>

    void __print(const pair<T, V> &x) {cerr << ''{''; __print(x.first); cerr << ",
    "; __print(x.second); cerr << ''}'';}

    template<typename T>

    void __print(const T &x) {int f = 0; cerr << ''{''; for (auto &i: x) cerr << (f++
    ? ", " : ""), __print(i); cerr << "}";}

    template<>

    void __print(const vector<bool> &x) {int f = 0; cerr << ''{''; for (size_t i =
    0; i < x.size(); ++i) cerr << (f++ ? ", " : ""), __print(x[i]); cerr << "}";}

    void _print() {cerr << "]\n";}

    template <typename T, typename... V>

    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


    void dbg_out() { cerr << endl; }

    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { __print(H);
    if (sizeof...(T)) cerr << ", "; dbg_out(T...); }

    #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:"; dbg_out(__VA_ARGS__);

    '
  dependsOn: []
  isVerificationFile: false
  path: Misc/debug.hpp
  requiredBy: []
  timestamp: '2024-05-13 12:48:47+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aizu/2_segment_tree.test.cpp
  - test/aizu/disjointset.test.cpp
  - test/aizu/1_seg_tree.test.cpp
  - test/aizu/pow_aizu.test.cpp
  - test/yosupo/Ds/unionfind_yosupo.test.cpp
  - test/yosupo/Ds/RMQ_yosupo.test.cpp
  - test/yosupo/Ds/PARS_yosupo.test.cpp
  - test/yosupo/string/Zalgorithm.test.cpp
  - test/yosupo/Graph/MST_yosupo.test.cpp
  - test/yosupo/Math/enum_prime_5.test.cpp
  - test/yosupo/Math/enum_prime_2.test.cpp
  - test/yosupo/Math/enum_prime_1.test.cpp
  - test/yosupo/Math/enum_prime_4.test.cpp
  - test/yosupo/Math/prime_test_yosupo.test.cpp
  - test/yosupo/Math/mod_sqrt_yosupo.test.cpp
  - test/yosupo/Math/enum_prime_3.test.cpp
  - test/yosupo/Math/BC_prime_mod.test.cpp
  - test/yosupo/Tree/tree_diameter_yosupo.test.cpp
  - test/yosupo/Tree/LCA_yosupo_2.test.cpp
  - test/yosupo/Tree/LCA_yosupo.test.cpp
  - primitive_root_yosupo.test.cpp
documentation_of: Misc/debug.hpp
layout: document
redirect_from:
- /library/Misc/debug.hpp
- /library/Misc/debug.hpp.html
title: Misc/debug.hpp
---
