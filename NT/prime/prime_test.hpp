#pragma once
#include "Mod/mod_mul.hpp"
bool isPrime(u64 x) {
    if (x < 64) {
        return (u64(1) << x) & 0x28208a20a08a28ac;
    }
    if (x % 2 == 0) {
        return false;
    }
    const int k = __builtin_ctzll(x - 1);
    const u64 d = (x - 1) >> k, IV = get_nr(x), R = (-x) % x, R2 = (-u128(x)) % x, nR = x - R;
    auto mr7 = [&](u64 t1, u64 t2, u64 t3, u64 t4, u64 t5, u64 t6, u64 t7) {
        u64 r1 = R, r2 = R, r3 = R, r4 = R, r5 = R, r6 = R, r7 = R;
        t1 = modmul(t1, R2, IV, x), t2 = modmul(t2, R2, IV, x), t3 = modmul(t3, R2, IV, x);
        t4 = modmul(t4, R2, IV, x), t5 = modmul(t5, R2, IV, x), t6 = modmul(t6, R2, IV, x), t7 = modmul(t7, R2, IV, x);
        for (u64 b = d; b; b >>= 1) {
            if (b & 1) {
                r1 = modmul(r1, t1, IV, x), r2 = modmul(r2, t2, IV, x), r3 = modmul(r3, t3, IV, x);
                r4 = modmul(r4, t4, IV, x), r5 = modmul(r5, t5, IV, x), r6 = modmul(r6, t6, IV, x), r7 = modmul(r7, t7, IV, x);
            }
            t1 = modmul(t1, t1, IV, x), t2 = modmul(t2, t2, IV, x), t3 = modmul(t3, t3, IV, x);
            t4 = modmul(t4, t4, IV, x), t5 = modmul(t5, t5, IV, x), t6 = modmul(t6, t6, IV, x), t7 = modmul(t7, t7, IV, x);
        }
        r1 = min(r1, r1 - x), r2 = min(r2, r2 - x), r3 = min(r3, r3 - x);
        r4 = min(r4, r4 - x), r5 = min(r5, r5 - x), r6 = min(r6, r6 - x), r7 = min(r7, r7 - x);
        int res1 = (r1 == R) | (r1 == nR), res2 = (r2 == R) | (r2 == nR), res3 = (r3 == R) | (r3 == nR);
        int res4 = (r4 == R) | (r4 == nR), res5 = (r5 == R) | (r5 == nR), res6 = (r6 == R) | (r6 == nR), res7 = (r7 == R) | (r7 == nR);
        for (int j = 0; j < k - 1; ++j) {
            r1 = modmul(r1, r1, IV, x), r2 = modmul(r2, r2, IV, x), r3 = modmul(r3, r3, IV, x);
            r4 = modmul(r4, r4, IV, x), r5 = modmul(r5, r5, IV, x), r6 = modmul(r6, r6, IV, x), r7 = modmul(r7, r7, IV, x);
            res1 |= (min(r1, r1 - x) == nR), res2 |= (min(r2, r2 - x) == nR), res3 |= (min(r3, r3 - x) == nR);
            res4 |= (min(r4, r4 - x) == nR), res5 |= (min(r5, r5 - x) == nR), res6 |= (min(r6, r6 - x) == nR), res7 |= (min(r7, r7 - x) == nR);
        }
        return res1 & res2 & res3 & res4 & res5 & res6 & res7;
    };
    if (x == 2 || x == 3 || x == 5 || x == 13 || x == 19 || x == 73 || x == 193 || x == 407521 || x == 299210837) {
        return true;
    }
    return mr7(2, 325, 9375, 28178, 450775, 9780504, 1795265022);
}
