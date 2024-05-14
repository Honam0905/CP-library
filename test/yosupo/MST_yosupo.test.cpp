#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "DS/DSU.hpp"
int n,m,x,y,w,total=0;
typedef tuple<int, int, int, int> edge;
int main() {
   cin>>n>>m;
    vector<edge>edges(m);
    rep(_,m){
       cin>>x>>y>>w;
       edges.emplace_back(w,x,y,_);
    }
    sort(all(edges));
    vector<int>ans;
    ll res=0;
    DSU d;
    d.init(n);
    for(const auto& [c,a,b,id]:edges){
        if(d.unite(a,b)){ 
        res+=c; 
        ans.push_back(id);
        if(ans.size()==n-1) break;
        }
    }
    cout<<res<<'\n';
    for(auto x:ans) cout<<x<<" ";
    return 0;
}
