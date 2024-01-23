#pragma once

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */

struct UnionFind {
    vector<int> par;
    UnionFind(int n) {
        par.assign(n, -1);
    };
    int find(int x) {
        if(par[x] < 0)
            return x;
        else
            return par[x] = find(par[x]);
    }
    int size(int x) {
        x = find(x);
        return -1 * par[x];
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return false;
        if(size(x) < size(y))
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    vector<int> leaders() {
        vector<int> res;
        for(int i = 0; i < (int)par.size(); i++) {
            if(par[i] < 0)
                res.push_back(i);
        }
        return res;
    }
};