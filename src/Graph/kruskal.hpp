#pragma once

/**
 * @brief Kruskal
 * @docs docs/kruskal.md
 */

#include "../DataStructure/union-find.hpp"
#include "graph-template.hpp"

template <typename T>
pair<T, Edges<T>> kruskal(Graph<T> &G) {
    // クラスカル法で G の最小全域木を求める
    // 返り値は (cost, vector<Edge>)
    int N = G.size();
    UnionFind uf(N);
    Edges<T> edges;
    for(int i = 0; i < N; i++) {
        for(auto &edge : G[i]) {
            edges.emplace_back(edge);
        }
    }
    auto comp = [](const Edge<T> &a, const Edge<T> &b) {
        return a.cost < b.cost;
    };
    sort(edges.begin(), edges.end(), comp);
    T cost = (T)0;
    Edges<T> mst;
    for(auto &edge : edges) {
        if(uf.unite(edge.from, edge.to)) {
            cost += edge.cost;
            mst.emplace_back(edge);
        }
    }
    if(uf.size(0) == N)
        return pair<T, Edges<T>>(cost, mst);
    else
        return pair<T, Edges<T>>((T)-1, mst);
}