#pragma once

#include "graph-template.hpp"

/**
 * @brief Heavy-Light Decomposition
 * @docs docs/hld.md
 */

template<typename T = int>
struct HeavyLightDecomposition {
    Graph<T> G;
    vector<int> sz, order, leader, par, group, depth;
    HeavyLightDecomposition(const Graph<T> &g) : G(g), sz(g.size()), order(g.size()), par(g.size()), group(g.size()), depth(g.size()) {}
    void build(){
        depth[0] = 0;
        dfs_subtree(0, -1);
        int t = 0, g = 0;
        leader.emplace_back(0);
        dfs_hld(0, -1, t, g);
    }
    vector<pair<int, int>> path_edge(int u, int v){
        vector<pair<int, int>> ret;
        int r = lca(u, v);
        auto rec = [&](auto &self, int c) -> void
        {
            if(r == c) return;
            int lr = leader[group[r]], lc = leader[group[c]];
            if(lr == lc){
                ret.emplace_back(order[r] + 1, order[c] + 1);
            }else{
                ret.emplace_back(order[lc], order[c] + 1);
                self(self, par[lc]);
            }
        };
        if(r != u) rec(rec, u);
        if(r != v) rec(rec, v);
        return ret;
    }
    vector<pair<int, int>> path_vertex(int u, int v){
        vector<pair<int, int>> ret;
        auto rec = [&](auto &self, int a, int b) -> void
        {
            int la = leader[group[a]], lb = leader[group[b]];
            if(depth[la] > depth[lb]){
                swap(a, b);
                swap(la, lb);
            }
            if(la == lb){
                if(depth[a] > depth[b]) swap(a, b);
                ret.emplace_back(order[a], order[b] + 1);
            }else{
                self(self, a, par[lb]);
                self(self, lb, b);
            }
        };
        rec(rec, u, v);
        return ret;
    }
    int lca(int u, int v){
        while(true){
            if(order[u] < order[v]) swap(u, v);
            if(leader[group[u]] == leader[group[v]]) return v;
            u = par[leader[group[u]]];
        }
    }
private:
    int dfs_subtree(int v, int p){
        par[v] = p;
        sz[v] = 1;
        for(auto &e: G[v]){
            if(e.to == p) continue;
            depth[e.to] = depth[v] + 1;
            sz[v] += dfs_subtree(e.to, v);
        }
        return sz[v];
    }
    void dfs_hld(int v, int p, int &t, int &g){
        order[v] = t++;
        group[v] = g;
        int idx = -1, cur_sz = 0;
        for(auto &e: G[v]){
            if(e.to == p) continue;
            if(sz[e.to] > cur_sz){
                idx = e.to;
                cur_sz = sz[e.to];
            }
        }
        if(idx != -1) dfs_hld(idx, v, t, g);
        for(auto &e: G[v]){
            if(e.to == p || e.to == idx) continue;
            g++;
            leader.emplace_back(e.to);
            dfs_hld(e.to, v, t, g);
        }
    }
};