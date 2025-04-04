#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../template.hpp"

#include "../../Graph/dijkstra.hpp"

int main() {
    ll v, e, r;
    cin >> v >> e >> r;
    Graph<ll> G(v);
    G.read(e, 0, true, true);
    auto dist = dijkstra(G, r);
    const ll INF = std::numeric_limits<ll>::max();
    for(auto d : dist) {
        if(d == INF)
            cout << "INF" << '\n';
        else
            cout << d << '\n';
    }
}