#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "DS/DSU.hpp"
int main() {
  FT;
   int n,q; cin>>n>>q;
   DSU uf;
   uf.init(n);
   while(q--){
      int op,a,b; cin>>op>>a>>b;
      if(op==0){
        uf.unite(a,b);
      }else if(op==1){
        cout<<uf.same(a,b)<<'\n';
      }
   }
   return 0;
}
