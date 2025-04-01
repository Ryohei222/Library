#pragma once

#include "../Math/algebraic-structure.hpp"

/**
 * @brief Segment Tree（セグメント木）
 * @docs docs/segment-tree.md
 * @cite https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp (改変あり)
 */

template <MonoidConcept Monoid>
struct SegmentTree {
    using S = typename Monoid::S;

  private:
    int n, sz;

    vector<S> seg;

  public:
        SegmentTree() = default;

    /**
     * @brief コンストラクタ
     * @param n 要素数
     * @note 時間計算量: O(n)
     */
    explicit SegmentTree(int n)
        : n(n) {
        sz = 1;
        while(sz < n)
            sz <<= 1;
        seg.assign(2 * sz, Monoid::e());
    }

    /**
     * @brief 配列からの初期化
     * @param v 初期値を持つ配列
     * @note 時間計算量: O(n)
     */
    explicit SegmentTree(const vector<S> &v)
        : SegmentTree((int)v.size()) {
        build(v);
    }

    /**
     * @brief 配列から木を構築する
     * @param v 初期値を持つ配列
     * @note 時間計算量: O(n)
     */
    void build(const vector<S> &v) {
        assert(n == (int)v.size());
        for(int k = 0; k < n; k++)
            seg[k + sz] = v[k];
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    /**
     * @brief 指定位置の値を設定する
     * @param k インデックス
     * @param x 設定する値
     * @note 時間計算量: O(log n)
     */
    void set(int k, const S &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    /**
     * @brief 指定位置の値を取得する
     * @param k インデックス
     * @return 位置kの値
     * @note 時間計算量: O(1)
     */
    S get(int k) const { return seg[k + sz]; }

        S operator[](int k) const { return get(k); }

    /**
     * @brief 指定位置に値を適用する（seg[k] = Monoid::op(seg[k], x)）
     * @param k インデックス
     * @param x 適用する値
     * @note 時間計算量: O(log n)
     */
    void apply(int k, const S &x) {
        k += sz;
        seg[k] = Monoid::op(seg[k], x);
        while(k >>= 1) {
            seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    /**
     * @brief 区間[l, r)の総積を求める
     * @param l 左端
     * @param r 右端
     * @return 区間の総積
     * @note 時間計算量: O(log n)
     */
    S prod(int l, int r) const {
        if(l >= r) return Monoid::e();
        S L = Monoid::e(), R = Monoid::e();
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = Monoid::op(L, seg[l++]);
            if(r & 1) R = Monoid::op(seg[--r], R);
        }
        return Monoid::op(L, R);
    }

    /**
     * @brief 全要素の総積を求める
     * @return 全要素の総積
     * @note 時間計算量: O(1)
     */
    S all_prod() const { return seg[1]; }

    /**
     * @brief 条件を満たす最初の位置を見つける
     * @param l 探索開始位置
     * @param check 条件を表す関数（bool(S)型）
     * @return 条件を満たす最小のインデックス（見つからなければn）
     * @note 時間計算量: O(log n)
     */
    template <typename C>
    int find_first(int l, const C &check) const {
        if(l >= n) return n;
        l += sz;
        S sum = Monoid::e();
        do {
            while((l & 1) == 0)
                l >>= 1;
            if(check(Monoid::op(sum, seg[l]))) {
                while(l < sz) {
                    l <<= 1;
                    auto nxt = Monoid::op(sum, seg[l]);
                    if(not check(nxt)) {
                        sum = nxt;
                        l++;
                    }
                }
                return l + 1 - sz;
            }
            sum = Monoid::op(sum, seg[l++]);
        } while((l & -l) != l);
        return n;
    }

    /**
     * @brief 条件を満たす最後の位置を見つける
     * @param r 探索終了位置（この手前まで）
     * @param check 条件を表す関数（bool(S)型）
     * @return 条件を満たす最大のインデックス（見つからなければ-1）
     * @note 時間計算量: O(log n)
     */
    template <typename C>
    int find_last(int r, const C &check) const {
        if(r <= 0) return -1;
        r += sz;
        S sum = Monoid::e();
        do {
            r--;
            while(r > 1 and (r & 1))
                r >>= 1;
            if(check(Monoid::op(seg[r], sum))) {
                while(r < sz) {
                    r = (r << 1) + 1;
                    auto nxt = Monoid::op(seg[r], sum);
                    if(not check(nxt)) {
                        sum = nxt;
                        r--;
                    }
                }
                return r - sz;
            }
            sum = Monoid::op(seg[r], sum);
        } while((r & -r) != r);
        return -1;
    }
};