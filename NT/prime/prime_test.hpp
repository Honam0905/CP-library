#pragma once
/*
   Primality tests by CP algorithms with higher bases
   @see https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test
*/
#include "Mod/mod_pow.hpp"
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = mod_pow_64(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(u64 n) {
    if (n < 2)
        return false;

    // Small primes to check divisibility
    for (u64 a : {2, 3, 5, 13, 19, 73, 193, 407521, 299210837}) {
        if (n % a == 0)
            return n == a;
    }

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    // Larger bases for checking primality
    for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
