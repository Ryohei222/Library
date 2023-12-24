---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/union-find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-2-a.test.cpp
    title: src/test/verify/aoj-grl-2-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/kruskal.md
    document_title: Kruskal
    links: []
  bundledCode: "#line 2 \"src/Graph/kruskal.hpp\"\n\n/**\n * @brief Kruskal\n * @docs\
    \ docs/kruskal.md\n */\n\n#line 2 \"src/Graph/graph-template.hpp\"\n\n/**\n *\
    \ @brief Graph Template\n * @docs docs/graph-template.md\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <typename T = int>\nstruct Edge\
    \ {\n    int from, to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\n\
    \    Edge(int from, int to, T cost = 1, int idx = -1)\n      : from(from)\n  \
    \    , to(to)\n      , cost(cost)\n      , idx(idx) {\n    }\n\n    operator int()\
    \ const { return to; }\n};\n\ntemplate <typename T = int>\nstruct Graph {\n  \
    \  vector<vector<Edge<T>>> g;\n    int es;\n\n    Graph() = default;\n\n    explicit\
    \ Graph(int n)\n      : g(n)\n      , es(0) {\n    }\n\n    size_t size() const\
    \ {\n        return g.size();\n    }\n\n    void resize(int n) {\n        g.resize(n);\n\
    \    }\n\n    void add_directed_edge(int from, int to, T cost = 1) {\n       \
    \ g[from].emplace_back(from, to, cost, es++);\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n\
    \        g[to].emplace_back(to, from, cost, es++);\n    }\n\n    void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n     \
    \   for(int i = 0; i < M; i++) {\n            int a, b;\n            cin >> a\
    \ >> b;\n            a += padding;\n            b += padding;\n            T c\
    \ = T(1);\n            if(weighted)\n                cin >> c;\n            if(directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n\n    void debug(){\n        rep(i,\
    \ g.size()){\n            cerr << i << \": \";\n            for(auto &e : g[i]){\n\
    \                cerr << e.to << \", \";\n            }\n            cerr << endl;\n\
    \        }\n    }\n\n    inline vector<Edge<T>>& operator[](const int& k) {\n\
    \        return g[k];\n    }\n\n    inline const vector<Edge<T>>& operator[](const\
    \ int& k) const {\n        return g[k];\n    }\n};\n\ntemplate <typename T = int>\n\
    using Edges = vector<Edge<T>>;\n#line 2 \"src/DataStructure/union-find.hpp\"\n\
    \n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n\nstruct UnionFind\
    \ {\n    vector<int> par;\n    UnionFind(int n) {\n        par.assign(n, -1);\n\
    \    };\n    int find(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = find(par[x]);\n    }\n    int size(int\
    \ x) {\n        x = find(x);\n        return -1 * par[x];\n    }\n    bool unite(int\
    \ x, int y) {\n        x = find(x);\n        y = find(y);\n        if(x == y)\n\
    \            return false;\n        if(size(x) < size(y))\n            swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n    bool same(int x, int y) {\n        return find(x) == find(y);\n  \
    \  }\n    vector<int> leaders(){\n        vector<int> res;\n        for(int i\
    \ = 0; i < (int)par.size(); i++){\n            if(par[i] < 0)\n              \
    \  res.push_back(i);\n        }\n        return res;\n    }\n};\n#line 10 \"src/Graph/kruskal.hpp\"\
    \n\ntemplate <typename T>\npair<T, Edges<T>> kruskal(Graph<T> &G){\n    // \u30AF\
    \u30E9\u30B9\u30AB\u30EB\u6CD5\u3067 G \u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\
    \u6C42\u3081\u308B\n    // \u8FD4\u308A\u5024\u306F (cost, vector<Edge>)\n   \
    \ int N = G.size();\n    UnionFind uf(N);\n    Edges<T> edges;\n    for(int i\
    \ = 0; i < N; i++){\n        for(auto &edge: G[i]){\n            edges.emplace_back(edge);\n\
    \        }\n    }\n    auto comp = [](const Edge<T> &a, const Edge<T> &b){\n \
    \       return a.cost < b.cost;\n    };\n    sort(edges.begin(), edges.end(),\
    \ comp);\n    T cost = (T)0;\n    Edges<T> mst;\n    for(auto &edge: edges){\n\
    \        if(uf.unite(edge.from, edge.to)){\n            cost += edge.cost;\n \
    \           mst.emplace_back(edge);\n        }\n    }\n    if(uf.size(0) == N)\
    \ return pair<T, Edges<T>>(cost, mst);\n    else return pair<T, Edges<T>>((T)-1,\
    \ mst);\n}\n"
  code: "#pragma once\n\n/**\n * @brief Kruskal\n * @docs docs/kruskal.md\n */\n\n\
    #include \"graph-template.hpp\"\n#include \"../DataStructure/union-find.hpp\"\n\
    \ntemplate <typename T>\npair<T, Edges<T>> kruskal(Graph<T> &G){\n    // \u30AF\
    \u30E9\u30B9\u30AB\u30EB\u6CD5\u3067 G \u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\
    \u6C42\u3081\u308B\n    // \u8FD4\u308A\u5024\u306F (cost, vector<Edge>)\n   \
    \ int N = G.size();\n    UnionFind uf(N);\n    Edges<T> edges;\n    for(int i\
    \ = 0; i < N; i++){\n        for(auto &edge: G[i]){\n            edges.emplace_back(edge);\n\
    \        }\n    }\n    auto comp = [](const Edge<T> &a, const Edge<T> &b){\n \
    \       return a.cost < b.cost;\n    };\n    sort(edges.begin(), edges.end(),\
    \ comp);\n    T cost = (T)0;\n    Edges<T> mst;\n    for(auto &edge: edges){\n\
    \        if(uf.unite(edge.from, edge.to)){\n            cost += edge.cost;\n \
    \           mst.emplace_back(edge);\n        }\n    }\n    if(uf.size(0) == N)\
    \ return pair<T, Edges<T>>(cost, mst);\n    else return pair<T, Edges<T>>((T)-1,\
    \ mst);\n}"
  dependsOn:
  - src/Graph/graph-template.hpp
  - src/DataStructure/union-find.hpp
  isVerificationFile: false
  path: src/Graph/kruskal.hpp
  requiredBy: []
  timestamp: '2023-12-24 14:35:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-grl-2-a.test.cpp
documentation_of: src/Graph/kruskal.hpp
layout: document
redirect_from:
- /library/src/Graph/kruskal.hpp
- /library/src/Graph/kruskal.hpp.html
title: Kruskal
---
## 概要

両端が異なる連結成分に属するような辺のうち、最小のコストを持つ辺を採用することを繰り返す

## 計算量

$O(E\log E)$

## 参考

[最小全域木：クラスカル法 – 37zigenのHP](https://37zigen.com/minimum-spanning-tree-kruskal/)