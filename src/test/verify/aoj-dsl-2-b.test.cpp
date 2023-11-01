#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../template.hpp"
#include "../../DataStructure/fenwick-tree.hpp"

int main(){
    ll n, q;
    cin >> n >> q;
    FenwickTree bit(n);
    rep(i, q){
        ll com, x, y;
        cin >> com >> x >> y;
        if(com == 0) bit.apply(x - 1, y);
        if(com == 1) cout << bit.prod(x - 1, y) << endl;
    }
}