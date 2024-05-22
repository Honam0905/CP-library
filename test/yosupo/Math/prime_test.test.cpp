#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "NT/prime/prime_test.hpp"

int main() {
    u64 n; cin>>n;
    cout<<(MillerRabin(n)?"Yes":"No")<<'\n';
    return 0;
}
