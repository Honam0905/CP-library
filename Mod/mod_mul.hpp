#pragma once
u64 get_nr(u64 M) {
    u64 IV = 2 - M;
    for (int i = 0; i < 5; ++i) {
        IV *= 2 - M * IV;
    }
    return IV;
}

u64 modmul(u64 x, u64 y, u64 IV, u64 M) {
    auto t = u128(x) * y;
    u64 lo = t, hi = t >> 64;
    return (hi + M) - u64((u128(lo * IV) * M) >> 64);
}
 
u64 modpow(u64 a, u64 b, u64 M) {
    u64 res = 1;
    u64 IV = get_nr(M);
    while (b) {
        if (b & 1) {
            res = modmul(res, a, IV, M);
        }
        a = modmul(a, a, IV, M);
        b >>= 1;
    }
    return res;
}
//or
//only good for long long or int64_t
long long modmul2(long long a,long long b,long long mod){
   return (a*b)%mod;
}
