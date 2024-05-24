#pragma once
template<class T>
std::vector<T> sieve_bitset_odd(T n) {
    const T S = sizeof(uint64_t) * 8;
    std::vector<uint64_t> bitset((n / 2 + S - 1) / S, 0xFFFFFFFFFFFFFFFFULL);
    std::vector<T> primes;

    primes.push_back(2);
    for (T i = 3; i * i <= n; i += 2) {
        if (bitset[i / 2 / S] & (1ULL << ((i / 2) % S))) {
            for (T j = i * i; j <= n; j += i * 2) {
                bitset[j / 2 / S] &= ~(1ULL << ((j / 2) % S));
            }
            primes.push_back(i);
        }
    }

    for (T i = primes.back() + 2; i <= n; i += 2) {
        if (bitset[i / 2 / S] & (1ULL << ((i / 2) % S))) {
            primes.push_back(i);
        }
    }

    return primes;
}
