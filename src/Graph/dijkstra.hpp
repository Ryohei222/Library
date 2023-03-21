#pragma once

/**
 * @brief Dijkstra
 * @docs docs/dijkstra.md
 */

#include "graph-template.hpp"

template <typename T>
vector<T> dijkstra(Graph<T> &G, int s) {
    const auto INF = numeric_limits<T>::max();
    using P = pair<T, int>;
    int n = G.size();
    vector<T> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    while(!que.empty()) {
        P t = que.top();
        que.pop();
        T cost = t.first;
        int u = t.second;
        if(cost > dist[u]) continue;
        for(auto e : G[u]) {
            T v = e.to;
            if(cost + e.cost < dist[v]) {
                dist[v] = cost + e.cost;
                que.emplace(dist[v], v);
            }
        }
    }
    return dist;
}