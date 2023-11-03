---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
    title: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment-tree.md
    document_title: Segment Tree
    links:
    - https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp
  bundledCode: "#line 2 \"src/DataStructure/segment-tree.hpp\"\n\n/**\n * @brief Segment\
    \ Tree\n * @docs docs/segment-tree.md\n */\n\ntemplate<typename T, typename F>\n\
    struct SegmentTree{\n    int n, sz;\n    vector<T> seg;\n    T id;\n    F f;\n\
    \    SegmentTree(int n, const F f, const T id) : n(n), f(f), id(id){\n       \
    \ sz = 1;\n        while(sz < n) sz <<= 1;\n        seg.assign(2 * sz, id);\n\
    \    }\n    SegmentTree(const vector<T> &v, const F f, const T id) : id(id), f(f){\n\
    \        n = (int)v.size();\n        SegmentTree(n, f, id);\n        build(v);\n\
    \    }\n    void build(const vector<T> &v){\n        for(int i = 0; i < n; i++)\
    \ seg[sz + i] = v[i];\n        for(int i = sz - 1; i > 0; --i) seg[i] = f(seg[i\
    \ * 2], seg[i * 2 + 1]);\n    }\n    void set(int idx, T x){\n        seg[sz +\
    \ idx] = x;\n        int par = (sz + idx) >> 1;\n        while(par > 0){\n   \
    \         seg[par] = f(seg[par * 2], seg[par * 2 + 1]);\n            par >>= 1;\n\
    \        }\n    }\n    T get(int idx){\n        return seg[sz + idx];\n    }\n\
    \    void apply(int idx, T x){\n        set(idx, f(x, get(idx)));\n    }\n   \
    \ T prod(int l, int r){\n        T sl = id, sr = id;\n        l += sz, r += sz;\n\
    \        while(l < r){\n            if(l & 1)  sl = f(sl, seg[l++]);\n       \
    \     if(r & 1)  sr = f(seg[--r], sr);\n            l >>= 1, r >>= 1;\n      \
    \  }\n        return f(sl, sr);\n    }\n};\n\n// https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\n\
    \ntemplate< typename T, typename F >\nSegmentTree< T, F > get_segment_tree(int\
    \ N, const F &f, const T &ti) {\n    return SegmentTree{N, f, ti};\n}\n\ntemplate<\
    \ typename T, typename F >\nSegmentTree< T, F > get_segment_tree(const vector<\
    \ T > &v, const F &f, const T &ti) {\n    return SegmentTree{v, f, ti};\n}\n"
  code: "#pragma once\n\n/**\n * @brief Segment Tree\n * @docs docs/segment-tree.md\n\
    \ */\n\ntemplate<typename T, typename F>\nstruct SegmentTree{\n    int n, sz;\n\
    \    vector<T> seg;\n    T id;\n    F f;\n    SegmentTree(int n, const F f, const\
    \ T id) : n(n), f(f), id(id){\n        sz = 1;\n        while(sz < n) sz <<= 1;\n\
    \        seg.assign(2 * sz, id);\n    }\n    SegmentTree(const vector<T> &v, const\
    \ F f, const T id) : id(id), f(f){\n        n = (int)v.size();\n        SegmentTree(n,\
    \ f, id);\n        build(v);\n    }\n    void build(const vector<T> &v){\n   \
    \     for(int i = 0; i < n; i++) seg[sz + i] = v[i];\n        for(int i = sz -\
    \ 1; i > 0; --i) seg[i] = f(seg[i * 2], seg[i * 2 + 1]);\n    }\n    void set(int\
    \ idx, T x){\n        seg[sz + idx] = x;\n        int par = (sz + idx) >> 1;\n\
    \        while(par > 0){\n            seg[par] = f(seg[par * 2], seg[par * 2 +\
    \ 1]);\n            par >>= 1;\n        }\n    }\n    T get(int idx){\n      \
    \  return seg[sz + idx];\n    }\n    void apply(int idx, T x){\n        set(idx,\
    \ f(x, get(idx)));\n    }\n    T prod(int l, int r){\n        T sl = id, sr =\
    \ id;\n        l += sz, r += sz;\n        while(l < r){\n            if(l & 1)\
    \  sl = f(sl, seg[l++]);\n            if(r & 1)  sr = f(seg[--r], sr);\n     \
    \       l >>= 1, r >>= 1;\n        }\n        return f(sl, sr);\n    }\n};\n\n\
    // https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\n\n\
    template< typename T, typename F >\nSegmentTree< T, F > get_segment_tree(int N,\
    \ const F &f, const T &ti) {\n    return SegmentTree{N, f, ti};\n}\n\ntemplate<\
    \ typename T, typename F >\nSegmentTree< T, F > get_segment_tree(const vector<\
    \ T > &v, const F &f, const T &ti) {\n    return SegmentTree{v, f, ti};\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/segment-tree.hpp
  requiredBy: []
  timestamp: '2023-11-03 15:30:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
documentation_of: src/DataStructure/segment-tree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/segment-tree.hpp
- /library/src/DataStructure/segment-tree.hpp.html
title: Segment Tree
---
