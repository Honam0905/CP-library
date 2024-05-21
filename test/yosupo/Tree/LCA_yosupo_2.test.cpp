#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#define sz(a) ((int) (a).size())
#include "DS/Sparse_table.hpp"
#include "tree/LCA_kactl.hpp"

int main() {
    int n,q,u,v,x; cin>>n>>q;
    vvc<int>g(n);
    For(i,1,n){
        cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    LCA lca(g);
    while(q--){
        cin>>u>>v;
        cout<<lca.lca(u,v)<<'\n';
    }
    return 0;
}
