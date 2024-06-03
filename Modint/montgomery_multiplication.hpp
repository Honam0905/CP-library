#pragma once
#include "Mod/mod_inv.hpp"
struct Montgomery_u32 {
    u32 n, n2, ni, r1, r2, r3;

    void set(u32 mod) {
        n = mod;
        n2 = mod << 1;
        ni = mod;
        ni *= 2 - ni * mod;
        ni *= 2 - ni * mod;
        ni *= 2 - ni * mod;
        ni *= 2 - ni * mod;
        r1 = (u32)(int32_t)-1 % mod + 1;
        r2 = (u64)(int64_t)-1 % mod + 1;
        r3 = (u32)(((u64)r1 * (u64)r2) % mod);
    }

    u32 reduce(u64 a) {
        u32 y = (u32)(a >> 32) - (u32)(((u64)((u32)a * ni) * n) >> 32);
        return (int32_t)y < 0 ? y + n : y;
    }

    u32 to(u32 a) {
        return reduce((u64)a * r2);
    }

    u32 from(u32 a) {
        return reduce((u64)a);
    }

    u32 add(u32 a, u32 b) {
        a += b;
        a -= (a >= n ? n : 0);
        return a;
    }

    u32 sub(u32 a, u32 b) {
        a += (a < b ? n : 0);
        a -= b;
        return a;
    }

    u32 min(u32 a) {
        return sub(0, a);
    }

    u32 shl(u32 a) {
        return (a <<= 1) >= n ? a - n : a;
    }

    u32 shr(u32 a) {
        return (a & 1) ? ((a >> 1) + (n >> 1) + 1) : (a >> 1);
    }

    u32 inv(u32 a) {
        return reduce((u64)r3 * inv_mod(a, n));
    }
};

struct Montgomery_u64 {
    u64 n, n2, ni, r1, r2, r3;

    void set(u64 mod) {
        n = mod;
        n2 = mod << 1;
        ni = mod;
        ni *= 2 - ni * mod;
        ni *= 2 - ni * mod;
        ni *= 2 - ni * mod;
        ni *= 2 - ni * mod;
        ni *= 2 - ni * mod;
        r1 = (u64)(int64_t)-1 % mod + 1;
        r2 = (u128)(i128)-1 % mod + 1;
        r3 = (u64)(((u128)r1 * (u128)r2) % mod);
    }

    u64 reduce(u128 a) {
        u64 y = (u64)(a >> 64) - (u64)(((u128)((u64)a * ni) * n) >> 64);
        return (int64_t)y < 0 ? y + n : y;
    }

    u64 to(u64 a) {
        return reduce((u128)a * r2);
    }

    u64 from(u64 a) {
        return reduce((u128)a);
    }

    u64 add(u64 a, u64 b) {
        a += b;
        a -= (a >= n ? n : 0);
        return a;
    }

    u64 sub(u64 a, u64 b) {
        a += (a < b ? n : 0);
        a -= b;
        return a;
    }

    u64 min(u64 a) {
        return sub(0, a);
    }

    u64 shl(u64 a) {
        return (a <<= 1) >= n ? a - n : a;
    }

    u64 shr(u64 a) {
        return (a & 1) ? ((a >> 1) + (n >> 1) + 1) : (a >> 1);
    }

    u64 inv(u64 a) {
        return reduce((u128)r3 * inv_mod(a, n));
    }
};
// Montgomery multiplication - 32-bit
u32 mul_m32(struct Montgomery_u32 *m, u32 a, u32 b) {
    return m->reduce((u64)a * b);
}

u32 div_m32(struct Montgomery_u32 *m, u32 a, u32 b) {
    return mul_m32(m, a, m->inv(b));
}

u32 pow_m32(struct Montgomery_u32 *m, u32 a, u64 k) {
    u32 ret = m->r1;
    u64 deg = k;
    while (deg > 0) {
        if (deg & 1) {
            ret = mul_m32(m, ret, a);
        }
        a = mul_m32(m, a, a);
        deg >>= 1;
    }
    return m->from(ret);
}

// Montgomery multiplication - 64-bit
u64 mul_m64(struct Montgomery_u64 *m, u64 a, u64 b) {
    return m->reduce((u128)a * b);
}

u64 div_m64(struct Montgomery_u64 *m, u64 a, u64 b) {
    return mul_m64(m, a, m->inv(b));
}

u64 pow_m64(struct Montgomery_u64 *m, u64 a, u64 k) {
    u64 ret = m->r1, deg = k;
    while (deg > 0) {
        if (deg & 1) {
            ret = mul_m64(m, ret, a);
        }
        a = mul_m64(m, a, a);
        deg >>= 1;
    }
    return m->from(ret);
}
