#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "tree/Tree_diameter.hpp"
int main() {
  FT;
  int n; cin>>n;
  tree_diameter<ll>tre(n);
  rep(i,n-1){
     ll a,b,c; cin>>a>>b>>c;
     tre.add_edge(a,b,c,true);
  }
  auto [wei,pat]=tre.get_diameter();
  cout<<wei<<" "<<pat.size()<<'\n';
  rep(i,pat.size()){
     cout<<pat[i]<<" ";
  }
  cout<<'\n';
    return 0;
}
