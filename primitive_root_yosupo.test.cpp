#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#line 2 "Misc/marco.hpp"
// Judges with GCC >= 12 only needs Ofast
// #pragma GCC optimize("O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize")
// MLE optimization
// #pragma GCC optimize("conserve-stack")
// Old judges
// #pragma GCC target("sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2")
// New judges. Test with assert(__builtin_cpu_supports("avx2"));
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// Atcoder
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ods;
- insert(x),erase(x)
- find_by_order(k): return iterator to the k-th smallest element
- order_of_key(x): the number of elements that are strictly smaller
*/
#include<bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;
 
 
#define pii pair<int,int>
#define pll pair<ll,ll>
 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ars(x) (x),(x+n)
 
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
 
#define For(i,a,b) for (int i=(a); i<(b); i++)
#define rep(i,a) For(i,0,a)
#define rev(i,a,b) for (int i=(a); i>(b); i--)
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)
#define REP(i,a) FOR(i,1,a)
#define REV(i,a,b) for (int i=(a); i>=(b); i--)
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FT ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using vi=vector<int>;
using vll = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
 
//template <class T>
//using ods =
//   tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#line 1 "Misc/debug.hpp"
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<>
void __print(const vector<bool> &x) {int f = 0; cerr << '{'; for (size_t i = 0; i < x.size(); ++i) cerr << (f++ ? ", " : ""), __print(x[i]); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { __print(H); if (sizeof...(T)) cerr << ", "; dbg_out(T...); }
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:"; dbg_out(__VA_ARGS__);
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#line 2 "Mod/mod_inv.hpp"

#include <cassert>
#include <type_traits>
using namespace std;

// gcd(a, m) != 1 return -1 
template <typename T>
T inv_mod(T a, T m) {
  if (m == 1) return 0;
  if (a >= m) a %= m;
  if (a < 0) a += m;
  if(__gcd(a,m)!=1) return -1;
  T b = m, s = 1, t = 0;
  while (true) {
    if (a == 1) return s;
    t -= b / a * s;
    b %= a;
    if (b == 1) return t + m;
    s -= a / b * t;
    a %= b;
  }
}
#line 3 "Modint/Barrett_2.hpp"
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
#line 3 "Mod/Primitive_root.hpp"
u64 primitive_root (u64 p) {
    if(p==2) return 1;
    vector<u64> fact;
    Barrett_u64 br;
    br.set(p);
    u64 phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);
    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= pow_b64(&br,res, phi / fact[i]) != 1;
        if (ok)  return res;
    }
    return -1;
}

int main() {
    FT;
    int t; cin>>t;
    while(t--){
      u64 n; cin>>n;
      u64 ans=primitive_root(n);
      cout<<ans<<'\n';
    } 
   return 0;
}
