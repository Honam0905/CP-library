#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "NT/prime/sieve/bool_sieve.hpp"
pair<int, vector<int>> enum_prime(int n) {
    if (n <= 1) return {0, {}};
    auto is_prime = prime_sieve(n);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    int dem = primes.size();
    return {dem, primes};
}
int main() {
    int n, a, b; cin>>n>>a>>b;
    auto [cnt, primes] = enum_prime(n);
    cout<<cnt<<" ";
    int x = 0;
    for (int i = b; i < primes.size(); i += a) {
        x++;
    }
    cout<<x<<'\n';
    for (int i = b; i < primes.size(); i += a) {
        cout<<primes[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
