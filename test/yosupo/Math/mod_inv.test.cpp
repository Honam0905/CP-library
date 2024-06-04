#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "Modint/montgomery_multiplication.hpp"
bool isPrime(u64 x) {
    if (x < 64) {
        return (u64(1) << x) & 0x28208a20a08a28ac;
    }
    if (x % 2 == 0) {
        return false;
    }
    
    Montgomery_u64 m;
    m.set(x);
    
    const int k = __builtin_ctzll(x - 1);
    const u64 d = (x - 1) >> k, IV = m.ni, R = m.r1, R2 = m.r2, nR = m.min(R);
    
    auto mr7 = [&](u64 t1, u64 t2, u64 t3, u64 t4, u64 t5, u64 t6, u64 t7) {
        u64 r1 = R, r2 = R, r3 = R, r4 = R, r5 = R, r6 = R, r7 = R;
        t1 = mul_m64(&m, t1, R2), t2 = mul_m64(&m, t2, R2), t3 = mul_m64(&m, t3, R2);
        t4 = mul_m64(&m, t4, R2), t5 = mul_m64(&m, t5, R2), t6 = mul_m64(&m, t6, R2), t7 = mul_m64(&m, t7, R2);
        for (u64 b = d; b; b >>= 1) {
            if (b & 1) {
                r1 = mul_m64(&m, r1, t1), r2 = mul_m64(&m, r2, t2), r3 = mul_m64(&m, r3, t3);
                r4 = mul_m64(&m, r4, t4), r5 = mul_m64(&m, r5, t5), r6 = mul_m64(&m, r6, t6), r7 = mul_m64(&m, r7, t7);
            }
            t1 = mul_m64(&m, t1, t1), t2 = mul_m64(&m, t2, t2), t3 = mul_m64(&m, t3, t3);
            t4 = mul_m64(&m, t4, t4), t5 = mul_m64(&m, t5, t5), t6 = mul_m64(&m, t6, t6), t7 = mul_m64(&m, t7, t7);
        }
        r1 = min(r1, m.sub(r1,x)), r2 = min(r2, m.sub(r2,x)), r3 = min(r3, m.sub(r3,x));
        r4 = min(r4, m.sub(r4,x)), r5 = min(r5, m.sub(r5,x)), r6 = min(r6, m.sub(r6,x)), r7 = min(r7, m.sub(r7,x));
        int res1 = (r1 == R) | (r1 == nR), res2 = (r2 == R) | (r2 == nR), res3 = (r3 == R) | (r3 == nR);
        int res4 = (r4 == R) | (r4 == nR), res5 = (r5 == R) | (r5 == nR), res6 = (r6 == R) | (r6 == nR), res7 = (r7 == R) | (r7 == nR);
        for (int j = 0; j < k - 1; ++j) {
            r1 = mul_m64(&m, r1, r1), r2 = mul_m64(&m, r2, r2), r3 = mul_m64(&m, r3, r3);
            r4 = mul_m64(&m, r4, r4), r5 = mul_m64(&m, r5, r5), r6 = mul_m64(&m, r6, r6), r7 = mul_m64(&m, r7, r7);
            res1 |= (min(r1, m.sub(r1,x)) == nR), res2 |= (min(r2, m.sub(r2,x)) == nR), res3 |= (min(r3, m.sub(r3,x)) == nR);
            res4 |= (min(r4, m.sub(r4,x)) == nR), res5 |= (min(r5, m.sub(r5,x)) == nR), res6 |= (min(r6, m.sub(r6,x)) == nR), res7 |= (min(r7, m.sub(r7,x)) == nR);
        }
        return res1 & res2 & res3 & res4 & res5 & res6 & res7;
    };
    if (x == 2 || x == 3 || x == 5 || x == 13 || x == 19 || x == 73 || x == 193 || x == 407521 || x == 299210837) {
        return true;
    }
    return mr7(2, 325, 9375, 28178, 450775, 9780504, 1795265022);
}

int main() {
    int t; cin>>t;
    while(t--){
      u64 n; cin>>n;
      cout<<(isPrime(n)?"Yes":"No")<<'\n';
    }
    return 0;
}
