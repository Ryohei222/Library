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
    _deprecated_at_docs: docs/segment-tree.md
    document_title: "Segment Tree\uFF08\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\uFF09"
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
    \n\n/**\n * @brief Segment Tree\uFF08\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\uFF09\
    \n * @docs docs/segment-tree.md\n * @cite https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <MonoidConcept Monoid>\nstruct SegmentTree\
    \ {\n    using S = typename Monoid::S;\n\n  private:\n    int n, sz;\n\n    vector<S>\
    \ seg;\n\n  public:\n        SegmentTree() = default;\n\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u8981\u7D20\u6570\
    \n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     */\n    explicit SegmentTree(int\
    \ n)\n        : n(n) {\n        sz = 1;\n        while(sz < n)\n            sz\
    \ <<= 1;\n        seg.assign(2 * sz, Monoid::e());\n    }\n\n    /**\n     * @brief\
    \ \u914D\u5217\u304B\u3089\u306E\u521D\u671F\u5316\n     * @param v \u521D\u671F\
    \u5024\u3092\u6301\u3064\u914D\u5217\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : O(n)\n     */\n    explicit SegmentTree(const vector<S> &v)\n        : SegmentTree((int)v.size())\
    \ {\n        build(v);\n    }\n\n    /**\n     * @brief \u914D\u5217\u304B\u3089\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\n     * @param v \u521D\u671F\u5024\u3092\
    \u6301\u3064\u914D\u5217\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n\
    \     */\n    void build(const vector<S> &v) {\n        assert(n == (int)v.size());\n\
    \        for(int k = 0; k < n; k++)\n            seg[k + sz] = v[k];\n       \
    \ for(int k = sz - 1; k > 0; k--) {\n            seg[k] = Monoid::op(seg[2 * k\
    \ + 0], seg[2 * k + 1]);\n        }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\
    \u4F4D\u7F6E\u306E\u5024\u3092\u8A2D\u5B9A\u3059\u308B\n     * @param k \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u8A2D\u5B9A\u3059\u308B\u5024\
    \n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    void set(int\
    \ k, const S &x) {\n        k += sz;\n        seg[k] = x;\n        while(k >>=\
    \ 1) {\n            seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n   \
    \     }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u4F4D\u7F6E\u306E\u5024\u3092\
    \u53D6\u5F97\u3059\u308B\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @return \u4F4D\u7F6Ek\u306E\u5024\n     * @note \u6642\u9593\u8A08\u7B97\
    \u91CF: O(1)\n     */\n    S get(int k) const { return seg[k + sz]; }\n\n    \
    \    S operator[](int k) const { return get(k); }\n\n    /**\n     * @brief \u6307\
    \u5B9A\u4F4D\u7F6E\u306B\u5024\u3092\u9069\u7528\u3059\u308B\uFF08seg[k] = Monoid::op(seg[k],\
    \ x)\uFF09\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param\
    \ x \u9069\u7528\u3059\u308B\u5024\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\n     */\n    void apply(int k, const S &x) {\n        k += sz;\n \
    \       seg[k] = Monoid::op(seg[k], x);\n        while(k >>= 1) {\n          \
    \  seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n\
    \    /**\n     * @brief \u533A\u9593[l, r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\n     * @param l \u5DE6\u7AEF\n     * @param r \u53F3\u7AEF\n     * @return\
    \ \u533A\u9593\u306E\u7DCF\u7A4D\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\n     */\n    S prod(int l, int r) const {\n        if(l >= r) return\
    \ Monoid::e();\n        S L = Monoid::e(), R = Monoid::e();\n        for(l +=\
    \ sz, r += sz; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) L = Monoid::op(L,\
    \ seg[l++]);\n            if(r & 1) R = Monoid::op(seg[--r], R);\n        }\n\
    \        return Monoid::op(L, R);\n    }\n\n    /**\n     * @brief \u5168\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\n     * @return \u5168\u8981\u7D20\
    \u306E\u7DCF\u7A4D\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(1)\n     */\n\
    \    S all_prod() const { return seg[1]; }\n\n    /**\n     * @brief \u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6700\u521D\u306E\u4F4D\u7F6E\u3092\u898B\u3064\u3051\
    \u308B\n     * @param l \u63A2\u7D22\u958B\u59CB\u4F4D\u7F6E\n     * @param check\
    \ \u6761\u4EF6\u3092\u8868\u3059\u95A2\u6570\uFF08bool(S)\u578B\uFF09\n     *\
    \ @return \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\uFF08\u898B\u3064\u304B\u3089\u306A\u3051\u308C\u3070n\uFF09\
    \n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    template\
    \ <typename C>\n    int find_first(int l, const C &check) const {\n        if(l\
    \ >= n) return n;\n        l += sz;\n        S sum = Monoid::e();\n        do\
    \ {\n            while((l & 1) == 0)\n                l >>= 1;\n            if(check(Monoid::op(sum,\
    \ seg[l]))) {\n                while(l < sz) {\n                    l <<= 1;\n\
    \                    auto nxt = Monoid::op(sum, seg[l]);\n                   \
    \ if(not check(nxt)) {\n                        sum = nxt;\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l + 1 - sz;\n            }\n            sum = Monoid::op(sum, seg[l++]);\n \
    \       } while((l & -l) != l);\n        return n;\n    }\n\n    /**\n     * @brief\
    \ \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\u4F4D\u7F6E\u3092\u898B\
    \u3064\u3051\u308B\n     * @param r \u63A2\u7D22\u7D42\u4E86\u4F4D\u7F6E\uFF08\
    \u3053\u306E\u624B\u524D\u307E\u3067\uFF09\n     * @param check \u6761\u4EF6\u3092\
    \u8868\u3059\u95A2\u6570\uFF08bool(S)\u578B\uFF09\n     * @return \u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6700\u5927\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \uFF08\u898B\u3064\u304B\u3089\u306A\u3051\u308C\u3070-1\uFF09\n     * @note \u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    template <typename C>\n    int\
    \ find_last(int r, const C &check) const {\n        if(r <= 0) return -1;\n  \
    \      r += sz;\n        S sum = Monoid::e();\n        do {\n            r--;\n\
    \            while(r > 1 and (r & 1))\n                r >>= 1;\n            if(check(Monoid::op(seg[r],\
    \ sum))) {\n                while(r < sz) {\n                    r = (r << 1)\
    \ + 1;\n                    auto nxt = Monoid::op(seg[r], sum);\n            \
    \        if(not check(nxt)) {\n                        sum = nxt;\n          \
    \              r--;\n                    }\n                }\n              \
    \  return r - sz;\n            }\n            sum = Monoid::op(seg[r], sum);\n\
    \        } while((r & -r) != r);\n        return -1;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../Math/algebraic-structure.hpp\"\n\n/**\n * @brief\
    \ Segment Tree\uFF08\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\uFF09\n * @docs docs/segment-tree.md\n\
    \ * @cite https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <MonoidConcept Monoid>\nstruct SegmentTree\
    \ {\n    using S = typename Monoid::S;\n\n  private:\n    int n, sz;\n\n    vector<S>\
    \ seg;\n\n  public:\n        SegmentTree() = default;\n\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u8981\u7D20\u6570\
    \n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     */\n    explicit SegmentTree(int\
    \ n)\n        : n(n) {\n        sz = 1;\n        while(sz < n)\n            sz\
    \ <<= 1;\n        seg.assign(2 * sz, Monoid::e());\n    }\n\n    /**\n     * @brief\
    \ \u914D\u5217\u304B\u3089\u306E\u521D\u671F\u5316\n     * @param v \u521D\u671F\
    \u5024\u3092\u6301\u3064\u914D\u5217\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : O(n)\n     */\n    explicit SegmentTree(const vector<S> &v)\n        : SegmentTree((int)v.size())\
    \ {\n        build(v);\n    }\n\n    /**\n     * @brief \u914D\u5217\u304B\u3089\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\n     * @param v \u521D\u671F\u5024\u3092\
    \u6301\u3064\u914D\u5217\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n\
    \     */\n    void build(const vector<S> &v) {\n        assert(n == (int)v.size());\n\
    \        for(int k = 0; k < n; k++)\n            seg[k + sz] = v[k];\n       \
    \ for(int k = sz - 1; k > 0; k--) {\n            seg[k] = Monoid::op(seg[2 * k\
    \ + 0], seg[2 * k + 1]);\n        }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\
    \u4F4D\u7F6E\u306E\u5024\u3092\u8A2D\u5B9A\u3059\u308B\n     * @param k \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u8A2D\u5B9A\u3059\u308B\u5024\
    \n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    void set(int\
    \ k, const S &x) {\n        k += sz;\n        seg[k] = x;\n        while(k >>=\
    \ 1) {\n            seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n   \
    \     }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u4F4D\u7F6E\u306E\u5024\u3092\
    \u53D6\u5F97\u3059\u308B\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @return \u4F4D\u7F6Ek\u306E\u5024\n     * @note \u6642\u9593\u8A08\u7B97\
    \u91CF: O(1)\n     */\n    S get(int k) const { return seg[k + sz]; }\n\n    \
    \    S operator[](int k) const { return get(k); }\n\n    /**\n     * @brief \u6307\
    \u5B9A\u4F4D\u7F6E\u306B\u5024\u3092\u9069\u7528\u3059\u308B\uFF08seg[k] = Monoid::op(seg[k],\
    \ x)\uFF09\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param\
    \ x \u9069\u7528\u3059\u308B\u5024\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\n     */\n    void apply(int k, const S &x) {\n        k += sz;\n \
    \       seg[k] = Monoid::op(seg[k], x);\n        while(k >>= 1) {\n          \
    \  seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n\
    \    /**\n     * @brief \u533A\u9593[l, r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\n     * @param l \u5DE6\u7AEF\n     * @param r \u53F3\u7AEF\n     * @return\
    \ \u533A\u9593\u306E\u7DCF\u7A4D\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\n     */\n    S prod(int l, int r) const {\n        if(l >= r) return\
    \ Monoid::e();\n        S L = Monoid::e(), R = Monoid::e();\n        for(l +=\
    \ sz, r += sz; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) L = Monoid::op(L,\
    \ seg[l++]);\n            if(r & 1) R = Monoid::op(seg[--r], R);\n        }\n\
    \        return Monoid::op(L, R);\n    }\n\n    /**\n     * @brief \u5168\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\n     * @return \u5168\u8981\u7D20\
    \u306E\u7DCF\u7A4D\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(1)\n     */\n\
    \    S all_prod() const { return seg[1]; }\n\n    /**\n     * @brief \u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6700\u521D\u306E\u4F4D\u7F6E\u3092\u898B\u3064\u3051\
    \u308B\n     * @param l \u63A2\u7D22\u958B\u59CB\u4F4D\u7F6E\n     * @param check\
    \ \u6761\u4EF6\u3092\u8868\u3059\u95A2\u6570\uFF08bool(S)\u578B\uFF09\n     *\
    \ @return \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\uFF08\u898B\u3064\u304B\u3089\u306A\u3051\u308C\u3070n\uFF09\
    \n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    template\
    \ <typename C>\n    int find_first(int l, const C &check) const {\n        if(l\
    \ >= n) return n;\n        l += sz;\n        S sum = Monoid::e();\n        do\
    \ {\n            while((l & 1) == 0)\n                l >>= 1;\n            if(check(Monoid::op(sum,\
    \ seg[l]))) {\n                while(l < sz) {\n                    l <<= 1;\n\
    \                    auto nxt = Monoid::op(sum, seg[l]);\n                   \
    \ if(not check(nxt)) {\n                        sum = nxt;\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l + 1 - sz;\n            }\n            sum = Monoid::op(sum, seg[l++]);\n \
    \       } while((l & -l) != l);\n        return n;\n    }\n\n    /**\n     * @brief\
    \ \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\u4F4D\u7F6E\u3092\u898B\
    \u3064\u3051\u308B\n     * @param r \u63A2\u7D22\u7D42\u4E86\u4F4D\u7F6E\uFF08\
    \u3053\u306E\u624B\u524D\u307E\u3067\uFF09\n     * @param check \u6761\u4EF6\u3092\
    \u8868\u3059\u95A2\u6570\uFF08bool(S)\u578B\uFF09\n     * @return \u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6700\u5927\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \uFF08\u898B\u3064\u304B\u3089\u306A\u3051\u308C\u3070-1\uFF09\n     * @note \u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    template <typename C>\n    int\
    \ find_last(int r, const C &check) const {\n        if(r <= 0) return -1;\n  \
    \      r += sz;\n        S sum = Monoid::e();\n        do {\n            r--;\n\
    \            while(r > 1 and (r & 1))\n                r >>= 1;\n            if(check(Monoid::op(seg[r],\
    \ sum))) {\n                while(r < sz) {\n                    r = (r << 1)\
    \ + 1;\n                    auto nxt = Monoid::op(seg[r], sum);\n            \
    \        if(not check(nxt)) {\n                        sum = nxt;\n          \
    \              r--;\n                    }\n                }\n              \
    \  return r - sz;\n            }\n            sum = Monoid::op(seg[r], sum);\n\
    \        } while((r & -r) != r);\n        return -1;\n    }\n};"
  dependsOn:
  - src/Math/algebraic-structure.hpp
  isVerificationFile: false
  path: src/DataStructure/segment-tree.hpp
  requiredBy: []
  timestamp: '2025-04-01 15:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
documentation_of: src/DataStructure/segment-tree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/segment-tree.hpp
- /library/src/DataStructure/segment-tree.hpp.html
title: "Segment Tree\uFF08\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\uFF09"
---
## セグメント木（Segment Tree）

## 使用例

```cpp
// 最小値を管理するセグメント木
SegmentTree<MinMonoid<int>> seg(10); // 長さ10の配列を管理

// 値を設定
seg.set(0, 5);
seg.set(1, 3);
seg.set(2, 7);
// ...

// 区間[1, 4)の最小値を取得
int min_val = seg.prod(1, 4);

// 値を更新（MinMonoidの場合は min(現在値, x) となる）
seg.apply(2, 1);

// ある値より小さい要素がある最初の位置を探す
int pos = seg.find_first(0, [](int x) { return x < 3; });
```
