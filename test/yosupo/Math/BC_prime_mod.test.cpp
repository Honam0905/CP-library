#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "Modint/dynamic_modint.hpp"
#include "NT/Combinatorics/Comb_common.hpp"
using mint=modint;
int main() {
    ll tt,m; cin>>tt>>m;
    mint::set_mod(m);
    Comb<mint>com;
    while(tt--){
        ll n,k; cin>>n>>k;
        cout<<com.binom(n,k).get()<<'\n';
    }
    return 0;
}
