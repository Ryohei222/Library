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
    int root(int x) {
        if(par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    };
    int size(int x) {
        x = root(x);
        return -1 * par[x];
    };
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y)
            return false;
        if(size(x) < size(y))
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    };
};