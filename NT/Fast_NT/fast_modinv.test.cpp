#pragma once
#include <cassert>
using namespace std;
 
struct fast_modinv {
  using u32 = unsigned int;
  using u64 = unsigned long long;
 
  u32 mod;
  u32 ipow2[64], pre[2048 / 2];
 
  fast_modinv(u32 m) : mod(m), ipow2(), pre() {
    assert(mod % 2 == 1 && mod < (1LL << 30));
 
    // Precompute ipow2
    ipow2[0] = 1 % mod;
    for (int i = 1; i < 64; i++) {
      ipow2[i] = u64(ipow2[i - 1]) * ((mod + 1) / 2) % mod;
    }
 
    // Precompute pre for odd numbers
    pre[0] = 1 % mod;
    for (int i = 3; i < 2048; i += 2) {
      pre[i >> 1] = [this, i]() -> int {
        int x = i, y = mod, u = 1, v = 0, t = 0, tmp = 0;
        while (y > 0) {
          t = x / y;
          x -= t * y, u -= t * v;
          tmp = x, x = y, y = tmp;
          tmp = u, u = v, v = tmp;
        }
        return u < 0 ? u + mod : u;
      }();
    }
  }
 
  bool is_prime(u32 n) const {
    if (n == 1) return false;
    for (int p = 3; p * p <= n; p += 2) {
      if (n % p == 0) return false;
    }
    return true;
  }
 
  u32 inv(u32 a) const {
    if (mod == 1) {
      return 0;
    }
 
    u32 b = mod, s = 1, t = 0;
    int n = __builtin_ctz(a);
    a >>= n;
 
    while (a - b != 0) {
      if (is_prime(mod)) {
        if (a < 2048) break;
      }
      int m = __builtin_ctz(a - b);
      bool f = a > b;
      n += m;
      a = f ? (a - b) >> m : a;
      b = f ? b : -(a - b) >> m;
      u32 u = f ? s - t : s << m;
      t = f ? t << m : -(s - t);
      s = u;
    }
    return u64(s) * pre[a >> 1] % mod * ipow2[n] % mod;
  }
 
  u32 operator()(u32 a) const { return inv(a); }
};
