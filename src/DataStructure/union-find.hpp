#pragma once

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */

struct UnionFind {
    vector<int> par;
    /**
     * @brief コンストラクタ
     * @param n 要素数
     * @note 時間計算量: O(n)
     */
    UnionFind(int n) {
        par.assign(n, -1);
    };
    /**
     * @brief 頂点xの根を求める
     * @param x 頂点
     * @return int 根の頂点番号
     * @note 時間計算量: 償却O(α(n))
     *       α(n)はアッカーマン関数の逆関数で、ほぼO(1)と考えて良い
     */
    int find(int x) {
        if(par[x] < 0)
            return x;
        else
            return par[x] = find(par[x]);
    }
    /**
     * @brief 頂点xが属する集合のサイズを求める
     * @param x 頂点
     * @return int 集合のサイズ
     * @note 時間計算量: 償却O(α(n))
     */
    int size(int x) {
        x = find(x);
        return -1 * par[x];
    }
    /**
     * @brief 頂点xと頂点yが属する集合を併合する
     * @param x 頂点
     * @param y 頂点
     * @return bool 併合に成功したかどうか（既に同じ集合の場合はfalse）
     * @note 時間計算量: 償却O(α(n))
     *       小さい方の集合を大きい方に併合する（union by size）
     */
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
    /**
     * @brief 頂点xと頂点yが同じ集合に属するかどうかを判定する
     * @param x 頂点
     * @param y 頂点
     * @return bool 同じ集合に属するならtrue
     * @note 時間計算量: 償却O(α(n))
     */
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    /**
     * @brief 各集合の代表元（根）のリストを取得する
     * @return vector<int> 代表元のリスト
     * @note 時間計算量: O(n)
     */
    vector<int> leaders() {
        vector<int> res;
        for(int i = 0; i < (int)par.size(); i++) {
            if(par[i] < 0)
                res.push_back(i);
        }
        return res;
    }
};