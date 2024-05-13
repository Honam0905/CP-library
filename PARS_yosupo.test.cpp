#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "marco.hpp"
#include "fast_io.hpp"
#include "Fenwick_tree.hpp"
void solve()
{
    int n,q; sc.read(n,q);
    vector<ll> a(n);
    rep(i,n) sc.read(a[i]);
    Fenwick ft(n);
    rep(i,n) ft.update(i+1,a[i]);
    while (q--) {
        int op; sc.read(op);
        if (op == 0) {
            int p, x; sc.read(p,x);
            ft.update(p + 1, x);
        } else {
            int l, r; sc.read(l,r);
            pr.write(ft.prefix(l,r));
            pr.writeln();
        }
    }
}
int main(){
FT;
int t=1; 
//sc.read(t); int tc=0;
while(t--)
{
//tc++;
//cout << "Case #" << tc << ": ";
solve();
// cerr << "Time elapsed: " << TIME << " s.\n";
}
}
