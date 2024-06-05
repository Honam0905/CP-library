#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "Mod/mod_inv.hpp"
#include "NT/Fast_NT/fast_modinv.hpp"
void benchmark() {
   const int MOD1 = 998244353;  
  const int MOD2 = 1000000007; 
  
  fast_modinv fmi1(MOD1);
  fast_modinv fmi2(MOD2);
  
  vector<int> test_cases;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(1, 10000000000);
  for (int i = 0; i < 5; i++) {
    test_cases.push_back(dist(rng));
  }
  
  
  cerr << "Benchmarking fast_modinv:\n";
  for (int tc : test_cases) {
    auto start = chrono::high_resolution_clock::now();
    int res1 = fmi1(tc);
    int res2 = fmi2(tc);
    auto end = chrono::high_resolution_clock::now();
    assert(res1 == inv_mod(tc, MOD1));
    assert(res2 == inv_mod(tc, MOD2));
    cerr << "Input: " << tc << ", Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns\n";
  }
  
  cerr << "\nBenchmarking inv_mod:\n";
  for (int tc : test_cases) {
    auto start = chrono::high_resolution_clock::now();
    int res1 = inv_mod(tc, MOD1);
    int res2 = inv_mod(tc, MOD2);
    auto end = chrono::high_resolution_clock::now();
    cerr << "Input: " << tc << ", Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns\n";
  }
}

int main() {
    FT;
    benchmark();
    int a,b; cin>>a>>b;
    cout<<a+b<<'\n';
    return 0;
}
