---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: test/yosupo/Ds/PARS_yosupo.test.cpp
    title: test/yosupo/Ds/PARS_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Ds/RMQ_yosupo.test.cpp
    title: test/yosupo/Ds/RMQ_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Ds/unionfind_yosupo.test.cpp
    title: test/yosupo/Ds/unionfind_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/LCA_yosupo.test.cpp
    title: test/yosupo/LCA_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/MST_yosupo.test.cpp
    title: test/yosupo/MST_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter_yosupo.test.cpp
    title: test/yosupo/tree_diameter_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aizu/2_segment_tree.test.cpp
  - test/aizu/disjointset.test.cpp
  - test/aizu/1_seg_tree.test.cpp
  - test/yosupo/Ds/unionfind_yosupo.test.cpp
  - test/yosupo/Ds/RMQ_yosupo.test.cpp
  - test/yosupo/Ds/PARS_yosupo.test.cpp
  - test/yosupo/tree_diameter_yosupo.test.cpp
  - test/yosupo/MST_yosupo.test.cpp
  - test/yosupo/LCA_yosupo.test.cpp
documentation_of: Misc/debug.hpp
layout: document
redirect_from:
- /library/Misc/debug.hpp
- /library/Misc/debug.hpp.html
title: Misc/debug.hpp
---
