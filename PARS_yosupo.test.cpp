#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "marco.hpp"
#include "Fenwick_tree.hpp"

int main(){
FT;
int t=1; 
//sc.read(t); int tc=0;
while(t--)
{
//tc++;
//cout << "Case #" << tc << ": ";
    int n,q; cin>>n>>q;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    Fenwick ft(n);
    rep(i,n) ft.update(i+1,a[i]);
    while (q--) {
        int op; cin>>op;
        if (op == 0) {
            int p, x; cin>>p>>x;
            ft.update(p + 1, x);
        } else {
            int l, r; cin>>l>>r;
            cout<<ft.prefix(l,r)<<'\n';
        }
    }
// cerr << "Time elapsed: " << TIME << " s.\n";
}
}
