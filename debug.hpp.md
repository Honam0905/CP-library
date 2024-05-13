---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"debug.hpp\"\nvoid __print(int x) {cerr << x;}\nvoid __print(long\
    \ x) {cerr << x;}\nvoid __print(long long x) {cerr << x;}\nvoid __print(unsigned\
    \ x) {cerr << x;}\nvoid __print(unsigned long x) {cerr << x;}\nvoid __print(unsigned\
    \ long long x) {cerr << x;}\nvoid __print(float x) {cerr << x;}\nvoid __print(double\
    \ x) {cerr << x;}\nvoid __print(long double x) {cerr << x;}\nvoid __print(char\
    \ x) {cerr << '\\'' << x << '\\'';}\nvoid __print(const char *x) {cerr << '\\\"\
    ' << x << '\\\"';}\nvoid __print(const string &x) {cerr << '\\\"' << x << '\\\"\
    ';}\nvoid __print(bool x) {cerr << (x ? \"true\" : \"false\");}\n \ntemplate<typename\
    \ T, typename V>\nvoid __print(const pair<T, V> &x) {cerr << '{'; __print(x.first);\
    \ cerr << \", \"; __print(x.second); cerr << '}';}\ntemplate<typename T>\nvoid\
    \ __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ?\
    \ \", \" : \"\"), __print(i); cerr << \"}\";}\nvoid _print() {cerr << \"]\\n\"\
    ;}\ntemplate <typename T, typename... V>\nvoid _print(T t, V... v) {__print(t);\
    \ if (sizeof...(v)) cerr << \", \"; _print(v...);}\n \nvoid dbg_out() { cerr <<\
    \ endl; }\ntemplate<typename Head, typename... Tail> void dbg_out(Head H, Tail...\
    \ T) { __print(H); if (sizeof...(T)) cerr << \", \"; dbg_out(T...); }\n#define\
    \ dbg(...) cerr << \"[\" << #__VA_ARGS__ << \"]:\"; dbg_out(__VA_ARGS__);\n"
  code: "#pragma once\nvoid __print(int x) {cerr << x;}\nvoid __print(long x) {cerr\
    \ << x;}\nvoid __print(long long x) {cerr << x;}\nvoid __print(unsigned x) {cerr\
    \ << x;}\nvoid __print(unsigned long x) {cerr << x;}\nvoid __print(unsigned long\
    \ long x) {cerr << x;}\nvoid __print(float x) {cerr << x;}\nvoid __print(double\
    \ x) {cerr << x;}\nvoid __print(long double x) {cerr << x;}\nvoid __print(char\
    \ x) {cerr << '\\'' << x << '\\'';}\nvoid __print(const char *x) {cerr << '\\\"\
    ' << x << '\\\"';}\nvoid __print(const string &x) {cerr << '\\\"' << x << '\\\"\
    ';}\nvoid __print(bool x) {cerr << (x ? \"true\" : \"false\");}\n \ntemplate<typename\
    \ T, typename V>\nvoid __print(const pair<T, V> &x) {cerr << '{'; __print(x.first);\
    \ cerr << \", \"; __print(x.second); cerr << '}';}\ntemplate<typename T>\nvoid\
    \ __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ?\
    \ \", \" : \"\"), __print(i); cerr << \"}\";}\nvoid _print() {cerr << \"]\\n\"\
    ;}\ntemplate <typename T, typename... V>\nvoid _print(T t, V... v) {__print(t);\
    \ if (sizeof...(v)) cerr << \", \"; _print(v...);}\n \nvoid dbg_out() { cerr <<\
    \ endl; }\ntemplate<typename Head, typename... Tail> void dbg_out(Head H, Tail...\
    \ T) { __print(H); if (sizeof...(T)) cerr << \", \"; dbg_out(T...); }\n#define\
    \ dbg(...) cerr << \"[\" << #__VA_ARGS__ << \"]:\"; dbg_out(__VA_ARGS__);\n"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2024-05-13 08:03:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
