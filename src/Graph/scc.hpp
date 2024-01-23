#pragma once

/**
 * @brief 強連結成分分解
 * @docs docs/scc.md
 */

#include "graph-template.hpp"

template <typename T>
struct SCC {
    Graph<T> G, rG;
    SCC(Graph<T> G)
        : G{G} {}
    Graph<T> dag;
    vector<bool> used;
    // group[i] := i 番目の頂点が属する強連結成分の番号
    // component[i] := i 番目の強連結成分に属する頂点の集合
    vector<int> order, group;
    vector<vector<int>> component;
    void build() {
        int N = G.size();
        used.resize(N, false);
        for(int i = 0; i < N; i++) {
            if(!used[i]) {
                dfs(i);
            }
        }
        using Pi = pair<int, int>;
        vector<Pi> sorted;
        for(int i = 0; i < N; i++) {
            sorted.emplace_back(i, order[i]);
        }
        sort(sorted.begin(), sorted.end(), greater<Pi>());
        // 逆辺を張ったグラフで DFS を行う
        rG.resize(N);
        for(int i = 0; i < N; i++) {
            for(Edge<T> e : G[i]) {
                rG.add_directed_edge(e.to, e.from);
            }
        }
        group.resize(N, -1);
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            int t = sorted[i].second;
            if(group[t] != -1) continue;
            rdfs(t, cnt);
            cnt++;
        }
        dag.resize(cnt);
        component.resize(cnt);
        for(int i = 0; i < N; i++) {
            component[group[i]].push_back(i);
            for(Edge<T> e : G[i]) {
                if(group[i] == group[e.to]) continue;
                dag.add_directed_edge(group[i], group[e.to]);
            }
        }
    }
    void dfs(int v) {
        if(used[v]) return;
        used[v] = true;
        for(Edge<T> e : G[v])
            dfs(e.to);
        order.push_back(v);
    }
    void rdfs(int v, int cnt) {
        if(group[v] != -1) return;
        group[v] = cnt;
        for(Edge<T> e : rG[v])
            rdfs(e.to, cnt);
    }
};
