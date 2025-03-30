#pragma once

/**
 * @brief 累積和
 */

#include <vector>
#include <cassert>
#include <concepts>
#include "../Util/debug.hpp"

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

    void build() {
        debug_assert(!built);
        for(int i = 0; i < n; i++) {
            data[i + 1] = data[i] + data[i + 1];
        }
        built = true;
    }

    void add(int idx, T x) {
        debug_assert(!built);
        data[idx + 1] += x;
    }

    T sum(int l, int r) {
        debug_assert(built);
        return data[r] - data[l];
    }
};