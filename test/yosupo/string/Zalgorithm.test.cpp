#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "Misc/marco.hpp"
#include "Misc/debug.hpp"
const int INF=1e9;
const ll INFI=1e15;
//----------Author: Nguyen Ho Nam,UIT, Saigon-----------------
#include "String/Z_algorithm.hpp"

int main() {
    string s; cin>>s;
    auto ans=z_algorithm(s);
    rep(i,ans.size()){
        cout<<ans[i]<<" ";
    }
    return 0;
}
