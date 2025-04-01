---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Util/debug.hpp
    title: Debug
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-static-range-sum.test.cpp
    title: src/test/verify/yosupo-static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/cumulative-sum.md
    document_title: "\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/cumulative-sum.hpp\"\n\n/**\n * @brief\
    \ \u7D2F\u7A4D\u548C\n * @docs docs/cumulative-sum.md\n */\n\n#include <vector>\n\
    #include <cassert>\n#include <concepts>\n#line 2 \"src/Util/debug.hpp\"\n\n/**\n\
    \ * @brief Debug\n */\n\n#ifdef LOCAL\n#define debug_assert(exp) assert(exp)\n\
    #else\n#define debug_assert(exp) true\n#endif\n\n#ifdef LOCAL\n#define dbg(x)\
    \ std::cerr << __LINE__ << \" : \" << #x << \" = \" << (x) << std::endl\n#else\n\
    #define dbg(x) true\n#endif\n#line 12 \"src/DataStructure/cumulative-sum.hpp\"\
    \n\ntemplate <std::integral T>\nstruct CumulativeSum {\n  private:\n    bool built\
    \ = false;\n\n  public:\n    int n;\n    std::vector<T> data;\n\n    /**\n   \
    \  * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u8981\
    \u7D20\u6570\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     */\n   \
    \ CumulativeSum(int n)\n        : n(n), data(n + 1, T()) {}\n\n    /**\n     *\
    \ @brief \u914D\u5217\u304B\u3089\u306E\u521D\u671F\u5316\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     * @param a \u521D\u671F\u5024\u3092\u6301\u3064\u914D\
    \u5217\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     */\n    CumulativeSum(const\
    \ std::vector<T> &a)\n        : n((int)a.size()), data(n + 1, T()) {\n       \
    \ for(int i = 0; i < n; i++)\n            add(i, a[i]);\n        build();\n  \
    \  }\n\n    /**\n     * @brief \u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\
    \n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     * @note add\u95A2\u6570\
    \u3067\u5024\u3092\u5168\u3066\u8FFD\u52A0\u3057\u305F\u5F8C\u306B\u547C\u3073\
    \u51FA\u3059\u5FC5\u8981\u304C\u3042\u308B\n     */\n    void build() {\n    \
    \    debug_assert(!built);\n        for(int i = 0; i < n; i++) {\n           \
    \ data[i + 1] = data[i] + data[i + 1];\n        }\n        built = true;\n   \
    \ }\n\n    /**\n     * @brief \u6307\u5B9A\u4F4D\u7F6E\u306B\u5024\u3092\u8FFD\
    \u52A0\u3059\u308B\n     * @param idx \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n\
    \     * @param x \u8FFD\u52A0\u3059\u308B\u5024\n     * @note \u6642\u9593\u8A08\
    \u7B97\u91CF: O(1)\n     * @note build\u95A2\u6570\u3092\u547C\u3073\u51FA\u3059\
    \u524D\u306B\u306E\u307F\u4F7F\u7528\u53EF\u80FD\n     */\n    void add(int idx,\
    \ T x) {\n        debug_assert(!built);\n        data[idx + 1] += x;\n    }\n\n\
    \    /**\n     * @brief \u533A\u9593[l, r)\u306E\u7DCF\u548C\u3092\u6C42\u3081\
    \u308B\n     * @param l \u5DE6\u7AEF\uFF08\u542B\u3080\uFF09\n     * @param r\
    \ \u53F3\u7AEF\uFF08\u542B\u307E\u306A\u3044\uFF09\n     * @return \u533A\u9593\
    [l, r)\u306E\u7DCF\u548C\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(1)\n\
    \     * @note build\u95A2\u6570\u3092\u547C\u3073\u51FA\u3057\u305F\u5F8C\u306B\
    \u306E\u307F\u4F7F\u7528\u53EF\u80FD\n     */\n    T sum(int l, int r) {\n   \
    \     debug_assert(built);\n        return data[r] - data[l];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u7D2F\u7A4D\u548C\n * @docs docs/cumulative-sum.md\n\
    \ */\n\n#include <vector>\n#include <cassert>\n#include <concepts>\n#include \"\
    ../Util/debug.hpp\"\n\ntemplate <std::integral T>\nstruct CumulativeSum {\n  private:\n\
    \    bool built = false;\n\n  public:\n    int n;\n    std::vector<T> data;\n\n\
    \    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u8981\u7D20\u6570\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n  \
    \   */\n    CumulativeSum(int n)\n        : n(n), data(n + 1, T()) {}\n\n    /**\n\
    \     * @brief \u914D\u5217\u304B\u3089\u306E\u521D\u671F\u5316\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     * @param a \u521D\u671F\u5024\u3092\u6301\u3064\
    \u914D\u5217\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     */\n   \
    \ CumulativeSum(const std::vector<T> &a)\n        : n((int)a.size()), data(n +\
    \ 1, T()) {\n        for(int i = 0; i < n; i++)\n            add(i, a[i]);\n \
    \       build();\n    }\n\n    /**\n     * @brief \u7D2F\u7A4D\u548C\u3092\u69CB\
    \u7BC9\u3059\u308B\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     *\
    \ @note add\u95A2\u6570\u3067\u5024\u3092\u5168\u3066\u8FFD\u52A0\u3057\u305F\u5F8C\
    \u306B\u547C\u3073\u51FA\u3059\u5FC5\u8981\u304C\u3042\u308B\n     */\n    void\
    \ build() {\n        debug_assert(!built);\n        for(int i = 0; i < n; i++)\
    \ {\n            data[i + 1] = data[i] + data[i + 1];\n        }\n        built\
    \ = true;\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u4F4D\u7F6E\u306B\u5024\
    \u3092\u8FFD\u52A0\u3059\u308B\n     * @param idx \u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9 (0-indexed)\n     * @param x \u8FFD\u52A0\u3059\u308B\u5024\n     * @note\
    \ \u6642\u9593\u8A08\u7B97\u91CF: O(1)\n     * @note build\u95A2\u6570\u3092\u547C\
    \u3073\u51FA\u3059\u524D\u306B\u306E\u307F\u4F7F\u7528\u53EF\u80FD\n     */\n\
    \    void add(int idx, T x) {\n        debug_assert(!built);\n        data[idx\
    \ + 1] += x;\n    }\n\n    /**\n     * @brief \u533A\u9593[l, r)\u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B\n     * @param l \u5DE6\u7AEF\uFF08\u542B\u3080\uFF09\
    \n     * @param r \u53F3\u7AEF\uFF08\u542B\u307E\u306A\u3044\uFF09\n     * @return\
    \ \u533A\u9593[l, r)\u306E\u7DCF\u548C\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : O(1)\n     * @note build\u95A2\u6570\u3092\u547C\u3073\u51FA\u3057\u305F\u5F8C\
    \u306B\u306E\u307F\u4F7F\u7528\u53EF\u80FD\n     */\n    T sum(int l, int r) {\n\
    \        debug_assert(built);\n        return data[r] - data[l];\n    }\n};"
  dependsOn:
  - src/Util/debug.hpp
  isVerificationFile: false
  path: src/DataStructure/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2025-04-01 15:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/yosupo-static-range-sum.test.cpp
documentation_of: src/DataStructure/cumulative-sum.hpp
layout: document
redirect_from:
- /library/src/DataStructure/cumulative-sum.hpp
- /library/src/DataStructure/cumulative-sum.hpp.html
title: "\u7D2F\u7A4D\u548C"
---
## 累積和（Cumulative Sum）

### 計算量

- 初期化・構築: $O(n)$
- 区間和クエリ: $O(1)$

### 使用例

```cpp
// 長さ5の配列 [1, 2, 3, 4, 5] の累積和を構築
vector<int> a = {1, 2, 3, 4, 5};
CumulativeSum<int> cs(a);

// 区間[1, 4)の和を計算（a[1] + a[2] + a[3] = 2 + 3 + 4 = 9）
int sum_1_4 = cs.sum(1, 4);  // 9

// 区間[0, 5)の和を計算（全要素の和 = 15）
int sum_all = cs.sum(0, 5);  // 15
```


```cpp
// 長さ5の累積和を初期化
CumulativeSum<int> cs(5);

// 値を追加
cs.add(0, 1);
cs.add(1, 2);
cs.add(2, 3);
cs.add(3, 4);
cs.add(4, 5);

// 累積和を構築
cs.build();

// 区間和を計算
int sum_1_4 = cs.sum(1, 4);  // 9
```