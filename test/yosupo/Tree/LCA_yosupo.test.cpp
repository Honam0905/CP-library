#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "tree/LCA_segtree.hpp"
int main() {
 int n,q,x; cin>>n>>q;
 vvc<int>adj(n); 
 For(i,1,n){
    cin>>x;
    adj[x].push_back(i);
 }
 LCA lca(adj);
 for(;q--;){
    int u,v; cin>>u>>v;
    cout<<lca.lca(u,v)<<'\n';
 }
    return 0;
}
