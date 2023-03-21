#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../template.hpp"
#include "../../Graph/dijkstra.hpp"

int main() {
    i64 v, e, r;
    cin >> v >> e >> r;
    Graph<i64> G(v);
    G.read(e, 0, true, true);
    auto dist = dijkstra(G, r);
    const i64 INF = std::numeric_limits<i64>::max();
    for(auto d : dist) {
        if(d == INF)
            cout << "INF" << endl;
        else
            cout << d << endl;
    }
}