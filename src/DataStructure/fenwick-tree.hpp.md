---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
    title: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fenwick-tree.md
    document_title: Fenwick Tree (Binary Indexed Tree)
    links: []
  bundledCode: "#line 2 \"src/DataStructure/fenwick-tree.hpp\"\n\n/**\n * @brief Fenwick\
    \ Tree (Binary Indexed Tree)\n * @docs docs/fenwick-tree.md\n */\n\ntemplate <typename\
    \ T = long long int>\nstruct FenwickTree {\n    int n;\n    vector<T> bit;\n \
    \   /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u8981\u7D20\u6570\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n  \
    \   */\n    FenwickTree(int n)\n        : n(n) {\n        bit.assign(n + 1, T(0));\n\
    \    }\n    /**\n     * @brief \u914D\u5217\u304B\u3089\u306E\u521D\u671F\u5316\
    \n     * @param a \u521D\u671F\u5024\u3092\u6301\u3064\u914D\u5217\n     * @note\
    \ \u6642\u9593\u8A08\u7B97\u91CF: O(n log n)\n     */\n    FenwickTree(const vector<T>\
    \ &a) {\n        n = (int)a.size();\n        bit.assign(n + 1, T(0));\n      \
    \  for(int i = 0; i < n; ++i) {\n            apply(i, a[i]);\n        }\n    }\n\
    \    /**\n     * @brief \u6307\u5B9A\u4F4D\u7F6E\u306B\u5024\u3092\u52A0\u7B97\
    \u3059\u308B\n     * @param idx \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n\
    \     * @param x \u52A0\u7B97\u3059\u308B\u5024\n     * @note \u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\n     */\n    void apply(int idx, T x) {\n        ++idx;\n\
    \        while(idx <= n) {\n            bit[idx] += x;\n            idx += idx\
    \ & -idx;\n        }\n    }\n    /**\n     * @brief \u6307\u5B9A\u4F4D\u7F6E\u306E\
    \u5024\u3092\u8A2D\u5B9A\u3059\u308B\n     * @param idx \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9 (0-indexed)\n     * @param x \u8A2D\u5B9A\u3059\u308B\u5024\n   \
    \  * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    void set(int\
    \ idx, T x) {\n        T pre = prod(idx, idx + 1);\n        apply(idx, x - pre);\n\
    \    }\n    /**\n     * @brief \u533A\u9593[0, r)\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\n     * @param r \u53F3\u7AEF\uFF08\u542B\u307E\u306A\u3044\uFF09\
    \n     * @return \u533A\u9593[0, r)\u306E\u7DCF\u548C\n     * @note \u6642\u9593\
    \u8A08\u7B97\u91CF: O(log n)\n     */\n    T prod(int r) {\n        T ret = T(0);\n\
    \        ++r;\n        while(r > 0) {\n            ret += bit[r];\n          \
    \  r -= r & -r;\n        }\n        return ret;\n    }\n    /**\n     * @brief\
    \ \u533A\u9593[l, r)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\n     * @param\
    \ l \u5DE6\u7AEF\uFF08\u542B\u3080\uFF09\n     * @param r \u53F3\u7AEF\uFF08\u542B\
    \u307E\u306A\u3044\uFF09\n     * @return \u533A\u9593[l, r)\u306E\u7DCF\u548C\n\
    \     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n    T prod(int\
    \ l, int r) {\n        if(l == 0)\n            return prod(r - 1);\n        else\n\
    \            return prod(r - 1) - prod(l - 1);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Fenwick Tree (Binary Indexed Tree)\n * @docs\
    \ docs/fenwick-tree.md\n */\n\ntemplate <typename T = long long int>\nstruct FenwickTree\
    \ {\n    int n;\n    vector<T> bit;\n    /**\n     * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     * @param n \u8981\u7D20\u6570\n     * @note \u6642\
    \u9593\u8A08\u7B97\u91CF: O(n)\n     */\n    FenwickTree(int n)\n        : n(n)\
    \ {\n        bit.assign(n + 1, T(0));\n    }\n    /**\n     * @brief \u914D\u5217\
    \u304B\u3089\u306E\u521D\u671F\u5316\n     * @param a \u521D\u671F\u5024\u3092\
    \u6301\u3064\u914D\u5217\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n log\
    \ n)\n     */\n    FenwickTree(const vector<T> &a) {\n        n = (int)a.size();\n\
    \        bit.assign(n + 1, T(0));\n        for(int i = 0; i < n; ++i) {\n    \
    \        apply(i, a[i]);\n        }\n    }\n    /**\n     * @brief \u6307\u5B9A\
    \u4F4D\u7F6E\u306B\u5024\u3092\u52A0\u7B97\u3059\u308B\n     * @param idx \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n     * @param x \u52A0\u7B97\u3059\
    \u308B\u5024\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n     */\n\
    \    void apply(int idx, T x) {\n        ++idx;\n        while(idx <= n) {\n \
    \           bit[idx] += x;\n            idx += idx & -idx;\n        }\n    }\n\
    \    /**\n     * @brief \u6307\u5B9A\u4F4D\u7F6E\u306E\u5024\u3092\u8A2D\u5B9A\
    \u3059\u308B\n     * @param idx \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n\
    \     * @param x \u8A2D\u5B9A\u3059\u308B\u5024\n     * @note \u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\n     */\n    void set(int idx, T x) {\n        T pre =\
    \ prod(idx, idx + 1);\n        apply(idx, x - pre);\n    }\n    /**\n     * @brief\
    \ \u533A\u9593[0, r)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\n     * @param\
    \ r \u53F3\u7AEF\uFF08\u542B\u307E\u306A\u3044\uFF09\n     * @return \u533A\u9593\
    [0, r)\u306E\u7DCF\u548C\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\n\
    \     */\n    T prod(int r) {\n        T ret = T(0);\n        ++r;\n        while(r\
    \ > 0) {\n            ret += bit[r];\n            r -= r & -r;\n        }\n  \
    \      return ret;\n    }\n    /**\n     * @brief \u533A\u9593[l, r)\u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B\n     * @param l \u5DE6\u7AEF\uFF08\u542B\u3080\
    \uFF09\n     * @param r \u53F3\u7AEF\uFF08\u542B\u307E\u306A\u3044\uFF09\n   \
    \  * @return \u533A\u9593[l, r)\u306E\u7DCF\u548C\n     * @note \u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\n     */\n    T prod(int l, int r) {\n        if(l == 0)\n\
    \            return prod(r - 1);\n        else\n            return prod(r - 1)\
    \ - prod(l - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2025-04-01 15:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  - src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
documentation_of: src/DataStructure/fenwick-tree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/fenwick-tree.hpp
- /library/src/DataStructure/fenwick-tree.hpp.html
title: Fenwick Tree (Binary Indexed Tree)
---
