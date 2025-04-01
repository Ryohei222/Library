#pragma once

/**
 * @brief 抽象化累積和
 * @docs docs/abstract-cumulative-sum.md
 */

#include <vector>
#include <cassert>
#include <concepts>
#include "../Util/debug.hpp"
#include "../Math/algebraic-structure.hpp"

template <GroupConcept T>
struct AbstructCumulativeSum {
  private:
    bool built = false;

  public:
    using S = typename T::S;
    int n;
    std::vector<S> data;

    /**
     * @brief コンストラクタ
     * @param n 要素数
     * @note 時間計算量: O(n)
     */
    AbstructCumulativeSum(int n)
        : n(n), data(n + 1, T::e()) {}
    
    /**
     * @brief 配列からの初期化コンストラクタ
     * @param a 初期値を持つ配列
     * @note 時間計算量: O(n)
     */
    AbstructCumulativeSum(const std::vector<S> &a)
        : n((int)a.size()), data(n + 1, T::e()) {
        for(int i = 0; i < n; i++)
            add(i, a[i]);
        build();
    }
    
    /**
     * @brief 累積和を構築する
     * @note 時間計算量: O(n)
     * @note add関数で値を全て追加した後に呼び出す必要がある
     */
    void build() {
        debug_assert(!built);
        for(int i = 0; i < n; i++) {
            data[i + 1] = T::op(data[i], data[i + 1]);
        }
        built = true;
    }
    
    /**
     * @brief 指定位置に値を追加する
     * @param idx インデックス (0-indexed)
     * @param x 追加する値
     * @note 時間計算量: O(1)
     * @note build関数を呼び出す前にのみ使用可能
     */
    void add(int idx, S x) {
        debug_assert(!built);
        data[idx + 1] = T::op(data[idx + 1], x);
    }
    
    /**
     * @brief 区間[l, r)の総和を求める
     * @param l 左端（含む）
     * @param r 右端（含まない）
     * @return 区間[l, r)の総和
     * @note 時間計算量: O(1)
     * @note build関数を呼び出した後にのみ使用可能
     */
    S sum(int l, int r) {
        debug_assert(built);
        return T::op(T::inv(data[l]), data[r]);
    }
};