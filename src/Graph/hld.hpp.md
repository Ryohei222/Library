---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/hld.md
    document_title: Heavy-Light Decomposition
    links: []
  bundledCode: "#line 2 \"src/Graph/hld.hpp\"\n\n#line 2 \"src/Graph/graph-template.hpp\"\
    \n\n/**\n * @brief Graph Template\n * @docs docs/graph-template.md\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
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
    \ 4 \"src/Graph/hld.hpp\"\n\n/**\n * @brief Heavy-Light Decomposition\n * @docs\
    \ docs/hld.md\n */\n\ntemplate <typename T = int>\nstruct HeavyLightDecomposition\
    \ {\n    Graph<T> G;\n    vector<int> sz, order, leader, par, group, depth;\n\
    \    HeavyLightDecomposition(const Graph<T> &g)\n        : G(g), sz(g.size()),\
    \ order(g.size()), par(g.size()), group(g.size()), depth(g.size()) {}\n    void\
    \ build() {\n        depth[0] = 0;\n        dfs_subtree(0, -1);\n        int t\
    \ = 0, g = 0;\n        leader.emplace_back(0);\n        dfs_hld(0, -1, t, g);\n\
    \    }\n    vector<pair<int, int>> path_edge(int u, int v) {\n        vector<pair<int,\
    \ int>> ret;\n        int r = lca(u, v);\n        auto rec = [&](auto &self, int\
    \ c) -> void {\n            if(r == c) return;\n            int lr = leader[group[r]],\
    \ lc = leader[group[c]];\n            if(lr == lc) {\n                ret.emplace_back(order[r]\
    \ + 1, order[c] + 1);\n            } else {\n                ret.emplace_back(order[lc],\
    \ order[c] + 1);\n                self(self, par[lc]);\n            }\n      \
    \  };\n        if(r != u) rec(rec, u);\n        if(r != v) rec(rec, v);\n    \
    \    return ret;\n    }\n    vector<pair<int, int>> path_vertex(int u, int v)\
    \ {\n        vector<pair<int, int>> ret;\n        auto rec = [&](auto &self, int\
    \ a, int b) -> void {\n            int la = leader[group[a]], lb = leader[group[b]];\n\
    \            if(depth[la] > depth[lb]) {\n                swap(a, b);\n      \
    \          swap(la, lb);\n            }\n            if(la == lb) {\n        \
    \        if(depth[a] > depth[b]) swap(a, b);\n                ret.emplace_back(order[a],\
    \ order[b] + 1);\n            } else {\n                self(self, a, par[lb]);\n\
    \                self(self, lb, b);\n            }\n        };\n        rec(rec,\
    \ u, v);\n        return ret;\n    }\n    int lca(int u, int v) {\n        while(true)\
    \ {\n            if(order[u] < order[v]) swap(u, v);\n            if(leader[group[u]]\
    \ == leader[group[v]]) return v;\n            u = par[leader[group[u]]];\n   \
    \     }\n    }\n\n  private:\n    int dfs_subtree(int v, int p) {\n        par[v]\
    \ = p;\n        sz[v] = 1;\n        for(auto &e : G[v]) {\n            if(e.to\
    \ == p) continue;\n            depth[e.to] = depth[v] + 1;\n            sz[v]\
    \ += dfs_subtree(e.to, v);\n        }\n        return sz[v];\n    }\n    void\
    \ dfs_hld(int v, int p, int &t, int &g) {\n        order[v] = t++;\n        group[v]\
    \ = g;\n        int idx = -1, cur_sz = 0;\n        for(auto &e : G[v]) {\n   \
    \         if(e.to == p) continue;\n            if(sz[e.to] > cur_sz) {\n     \
    \           idx = e.to;\n                cur_sz = sz[e.to];\n            }\n \
    \       }\n        if(idx != -1) dfs_hld(idx, v, t, g);\n        for(auto &e :\
    \ G[v]) {\n            if(e.to == p || e.to == idx) continue;\n            g++;\n\
    \            leader.emplace_back(e.to);\n            dfs_hld(e.to, v, t, g);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph-template.hpp\"\n\n/**\n * @brief Heavy-Light\
    \ Decomposition\n * @docs docs/hld.md\n */\n\ntemplate <typename T = int>\nstruct\
    \ HeavyLightDecomposition {\n    Graph<T> G;\n    vector<int> sz, order, leader,\
    \ par, group, depth;\n    HeavyLightDecomposition(const Graph<T> &g)\n       \
    \ : G(g), sz(g.size()), order(g.size()), par(g.size()), group(g.size()), depth(g.size())\
    \ {}\n    void build() {\n        depth[0] = 0;\n        dfs_subtree(0, -1);\n\
    \        int t = 0, g = 0;\n        leader.emplace_back(0);\n        dfs_hld(0,\
    \ -1, t, g);\n    }\n    vector<pair<int, int>> path_edge(int u, int v) {\n  \
    \      vector<pair<int, int>> ret;\n        int r = lca(u, v);\n        auto rec\
    \ = [&](auto &self, int c) -> void {\n            if(r == c) return;\n       \
    \     int lr = leader[group[r]], lc = leader[group[c]];\n            if(lr ==\
    \ lc) {\n                ret.emplace_back(order[r] + 1, order[c] + 1);\n     \
    \       } else {\n                ret.emplace_back(order[lc], order[c] + 1);\n\
    \                self(self, par[lc]);\n            }\n        };\n        if(r\
    \ != u) rec(rec, u);\n        if(r != v) rec(rec, v);\n        return ret;\n \
    \   }\n    vector<pair<int, int>> path_vertex(int u, int v) {\n        vector<pair<int,\
    \ int>> ret;\n        auto rec = [&](auto &self, int a, int b) -> void {\n   \
    \         int la = leader[group[a]], lb = leader[group[b]];\n            if(depth[la]\
    \ > depth[lb]) {\n                swap(a, b);\n                swap(la, lb);\n\
    \            }\n            if(la == lb) {\n                if(depth[a] > depth[b])\
    \ swap(a, b);\n                ret.emplace_back(order[a], order[b] + 1);\n   \
    \         } else {\n                self(self, a, par[lb]);\n                self(self,\
    \ lb, b);\n            }\n        };\n        rec(rec, u, v);\n        return\
    \ ret;\n    }\n    int lca(int u, int v) {\n        while(true) {\n          \
    \  if(order[u] < order[v]) swap(u, v);\n            if(leader[group[u]] == leader[group[v]])\
    \ return v;\n            u = par[leader[group[u]]];\n        }\n    }\n\n  private:\n\
    \    int dfs_subtree(int v, int p) {\n        par[v] = p;\n        sz[v] = 1;\n\
    \        for(auto &e : G[v]) {\n            if(e.to == p) continue;\n        \
    \    depth[e.to] = depth[v] + 1;\n            sz[v] += dfs_subtree(e.to, v);\n\
    \        }\n        return sz[v];\n    }\n    void dfs_hld(int v, int p, int &t,\
    \ int &g) {\n        order[v] = t++;\n        group[v] = g;\n        int idx =\
    \ -1, cur_sz = 0;\n        for(auto &e : G[v]) {\n            if(e.to == p) continue;\n\
    \            if(sz[e.to] > cur_sz) {\n                idx = e.to;\n          \
    \      cur_sz = sz[e.to];\n            }\n        }\n        if(idx != -1) dfs_hld(idx,\
    \ v, t, g);\n        for(auto &e : G[v]) {\n            if(e.to == p || e.to ==\
    \ idx) continue;\n            g++;\n            leader.emplace_back(e.to);\n \
    \           dfs_hld(e.to, v, t, g);\n        }\n    }\n};"
  dependsOn:
  - src/Graph/graph-template.hpp
  isVerificationFile: false
  path: src/Graph/hld.hpp
  requiredBy: []
  timestamp: '2024-01-23 19:55:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/test/verify/yosupo-vertex-add-path-sum.test.cpp
documentation_of: src/Graph/hld.hpp
layout: document
redirect_from:
- /library/src/Graph/hld.hpp
- /library/src/Graph/hld.hpp.html
title: Heavy-Light Decomposition
---
## メモ

- `order[i]` : 頂点 $i$ を訪れた時刻
- `group[i]` : 頂点 $i$ が所属している連結成分の index
- `leader[i]` : 連結成分 $i$ に含まれる最も浅い頂点の index