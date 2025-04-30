---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/Eulerian_trail_yosupo.test.cpp
    title: test/yosupo/Graph/Eulerian_trail_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Eulerian_trail (directed).hpp\"\ntemplate<typename\
    \ T,bool directed>\nstruct eulerian_trail {\n    int n, m, E, ptr = 0;\n    vector<int>head,\
    \ link, to, eid, it_prev, it_cur;\n    vector<bool>used;\n    vector<T>path;\n\
    \    vector<int>edge_path;\n\n    eulerian_trail(int _n, int _m) : n(_n), m(_m)\
    \ {\n        E = directed ? m : 2*m;\n        head.assign(n, 0);\n        link.assign(E+1,\
    \ 0);\n        to.assign(E+1, 0);\n        eid.assign(E+1, 0);\n        used.assign(m,\
    \ false);\n        it_prev.assign(n, 0);\n        it_cur.assign(n, 0);\n    }\n\
    \n    void add_edge(int u, int v, int id) {\n        auto ins = [&](int U, int\
    \ V, int EID){\n            int idx = ++ptr;\n            to[idx] = V;\n     \
    \       eid[idx] = EID;\n            int old = head[U];\n            link[idx]\
    \ = 0 ^ old;\n            if(old) link[old] ^= 0 ^ idx;\n            head[U] =\
    \ idx;\n        };\n        if constexpr(directed) ins(u, v, id);\n        else\
    \ { ins(u, v, id); ins(v, u, id); }\n    }\n\n    bool is_eulerian() {\n     \
    \   if constexpr(directed) {\n            int start=0, end=0;\n            vector<int>in(n,0),\
    \ out(n,0);\n            for(int u=0; u<n; u++){\n                int prev=0,\
    \ cur=head[u];\n                while(cur){\n                    out[u]++; in[to[cur]]++;\n\
    \                    int nxt = prev ^ link[cur];\n                    prev = cur;\
    \ cur = nxt;\n                }\n            }\n            for(int i=0;i<n;i++){\n\
    \                int d = out[i] - in[i];\n                if(d==1) start++;\n\
    \                else if(d==-1) end++;\n                else if(d!=0) return false;\n\
    \            }\n            return (start==1&&end==1) || (start==0&&end==0);\n\
    \        } else {\n            int odd=0;\n            for(int u=0;u<n;u++){\n\
    \                int deg=0, prev=0, cur=head[u];\n                while(cur){\n\
    \                    deg++;\n                    int nxt = prev ^ link[cur];\n\
    \                    prev = cur; cur = nxt;\n                }\n             \
    \   if(deg%2) odd++;\n                if(odd>2) return false;\n            }\n\
    \            return odd==0 || odd==2;\n        }\n    }\n\n    T find_start()\
    \ {\n        if constexpr(directed) {\n            vector<int>in(n,0), out(n,0);\n\
    \            for(int u=0;u<n;u++){\n                int prev=0, cur=head[u];\n\
    \                while(cur){\n                    out[u]++; in[to[cur]]++;\n \
    \                   int nxt=prev^link[cur];\n                    prev=cur; cur=nxt;\n\
    \                }\n            }\n            for(int i=0;i<n;i++)\n        \
    \        if(out[i]-in[i]==1) return i;\n            for(int i=0;i<n;i++)\n   \
    \             if(out[i]>0) return i;\n            return 0;\n        } else {\n\
    \            for(int u=0;u<n;u++){\n                int deg=0, prev=0, cur=head[u];\n\
    \                while(cur){\n                    deg++;\n                   \
    \ int nxt=prev^link[cur];\n                    prev=cur; cur=nxt;\n          \
    \      }\n                if(deg%2==1) return u;\n            }\n            for(int\
    \ u=0;u<n;u++)\n                if(head[u]!=0) return u;\n            return 0;\n\
    \        }\n    }\n\n    bool get_trail(){\n        if(!is_eulerian()) return\
    \ false;\n        for(int u=0;u<n;u++){\n            it_prev[u]=0;\n         \
    \   it_cur[u]=head[u];\n        }\n        stack<pair<T,int>>st;\n        st.emplace(find_start(),\
    \ -1);\n        while(!st.empty()){\n            auto [u, in_eid]=st.top();\n\
    \            int &prev=it_prev[u];\n            int &cur=it_cur[u];\n        \
    \    while(cur){\n                int idx=cur;\n                int nxt=prev^link[idx];\n\
    \                prev=idx;\n                cur=nxt;\n                int e=eid[idx];\n\
    \                if(!used[e]){\n                    used[e]=true;\n          \
    \          st.emplace(to[idx], e);\n                    goto CONTINUE;\n     \
    \           }\n            }\n            path.push_back(u);\n            edge_path.push_back(in_eid);\n\
    \            st.pop();\n            CONTINUE: ;\n        }\n        if((int)path.size()!=m+1)\n\
    \            return false;\n        reverse(path.begin(),path.end());\n      \
    \  reverse(edge_path.begin(),edge_path.end());\n        return true;\n    }\n\
    };\n"
  code: "#pragma once\ntemplate<typename T,bool directed>\nstruct eulerian_trail {\n\
    \    int n, m, E, ptr = 0;\n    vector<int>head, link, to, eid, it_prev, it_cur;\n\
    \    vector<bool>used;\n    vector<T>path;\n    vector<int>edge_path;\n\n    eulerian_trail(int\
    \ _n, int _m) : n(_n), m(_m) {\n        E = directed ? m : 2*m;\n        head.assign(n,\
    \ 0);\n        link.assign(E+1, 0);\n        to.assign(E+1, 0);\n        eid.assign(E+1,\
    \ 0);\n        used.assign(m, false);\n        it_prev.assign(n, 0);\n       \
    \ it_cur.assign(n, 0);\n    }\n\n    void add_edge(int u, int v, int id) {\n \
    \       auto ins = [&](int U, int V, int EID){\n            int idx = ++ptr;\n\
    \            to[idx] = V;\n            eid[idx] = EID;\n            int old =\
    \ head[U];\n            link[idx] = 0 ^ old;\n            if(old) link[old] ^=\
    \ 0 ^ idx;\n            head[U] = idx;\n        };\n        if constexpr(directed)\
    \ ins(u, v, id);\n        else { ins(u, v, id); ins(v, u, id); }\n    }\n\n  \
    \  bool is_eulerian() {\n        if constexpr(directed) {\n            int start=0,\
    \ end=0;\n            vector<int>in(n,0), out(n,0);\n            for(int u=0;\
    \ u<n; u++){\n                int prev=0, cur=head[u];\n                while(cur){\n\
    \                    out[u]++; in[to[cur]]++;\n                    int nxt = prev\
    \ ^ link[cur];\n                    prev = cur; cur = nxt;\n                }\n\
    \            }\n            for(int i=0;i<n;i++){\n                int d = out[i]\
    \ - in[i];\n                if(d==1) start++;\n                else if(d==-1)\
    \ end++;\n                else if(d!=0) return false;\n            }\n       \
    \     return (start==1&&end==1) || (start==0&&end==0);\n        } else {\n   \
    \         int odd=0;\n            for(int u=0;u<n;u++){\n                int deg=0,\
    \ prev=0, cur=head[u];\n                while(cur){\n                    deg++;\n\
    \                    int nxt = prev ^ link[cur];\n                    prev = cur;\
    \ cur = nxt;\n                }\n                if(deg%2) odd++;\n          \
    \      if(odd>2) return false;\n            }\n            return odd==0 || odd==2;\n\
    \        }\n    }\n\n    T find_start() {\n        if constexpr(directed) {\n\
    \            vector<int>in(n,0), out(n,0);\n            for(int u=0;u<n;u++){\n\
    \                int prev=0, cur=head[u];\n                while(cur){\n     \
    \               out[u]++; in[to[cur]]++;\n                    int nxt=prev^link[cur];\n\
    \                    prev=cur; cur=nxt;\n                }\n            }\n  \
    \          for(int i=0;i<n;i++)\n                if(out[i]-in[i]==1) return i;\n\
    \            for(int i=0;i<n;i++)\n                if(out[i]>0) return i;\n  \
    \          return 0;\n        } else {\n            for(int u=0;u<n;u++){\n  \
    \              int deg=0, prev=0, cur=head[u];\n                while(cur){\n\
    \                    deg++;\n                    int nxt=prev^link[cur];\n   \
    \                 prev=cur; cur=nxt;\n                }\n                if(deg%2==1)\
    \ return u;\n            }\n            for(int u=0;u<n;u++)\n               \
    \ if(head[u]!=0) return u;\n            return 0;\n        }\n    }\n\n    bool\
    \ get_trail(){\n        if(!is_eulerian()) return false;\n        for(int u=0;u<n;u++){\n\
    \            it_prev[u]=0;\n            it_cur[u]=head[u];\n        }\n      \
    \  stack<pair<T,int>>st;\n        st.emplace(find_start(), -1);\n        while(!st.empty()){\n\
    \            auto [u, in_eid]=st.top();\n            int &prev=it_prev[u];\n \
    \           int &cur=it_cur[u];\n            while(cur){\n                int\
    \ idx=cur;\n                int nxt=prev^link[idx];\n                prev=idx;\n\
    \                cur=nxt;\n                int e=eid[idx];\n                if(!used[e]){\n\
    \                    used[e]=true;\n                    st.emplace(to[idx], e);\n\
    \                    goto CONTINUE;\n                }\n            }\n      \
    \      path.push_back(u);\n            edge_path.push_back(in_eid);\n        \
    \    st.pop();\n            CONTINUE: ;\n        }\n        if((int)path.size()!=m+1)\n\
    \            return false;\n        reverse(path.begin(),path.end());\n      \
    \  reverse(edge_path.begin(),edge_path.end());\n        return true;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Eulerian_trail (directed).hpp
  requiredBy: []
  timestamp: '2025-04-30 09:00:15+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Graph/Eulerian_trail_yosupo.test.cpp
documentation_of: Graph/Eulerian_trail (directed).hpp
layout: document
redirect_from:
- /library/Graph/Eulerian_trail (directed).hpp
- /library/Graph/Eulerian_trail (directed).hpp.html
title: Graph/Eulerian_trail (directed).hpp
---
