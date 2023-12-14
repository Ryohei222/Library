#pragma once

/**
 * @brief Tree-Diameter
 * @docs docs/diameter.md
 */

#include "graph-template.hpp"

template <typename T = int>
tuple<T, int, int> diameter(Graph<T> &G){
    auto dfs = [&](auto &self, int v, int p) -> pair<T, int>
    {
        pair<T, int> ret(0, v);
        for(auto &e : G[v]){
            if(e.to == p) continue;
            auto result = self(self, e.to, v);
            result.first += e.cost;
            if(ret.first < result.first){
                ret = result;
            }
        }
        return ret;
    };
    auto [_, v1] = dfs(dfs, 0, -1);
    auto [d, v2] = dfs(dfs, v1, -1);
    return tuple<T, int, int>(d, v1, v2);
}