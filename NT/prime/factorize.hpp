#pragma once
#include "Modint/Barrett_2.hpp"
#include "NT/prime/prime_test.hpp"
u64 pollard(u64 n) {
  Barrett_u64 br;
  br.set(n);
	u64 x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	auto f = [&](u64 x) { return mul_b64(&br,x, x) + i; };
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = mul_b64(&br,prd, max(x,y) - min(x,y)))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<u64> factor(u64 n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	u64 x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
