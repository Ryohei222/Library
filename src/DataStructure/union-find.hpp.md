---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/kruskal.hpp
    title: Kruskal
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-1-a.test.cpp
    title: src/test/verify/aoj-dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-2-a.test.cpp
    title: src/test/verify/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yuki-697.test.cpp
    title: src/test/verify/yuki-697.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"src/DataStructure/union-find.hpp\"\n\n/**\n * @brief Union-Find\n\
    \ * @docs docs/union-find.md\n */\n\nstruct UnionFind {\n    vector<int> par;\n\
    \    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u8981\u7D20\u6570\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n  \
    \   */\n    UnionFind(int n) {\n        par.assign(n, -1);\n    };\n    /**\n\
    \     * @brief \u9802\u70B9x\u306E\u6839\u3092\u6C42\u3081\u308B\n     * @param\
    \ x \u9802\u70B9\n     * @return int \u6839\u306E\u9802\u70B9\u756A\u53F7\n  \
    \   * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     * \
    \      \u03B1(n)\u306F\u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\u95A2\u6570\u306E\u9006\
    \u95A2\u6570\u3067\u3001\u307B\u307CO(1)\u3068\u8003\u3048\u3066\u826F\u3044\n\
    \     */\n    int find(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = find(par[x]);\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\
    \u30BA\u3092\u6C42\u3081\u308B\n     * @param x \u9802\u70B9\n     * @return int\
    \ \u96C6\u5408\u306E\u30B5\u30A4\u30BA\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : \u511F\u5374O(\u03B1(n))\n     */\n    int size(int x) {\n        x = find(x);\n\
    \        return -1 * par[x];\n    }\n    /**\n     * @brief \u9802\u70B9x\u3068\
    \u9802\u70B9y\u304C\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\
    \n     * @param x \u9802\u70B9\n     * @param y \u9802\u70B9\n     * @return bool\
    \ \u4F75\u5408\u306B\u6210\u529F\u3057\u305F\u304B\u3069\u3046\u304B\uFF08\u65E2\
    \u306B\u540C\u3058\u96C6\u5408\u306E\u5834\u5408\u306Ffalse\uFF09\n     * @note\
    \ \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     *       \u5C0F\
    \u3055\u3044\u65B9\u306E\u96C6\u5408\u3092\u5927\u304D\u3044\u65B9\u306B\u4F75\
    \u5408\u3059\u308B\uFF08union by size\uFF09\n     */\n    bool unite(int x, int\
    \ y) {\n        x = find(x);\n        y = find(y);\n        if(x == y)\n     \
    \       return false;\n        if(size(x) < size(y))\n            swap(x, y);\n\
    \        par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \    /**\n     * @brief \u9802\u70B9x\u3068\u9802\u70B9y\u304C\u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n     * @param x \u9802\u70B9\n     * @param y \u9802\u70B9\n     * @return\
    \ bool \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u306A\u3089true\n    \
    \ * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     */\n\
    \    bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n  \
    \  /**\n     * @brief \u5404\u96C6\u5408\u306E\u4EE3\u8868\u5143\uFF08\u6839\uFF09\
    \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\n     * @return vector<int>\
    \ \u4EE3\u8868\u5143\u306E\u30EA\u30B9\u30C8\n     * @note \u6642\u9593\u8A08\u7B97\
    \u91CF: O(n)\n     */\n    vector<int> leaders() {\n        vector<int> res;\n\
    \        for(int i = 0; i < (int)par.size(); i++) {\n            if(par[i] < 0)\n\
    \                res.push_back(i);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n\
    \ */\n\nstruct UnionFind {\n    vector<int> par;\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u8981\u7D20\u6570\n   \
    \  * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     */\n    UnionFind(int n)\
    \ {\n        par.assign(n, -1);\n    };\n    /**\n     * @brief \u9802\u70B9x\u306E\
    \u6839\u3092\u6C42\u3081\u308B\n     * @param x \u9802\u70B9\n     * @return int\
    \ \u6839\u306E\u9802\u70B9\u756A\u53F7\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : \u511F\u5374O(\u03B1(n))\n     *       \u03B1(n)\u306F\u30A2\u30C3\u30AB\u30FC\
    \u30DE\u30F3\u95A2\u6570\u306E\u9006\u95A2\u6570\u3067\u3001\u307B\u307CO(1)\u3068\
    \u8003\u3048\u3066\u826F\u3044\n     */\n    int find(int x) {\n        if(par[x]\
    \ < 0)\n            return x;\n        else\n            return par[x] = find(par[x]);\n\
    \    }\n    /**\n     * @brief \u9802\u70B9x\u304C\u5C5E\u3059\u308B\u96C6\u5408\
    \u306E\u30B5\u30A4\u30BA\u3092\u6C42\u3081\u308B\n     * @param x \u9802\u70B9\
    \n     * @return int \u96C6\u5408\u306E\u30B5\u30A4\u30BA\n     * @note \u6642\
    \u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     */\n    int size(int\
    \ x) {\n        x = find(x);\n        return -1 * par[x];\n    }\n    /**\n  \
    \   * @brief \u9802\u70B9x\u3068\u9802\u70B9y\u304C\u5C5E\u3059\u308B\u96C6\u5408\
    \u3092\u4F75\u5408\u3059\u308B\n     * @param x \u9802\u70B9\n     * @param y\
    \ \u9802\u70B9\n     * @return bool \u4F75\u5408\u306B\u6210\u529F\u3057\u305F\
    \u304B\u3069\u3046\u304B\uFF08\u65E2\u306B\u540C\u3058\u96C6\u5408\u306E\u5834\
    \u5408\u306Ffalse\uFF09\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374\
    O(\u03B1(n))\n     *       \u5C0F\u3055\u3044\u65B9\u306E\u96C6\u5408\u3092\u5927\
    \u304D\u3044\u65B9\u306B\u4F75\u5408\u3059\u308B\uFF08union by size\uFF09\n  \
    \   */\n    bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if(x == y)\n            return false;\n        if(size(x) < size(y))\n\
    \            swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n   \
    \     return true;\n    }\n    /**\n     * @brief \u9802\u70B9x\u3068\u9802\u70B9\
    y\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3059\u308B\n     * @param x \u9802\u70B9\n     * @param y\
    \ \u9802\u70B9\n     * @return bool \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\
    \u308B\u306A\u3089true\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374\
    O(\u03B1(n))\n     */\n    bool same(int x, int y) {\n        return find(x) ==\
    \ find(y);\n    }\n    /**\n     * @brief \u5404\u96C6\u5408\u306E\u4EE3\u8868\
    \u5143\uFF08\u6839\uFF09\u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\
    \n     * @return vector<int> \u4EE3\u8868\u5143\u306E\u30EA\u30B9\u30C8\n    \
    \ * @note \u6642\u9593\u8A08\u7B97\u91CF: O(n)\n     */\n    vector<int> leaders()\
    \ {\n        vector<int> res;\n        for(int i = 0; i < (int)par.size(); i++)\
    \ {\n            if(par[i] < 0)\n                res.push_back(i);\n        }\n\
    \        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/union-find.hpp
  requiredBy:
  - src/Graph/kruskal.hpp
  timestamp: '2025-04-01 15:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-grl-2-a.test.cpp
  - src/test/verify/aoj-dsl-1-a.test.cpp
  - src/test/verify/yuki-697.test.cpp
documentation_of: src/DataStructure/union-find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/union-find.hpp
- /library/src/DataStructure/union-find.hpp.html
title: Union-Find
---
## Union-Find（素集合データ構造）

## 使用例

```cpp
// 10頂点のUnion-Find
UnionFind uf(10);

// 0と1を同じグループに
uf.unite(0, 1);
// 2と3を同じグループに
uf.unite(2, 3);
// 0と3を同じグループに（0,1,2,3が同じグループになる）
uf.unite(0, 3);

// 0と2が同じグループか確認（true）
bool same_group = uf.same(0, 2);

// 0のグループのサイズを取得（4）
int group_size = uf.size(0);

// すべての根（代表元）のリストを取得
vector<int> roots = uf.leaders();
```
