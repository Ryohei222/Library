#pragma once

/**
 * @brief Fenwick tree
 * @docs docs/fenwick-tree.md
 */

template<typename T = long long int>
struct FenwickTree{
    int n;
    vector<T> bit;
    FenwickTree(int n) : n(n) {
        bit.assign(n + 1, T(0));
    };
    FenwickTree(const vector<T> &a){
        n = (int)a.size();
        bit.assign(n + 1, T(0));
        for(int i = 0; i < n; ++i){
            apply(i, a[i]);
        }
    };
    void apply(int idx, T x){
        ++idx;
        while(idx <= n){
            bit[idx] += x;
            idx += idx & -idx;
        }
    };
    T prod(int r){
        T ret = T(0);
        ++r;
        while(r > 0){
            ret += bit[r];
            r -= r & -r;
        }
        return ret;
    };
    T prod(int l, int r){
        if(l == 0) return prod(r - 1);
        else return prod(r - 1) - prod(l - 1);
    };
};