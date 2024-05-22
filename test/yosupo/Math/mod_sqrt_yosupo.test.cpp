#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "Mod/mod_sqrt.hpp"

int main() {
    int t; cin>>t;
    while(t--){
       ll a,b; cin>>a>>b;
       cout<<mod_sqrt(a,b)<<'\n';
    } 
    return 0;
}
