---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/aoj-grl-2-a2.test.cpp
    title: src/test/verify/aoj-grl-2-a2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/prim.md
    document_title: Prim
    links: []
  bundledCode: "#line 2 \"src/Graph/prim.hpp\"\n\n/**\n * @brief Prim\n * @docs docs/prim.md\n\
    \ */\n\n#line 2 \"src/Graph/graph-template.hpp\"\n\n/**\n * @brief Graph Template\n\
    \ * @docs docs/graph-template.md\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <typename T = int>\nstruct Edge\
    \ {\n    int from, to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\n\
    \    Edge(int from, int to, T cost = 1, int idx = -1)\n        : from(from)\n\
    \        , to(to)\n        , cost(cost)\n        , idx(idx) {\n    }\n\n    operator\
    \ int() const { return to; }\n};\n\ntemplate <typename T = int>\nstruct Graph\
    \ {\n    vector<vector<Edge<T>>> g;\n    int es;\n\n    Graph() = default;\n\n\
    \    explicit Graph(int n)\n        : g(n)\n        , es(0) {\n    }\n\n    size_t\
    \ size() const {\n        return g.size();\n    }\n\n    void resize(int n) {\n\
    \        g.resize(n);\n    }\n\n    void add_directed_edge(int from, int to, T\
    \ cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n\n\
    \    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n\n\
    \    void read(int M, int padding = -1, bool weighted = false, bool directed =\
    \ false) {\n        for(int i = 0; i < M; i++) {\n            int a, b;\n    \
    \        cin >> a >> b;\n            a += padding;\n            b += padding;\n\
    \            T c = T(1);\n            if(weighted)\n                cin >> c;\n\
    \            if(directed)\n                add_directed_edge(a, b, c);\n     \
    \       else\n                add_edge(a, b, c);\n        }\n    }\n\n    void\
    \ debug() {\n        rep(i, g.size()) {\n            cerr << i << \": \";\n  \
    \          for(auto& e : g[i]) {\n                cerr << e.to << \", \";\n  \
    \          }\n            cerr << endl;\n        }\n    }\n\n    inline vector<Edge<T>>&\
    \ operator[](const int& k) {\n        return g[k];\n    }\n\n    inline const\
    \ vector<Edge<T>>& operator[](const int& k) const {\n        return g[k];\n  \
    \  }\n};\n\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n#line\
    \ 9 \"src/Graph/prim.hpp\"\n\ntemplate <typename T>\nbool operator>(const Edge<T>\
    \ &a, const Edge<T> &b) {\n    return a.cost > b.cost;\n}\n\ntemplate <typename\
    \ T>\npair<T, Edges<T>> prim(Graph<T> &G) {\n    // \u30D7\u30EA\u30E0\u6CD5\u3067\
    \ G \u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\n    // \u8FD4\
    \u308A\u5024\u306F (cost, vector<Edge>)\n    // \u4E00\u65B9\u306E\u7AEF\u70B9\
    \u304C\u73FE\u5728\u306E\u9802\u70B9\u96C6\u5408\u306B\u542B\u307E\u308C\u3001\
    \u304B\u3064\u3082\u3046\u4E00\u65B9\u306E\u7AEF\u70B9\u304C\u9802\u70B9\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u306A\u3044\u8FBA\u306E\u3046\u3061\u3001\u30B3\
    \u30B9\u30C8\u6700\u5C0F\u306E\u8FBA\u3092\u63A1\u7528\u3059\u308B\u3053\u3068\
    \u3092\u7E70\u308A\u8FD4\u3059\n    int N = G.size();\n    priority_queue<Edge<T>,\
    \ Edges<T>, greater<Edge<T>>> pq;\n    for(int i = 0; i < (int)G[0].size(); i++)\
    \ {\n        pq.emplace(G[0][i]);\n    }\n    vector<bool> vis(N);\n    vis[0]\
    \ = true;\n    T cost = (T)0;\n    Edges<T> mst;\n    while(!pq.empty()) {\n \
    \       Edge<T> edge = pq.top();\n        pq.pop();\n        if(vis[edge.to])\
    \ continue;\n        cost += edge.cost;\n        mst.emplace_back(edge);\n   \
    \     vis[edge.to] = true;\n        for(auto &nedge : G[edge.to]) {\n        \
    \    if(vis[nedge.to]) continue;\n            pq.emplace(nedge);\n        }\n\
    \    }\n    if((int)mst.size() == N - 1)\n        return pair<T, Edges<T>>(cost,\
    \ mst);\n    else\n        return pair<T, Edges<T>>((T)-1, mst);\n}\n"
  code: "#pragma once\n\n/**\n * @brief Prim\n * @docs docs/prim.md\n */\n\n#include\
    \ \"graph-template.hpp\"\n\ntemplate <typename T>\nbool operator>(const Edge<T>\
    \ &a, const Edge<T> &b) {\n    return a.cost > b.cost;\n}\n\ntemplate <typename\
    \ T>\npair<T, Edges<T>> prim(Graph<T> &G) {\n    // \u30D7\u30EA\u30E0\u6CD5\u3067\
    \ G \u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\n    // \u8FD4\
    \u308A\u5024\u306F (cost, vector<Edge>)\n    // \u4E00\u65B9\u306E\u7AEF\u70B9\
    \u304C\u73FE\u5728\u306E\u9802\u70B9\u96C6\u5408\u306B\u542B\u307E\u308C\u3001\
    \u304B\u3064\u3082\u3046\u4E00\u65B9\u306E\u7AEF\u70B9\u304C\u9802\u70B9\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u306A\u3044\u8FBA\u306E\u3046\u3061\u3001\u30B3\
    \u30B9\u30C8\u6700\u5C0F\u306E\u8FBA\u3092\u63A1\u7528\u3059\u308B\u3053\u3068\
    \u3092\u7E70\u308A\u8FD4\u3059\n    int N = G.size();\n    priority_queue<Edge<T>,\
    \ Edges<T>, greater<Edge<T>>> pq;\n    for(int i = 0; i < (int)G[0].size(); i++)\
    \ {\n        pq.emplace(G[0][i]);\n    }\n    vector<bool> vis(N);\n    vis[0]\
    \ = true;\n    T cost = (T)0;\n    Edges<T> mst;\n    while(!pq.empty()) {\n \
    \       Edge<T> edge = pq.top();\n        pq.pop();\n        if(vis[edge.to])\
    \ continue;\n        cost += edge.cost;\n        mst.emplace_back(edge);\n   \
    \     vis[edge.to] = true;\n        for(auto &nedge : G[edge.to]) {\n        \
    \    if(vis[nedge.to]) continue;\n            pq.emplace(nedge);\n        }\n\
    \    }\n    if((int)mst.size() == N - 1)\n        return pair<T, Edges<T>>(cost,\
    \ mst);\n    else\n        return pair<T, Edges<T>>((T)-1, mst);\n}"
  dependsOn:
  - src/Graph/graph-template.hpp
  isVerificationFile: false
  path: src/Graph/prim.hpp
  requiredBy: []
  timestamp: '2024-01-23 19:55:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/test/verify/aoj-grl-2-a2.test.cpp
documentation_of: src/Graph/prim.hpp
layout: document
redirect_from:
- /library/src/Graph/prim.hpp
- /library/src/Graph/prim.hpp.html
title: Prim
---
## 概要

一方の端点が現在の頂点集合に含まれ、かつもう一方の端点が頂点集合に含まれない辺のうち、コスト最小の辺を採用することを繰り返す

## 計算量

$O(E\log V)$

## 参考

[最小全域木：プリム法 – 37zigenのHP](https://37zigen.com/minimum-spanning-tree-prim/)