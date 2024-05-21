#pragma once
template <int id> struct dynamic_modint {
  int x;

  dynamic_modint() : x(0) {}

  dynamic_modint(int64_t y) {
    int z = y % get_mod();
    if (z < 0) z += get_mod();
    x = z;
  }

  dynamic_modint &operator+=(const dynamic_modint &p) {
    if ((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  dynamic_modint &operator-=(const dynamic_modint &p) {
    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  dynamic_modint &operator*=(const dynamic_modint &p) {
    x = rem((unsigned long long)x * p.x);
    return *this;
  }

  dynamic_modint &operator/=(const dynamic_modint &p) {
    *this *= p.inverse();
    return *this;
  }

  dynamic_modint operator-() const { return dynamic_modint(-x); }
  dynamic_modint operator+() const { return *this; }

  dynamic_modint operator+(const dynamic_modint &p) const {
    return dynamic_modint(*this) += p;
  }

  dynamic_modint operator-(const dynamic_modint &p) const {
    return dynamic_modint(*this) -= p;
  }

  dynamic_modint operator*(const dynamic_modint &p) const {
    return dynamic_modint(*this) *= p;
  }

  dynamic_modint operator/(const dynamic_modint &p) const {
    return dynamic_modint(*this) /= p;
  }

  bool operator==(const dynamic_modint &p) const { return x == p.x; }

  bool operator!=(const dynamic_modint &p) const { return x != p.x; }

  dynamic_modint inv() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return dynamic_modint(u);
  }

  dynamic_modint pow(int64_t n) const {
    dynamic_modint ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const dynamic_modint &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, dynamic_modint &a) {
    int64_t t;
    is >> t;
    a = dynamic_modint(t);
    return (is);
  }

  int get() const { return x; }

  inline unsigned int rem(unsigned long long p) { return barrett().rem(p); }

  static inline Barrett &barrett() {
    static Barrett b;
    return b;
  }

  static inline int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) {
    assert(0 < md && md <= (1LL << 30) - 1);
    get_mod() = md;
    barrett() = Barrett(md);
  }
};

using modint = dynamic_modint<-1>;
