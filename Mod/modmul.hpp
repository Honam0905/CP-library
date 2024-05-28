#pragma once
#include "Modint/Barrett_reduction.hpp"
long long modmul(long long a,long long b,long long mod){
    Barrett br(mod);
    return br.mul(a, b);
}

//or
//only good for long long or int64_t
long long modmul2(long long a,long long b,long long mod){
   return (a*b)%mod;
}
