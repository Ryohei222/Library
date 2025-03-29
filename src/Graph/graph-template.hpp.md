---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/diameter.hpp
    title: Tree-Diameter
  - icon: ':heavy_check_mark:'
    path: src/Graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: src/Graph/hld.hpp
    title: Heavy-Light Decomposition
  - icon: ':heavy_check_mark:'
    path: src/Graph/kruskal.hpp
    title: Kruskal
  - icon: ':heavy_check_mark:'
    path: src/Graph/lca.hpp
    title: "LCA(\u30C0\u30D6\u30EA\u30F3\u30B0)"
  - icon: ':heavy_check_mark:'
    path: src/Graph/prim.hpp
    title: Prim
  - icon: ':heavy_check_mark:'
    path: src/Graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-1-a.test.cpp
    title: src/test/verify/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-2-a.test.cpp
    title: src/test/verify/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-2-a2.test.cpp
    title: src/test/verify/aoj-grl-2-a2.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-3-c.test.cpp
    title: src/test/verify/aoj-grl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-5-a.test.cpp
    title: src/test/verify/aoj-grl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-lca.test.cpp
    title: src/test/verify/yosupo-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Graph Template
    links:
    - https://github.com/ei1333/library/blob/master/graph/graph-template.hpp
  bundledCode: "#line 2 \"src/Graph/graph-template.hpp\"\n\n/**\n * @brief Graph Template\n\
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
    \  }\n};\n\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n"
  code: "#pragma once\n\n/**\n * @brief Graph Template\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
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
    \  }\n};\n\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/graph-template.hpp
  requiredBy:
  - src/Graph/scc.hpp
  - src/Graph/diameter.hpp
  - src/Graph/lca.hpp
  - src/Graph/hld.hpp
  - src/Graph/prim.hpp
  - src/Graph/kruskal.hpp
  - src/Graph/dijkstra.hpp
  timestamp: '2025-03-29 13:19:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-grl-3-c.test.cpp
  - src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  - src/test/verify/aoj-grl-2-a.test.cpp
  - src/test/verify/aoj-grl-5-a.test.cpp
  - src/test/verify/yosupo-lca.test.cpp
  - src/test/verify/aoj-grl-1-a.test.cpp
  - src/test/verify/aoj-grl-2-a2.test.cpp
documentation_of: src/Graph/graph-template.hpp
layout: document
redirect_from:
- /library/src/Graph/graph-template.hpp
- /library/src/Graph/graph-template.hpp.html
title: Graph Template
---
