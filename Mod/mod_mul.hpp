#pragma once
ll modmul(ll a, ll b,ll mod) {
    ll ans = 0;
    while (b) {
        if (b & 1)
            (ans += a) %= mod;
        (a *= 2) %= mod;
        b /= 2;
    }
    return ans;
}
 
ll modpow(ll a, ll n,ll mod) {
    ll ans = 1;
    for (; n; n /= 2, a = modmul(a, a, mod))
        if (n & 1)
            ans = modmul(ans, a, mod);
    return ans;
}
//or
//only good for long long or int64_t
long long modmul2(long long a,long long b,long long mod){
   return (a*b)%mod;
}
