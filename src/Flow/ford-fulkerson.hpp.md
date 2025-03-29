---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-6-a.test.cpp
    title: src/test/verify/aoj-grl-6-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/ford-fulkerson.md
    document_title: Ford-Fulkerson
    links: []
  bundledCode: "#line 2 \"src/Flow/ford-fulkerson.hpp\"\n\n/**\n * @brief Ford-Fulkerson\n\
    \ * @docs docs/ford-fulkerson.md\n */\n\ntemplate <typename T>\nstruct FordFulkerson\
    \ {\n    struct Edge {\n        int to, rev_idx;\n        T cap;\n    };\n   \
    \ int N;\n    vector<vector<Edge>> G;\n    vector<bool> vis;\n\n    FordFulkerson(int\
    \ N)\n        : N(N), G(N), vis(N) {}\n\n    void add_edge(int from, int to, T\
    \ cap) {\n        G[from].emplace_back((Edge){to, (int)G[to].size(), cap}); //\
    \ e.from = G[e.to][e.rev_idx].to;\n        G[to].emplace_back((Edge){from, (int)G[from].size()\
    \ - 1, T(0)});\n    }\n\n    // v -> t \u306E\u6D41\u91CF f \u4EE5\u4E0B\u306E\
    \u5897\u52A0\u9053\u3092\u63A2\u3059\n    T dfs(int v, int t, T f) {\n       \
    \ if(v == t) return f;\n        vis[v] = true;\n        for(auto &e : G[v]) {\n\
    \            if(!vis[e.to] && e.cap > (T)0) {\n                T d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if(d > (T)0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev_idx].cap += d;\n                  \
    \  return d;\n                }\n            }\n        }\n        return (T)0;\n\
    \    }\n\n    T max_flow(int s, int t) {\n        T flow = 0, INF = numeric_limits<T>::max();\n\
    \        while(true) {\n            vis.assign(N, false);\n            T f = dfs(s,\
    \ t, INF);\n            if(f == (T)0) return flow;\n            flow += f;\n \
    \       }\n    }\n\n    void debug() {\n        cerr << \"---------\" << '\\n';\n\
    \        for(int i = 0; i < N; i++) {\n            for(auto &e : G[i]) {\n   \
    \             if(e.to < i) continue;\n                cerr << i << \" -> \" <<\
    \ e.to << \": \" << G[e.to][e.rev_idx].cap << '\\n';\n            }\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Ford-Fulkerson\n * @docs docs/ford-fulkerson.md\n\
    \ */\n\ntemplate <typename T>\nstruct FordFulkerson {\n    struct Edge {\n   \
    \     int to, rev_idx;\n        T cap;\n    };\n    int N;\n    vector<vector<Edge>>\
    \ G;\n    vector<bool> vis;\n\n    FordFulkerson(int N)\n        : N(N), G(N),\
    \ vis(N) {}\n\n    void add_edge(int from, int to, T cap) {\n        G[from].emplace_back((Edge){to,\
    \ (int)G[to].size(), cap}); // e.from = G[e.to][e.rev_idx].to;\n        G[to].emplace_back((Edge){from,\
    \ (int)G[from].size() - 1, T(0)});\n    }\n\n    // v -> t \u306E\u6D41\u91CF\
    \ f \u4EE5\u4E0B\u306E\u5897\u52A0\u9053\u3092\u63A2\u3059\n    T dfs(int v, int\
    \ t, T f) {\n        if(v == t) return f;\n        vis[v] = true;\n        for(auto\
    \ &e : G[v]) {\n            if(!vis[e.to] && e.cap > (T)0) {\n               \
    \ T d = dfs(e.to, t, min(f, e.cap));\n                if(d > (T)0) {\n       \
    \             e.cap -= d;\n                    G[e.to][e.rev_idx].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return (T)0;\n    }\n\n    T max_flow(int s, int t) {\n        T flow\
    \ = 0, INF = numeric_limits<T>::max();\n        while(true) {\n            vis.assign(N,\
    \ false);\n            T f = dfs(s, t, INF);\n            if(f == (T)0) return\
    \ flow;\n            flow += f;\n        }\n    }\n\n    void debug() {\n    \
    \    cerr << \"---------\" << '\\n';\n        for(int i = 0; i < N; i++) {\n \
    \           for(auto &e : G[i]) {\n                if(e.to < i) continue;\n  \
    \              cerr << i << \" -> \" << e.to << \": \" << G[e.to][e.rev_idx].cap\
    \ << '\\n';\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Flow/ford-fulkerson.hpp
  requiredBy: []
  timestamp: '2025-03-29 13:19:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-grl-6-a.test.cpp
documentation_of: src/Flow/ford-fulkerson.hpp
layout: document
redirect_from:
- /library/src/Flow/ford-fulkerson.hpp
- /library/src/Flow/ford-fulkerson.hpp.html
title: Ford-Fulkerson
---
## 概要

残余グラフを構築し、s-t 間に増加パスが存在する間フローを流し続ける。

最大流 の流量を $F$ として、最悪計算量が $O(F|E|)$ になる。

## 参考資料

蟻本 p190