#pragma once

/**
 * @brief Prim
 * @docs docs/prim.md
 */

#include "graph-template.hpp"

template <typename T>
bool operator>(const Edge<T> &a, const Edge<T> &b) {
    return a.cost > b.cost;
}

template <typename T>
pair<T, Edges<T>> prim(Graph<T> &G) {
    // プリム法で G の最小全域木を求める
    // 返り値は (cost, vector<Edge>)
    // 一方の端点が現在の頂点集合に含まれ、かつもう一方の端点が頂点集合に含まれない辺のうち、コスト最小の辺を採用することを繰り返す
    int N = G.size();
    priority_queue<Edge<T>, Edges<T>, greater<Edge<T>>> pq;
    for(int i = 0; i < (int)G[0].size(); i++) {
        pq.emplace(G[0][i]);
    }
    vector<bool> vis(N);
    vis[0] = true;
    T cost = (T)0;
    Edges<T> mst;
    while(!pq.empty()) {
        Edge<T> edge = pq.top();
        pq.pop();
        if(vis[edge.to]) continue;
        cost += edge.cost;
        mst.emplace_back(edge);
        vis[edge.to] = true;
        for(auto &nedge : G[edge.to]) {
            if(vis[nedge.to]) continue;
            pq.emplace(nedge);
        }
    }
    if((int)mst.size() == N - 1)
        return pair<T, Edges<T>>(cost, mst);
    else
        return pair<T, Edges<T>>((T)-1, mst);
}