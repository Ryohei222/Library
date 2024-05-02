---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/aoj-grl-5-a.test.cpp
    title: src/test/verify/aoj-grl-5-a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/diameter.md
    document_title: Tree-Diameter
    links: []
  bundledCode: "#line 2 \"src/Graph/diameter.hpp\"\n\n/**\n * @brief Tree-Diameter\n\
    \ * @docs docs/diameter.md\n */\n\n#line 2 \"src/Graph/graph-template.hpp\"\n\n\
    /**\n * @brief Graph Template\n * @docs docs/graph-template.md\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
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
    \ 9 \"src/Graph/diameter.hpp\"\n\ntemplate <typename T = int>\ntuple<T, int, int>\
    \ diameter(Graph<T> &G) {\n    auto dfs = [&](auto &self, int v, int p) -> pair<T,\
    \ int> {\n        pair<T, int> ret(0, v);\n        for(auto &e : G[v]) {\n   \
    \         if(e.to == p) continue;\n            auto result = self(self, e.to,\
    \ v);\n            result.first += e.cost;\n            if(ret.first < result.first)\
    \ {\n                ret = result;\n            }\n        }\n        return ret;\n\
    \    };\n    auto [_, v1] = dfs(dfs, 0, -1);\n    auto [d, v2] = dfs(dfs, v1,\
    \ -1);\n    return tuple<T, int, int>(d, v1, v2);\n}\n"
  code: "#pragma once\n\n/**\n * @brief Tree-Diameter\n * @docs docs/diameter.md\n\
    \ */\n\n#include \"graph-template.hpp\"\n\ntemplate <typename T = int>\ntuple<T,\
    \ int, int> diameter(Graph<T> &G) {\n    auto dfs = [&](auto &self, int v, int\
    \ p) -> pair<T, int> {\n        pair<T, int> ret(0, v);\n        for(auto &e :\
    \ G[v]) {\n            if(e.to == p) continue;\n            auto result = self(self,\
    \ e.to, v);\n            result.first += e.cost;\n            if(ret.first < result.first)\
    \ {\n                ret = result;\n            }\n        }\n        return ret;\n\
    \    };\n    auto [_, v1] = dfs(dfs, 0, -1);\n    auto [d, v2] = dfs(dfs, v1,\
    \ -1);\n    return tuple<T, int, int>(d, v1, v2);\n}"
  dependsOn:
  - src/Graph/graph-template.hpp
  isVerificationFile: false
  path: src/Graph/diameter.hpp
  requiredBy: []
  timestamp: '2024-01-23 19:55:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/test/verify/aoj-grl-5-a.test.cpp
documentation_of: src/Graph/diameter.hpp
layout: document
redirect_from:
- /library/src/Graph/diameter.hpp
- /library/src/Graph/diameter.hpp.html
title: Tree-Diameter
---
