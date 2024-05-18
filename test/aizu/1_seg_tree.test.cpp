#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "DS/Segment_tree.hpp"
ll op(ll a,ll b) {return min(a,b);}
ll e(){return INT_MAX;}

int main() {
  int n,q,tt,l,r; cin>>n>>q;
  SegTree<ll>st(n,op,e);
  while(q--){
    cin>>tt>>l>>r;
    if(tt==0){
        st.modify(l,r);
    }if(tt==1){
        cout<<st.query(l,r+1)<<'\n';
    }
  }
    return 0;
}
