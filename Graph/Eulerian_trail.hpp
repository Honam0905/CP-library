#pragma once
template<typename T,bool directed>
struct eulerian_trail {
    int n, m, E, ptr = 0;
    vector<int>head, link, to, eid, it_prev, it_cur;
    vector<bool>used;
    vector<T>path;
    vector<int>edge_path;

    eulerian_trail(int _n, int _m) : n(_n), m(_m) {
        E = directed ? m : 2*m;
        head.assign(n, 0);
        link.assign(E+1, 0);
        to.assign(E+1, 0);
        eid.assign(E+1, 0);
        used.assign(m, false);
        it_prev.assign(n, 0);
        it_cur.assign(n, 0);
    }

    void add_edge(int u, int v, int id) {
        auto ins = [&](int U, int V, int EID){
            int idx = ++ptr;
            to[idx] = V;
            eid[idx] = EID;
            int old = head[U];
            link[idx] = 0 ^ old;
            if(old) link[old] ^= 0 ^ idx;
            head[U] = idx;
        };
        if constexpr(directed) ins(u, v, id);
        else { ins(u, v, id); ins(v, u, id); }
    }

    bool is_eulerian() {
        if constexpr(directed) {
            int start=0, end=0;
            vector<int>in(n,0), out(n,0);
            for(int u=0; u<n; u++){
                int prev=0, cur=head[u];
                while(cur){
                    out[u]++; in[to[cur]]++;
                    int nxt = prev ^ link[cur];
                    prev = cur; cur = nxt;
                }
            }
            for(int i=0;i<n;i++){
                int d = out[i] - in[i];
                if(d==1) start++;
                else if(d==-1) end++;
                else if(d!=0) return false;
            }
            return (start==1&&end==1) || (start==0&&end==0);
        } else {
            int odd=0;
            for(int u=0;u<n;u++){
                int deg=0, prev=0, cur=head[u];
                while(cur){
                    deg++;
                    int nxt = prev ^ link[cur];
                    prev = cur; cur = nxt;
                }
                if(deg%2) odd++;
                if(odd>2) return false;
            }
            return odd==0 || odd==2;
        }
    }

    T find_start() {
        if constexpr(directed) {
            vector<int>in(n,0), out(n,0);
            for(int u=0;u<n;u++){
                int prev=0, cur=head[u];
                while(cur){
                    out[u]++; in[to[cur]]++;
                    int nxt=prev^link[cur];
                    prev=cur; cur=nxt;
                }
            }
            for(int i=0;i<n;i++)
                if(out[i]-in[i]==1) return i;
            for(int i=0;i<n;i++)
                if(out[i]>0) return i;
            return 0;
        } else {
            for(int u=0;u<n;u++){
                int deg=0, prev=0, cur=head[u];
                while(cur){
                    deg++;
                    int nxt=prev^link[cur];
                    prev=cur; cur=nxt;
                }
                if(deg%2==1) return u;
            }
            for(int u=0;u<n;u++)
                if(head[u]!=0) return u;
            return 0;
        }
    }

    bool get_trail(){
        if(!is_eulerian()) return false;
        for(int u=0;u<n;u++){
            it_prev[u]=0;
            it_cur[u]=head[u];
        }
        stack<pair<T,int>>st;
        st.emplace(find_start(), -1);
        while(!st.empty()){
            auto [u, in_eid]=st.top();
            int &prev=it_prev[u];
            int &cur=it_cur[u];
            while(cur){
                int idx=cur;
                int nxt=prev^link[idx];
                prev=idx;
                cur=nxt;
                int e=eid[idx];
                if(!used[e]){
                    used[e]=true;
                    st.emplace(to[idx], e);
                    goto CONTINUE;
                }
            }
            path.push_back(u);
            edge_path.push_back(in_eid);
            st.pop();
            CONTINUE: ;
        }
        if((int)path.size()!=m+1)
            return false;
        reverse(path.begin(),path.end());
        reverse(edge_path.begin(),edge_path.end());
        return true;
    }
};
