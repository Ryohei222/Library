#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../Graph/scc.hpp"
#include "../../template.hpp"

int main() {
    int V, E, Q;
    cin >> V >> E;
    Graph<int> G(V);
    G.read(E, 0, false, true);
    SCC<int> scc(G);
    cin >> Q;
    scc.build();
    rep(i, Q) {
        int u, v;
        cin >> u >> v;
        cout << (scc.group[u] == scc.group[v]) << endl;
    }
}