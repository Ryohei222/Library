#pragma once

/**
 * @brief LCA(ダブリング)
 * @docs docs/lca-doubling.md
 */

#include "graph-template.hpp"
template<typename T = int>
struct LCA{  
    // N: 頂点数, K: ダブリングで 2^0, 2^1, 2^2 , ... 個先の頂点を持つが、2 の何乗先の頂点まで持つかを表す
    int N, K;
    vector<int> dist;
    vector<vector<int>> doubling;
    LCA(Graph<T> G, int find){
        N = (int)G.size();
        K = 1;
        while((1LL<<K) <= N) K++;
        dist.assign(N, -1);
        doubling.assign(N, vector<int>(K, -1));
        // 根から BFS して各頂点の親を求める
        queue<int> que;
        que.push(find);
        dist[find] = 0;
        doubling[find][0] = find;
        while(!que.empty()){
            int t = que.front(); que.pop();
            for(auto e : G[t]){
                if(dist[e.to] == -1){
                    dist[e.to] = dist[t] + 1;
                    doubling[e.to][0] = t;
                    que.push(e.to);
                }
            }
        }
        for(int k = 1; k < K; k++){
            for(int i = 0; i < N; i++){
                doubling[i][k] = doubling[doubling[i][k - 1]][k - 1];
            }
        }
    }
    int query(int u, int v){
        if(dist[u] > dist[v]) swap(u, v);
        for(int k = 0; k < K; k++){
            if((dist[v] - dist[u]) & ((1LL) << k)) v = doubling[v][k];
        }
        if(u == v) return u;
        for(int k = K - 1; k >= 0; k--){
            if(doubling[u][k] != doubling[v][k]){
                u = doubling[u][k];
                v = doubling[v][k];
            }
        }
        return doubling[u][0];
    }
};