#pragma once
#include "Modint/Barrett_reduction.hpp"
ll modmul(ll a,ll b,ll mod){
    Barrett br(mod);
    return br.mul(a, b);
}

ll mod_pow(ll a, ll n, ll mod) {
  a %= mod;
  Barrett bt(mod);
  ll p = a;
  ll v = 1;
  while (n) {
    if (n & 1) v = bt.mul(v, p);
    p = bt.mul(p, p);
    n >>= 1;
  }
  return v;
}
//or
//only good for long long or int64_t
long long modmul2(long long a,long long b,long long mod){
   return (a*b)%mod;
}
