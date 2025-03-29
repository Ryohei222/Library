---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-1-a.test.cpp
    title: src/test/verify/aoj-grl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dijkstra
    links: []
  bundledCode: "#line 2 \"src/Graph/dijkstra.hpp\"\n\n/**\n * @brief Dijkstra\n */\n\
    \n#line 2 \"src/Graph/graph-template.hpp\"\n\n/**\n * @brief Graph Template\n\
    \ * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
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
    \          }\n            cerr << '\\n';\n        }\n    }\n\n    inline vector<Edge<T>>&\
    \ operator[](const int& k) {\n        return g[k];\n    }\n\n    inline const\
    \ vector<Edge<T>>& operator[](const int& k) const {\n        return g[k];\n  \
    \  }\n};\n\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n#line\
    \ 8 \"src/Graph/dijkstra.hpp\"\n\ntemplate <typename T>\nvector<T> dijkstra(Graph<T>\
    \ &G, int s) {\n    const auto INF = numeric_limits<T>::max();\n    using P =\
    \ pair<T, int>;\n    int n = G.size();\n    vector<T> dist(n, INF);\n    dist[s]\
    \ = 0;\n    priority_queue<P, vector<P>, greater<P>> que;\n    que.emplace(0,\
    \ s);\n    while(!que.empty()) {\n        P t = que.top();\n        que.pop();\n\
    \        T cost = t.first;\n        int u = t.second;\n        if(cost > dist[u])\
    \ continue;\n        for(auto &e : G[u]) {\n            int v = e.to;\n      \
    \      T ncost = cost + e.cost;\n            if(ncost < dist[v]) {\n         \
    \       dist[v] = ncost;\n                que.emplace(dist[v], v);\n         \
    \   }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Dijkstra\n */\n\n#include \"graph-template.hpp\"\
    \n\ntemplate <typename T>\nvector<T> dijkstra(Graph<T> &G, int s) {\n    const\
    \ auto INF = numeric_limits<T>::max();\n    using P = pair<T, int>;\n    int n\
    \ = G.size();\n    vector<T> dist(n, INF);\n    dist[s] = 0;\n    priority_queue<P,\
    \ vector<P>, greater<P>> que;\n    que.emplace(0, s);\n    while(!que.empty())\
    \ {\n        P t = que.top();\n        que.pop();\n        T cost = t.first;\n\
    \        int u = t.second;\n        if(cost > dist[u]) continue;\n        for(auto\
    \ &e : G[u]) {\n            int v = e.to;\n            T ncost = cost + e.cost;\n\
    \            if(ncost < dist[v]) {\n                dist[v] = ncost;\n       \
    \         que.emplace(dist[v], v);\n            }\n        }\n    }\n    return\
    \ dist;\n}"
  dependsOn:
  - src/Graph/graph-template.hpp
  isVerificationFile: false
  path: src/Graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2025-03-29 13:43:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-grl-1-a.test.cpp
documentation_of: src/Graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/Graph/dijkstra.hpp
- /library/src/Graph/dijkstra.hpp.html
title: Dijkstra
---
