#pragma once
using BYTE=unsigned char;
template<class T>
std::vector<T> sieve_2(T lim) {
    std::vector<T> primes;
    primes.reserve(lim / std::log(lim));

    if (lim >= 2) {
        primes.push_back(2);
    }

    T sqrt = std::sqrt(lim);
    int sieve_size = std::max(sqrt, static_cast<T>(1 << 15));
    int segment_size = sieve_size * 16;
    std::vector<BYTE> mark(sieve_size);
    std::vector<BYTE> is_prime(sqrt + 1, true);
    std::vector<T> seg_prime;
    std::vector<T> seg_multi;

    for (T i = 3; i <= sqrt; i += 2) {
        if (is_prime[i]) {
            for (T j = i * i; j <= sqrt; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int reset[16];
    for (int i = 0; i < 8; ++i) {
        reset[2 * i] = reset[2 * i + 1] = ~(1 << i);
    }

    T s = 3;
    for (T low = 0; low <= lim; low += segment_size) {
        std::fill(mark.begin(), mark.end(), 0xff);
        T high = std::min(low + segment_size - 1, lim);
        sieve_size = (high - low) / 16 + 1;

        for (; s * s <= high; s += 2) {
            if (is_prime[s]) {
                seg_prime.push_back(s);
                seg_multi.push_back(s * s - low);
            }
        }

        for (size_t i = 0; i < seg_prime.size(); ++i) {
            T j = seg_multi[i];
            for (T k = seg_prime[i] * 2; j < segment_size; j += k) {
                mark[j >> 4] &= reset[j % 16];
            }
            seg_multi[i] = j - segment_size;
        }

        if (high == lim) {
            int bits = 0xff << ((lim % 16) + 1) / 2;
            mark[sieve_size - 1] &= ~bits;
        }

        for (int n = 0; n < sieve_size; n++) {
            for (int i = 0; i < 8; i++) {
                if (mark[n] & (1 << i)) {
                    auto p = low + n * 16 + i * 2 + 1;
                    if (p > 2) {
                        primes.push_back(p);
                    }
                }
            }
        }
    }

    return primes;
}
