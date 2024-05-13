---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/RMQ_yosupo.test.cpp
    title: yosupo/RMQ_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DS/Sparse_table.hpp\"\n/**\n * Author: Johan Sannemo, pajenegod\n\
    \ * Date: 2015-02-06\n * License: CC0\n * Source: Folklore\n * Description: Range\
    \ Minimum Queries on an array. Returns\n * min(V[a], V[a + 1], ... V[b - 1]) in\
    \ constant time.\n * Usage:\n *  RMQ rmq(values);\n *  rmq.query(inclusive, exclusive);\n\
    \ * Time: $O(|V| \\log |V| + Q)$\n * Status: stress-tested\n */\n\ntemplate<class\
    \ T>\nstruct sparsetable {\n\tvector<vector<T>> jmp;\n\tsparsetable(const vector<T>&\
    \ V) : jmp(1, V) {\n\t\tfor (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k)\
    \ {\n\t\t\tjmp.emplace_back(V.size() - pw * 2 + 1);\n\t\t\trep(j,jmp[k].size())\n\
    \t\t\t\tjmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);\n\t\t}\n\t}\n\tT query(int\
    \ a, int b) {\n\t\tassert(a < b); // or return inf if a == b\n\t\tint dep = 31\
    \ - __builtin_clz(b - a);\n\t\treturn min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\
    \t}\n};\n"
  code: "#pragma once\n/**\n * Author: Johan Sannemo, pajenegod\n * Date: 2015-02-06\n\
    \ * License: CC0\n * Source: Folklore\n * Description: Range Minimum Queries on\
    \ an array. Returns\n * min(V[a], V[a + 1], ... V[b - 1]) in constant time.\n\
    \ * Usage:\n *  RMQ rmq(values);\n *  rmq.query(inclusive, exclusive);\n * Time:\
    \ $O(|V| \\log |V| + Q)$\n * Status: stress-tested\n */\n\ntemplate<class T>\n\
    struct sparsetable {\n\tvector<vector<T>> jmp;\n\tsparsetable(const vector<T>&\
    \ V) : jmp(1, V) {\n\t\tfor (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k)\
    \ {\n\t\t\tjmp.emplace_back(V.size() - pw * 2 + 1);\n\t\t\trep(j,jmp[k].size())\n\
    \t\t\t\tjmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);\n\t\t}\n\t}\n\tT query(int\
    \ a, int b) {\n\t\tassert(a < b); // or return inf if a == b\n\t\tint dep = 31\
    \ - __builtin_clz(b - a);\n\t\treturn min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DS/Sparse_table.hpp
  requiredBy: []
  timestamp: '2024-05-13 21:55:17+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/RMQ_yosupo.test.cpp
documentation_of: DS/Sparse_table.hpp
layout: document
redirect_from:
- /library/DS/Sparse_table.hpp
- /library/DS/Sparse_table.hpp.html
title: DS/Sparse_table.hpp
---
