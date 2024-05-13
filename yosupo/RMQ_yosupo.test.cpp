#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "DS/Sparse_table.hpp"

int main() {
  int n,q,l,r; cin>>n>>q;
  vi a(n);
  rep(i,n) cin>>a[i];
  sparsetable<int>st(a);
  while(q--){
    cin>>l>>r;
    cout<<st.query(l,r)<<'\n';
  }
    return 0;
}
