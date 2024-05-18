#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "DS/Segment_tree.hpp"

int main() {
  int n,q,op,l,r; cin>>n>>q;
  SegTree<int>st(n);
  while(q--){
    cin>>op>>l>>r;
    if(op==0){
        st.modify(l,r);
    }if(op==1){
        cout<<st.query(l,r+1)<<'\n';
    }
  }
    return 0;
}
