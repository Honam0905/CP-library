#pragma once
template <class T> class SegTree {
private:
const T DEFAULT = 1; //change depend on the problem
    int n;  // array size
    vector<T> t;
public:
    SegTree(int size) {
        n = size;
        t.resize(4 * n);
    }

    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
    }

    void modify(int p, T value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }

    T query(int l, int r) {  // sum on interval [l, r)
        T res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }
};
