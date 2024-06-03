#pragma once
#include "Modint/Barrett_2.hpp"
ll primitive_root (ll p) {
    if(p==2) return 1;
    vector<ll> fact;
    Barrett_u64 br;
    br.set(p);
    ll phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);
    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= pow_b64(&br,res, phi / fact[i]) != 1;
        if (ok)  return res;
    }
    return -1;
}
