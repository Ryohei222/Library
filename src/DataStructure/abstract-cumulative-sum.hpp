#pragma once

/**
 * @brief 抽象化累積和
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
    AbstructCumulativeSum(int n)
        : n(n), data(n + 1, T::e()) {}
    AbstructCumulativeSum(const std::vector<S> &a)
        : n((int)a.size()), data(n + 1, T::e()) {
        for(int i = 0; i < n; i++)
            add(i, a[i]);
        build();
    }
    void build() {
        debug_assert(!built);
        for(int i = 0; i < n; i++) {
            data[i + 1] = T::op(data[i], data[i + 1]);
        }
        built = true;
    }
    void add(int idx, S x) {
        debug_assert(!built);
        data[idx + 1] = T::op(data[idx + 1], x);
    }
    S sum(int l, int r) {
        debug_assert(built);
        return T::op(T::inv(data[l]), data[r]);
    }
};