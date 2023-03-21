---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Graph/dijkstra.hpp
    title: src/Graph/dijkstra.hpp
  - icon: ':warning:'
    path: src/test/verify/aoj-grl-1-a.cpp
    title: src/test/verify/aoj-grl-1-a.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/ei1333/library/blob/master/graph/graph-template.hpp)
  bundledCode: "#line 2 \"src/Graph/graph-template.hpp\"\n\n/*\n** @ei1333 \u3055\u3093\
    \u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8(https://github.com/ei1333/library/blob/master/graph/graph-template.hpp)\
    \ \u3088\u308A\n*/\ntemplate <typename T = int>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\n    Edge(int from,\
    \ int to, T cost = 1, int idx = -1)\n      : from(from)\n      , to(to)\n    \
    \  , cost(cost)\n      , idx(idx) {\n    }\n\n    operator int() const { return\
    \ to; }\n};\n\ntemplate <typename T = int>\nstruct Graph {\n    vector<vector<Edge<T>>>\
    \ g;\n    int es;\n\n    Graph() = default;\n\n    explicit Graph(int n)\n   \
    \   : g(n)\n      , es(0) {\n    }\n\n    size_t size() const {\n        return\
    \ g.size();\n    }\n\n    void add_directed_edge(int from, int to, T cost = 1)\
    \ {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n\
    \        g[to].emplace_back(to, from, cost, es++);\n    }\n\n    void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n     \
    \   for(int i = 0; i < M; i++) {\n            int a, b;\n            cin >> a\
    \ >> b;\n            a += padding;\n            b += padding;\n            T c\
    \ = T(1);\n            if(weighted)\n                cin >> c;\n            if(directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n\n    inline vector<Edge<T>>& operator[](const\
    \ int& k) {\n        return g[k];\n    }\n\n    inline const vector<Edge<T>>&\
    \ operator[](const int& k) const {\n        return g[k];\n    }\n};\n\ntemplate\
    \ <typename T = int>\nusing Edges = vector<Edge<T>>;\n"
  code: "#pragma once\n\n/*\n** @ei1333 \u3055\u3093\u306E\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8(https://github.com/ei1333/library/blob/master/graph/graph-template.hpp)\
    \ \u3088\u308A\n*/\ntemplate <typename T = int>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\n    Edge(int from,\
    \ int to, T cost = 1, int idx = -1)\n      : from(from)\n      , to(to)\n    \
    \  , cost(cost)\n      , idx(idx) {\n    }\n\n    operator int() const { return\
    \ to; }\n};\n\ntemplate <typename T = int>\nstruct Graph {\n    vector<vector<Edge<T>>>\
    \ g;\n    int es;\n\n    Graph() = default;\n\n    explicit Graph(int n)\n   \
    \   : g(n)\n      , es(0) {\n    }\n\n    size_t size() const {\n        return\
    \ g.size();\n    }\n\n    void add_directed_edge(int from, int to, T cost = 1)\
    \ {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n\
    \        g[to].emplace_back(to, from, cost, es++);\n    }\n\n    void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n     \
    \   for(int i = 0; i < M; i++) {\n            int a, b;\n            cin >> a\
    \ >> b;\n            a += padding;\n            b += padding;\n            T c\
    \ = T(1);\n            if(weighted)\n                cin >> c;\n            if(directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n\n    inline vector<Edge<T>>& operator[](const\
    \ int& k) {\n        return g[k];\n    }\n\n    inline const vector<Edge<T>>&\
    \ operator[](const int& k) const {\n        return g[k];\n    }\n};\n\ntemplate\
    \ <typename T = int>\nusing Edges = vector<Edge<T>>;"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/graph-template.hpp
  requiredBy:
  - src/Graph/dijkstra.hpp
  - src/test/verify/aoj-grl-1-a.cpp
  timestamp: '2023-03-21 22:14:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/graph-template.hpp
layout: document
redirect_from:
- /library/src/Graph/graph-template.hpp
- /library/src/Graph/graph-template.hpp.html
title: src/Graph/graph-template.hpp
---