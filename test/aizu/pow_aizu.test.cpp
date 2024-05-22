#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "Modint/montgomery_modint.hpp"
using mint=modint1000000007;

int main() {
   ll a,b; cin>>a>>b;
   mint ans=mint(a).pow(b);
   cout<<ans<<'\n';
    return 0;
}
