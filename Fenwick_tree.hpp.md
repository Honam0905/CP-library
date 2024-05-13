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
  bundledCode: "#line 2 \"Fenwick_tree.hpp\"\nstruct Fenwick{\n\tvector<ll> s;\n \
    \   int n;\n\tFenwick(int n) : n(n),s(n+1,0) {}\n\tvoid update(int pos, ll dif)\
    \ {\n        for (; pos <= n; pos += pos & -pos) s[pos] += dif;\n    }\n    ll\
    \ query(int pos) {\n        ll res = 0;\n        for (; pos > 0; pos -= pos &\
    \ -pos) res += s[pos];\n        return res;\n    }\n    ll prefix(int l,int r){\n\
    \         if(l==r) return 0;\n         return query(r)-query(l);\n    }\n\tint\
    \ lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum\n\t\t// Returns n\
    \ if no sum is >= sum, or -1 if empty sum is.\n\t\tif (sum <= 0) return -1;\n\t\
    \tint pos = 0;\n\t\tfor (int pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw\
    \ <= s.size() && s[pos + pw-1] < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\t\
    \t}\n\t\treturn pos;\n\t}\n};\n"
  code: "#pragma once\nstruct Fenwick{\n\tvector<ll> s;\n    int n;\n\tFenwick(int\
    \ n) : n(n),s(n+1,0) {}\n\tvoid update(int pos, ll dif) {\n        for (; pos\
    \ <= n; pos += pos & -pos) s[pos] += dif;\n    }\n    ll query(int pos) {\n  \
    \      ll res = 0;\n        for (; pos > 0; pos -= pos & -pos) res += s[pos];\n\
    \        return res;\n    }\n    ll prefix(int l,int r){\n         if(l==r) return\
    \ 0;\n         return query(r)-query(l);\n    }\n\tint lower_bound(ll sum) {//\
    \ min pos st sum of [0, pos] >= sum\n\t\t// Returns n if no sum is >= sum, or\
    \ -1 if empty sum is.\n\t\tif (sum <= 0) return -1;\n\t\tint pos = 0;\n\t\tfor\
    \ (int pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw <= s.size() && s[pos\
    \ + pw-1] < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\t\t}\n\t\treturn pos;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Fenwick_tree.hpp
  requiredBy: []
  timestamp: '2024-05-13 12:09:00+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Fenwick_tree.hpp
layout: document
redirect_from:
- /library/Fenwick_tree.hpp
- /library/Fenwick_tree.hpp.html
title: Fenwick_tree.hpp
---
