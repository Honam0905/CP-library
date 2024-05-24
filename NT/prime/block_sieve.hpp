#pragma once
template<class T>
vector<T> block_sieve(T L, T R) {
    T lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<T> primes;

    for (T i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (T j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<T> isPrime;
    vector<char> block(R - L + 1, true);

    for (T i : primes) {
        for (T j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            block[j - L] = false;
    }

    if (L == 1)
        block[0] = false;

    for (T i = L; i <= R; ++i) {
        if (block[i - L])
            isPrime.emplace_back(i);
    }

    return isPrime;
}
