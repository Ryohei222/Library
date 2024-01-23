#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../Graph/prim.hpp"
#include "../../template.hpp"

int main() {
    ll V, E;
    cin >> V >> E;
    Graph G(V);
    G.read(E, 0, true, false);
    auto [cost, mst] = prim(G);
    cout << cost << endl;
}