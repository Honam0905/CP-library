#pragma once
struct Fenwick{
	vector<ll> s;
    int n;
	Fenwick(int n) : n(n),s(n+1,0) {}
	void update(int pos, ll dif) {
        for (; pos <= n; pos += pos & -pos) s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for (; pos > 0; pos -= pos & -pos) res += s[pos];
        return res;
    }
    ll prefix(int l,int r){
         if(l==r) return 0;
         return query(r)-query(l);
    }
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};
