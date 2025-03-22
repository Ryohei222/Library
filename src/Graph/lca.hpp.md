---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/yosupo-lca.test.cpp
    title: src/test/verify/yosupo-lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "LCA(\u30C0\u30D6\u30EA\u30F3\u30B0)"
    links: []
  bundledCode: "#line 2 \"src/Graph/lca.hpp\"\n\n/**\n * @brief LCA(\u30C0\u30D6\u30EA\
    \u30F3\u30B0)\n */\n\n#line 2 \"src/Graph/graph-template.hpp\"\n\n/**\n * @brief\
    \ Graph Template\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
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
    \ 8 \"src/Graph/lca.hpp\"\ntemplate <typename T = int>\nstruct LCA {\n    // N:\
    \ \u9802\u70B9\u6570, K: \u30C0\u30D6\u30EA\u30F3\u30B0\u3067 2^0, 2^1, 2^2 ,\
    \ ... \u500B\u5148\u306E\u9802\u70B9\u3092\u6301\u3064\u304C\u30012 \u306E\u4F55\
    \u4E57\u5148\u306E\u9802\u70B9\u307E\u3067\u6301\u3064\u304B\u3092\u8868\u3059\
    \n    int N, K;\n    vector<int> dist;\n    vector<vector<int>> doubling;\n  \
    \  LCA(Graph<T> G, int find) {\n        N = (int)G.size();\n        K = 1;\n \
    \       while((1LL << K) <= N)\n            K++;\n        dist.assign(N, -1);\n\
    \        doubling.assign(N, vector<int>(K, -1));\n        // \u6839\u304B\u3089\
    \ BFS \u3057\u3066\u5404\u9802\u70B9\u306E\u89AA\u3092\u6C42\u3081\u308B\n   \
    \     queue<int> que;\n        que.push(find);\n        dist[find] = 0;\n    \
    \    doubling[find][0] = find;\n        while(!que.empty()) {\n            int\
    \ t = que.front();\n            que.pop();\n            for(auto e : G[t]) {\n\
    \                if(dist[e.to] == -1) {\n                    dist[e.to] = dist[t]\
    \ + 1;\n                    doubling[e.to][0] = t;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        for(int k = 1; k < K; k++)\
    \ {\n            for(int i = 0; i < N; i++) {\n                doubling[i][k]\
    \ = doubling[doubling[i][k - 1]][k - 1];\n            }\n        }\n    }\n  \
    \  int query(int u, int v) {\n        if(dist[u] > dist[v]) swap(u, v);\n    \
    \    for(int k = 0; k < K; k++) {\n            if((dist[v] - dist[u]) & ((1LL)\
    \ << k)) v = doubling[v][k];\n        }\n        if(u == v) return u;\n      \
    \  for(int k = K - 1; k >= 0; k--) {\n            if(doubling[u][k] != doubling[v][k])\
    \ {\n                u = doubling[u][k];\n                v = doubling[v][k];\n\
    \            }\n        }\n        return doubling[u][0];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief LCA(\u30C0\u30D6\u30EA\u30F3\u30B0)\n */\n\
    \n#include \"graph-template.hpp\"\ntemplate <typename T = int>\nstruct LCA {\n\
    \    // N: \u9802\u70B9\u6570, K: \u30C0\u30D6\u30EA\u30F3\u30B0\u3067 2^0, 2^1,\
    \ 2^2 , ... \u500B\u5148\u306E\u9802\u70B9\u3092\u6301\u3064\u304C\u30012 \u306E\
    \u4F55\u4E57\u5148\u306E\u9802\u70B9\u307E\u3067\u6301\u3064\u304B\u3092\u8868\
    \u3059\n    int N, K;\n    vector<int> dist;\n    vector<vector<int>> doubling;\n\
    \    LCA(Graph<T> G, int find) {\n        N = (int)G.size();\n        K = 1;\n\
    \        while((1LL << K) <= N)\n            K++;\n        dist.assign(N, -1);\n\
    \        doubling.assign(N, vector<int>(K, -1));\n        // \u6839\u304B\u3089\
    \ BFS \u3057\u3066\u5404\u9802\u70B9\u306E\u89AA\u3092\u6C42\u3081\u308B\n   \
    \     queue<int> que;\n        que.push(find);\n        dist[find] = 0;\n    \
    \    doubling[find][0] = find;\n        while(!que.empty()) {\n            int\
    \ t = que.front();\n            que.pop();\n            for(auto e : G[t]) {\n\
    \                if(dist[e.to] == -1) {\n                    dist[e.to] = dist[t]\
    \ + 1;\n                    doubling[e.to][0] = t;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        for(int k = 1; k < K; k++)\
    \ {\n            for(int i = 0; i < N; i++) {\n                doubling[i][k]\
    \ = doubling[doubling[i][k - 1]][k - 1];\n            }\n        }\n    }\n  \
    \  int query(int u, int v) {\n        if(dist[u] > dist[v]) swap(u, v);\n    \
    \    for(int k = 0; k < K; k++) {\n            if((dist[v] - dist[u]) & ((1LL)\
    \ << k)) v = doubling[v][k];\n        }\n        if(u == v) return u;\n      \
    \  for(int k = K - 1; k >= 0; k--) {\n            if(doubling[u][k] != doubling[v][k])\
    \ {\n                u = doubling[u][k];\n                v = doubling[v][k];\n\
    \            }\n        }\n        return doubling[u][0];\n    }\n};"
  dependsOn:
  - src/Graph/graph-template.hpp
  isVerificationFile: false
  path: src/Graph/lca.hpp
  requiredBy: []
  timestamp: '2025-03-22 12:22:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/test/verify/yosupo-lca.test.cpp
documentation_of: src/Graph/lca.hpp
layout: document
redirect_from:
- /library/src/Graph/lca.hpp
- /library/src/Graph/lca.hpp.html
title: "LCA(\u30C0\u30D6\u30EA\u30F3\u30B0)"
---
