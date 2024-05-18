#pragma once
template <class T> class SegTree {
private:
    int n;  // array size
    vector<T> t;
    T (*op)(T, T);
    T (*e)();

public:
    SegTree(int size, T (*op)(T, T), T (*e)()) {
        n = size;
        this->op = op;
        this->e = e;
        t.resize(4 * n);
        for (int i = 0; i < 4 * n; i++) {
            t[i] = this->e();
        }
    }

    void build() {
        for (int i = n - 1; i > 0; --i) t[i] = op(t[i << 1], t[i << 1 | 1]);
    }

    void modify(int p, T value) {
        for (t[p += n] = value; p > 1; p >>= 1)  t[p >> 1] = op(t[p], t[p ^ 1]);
    }

    void add(int p, T value) {
        for (t[p += n] += value; p > 1; p >>= 1)  t[p >> 1] = op(t[p], t[p ^ 1]);
    }

    T query(int l, int r) {
        T res = e();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = op(res, t[l++]);
            if (r & 1) res = op(res, t[--r]);
        }
        return res;
    }
};
