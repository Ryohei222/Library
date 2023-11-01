#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../template.hpp"
#include "../../Graph/lca.hpp"

int main(){
    ll N, Q;
    cin >> N >> Q;
    Graph<> G(N);
    vl p(N - 1);
    cin >> p;
    rep(i, N - 1) G.add_edge(p[i], i + 1);
    LCA<> lca(G, 0);
    rep(i, Q){
        ll u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}