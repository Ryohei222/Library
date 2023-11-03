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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"src/DataStructure/union-find.hpp\"\n\n/**\n * @brief Union-Find\n\
    \ * @docs docs/union-find.md\n */\n\nstruct UnionFind {\n    vector<int> par;\n\
    \    UnionFind(int n) {\n        par.assign(n, -1);\n    };\n    int root(int\
    \ x) {\n        if(par[x] < 0)\n            return x;\n        else\n        \
    \    return par[x] = root(par[x]);\n    }\n    int size(int x) {\n        x =\
    \ root(x);\n        return -1 * par[x];\n    }\n    bool unite(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if(x == y)\n            return\
    \ false;\n        if(size(x) < size(y))\n            swap(x, y);\n        par[x]\
    \ += par[y];\n        par[y] = x;\n        return true;\n    }\n    bool same(int\
    \ x, int y) {\n        return root(x) == root(y);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n\
    \ */\n\nstruct UnionFind {\n    vector<int> par;\n    UnionFind(int n) {\n   \
    \     par.assign(n, -1);\n    };\n    int root(int x) {\n        if(par[x] < 0)\n\
    \            return x;\n        else\n            return par[x] = root(par[x]);\n\
    \    }\n    int size(int x) {\n        x = root(x);\n        return -1 * par[x];\n\
    \    }\n    bool unite(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if(x == y)\n            return false;\n        if(size(x) < size(y))\n\
    \            swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n   \
    \     return true;\n    }\n    bool same(int x, int y) {\n        return root(x)\
    \ == root(y);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/union-find.hpp
  requiredBy:
  - src/Graph/kruskal.hpp
  timestamp: '2023-11-03 15:30:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-dsl-1-a.test.cpp
  - src/test/verify/aoj-grl-2-a.test.cpp
documentation_of: src/DataStructure/union-find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/union-find.hpp
- /library/src/DataStructure/union-find.hpp.html
title: Union-Find
---
TODO: かく