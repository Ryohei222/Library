---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
    title: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
  - icon: ':x:'
    path: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Fenwick Tree
    links: []
  bundledCode: "#line 2 \"src/DataStructure/fenwick-tree.hpp\"\n\n/**\n * @brief Fenwick\
    \ Tree\n */\n\ntemplate <typename T = long long int>\nstruct FenwickTree {\n \
    \   int n;\n    vector<T> bit;\n    FenwickTree(int n)\n        : n(n) {\n   \
    \     bit.assign(n + 1, T(0));\n    }\n    FenwickTree(const vector<T> &a) {\n\
    \        n = (int)a.size();\n        bit.assign(n + 1, T(0));\n        for(int\
    \ i = 0; i < n; ++i) {\n            apply(i, a[i]);\n        }\n    }\n    void\
    \ apply(int idx, T x) {\n        ++idx;\n        while(idx <= n) {\n         \
    \   bit[idx] += x;\n            idx += idx & -idx;\n        }\n    }\n    void\
    \ set(int idx, T x) {\n        T pre = prod(idx, idx + 1);\n        apply(idx,\
    \ x - pre);\n    }\n    T prod(int r) {\n        T ret = T(0);\n        ++r;\n\
    \        while(r > 0) {\n            ret += bit[r];\n            r -= r & -r;\n\
    \        }\n        return ret;\n    }\n    T prod(int l, int r) {\n        if(l\
    \ == 0)\n            return prod(r - 1);\n        else\n            return prod(r\
    \ - 1) - prod(l - 1);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Fenwick Tree\n */\n\ntemplate <typename T\
    \ = long long int>\nstruct FenwickTree {\n    int n;\n    vector<T> bit;\n   \
    \ FenwickTree(int n)\n        : n(n) {\n        bit.assign(n + 1, T(0));\n   \
    \ }\n    FenwickTree(const vector<T> &a) {\n        n = (int)a.size();\n     \
    \   bit.assign(n + 1, T(0));\n        for(int i = 0; i < n; ++i) {\n         \
    \   apply(i, a[i]);\n        }\n    }\n    void apply(int idx, T x) {\n      \
    \  ++idx;\n        while(idx <= n) {\n            bit[idx] += x;\n           \
    \ idx += idx & -idx;\n        }\n    }\n    void set(int idx, T x) {\n       \
    \ T pre = prod(idx, idx + 1);\n        apply(idx, x - pre);\n    }\n    T prod(int\
    \ r) {\n        T ret = T(0);\n        ++r;\n        while(r > 0) {\n        \
    \    ret += bit[r];\n            r -= r & -r;\n        }\n        return ret;\n\
    \    }\n    T prod(int l, int r) {\n        if(l == 0)\n            return prod(r\
    \ - 1);\n        else\n            return prod(r - 1) - prod(l - 1);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2025-03-22 12:22:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  - src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
documentation_of: src/DataStructure/fenwick-tree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/fenwick-tree.hpp
- /library/src/DataStructure/fenwick-tree.hpp.html
title: Fenwick Tree
---
