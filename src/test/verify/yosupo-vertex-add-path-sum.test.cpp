#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../../template.hpp"

#include "../../DataStructure/fenwick-tree.hpp"
#include "../../Graph/hld.hpp"

int main() {
    ll N, Q;
    cin >> N >> Q;
    vl a(N);
    cin >> a;
    Graph<ll> G(N);
    G.read(N - 1, 0);
    auto hld = HeavyLightDecomposition(G);
    hld.build();
    FenwickTree seg(N);
    rep(i, N) {
        seg.set(hld.order[i], a[i]);
    }
    while(Q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 0) {
            seg.apply(hld.order[x], y);
        } else {
            ll ans = 0;
            auto paths = hld.path_vertex(x, y);
            for(auto [p, q] : paths) {
                ans += seg.prod(p, q);
            }
            cout << ans << '\n';
        }
    }
}
