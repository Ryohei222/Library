#pragma once

/**
 * @brief セグ木 チートシート
 * @cite https://betrue12.hateblo.jp/entry/2020/09/23/005940 (改変あり)
 */

#include <numeric>
#include <algorithm>

#include <atcoder/segtree>
#include <atcoder/lazysegtree>

struct RangeAddRangeMin {
    using S = long long;
    using F = long long;

    static constexpr S inf = std::numeric_limits<S>::max();

    static constexpr S op(S a, S b) { return std::min(a, b); }
    static constexpr S e() { return inf; }
    static constexpr S mapping(F f, S x) { return f + x; }
    static constexpr F composition(F f, F g) { return f + g; }
    static constexpr F id() { return 0; }

    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
};

struct RangeAddRangeMax {
    using S = long long;
    using F = long long;

    static constexpr S minf = std::numeric_limits<S>::min();

    static constexpr S op(S a, S b) { return std::max(a, b); }
    static constexpr S e() { return minf; }
    static constexpr S mapping(F f, S x) { return f + x; }
    static constexpr F composition(F f, F g) { return f + g; }
    static constexpr F id() { return 0; }

    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
};

struct RangeAddRangeSum {
    struct S {
        long long value;
        int size;
    };
    using F = long long;

    static constexpr S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
    static constexpr S e() { return {0, 0}; }
    static constexpr S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
    static constexpr F composition(F f, F g) { return f + g; }
    static constexpr F id() { return 0; }
    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
};

struct RangeUpdateRangeMin {
    using S = long long;
    using F = long long;

    static constexpr S inf = std::numeric_limits<S>::max();
    static constexpr F id = std::numeric_limits<S>::max();

    static constexpr S op(S a, S b) { return std::min(a, b); }
    static constexpr S e() { return inf; }
    static constexpr S mapping(F f, S x) { return (f == id ? x : f); }
    static constexpr F composition(F f, F g) { return (f == id ? g : f); }
    static constexpr F id() { return id; }
    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
};

struct RangeUpdateRangeMax {
    using S = long long;
    using F = long long;

    static constexpr S minf = std::numeric_limits<S>::min();
    static constexpr F id = std::numeric_limits<S>::max();

    static constexpr S op(S a, S b) { return std::max(a, b); }
    static constexpr S e() { return minf; }
    static constexpr S mapping(F f, S x) { return (f == id ? x : f); }
    static constexpr F composition(F f, F g) { return (f == id ? g : f); }
    static constexpr F id() { return id; }
    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
};

struct RangeUpdateRangeSum {
    struct S {
        long long value;
        int size;
    };
    using F = long long;

    static constexpr const F ID = std::numeric_limits<F>::max();

    static constexpr S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
    static constexpr S e() { return {0, 0}; }
    static constexpr S mapping(F f, S x) {
        if(f != ID) x.value = f * x.size;
        return x;
    }
    static constexpr F composition(F f, F g) { return (f == ID ? g : f); }
    static constexpr F id() { return ID; }
    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
};