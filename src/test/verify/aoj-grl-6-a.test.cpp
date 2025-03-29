#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"
#include "../../template.hpp"

#include "../../Flow/ford-fulkerson.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    FordFulkerson<int> flow(V);
    rep(i, E) {
        ll u, v, c;
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }
    cout << flow.max_flow(0, V - 1) << '\n';
}