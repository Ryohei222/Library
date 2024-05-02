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
  - icon: ':x:'
    path: src/test/verify/yuki-697.test.cpp
    title: src/test/verify/yuki-697.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"src/DataStructure/union-find.hpp\"\n\n/**\n * @brief Union-Find\n\
    \ * @docs docs/union-find.md\n */\n\nstruct UnionFind {\n    vector<int> par;\n\
    \    UnionFind(int n) {\n        par.assign(n, -1);\n    };\n    int find(int\
    \ x) {\n        if(par[x] < 0)\n            return x;\n        else\n        \
    \    return par[x] = find(par[x]);\n    }\n    int size(int x) {\n        x =\
    \ find(x);\n        return -1 * par[x];\n    }\n    bool unite(int x, int y) {\n\
    \        x = find(x);\n        y = find(y);\n        if(x == y)\n            return\
    \ false;\n        if(size(x) < size(y))\n            swap(x, y);\n        par[x]\
    \ += par[y];\n        par[y] = x;\n        return true;\n    }\n    bool same(int\
    \ x, int y) {\n        return find(x) == find(y);\n    }\n    vector<int> leaders()\
    \ {\n        vector<int> res;\n        for(int i = 0; i < (int)par.size(); i++)\
    \ {\n            if(par[i] < 0)\n                res.push_back(i);\n        }\n\
    \        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n\
    \ */\n\nstruct UnionFind {\n    vector<int> par;\n    UnionFind(int n) {\n   \
    \     par.assign(n, -1);\n    };\n    int find(int x) {\n        if(par[x] < 0)\n\
    \            return x;\n        else\n            return par[x] = find(par[x]);\n\
    \    }\n    int size(int x) {\n        x = find(x);\n        return -1 * par[x];\n\
    \    }\n    bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if(x == y)\n            return false;\n        if(size(x) < size(y))\n\
    \            swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n   \
    \     return true;\n    }\n    bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n    vector<int> leaders() {\n        vector<int> res;\n\
    \        for(int i = 0; i < (int)par.size(); i++) {\n            if(par[i] < 0)\n\
    \                res.push_back(i);\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/union-find.hpp
  requiredBy:
  - src/Graph/kruskal.hpp
  timestamp: '2024-01-23 19:55:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - src/test/verify/aoj-dsl-1-a.test.cpp
  - src/test/verify/yuki-697.test.cpp
  - src/test/verify/aoj-grl-2-a.test.cpp
documentation_of: src/DataStructure/union-find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/union-find.hpp
- /library/src/DataStructure/union-find.hpp.html
title: Union-Find
---
TODO: かく