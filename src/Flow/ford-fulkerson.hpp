#pragma once

/**
 * @brief Ford-Fulkerson
 * @docs docs/ford-fulkerson.md
 */

template <typename T>
struct FordFulkerson {
    struct Edge {
        int to, rev_idx;
        T cap;
    };
    int N;
    vector<vector<Edge>> G;
    vector<bool> vis;

    FordFulkerson(int N)
      : N(N), G(N), vis(N) {}

    void add_edge(int from, int to, T cap) {
        G[from].emplace_back((Edge){to, (int)G[to].size(), cap}); // e.from = G[e.to][e.rev_idx].to;
        G[to].emplace_back((Edge){from, (int)G[from].size() - 1, T(0)});
    }

    // v -> t の流量 f 以下の増加道を探す
    T dfs(int v, int t, T f) {
        if(v == t) return f;
        vis[v] = true;
        for(auto &e : G[v]) {
            if(!vis[e.to] && e.cap > (T)0) {
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > (T)0) {
                    e.cap -= d;
                    G[e.to][e.rev_idx].cap += d;
                    return d;
                }
            }
        }
        return (T)0;
    }

    T max_flow(int s, int t) {
        T flow = 0, INF = numeric_limits<T>::max();
        while(true) {
            vis.assign(N, false);
            T f = dfs(s, t, INF);
            if(f == (T)0) return flow;
            flow += f;
        }
    }

    void debug() {
        cerr << "---------" << endl;
        for(int i = 0; i < N; i++) {
            for(auto &e : G[i]) {
                if(e.to < i) continue;
                cerr << i << " -> " << e.to << ": " << G[e.to][e.rev_idx].cap << endl;
            }
        }
    }
};