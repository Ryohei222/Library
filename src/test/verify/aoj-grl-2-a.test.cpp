#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../template.hpp"

#include "../../Graph/kruskal.hpp"

int main() {
    ll V, E;
    cin >> V >> E;
    Graph G(V);
    G.read(E, 0, true, false);
    auto [cost, mst] = kruskal(G);
    cout << cost << endl;
}