#pragma once
#include "Mod/mod_inv.hpp"
struct Barrett_u32 {
    u64 m, m2, im;
    u64 div, rem;

    void set(u64 mod) {
        m = mod;
        m2 = mod << 1;
        im = ((((u128)(1ull) << 64)) + mod - 1) / mod;
        div = 0;
        rem = 0;
    }

    void reduce(u64 a) {
        u64 x = (u64)(((u128)(a) * im) >> 64);
        u64 y = x * m;
        unsigned long long z;
        u32 w = __builtin_usubll_overflow(a, y, &z) ? m : 0;
        div = x;
        rem = z + w;
    }

    u32 add(u32 a, u32 b) {
        a += b;
        a -= (a >= (u32)m ? (u32)m : 0);
        return a;
    }

    u32 sub(u32 a, u32 b) {
        a += (a < b ? (u32)m : 0);
        a -= b;
        return a;
    }

    u32 min(u32 a) {
        return sub(0, a);
    }

    u32 shl(u32 a) {
        return (a <<= 1) >= m ? a - m : a;
    }

    u32 shr(u32 a) {
        return (a & 1) ? ((a >> 1) + (m >> 1) + 1) : (a >> 1);
    }
};

struct Barrett_u64 {
    u128 m, m2, im;
    u128 div, rem;

    void set(u128 mod) {
        m = mod;
        m2 = mod << 1;
        im = (~((u128)0ull)) / mod;
        div = 0;
        rem = 0;
    }

    void reduce(u128 x) {
        if (m == 1) {
            div = x;
            rem = 0;
            return;
        }
        uint8_t  f;
        u128 a = x >> 64;
        u128 b = x & 0xffffffffffffffffull;
        u128 c = im >> 64;
        u128 d = im & 0xffffffffffffffffull;
        u128 ac = a * c;
        u128 bd = (b * d) >> 64;
        u128 ad = a * d;
        u128 bc = b * c;
        f = (ad > ((u128)((i128)(-1L)) - bd));
        bd += ad;
        ac += f;
        f = (bc > ((u128)((i128)(-1L)) - bd));
        bd += bc;
        ac += f;
        u128 q = ac + (bd >> 64);
        u128 r = x - q * m;
        if (m <= r) {
            r -= m;
            q += 1;
        }
        div = q;
        rem = r;
    }

    u64 add(u64 a, u64 b) {
        a += b;
        a -= (a >= (u64)m ? (u64)m : 0);
        return a;
    }

    u64 sub(u64 a, u64 b) {
        a += (a < b ? (u64)m : 0);
        a -= b;
        return a;
    }

    u64 min(u64 a) {
        return sub(0, a);
    }

    u64 shl(u64 a) {
        return (a <<= 1) >= m ? a - m : a;
    }

    u64 shr(u64 a) {
        return (a & 1) ? ((a >> 1) + (m >> 1) + 1) : (a >> 1);
    }
};
// Barrett reduction - 32-bit
u32 mul_b32(struct Barrett_u32 *b, u32 a, u32 x) {
    b->reduce((u64)a * x);
    return (u32)b->rem;
}

u32 div_b32(struct Barrett_u32 *b, u32 a, u32 x) {
    b->reduce((u64)a << 32);
    return (u32)(b->div * inv_mod(x,(u32)b->m));
}

u32 pow_b32(struct Barrett_u32 *b, u32 a, u64 k) {
    u32 ret = 1u;
    u64 deg = k;
    while (deg > 0) {
        if (deg & 1) {
            ret = mul_b32(b, ret, a);
        }
        a = mul_b32(b, a, a);
        deg >>= 1;
    }
    return ret;
}

// Barrett reduction - 64-bit
u64 mul_b64(struct Barrett_u64 *b, u64 a, u64 x) {
    b->reduce((u128)a * x);
    return (u64)b->rem;
}

u64 div_b64(struct Barrett_u64 *b, u64 a, u64 x) {
    b->reduce((u128)a << 64);
    return (u64)(b->div * inv_mod(x,(u64)b->m));
}

u64 pow_b64(struct Barrett_u64 *b, u64 a, u64 k) {
    u64 ret = 1ull, deg = k;
    while (deg > 0) {
        if (deg & 1) {
            ret = mul_b64(b, ret, a);
        }
        a = mul_b64(b, a, a);
        deg >>= 1;
    }
    return ret;
}
