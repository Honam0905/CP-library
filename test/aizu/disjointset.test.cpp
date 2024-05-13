#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "DS/DSU.hpp"
int n,q,tt,u,v;
int main(){
FT;
   cin>>n>>q;
   DSU d;
   d.init(n);
   while(q--){
     cin>>tt>>u>>v;
     if(tt==0){
         d.unite(u,v);
     }if(tt==1){
        cout<<d.same(u,v)<<'\n';
     }
   }
   return 0;
}
