#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../template.hpp"

#include "../../DataStructure/segment-tree.hpp"

int main() {
    ll n, q;
    cin >> n >> q;
    auto seg = SegmentTree<AdditiveGroup<ll>>(n);
    rep(i, q) {
        ll com, x, y;
        cin >> com >> x >> y;
        if(com == 0) seg.apply(x - 1, y);
        if(com == 1) cout << seg.prod(x - 1, y) << '\n';
    }
}