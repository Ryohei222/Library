#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using i64 = long long int;
using P = pair<i64, i64>;

struct edge{
    i64 src, to, cost;
    edge(i64 to, i64 cost) : src(-1), to(to), cost(cost) {}
    edge(i64 src, i64 to, i64 cost) : src(src), to(to), cost(cost) {}
    bool operator <(const edge &u){
        return this->cost < u.cost;
    };
};

using Graph = vector<vector<edge>>;
const i64 INF = numeric_limits<i64>::max();

vector<i64> dijkstra(Graph G, i64 s){
    //
    // Dijkstra 法 O(ElogV)
    // Graph G : 有向グラフ
    // i64 s : 始点の番号
    //
    i64 n = G.size();
    vector<i64> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    while(!que.empty()){
        P t = que.top(); que.pop();
        i64 cost = t.first, u = t.second;
        if(cost > dist[u]) continue;
        for(auto e : G[u]){
            i64 v = e.to;
            if(cost + e.cost < dist[v]){
                dist[v] = cost + e.cost;
                que.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

void GRL_1_A(){
    i64 v, e, r;
    cin >> v >> e >> r;
    Graph G(v);
    for(i64 i = 0; i < e; ++i){
        i64 s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(s, t, d);
    }
    auto dist = dijkstra(G, r);
    for(auto d: dist){
        if(d == INF) cout << "INF" << endl;
        else cout << d << endl;
    }
}

int main(){
    /* GRL_1_A(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/GRL_1_A/judge/3892499/C++14 */
}
