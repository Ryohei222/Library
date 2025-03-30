---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/algebraic-structure.hpp
    title: src/Math/algebraic-structure.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
    title: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tree
    links:
    - https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp
  bundledCode: "#line 2 \"src/DataStructure/segment-tree.hpp\"\n\n#line 2 \"src/Math/algebraic-structure.hpp\"\
    \n\n#include <numeric>\n#include <concepts>\n\ntemplate <typename T>\nconcept\
    \ HasInnerType = requires() {\n    typename T::S;\n};\n\ntemplate <typename T>\n\
    concept HasIdentity = requires() {\n    { T::e() } -> std::same_as<typename T::S>;\n\
    };\n\ntemplate <typename T>\nconcept HasInverse = requires() {\n    { T::inv(std::declval<typename\
    \ T::S>()) } -> std::same_as<typename T::S>;\n};\n\ntemplate <typename T>\nconcept\
    \ HasBinaryOperation = requires() {\n    { T::op(std::declval<typename T::S>(),\
    \ std::declval<typename T::S>()) } -> std::same_as<typename T::S>;\n};\n\ntemplate\
    \ <class T>\nconcept MonoidConcept = HasInnerType<T> && HasIdentity<T> && HasBinaryOperation<T>;\n\
    \ntemplate <class T>\nconcept GroupConcept = MonoidConcept<T> && HasInverse<T>;\n\
    \ntemplate <std::integral T>\nstruct MinMonoid {\n    using S = T;\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::max(); }\n    static constexpr\
    \ S op(const S &a, const S &b) { return std::min(a, b); }\n};\n\ntemplate <std::integral\
    \ T>\nstruct MaxMonoid {\n    using S = T;\n    static constexpr S e() { return\
    \ std::numeric_limits<S>::min(); }\n    static constexpr S op(const S &a, const\
    \ S &b) { return std::max(a, b); }\n};\n\ntemplate <typename T>\nstruct MultiplicativeMonoid\
    \ {\n    using S = T;\n    static constexpr S e() { return S(1); }\n    static\
    \ constexpr S op(const S &a, const S &b) { return a * b; }\n};\n\ntemplate <typename\
    \ T>\nstruct AdditiveGroup {\n    using S = T;\n    static constexpr S e() { return\
    \ S(); }\n    static constexpr S op(const S &a, const S &b) { return a + b; }\n\
    \    static constexpr S inv(const S &a) { return -a; }\n};\n\ntemplate <typename\
    \ T>\nstruct XORGroup {\n    using S = T;\n    static constexpr S e() { return\
    \ S(); }\n    static constexpr S op(const S &a, const S &b) { return a ^ b; }\n\
    \    static constexpr S inv(const S &a) { return a; }\n};\n#line 4 \"src/DataStructure/segment-tree.hpp\"\
    \n\n/**\n * @brief Segment Tree\n * @cite https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <MonoidConcept Monoid>\nstruct SegmentTree\
    \ {\n    using S = typename Monoid::S;\n\n  private:\n    int n, sz;\n\n    vector<S>\
    \ seg;\n\n  public:\n    SegmentTree() = default;\n\n    explicit SegmentTree(int\
    \ n)\n        : n(n) {\n        sz = 1;\n        while(sz < n)\n            sz\
    \ <<= 1;\n        seg.assign(2 * sz, Monoid::e());\n    }\n\n    explicit SegmentTree(const\
    \ vector<S> &v)\n        : SegmentTree((int)v.size()) {\n        build(v);\n \
    \   }\n\n    void build(const vector<S> &v) {\n        assert(n == (int)v.size());\n\
    \        for(int k = 0; k < n; k++)\n            seg[k + sz] = v[k];\n       \
    \ for(int k = sz - 1; k > 0; k--) {\n            seg[k] = Monoid::op(seg[2 * k\
    \ + 0], seg[2 * k + 1]);\n        }\n    }\n\n    void set(int k, const S &x)\
    \ {\n        k += sz;\n        seg[k] = x;\n        while(k >>= 1) {\n       \
    \     seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\
    \n    S get(int k) const { return seg[k + sz]; }\n\n    S operator[](int k) const\
    \ { return get(k); }\n\n    void apply(int k, const S &x) {\n        k += sz;\n\
    \        seg[k] = Monoid::op(seg[k], x);\n        while(k >>= 1) {\n         \
    \   seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n\
    \    S prod(int l, int r) const {\n        if(l >= r) return Monoid::e();\n  \
    \      S L = Monoid::e(), R = Monoid::e();\n        for(l += sz, r += sz; l <\
    \ r; l >>= 1, r >>= 1) {\n            if(l & 1) L = Monoid::op(L, seg[l++]);\n\
    \            if(r & 1) R = Monoid::op(seg[--r], R);\n        }\n        return\
    \ Monoid::op(L, R);\n    }\n\n    S all_prod() const { return seg[1]; }\n\n  \
    \  template <typename C>\n    int find_first(int l, const C &check) const {\n\
    \        if(l >= n) return n;\n        l += sz;\n        S sum = Monoid::e();\n\
    \        do {\n            while((l & 1) == 0)\n                l >>= 1;\n   \
    \         if(check(Monoid::op(sum, seg[l]))) {\n                while(l < sz)\
    \ {\n                    l <<= 1;\n                    auto nxt = Monoid::op(sum,\
    \ seg[l]);\n                    if(not check(nxt)) {\n                       \
    \ sum = nxt;\n                        l++;\n                    }\n          \
    \      }\n                return l + 1 - sz;\n            }\n            sum =\
    \ Monoid::op(sum, seg[l++]);\n        } while((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <typename C>\n    int find_last(int r, const C &check)\
    \ const {\n        if(r <= 0) return -1;\n        r += sz;\n        S sum = Monoid::e();\n\
    \        do {\n            r--;\n            while(r > 1 and (r & 1))\n      \
    \          r >>= 1;\n            if(check(Monoid::op(seg[r], sum))) {\n      \
    \          while(r < sz) {\n                    r = (r << 1) + 1;\n          \
    \          auto nxt = Monoid::op(seg[r], sum);\n                    if(not check(nxt))\
    \ {\n                        sum = nxt;\n                        r--;\n      \
    \              }\n                }\n                return r - sz;\n        \
    \    }\n            sum = Monoid::op(seg[r], sum);\n        } while((r & -r) !=\
    \ r);\n        return -1;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../Math/algebraic-structure.hpp\"\n\n/**\n * @brief\
    \ Segment Tree\n * @cite https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <MonoidConcept Monoid>\nstruct SegmentTree\
    \ {\n    using S = typename Monoid::S;\n\n  private:\n    int n, sz;\n\n    vector<S>\
    \ seg;\n\n  public:\n    SegmentTree() = default;\n\n    explicit SegmentTree(int\
    \ n)\n        : n(n) {\n        sz = 1;\n        while(sz < n)\n            sz\
    \ <<= 1;\n        seg.assign(2 * sz, Monoid::e());\n    }\n\n    explicit SegmentTree(const\
    \ vector<S> &v)\n        : SegmentTree((int)v.size()) {\n        build(v);\n \
    \   }\n\n    void build(const vector<S> &v) {\n        assert(n == (int)v.size());\n\
    \        for(int k = 0; k < n; k++)\n            seg[k + sz] = v[k];\n       \
    \ for(int k = sz - 1; k > 0; k--) {\n            seg[k] = Monoid::op(seg[2 * k\
    \ + 0], seg[2 * k + 1]);\n        }\n    }\n\n    void set(int k, const S &x)\
    \ {\n        k += sz;\n        seg[k] = x;\n        while(k >>= 1) {\n       \
    \     seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\
    \n    S get(int k) const { return seg[k + sz]; }\n\n    S operator[](int k) const\
    \ { return get(k); }\n\n    void apply(int k, const S &x) {\n        k += sz;\n\
    \        seg[k] = Monoid::op(seg[k], x);\n        while(k >>= 1) {\n         \
    \   seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n\
    \    S prod(int l, int r) const {\n        if(l >= r) return Monoid::e();\n  \
    \      S L = Monoid::e(), R = Monoid::e();\n        for(l += sz, r += sz; l <\
    \ r; l >>= 1, r >>= 1) {\n            if(l & 1) L = Monoid::op(L, seg[l++]);\n\
    \            if(r & 1) R = Monoid::op(seg[--r], R);\n        }\n        return\
    \ Monoid::op(L, R);\n    }\n\n    S all_prod() const { return seg[1]; }\n\n  \
    \  template <typename C>\n    int find_first(int l, const C &check) const {\n\
    \        if(l >= n) return n;\n        l += sz;\n        S sum = Monoid::e();\n\
    \        do {\n            while((l & 1) == 0)\n                l >>= 1;\n   \
    \         if(check(Monoid::op(sum, seg[l]))) {\n                while(l < sz)\
    \ {\n                    l <<= 1;\n                    auto nxt = Monoid::op(sum,\
    \ seg[l]);\n                    if(not check(nxt)) {\n                       \
    \ sum = nxt;\n                        l++;\n                    }\n          \
    \      }\n                return l + 1 - sz;\n            }\n            sum =\
    \ Monoid::op(sum, seg[l++]);\n        } while((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <typename C>\n    int find_last(int r, const C &check)\
    \ const {\n        if(r <= 0) return -1;\n        r += sz;\n        S sum = Monoid::e();\n\
    \        do {\n            r--;\n            while(r > 1 and (r & 1))\n      \
    \          r >>= 1;\n            if(check(Monoid::op(seg[r], sum))) {\n      \
    \          while(r < sz) {\n                    r = (r << 1) + 1;\n          \
    \          auto nxt = Monoid::op(seg[r], sum);\n                    if(not check(nxt))\
    \ {\n                        sum = nxt;\n                        r--;\n      \
    \              }\n                }\n                return r - sz;\n        \
    \    }\n            sum = Monoid::op(seg[r], sum);\n        } while((r & -r) !=\
    \ r);\n        return -1;\n    }\n};"
  dependsOn:
  - src/Math/algebraic-structure.hpp
  isVerificationFile: false
  path: src/DataStructure/segment-tree.hpp
  requiredBy: []
  timestamp: '2025-03-30 10:41:22+09:00'
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
