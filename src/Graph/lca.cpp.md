---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/Graph/graph-template.cpp
    title: src/Graph/graph-template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/graph-template.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<typename T>\nstruct Edge{\n   \
    \ int to, int from;\n    T cost;\n    Edge(int to) : to(to) {}\n    Edge(int to,\
    \ T cost) : to(to), cost(cost) {}\n    Edge(int from, int to, T cost) : from(from),\
    \ to(to), cost(cost) {}\n};\n\ntemplate<typename T>\nusing Graph = vector<vector<Edge<T>>>;\n\
    #line 2 \"src/Graph/lca.cpp\"\n\n//\ntemplate<typename T>\nstruct LCA{  \n   \
    \ // N: \u9802\u70B9\u6570, K: \u30C0\u30D6\u30EA\u30F3\u30B0\u3067 2^0, 2^1,\
    \ 2^2 , ... \u500B\u5148\u306E\u9802\u70B9\u3092\u6301\u3064\u304C\u30012 \u306E\
    \u4F55\u4E57\u5148\u306E\u9802\u70B9\u307E\u3067\u6301\u3064\u304B\u3092\u8868\
    \u3059\n    int N, K = 20;\n    vector<int> dist;\n    // doubling[i][j] := \u9802\
    \u70B9 i \u306E 2^j \u500B\u5148(\u89AA)\u306E\u9802\u70B9\u756A\u53F7\n    vector<vector<int>>\
    \ doubling;\n    // par: \u6839\n    LCA(Graph<T> G, int par){\n        N = G.size();\n\
    \        dist.assign(N, -1);\n        doubling.assign(N, vector<int>(K, -1));\n\
    \        // \u6839\u304B\u3089 BFS \u3057\u3066\u5404\u9802\u70B9\u306E\u89AA\u3092\
    \u6C42\u3081\u308B\n        queue<int> que;\n        que.push(par);\n        dist[par]\
    \ = 0;\n        doubling[par][0] = par;\n        while(!que.empty()){\n      \
    \      int t = que.front(); que.pop();\n            for(auto e : G[t]){\n    \
    \            if(dist[e.to] == -1){\n                    dist[e.to] = dist[t] +\
    \ 1;\n                    doubling[e.to][0] = t;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        for(int k = 1; k < K; k++){\n\
    \            for(int i = 0; i < N; i++){\n                doubling[i][k] = doubling[doubling[i][k\
    \ - 1]][k - 1];\n            }\n        }\n    }\n    int query(int u, int v){\n\
    \        if(dist[u] > dist[v]) swap(u, v);\n        // d(par, u) = d(par, v) \u304C\
    \u6210\u308A\u7ACB\u3064\u3088\u3046\u306B v \u3092\u52D5\u304B\u3059\n      \
    \  for(int k = 0; k < K; k++){\n            if((dist[v] - dist[u]) & ((1LL) <<\
    \ k)) v = doubling[v][k];\n        }\n        // u \u304C v \u306E\u7956\u5148\
    \u306A\u3089\u3070 u \u304C (u, v) \u306E LCA\n        if(u == v) return u;\n\
    \        for(int k = K - 1; k >= 0; k--){\n            // doubling[u][k] != doubling[v][k]\
    \ \u306A\u3089\u3070 (u, v) \u306E LCA \u306F\u5C11\u306A\u304F\u3068\u3082 u,\
    \ v \u306E (2^k) + 1 \u500B\u5148\u306E\u9802\u70B9\n            if(doubling[u][k]\
    \ != doubling[v][k]){\n                u = doubling[u][k];\n                v\
    \ = doubling[v][k];\n            }\n        }\n        // u, v \u306B\u683C\u7D0D\
    \u3055\u308C\u3066\u3044\u308B\u9802\u70B9\u306F (u, v) \u306E LCA \u306E 1 \u3064\
    \u624B\u524D\u306A\u306E\u3067\n        return doubling[u][0];\n    }\n};\n\n\
    void GRL_5_C(){\n    int n;\n    cin >> n;\n    Graph<int> G(n);\n    for(int\
    \ i = 0; i < n; i++){\n        int k;\n        cin >> k;\n        for(int j =\
    \ 0; j < k; k++){\n            int to;\n            cin >> to;\n            G[i].emplace_back(to);\n\
    \            G[to].emplace_back(i);\n        }\n    }\n    LCA<int> lca(G, 0);\n\
    \    int q;\n    cin >> q;\n    for(int i = 0; i < q; i++){\n        int u, v;\n\
    \        cin >> u >> v;\n        cout << lca.query(u, v) << endl;\n    }\n}\n"
  code: "#include \"graph-template.cpp\"\n\n//\ntemplate<typename T>\nstruct LCA{\
    \  \n    // N: \u9802\u70B9\u6570, K: \u30C0\u30D6\u30EA\u30F3\u30B0\u3067 2^0,\
    \ 2^1, 2^2 , ... \u500B\u5148\u306E\u9802\u70B9\u3092\u6301\u3064\u304C\u3001\
    2 \u306E\u4F55\u4E57\u5148\u306E\u9802\u70B9\u307E\u3067\u6301\u3064\u304B\u3092\
    \u8868\u3059\n    int N, K = 20;\n    vector<int> dist;\n    // doubling[i][j]\
    \ := \u9802\u70B9 i \u306E 2^j \u500B\u5148(\u89AA)\u306E\u9802\u70B9\u756A\u53F7\
    \n    vector<vector<int>> doubling;\n    // par: \u6839\n    LCA(Graph<T> G, int\
    \ par){\n        N = G.size();\n        dist.assign(N, -1);\n        doubling.assign(N,\
    \ vector<int>(K, -1));\n        // \u6839\u304B\u3089 BFS \u3057\u3066\u5404\u9802\
    \u70B9\u306E\u89AA\u3092\u6C42\u3081\u308B\n        queue<int> que;\n        que.push(par);\n\
    \        dist[par] = 0;\n        doubling[par][0] = par;\n        while(!que.empty()){\n\
    \            int t = que.front(); que.pop();\n            for(auto e : G[t]){\n\
    \                if(dist[e.to] == -1){\n                    dist[e.to] = dist[t]\
    \ + 1;\n                    doubling[e.to][0] = t;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        for(int k = 1; k < K; k++){\n\
    \            for(int i = 0; i < N; i++){\n                doubling[i][k] = doubling[doubling[i][k\
    \ - 1]][k - 1];\n            }\n        }\n    }\n    int query(int u, int v){\n\
    \        if(dist[u] > dist[v]) swap(u, v);\n        // d(par, u) = d(par, v) \u304C\
    \u6210\u308A\u7ACB\u3064\u3088\u3046\u306B v \u3092\u52D5\u304B\u3059\n      \
    \  for(int k = 0; k < K; k++){\n            if((dist[v] - dist[u]) & ((1LL) <<\
    \ k)) v = doubling[v][k];\n        }\n        // u \u304C v \u306E\u7956\u5148\
    \u306A\u3089\u3070 u \u304C (u, v) \u306E LCA\n        if(u == v) return u;\n\
    \        for(int k = K - 1; k >= 0; k--){\n            // doubling[u][k] != doubling[v][k]\
    \ \u306A\u3089\u3070 (u, v) \u306E LCA \u306F\u5C11\u306A\u304F\u3068\u3082 u,\
    \ v \u306E (2^k) + 1 \u500B\u5148\u306E\u9802\u70B9\n            if(doubling[u][k]\
    \ != doubling[v][k]){\n                u = doubling[u][k];\n                v\
    \ = doubling[v][k];\n            }\n        }\n        // u, v \u306B\u683C\u7D0D\
    \u3055\u308C\u3066\u3044\u308B\u9802\u70B9\u306F (u, v) \u306E LCA \u306E 1 \u3064\
    \u624B\u524D\u306A\u306E\u3067\n        return doubling[u][0];\n    }\n};\n\n\
    void GRL_5_C(){\n    int n;\n    cin >> n;\n    Graph<int> G(n);\n    for(int\
    \ i = 0; i < n; i++){\n        int k;\n        cin >> k;\n        for(int j =\
    \ 0; j < k; k++){\n            int to;\n            cin >> to;\n            G[i].emplace_back(to);\n\
    \            G[to].emplace_back(i);\n        }\n    }\n    LCA<int> lca(G, 0);\n\
    \    int q;\n    cin >> q;\n    for(int i = 0; i < q; i++){\n        int u, v;\n\
    \        cin >> u >> v;\n        cout << lca.query(u, v) << endl;\n    }\n}"
  dependsOn:
  - src/Graph/graph-template.cpp
  isVerificationFile: false
  path: src/Graph/lca.cpp
  requiredBy: []
  timestamp: '2022-09-02 20:16:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/lca.cpp
layout: document
redirect_from:
- /library/src/Graph/lca.cpp
- /library/src/Graph/lca.cpp.html
title: src/Graph/lca.cpp
---
