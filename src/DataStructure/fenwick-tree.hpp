#pragma once

/**
 * @brief Fenwick Tree (Binary Indexed Tree)
 * @docs docs/fenwick-tree.md
 */

template <typename T = long long int>
struct FenwickTree {
    int n;
    vector<T> bit;
    /**
     * @brief コンストラクタ
     * @param n 要素数
     * @note 時間計算量: O(n)
     */
    FenwickTree(int n)
        : n(n) {
        bit.assign(n + 1, T(0));
    }
    /**
     * @brief 配列からの初期化
     * @param a 初期値を持つ配列
     * @note 時間計算量: O(n log n)
     */
    FenwickTree(const vector<T> &a) {
        n = (int)a.size();
        bit.assign(n + 1, T(0));
        for(int i = 0; i < n; ++i) {
            apply(i, a[i]);
        }
    }
    /**
     * @brief 指定位置に値を加算する
     * @param idx インデックス (0-indexed)
     * @param x 加算する値
     * @note 時間計算量: O(log n)
     */
    void apply(int idx, T x) {
        ++idx;
        while(idx <= n) {
            bit[idx] += x;
            idx += idx & -idx;
        }
    }
    /**
     * @brief 指定位置の値を設定する
     * @param idx インデックス (0-indexed)
     * @param x 設定する値
     * @note 時間計算量: O(log n)
     */
    void set(int idx, T x) {
        T pre = prod(idx, idx + 1);
        apply(idx, x - pre);
    }
    /**
     * @brief 区間[0, r)の総和を求める
     * @param r 右端（含まない）
     * @return 区間[0, r)の総和
     * @note 時間計算量: O(log n)
     */
    T prod(int r) {
        T ret = T(0);
        ++r;
        while(r > 0) {
            ret += bit[r];
            r -= r & -r;
        }
        return ret;
    }
    /**
     * @brief 区間[l, r)の総和を求める
     * @param l 左端（含む）
     * @param r 右端（含まない）
     * @return 区間[l, r)の総和
     * @note 時間計算量: O(log n)
     */
    T prod(int l, int r) {
        if(l == 0)
            return prod(r - 1);
        else
            return prod(r - 1) - prod(l - 1);
    }
};