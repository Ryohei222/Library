#pragma once

/**
 * @brief Segment Tree
 */

template <typename T, typename F>
struct SegmentTree {
    int n, sz;
    vector<T> seg;
    T id;
    F f;
    SegmentTree(int n, const F f, const T id)
        : n(n), f(f), id(id) {
        sz = 1;
        while(sz < n)
            sz <<= 1;
        seg.assign(2 * sz, id);
    }
    SegmentTree(const vector<T> &v, const F f, const T id)
        : id(id), f(f) {
        n = (int)v.size();
        sz = 1;
        while(sz < n)
            sz *= 2;
        seg.assign(2 * sz, id);
        build(v);
    }
    void build(const vector<T> &v) {
        for(int i = 0; i < n; i++)
            seg[sz + i] = v[i];
        for(int i = sz - 1; i > 0; --i)
            seg[i] = f(seg[i * 2], seg[i * 2 + 1]);
    }
    void set(int idx, T x) {
        seg[sz + idx] = x;
        int par = (sz + idx) >> 1;
        while(par > 0) {
            seg[par] = f(seg[par * 2], seg[par * 2 + 1]);
            par >>= 1;
        }
    }
    T get(int idx) {
        return seg[sz + idx];
    }
    void apply(int idx, T x) {
        set(idx, f(x, get(idx)));
    }
    T prod(int l, int r) {
        T sl = id, sr = id;
        l += sz, r += sz;
        while(l < r) {
            if(l & 1) sl = f(sl, seg[l++]);
            if(r & 1) sr = f(seg[--r], sr);
            l >>= 1, r >>= 1;
        }
        return f(sl, sr);
    }
};

// https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp

template <typename T, typename F>
SegmentTree<T, F> get_segment_tree(int N, const F &f, const T &ti) {
    return SegmentTree{N, f, ti};
}

template <typename T, typename F>
SegmentTree<T, F> get_segment_tree(const vector<T> &v, const F &f, const T &ti) {
    return SegmentTree{v, f, ti};
}