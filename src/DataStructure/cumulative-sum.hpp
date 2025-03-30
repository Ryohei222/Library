#pragma once
#include <vector>
#include <cassert>
#include <concepts>

template <std::integral T>
struct CumulativeSum {
  private:
    bool built = false;

  public:
    int n;
    std::vector<T> data;
    CumulativeSum(int n)
        : n(n), data(n + 1, T()) {}
    CumulativeSum(const std::vector<T> &a)
        : n((int)a.size()), data(n + 1, T()) {
        for(int i = 0; i < n; i++)
            add(i, a[i]);
        build();
    }
    /**
     * @brief 累積和を構築する
     *
     */
    void build() {
#ifdef LOCAL
        assert(!built);
#endif
        for(int i = 0; i < n; i++) {
            data[i + 1] = data[i] + data[i + 1];
        }
        built = true;
    }
    /**
     * @brief data[idx + 1] += x
     *
     * @param idx 加算する位置 (0-indexed)
     * @param x 加算する値
     */
    void add(int idx, T x) {
#ifdef LOCAL
        assert(!built);
#endif
        assert(!built);
        data[idx + 1] += x;
    }
    /**
     * @brief [l, r) の和, data[r] - data[l]
     *
     * @param l 左端の位置 (0-indexed, 閉区間)
     * @param r 右端の位置 (0-indexed, 開区間)
     * @return T 区間の総和
     */
    T sum(int l, int r) {
#ifdef LOCAL
        assert(built);
#endif
        return data[r] - data[l];
    }
};