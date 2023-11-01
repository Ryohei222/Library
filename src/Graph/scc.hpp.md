---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/graph-template.hpp
    title: src/Graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-3-c.test.cpp
    title: src/test/verify/aoj-grl-3-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/scc.md
    document_title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"src/Graph/scc.hpp\"\n\n/**\n * @brief \u5F37\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\n * @docs docs/scc.md\n */\n\n#line 2 \"src/Graph/graph-template.hpp\"\
    \n\n/*\n** @ei1333 \u3055\u3093\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8(https://github.com/ei1333/library/blob/master/graph/graph-template.hpp)\
    \ \u3088\u308A\n*/\ntemplate <typename T = int>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\n    Edge(int from,\
    \ int to, T cost = 1, int idx = -1)\n      : from(from)\n      , to(to)\n    \
    \  , cost(cost)\n      , idx(idx) {\n    }\n\n    operator int() const { return\
    \ to; }\n};\n\ntemplate <typename T = int>\nstruct Graph {\n    vector<vector<Edge<T>>>\
    \ g;\n    int es;\n\n    Graph() = default;\n\n    explicit Graph(int n)\n   \
    \   : g(n)\n      , es(0) {\n    }\n\n    size_t size() const {\n        return\
    \ g.size();\n    }\n\n    void resize(int n) {\n        g.resize(n);\n    }\n\n\
    \    void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n\n    void add_edge(int from, int to, T cost = 1) {\n\
    \        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n\n    void read(int M, int padding = -1, bool weighted\
    \ = false, bool directed = false) {\n        for(int i = 0; i < M; i++) {\n  \
    \          int a, b;\n            cin >> a >> b;\n            a += padding;\n\
    \            b += padding;\n            T c = T(1);\n            if(weighted)\n\
    \                cin >> c;\n            if(directed)\n                add_directed_edge(a,\
    \ b, c);\n            else\n                add_edge(a, b, c);\n        }\n  \
    \  }\n\n    void debug(){\n        rep(i, g.size()){\n            cerr << i <<\
    \ \": \";\n            for(auto &e : g[i]){\n                cerr << e.to << \"\
    , \";\n            }\n            cerr << endl;\n        }\n    }\n\n    inline\
    \ vector<Edge<T>>& operator[](const int& k) {\n        return g[k];\n    }\n\n\
    \    inline const vector<Edge<T>>& operator[](const int& k) const {\n        return\
    \ g[k];\n    }\n};\n\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n\
    #line 9 \"src/Graph/scc.hpp\"\n\ntemplate <typename T>\nstruct SCC {\n    Graph<T>\
    \ G, rG;\n    SCC(Graph<T> G)\n      : G{G} {}\n    Graph<T> dag;\n    vector<bool>\
    \ used;\n    // group[i] := i \u756A\u76EE\u306E\u9802\u70B9\u304C\u5C5E\u3059\
    \u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\n    // component[i] :=\
    \ i \u756A\u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u9802\
    \u70B9\u306E\u96C6\u5408\n    vector<int> order, group;\n    vector<vector<int>>\
    \ component;\n    void build() {\n        int N = G.size();\n        used.resize(N,\
    \ false);\n        for(int i = 0; i < N; i++) {\n            if(!used[i]) {\n\
    \                dfs(i);\n            }\n        }\n        using Pi = pair<int,\
    \ int>;\n        vector<Pi> sorted;\n        for(int i = 0; i < N; i++) {\n  \
    \          sorted.emplace_back(i, order[i]);\n        }\n        sort(sorted.begin(),\
    \ sorted.end(), greater<Pi>());\n        // \u9006\u8FBA\u3092\u5F35\u3063\u305F\
    \u30B0\u30E9\u30D5\u3067 DFS \u3092\u884C\u3046\n        rG.resize(N);\n     \
    \   for(int i = 0; i < N; i++) {\n            for(Edge<T> e : G[i]) {\n      \
    \          rG.add_directed_edge(e.to, e.from);\n            }\n        }\n   \
    \     group.resize(N, -1);\n        int cnt = 0;\n        for(int i = 0; i < N;\
    \ i++) {\n            int t = sorted[i].second;\n            if(group[t] != -1)\
    \ continue;\n            rdfs(t, cnt);\n            cnt++;\n        }\n      \
    \  dag.resize(cnt);\n        component.resize(cnt);\n        for(int i = 0; i\
    \ < N; i++) {\n            component[group[i]].push_back(i);\n            for(Edge<T>\
    \ e : G[i]) {\n                if(group[i] == group[e.to]) continue;\n       \
    \         dag.add_directed_edge(group[i], group[e.to]);\n            }\n     \
    \   }\n    }\n    void dfs(int v) {\n        if(used[v]) return;\n        used[v]\
    \ = true;\n        for(Edge<T> e : G[v])\n            dfs(e.to);\n        order.push_back(v);\n\
    \    }\n    void rdfs(int v, int cnt) {\n        if(group[v] != -1) return;\n\
    \        group[v] = cnt;\n        for(Edge<T> e : rG[v])\n            rdfs(e.to,\
    \ cnt);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \n * @docs docs/scc.md\n */\n\n#include \"graph-template.hpp\"\n\ntemplate <typename\
    \ T>\nstruct SCC {\n    Graph<T> G, rG;\n    SCC(Graph<T> G)\n      : G{G} {}\n\
    \    Graph<T> dag;\n    vector<bool> used;\n    // group[i] := i \u756A\u76EE\u306E\
    \u9802\u70B9\u304C\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u756A\
    \u53F7\n    // component[i] := i \u756A\u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\
    \u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u96C6\u5408\n    vector<int> order,\
    \ group;\n    vector<vector<int>> component;\n    void build() {\n        int\
    \ N = G.size();\n        used.resize(N, false);\n        for(int i = 0; i < N;\
    \ i++) {\n            if(!used[i]) {\n                dfs(i);\n            }\n\
    \        }\n        using Pi = pair<int, int>;\n        vector<Pi> sorted;\n \
    \       for(int i = 0; i < N; i++) {\n            sorted.emplace_back(i, order[i]);\n\
    \        }\n        sort(sorted.begin(), sorted.end(), greater<Pi>());\n     \
    \   // \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\u3067 DFS \u3092\
    \u884C\u3046\n        rG.resize(N);\n        for(int i = 0; i < N; i++) {\n  \
    \          for(Edge<T> e : G[i]) {\n                rG.add_directed_edge(e.to,\
    \ e.from);\n            }\n        }\n        group.resize(N, -1);\n        int\
    \ cnt = 0;\n        for(int i = 0; i < N; i++) {\n            int t = sorted[i].second;\n\
    \            if(group[t] != -1) continue;\n            rdfs(t, cnt);\n       \
    \     cnt++;\n        }\n        dag.resize(cnt);\n        component.resize(cnt);\n\
    \        for(int i = 0; i < N; i++) {\n            component[group[i]].push_back(i);\n\
    \            for(Edge<T> e : G[i]) {\n                if(group[i] == group[e.to])\
    \ continue;\n                dag.add_directed_edge(group[i], group[e.to]);\n \
    \           }\n        }\n    }\n    void dfs(int v) {\n        if(used[v]) return;\n\
    \        used[v] = true;\n        for(Edge<T> e : G[v])\n            dfs(e.to);\n\
    \        order.push_back(v);\n    }\n    void rdfs(int v, int cnt) {\n       \
    \ if(group[v] != -1) return;\n        group[v] = cnt;\n        for(Edge<T> e :\
    \ rG[v])\n            rdfs(e.to, cnt);\n    }\n};\n"
  dependsOn:
  - src/Graph/graph-template.hpp
  isVerificationFile: false
  path: src/Graph/scc.hpp
  requiredBy: []
  timestamp: '2023-11-01 18:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-grl-3-c.test.cpp
documentation_of: src/Graph/scc.hpp
layout: document
redirect_from:
- /library/src/Graph/scc.hpp
- /library/src/Graph/scc.hpp.html
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
## 概要

$G$ に対して DFS しての帰りがけ順を求める。$G$ の辺を逆にしたグラフ $G'$ に対して、帰りがけ順が最も大きい頂点から DFS を行う。このとき、ある頂点からたどり付けた頂点集合はその頂点を含む強連結成分になっている。

## 計算量

$\mathcal{O}(|V| + |E|)$ 