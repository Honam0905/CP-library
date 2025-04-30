#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "Graph/Eulerian_trail (directed).hpp"
int main(){
  int t; cin>>t;
  while(t--){
    int n,m; cin>>n>>m;
    eulerian_trail<int,false>et(n,m);
    rep(i,m){
        int u,v; cin>>u>>v;
        et.add_edge(u,v,i);
    }
     if(!et.get_trail()){
        cout<<"No"<<'\n';
     }else{
        cout<<"Yes"<<'\n';
        rep(i,(int)et.path.size()){
            cout<<et.path[i]<<(i+1<(int)et.path.size()?' ':'\n');
        }
        if(m==0){
            cout<<'\n';
        }else{
            For(i,1,(int)et.edge_path.size()){
                cout<<et.edge_path[i]<<(i+1<(int)et.edge_path.size()?' ':'\n');
            }
        }
     }
   }
}
