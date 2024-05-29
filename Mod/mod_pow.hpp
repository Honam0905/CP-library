#pragma once
#include "Modint/dynamic_modint.hpp"
u32 mod_pow(int a, ll n, int mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  if ((mod & 1) && (mod < (1 << 30))) {
    using mint = dynamic_modint<202311021>;
    mint::set_mod(mod);
    return mint(a).pow(n).get();
  }
  Barrett bt(mod);
  int r = 1;
  while (n) {
    if (n & 1) r = bt.mul(r, a);
    a = bt.mul(a, a), n >>= 1;
  }
  return r;
}

u64 mod_pow_64(ll a, ll n, u64 mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  if ((mod & 1) && (mod < (u64(1) << 62))) {
    using mint =dynamic_modint<202311021>;
    mint::set_mod(mod);
    return mint(a).pow(n).get();
  }
  Barrett_64 bt(mod);
  ll r = 1;
  while (n) {
    if (n & 1) r = bt.mul(r, a);
    a = bt.mul(a, a), n >>= 1;
  }
  return r;
}
