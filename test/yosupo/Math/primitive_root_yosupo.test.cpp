#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "Mod/Primitive_root.hpp"
int main() {
    FT;
    u64 t; cin>>t;
    while(t--){
      u64 n; cin>>n;
      cout<<primitive_root(n)<<"\n";
    } 
}
