#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "NT/prime/factorize.hpp"

int main() {
    int t; cin>>t;
    while(t--){
    u64 n; cin>>n;
    auto fac=factor(n);
    sort(all(fac));
    cout<<fac.size()<<" ";
    for(auto x:fac){
     cout<<x<<" ";
    }
     cout<<'\n';
    }
    return 0;
}
