---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/GRL_1_A/judge/3892499/C++14
  bundledCode: "#line 1 \"src/Graph/Dijkstra.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <queue>\n#include <algorithm>\n\
    \nusing namespace std;\nusing i64 = long long int;\nusing P = pair<i64, i64>;\n\
    \nstruct edge{\n    i64 src, to, cost;\n    edge(i64 to, i64 cost) : src(-1),\
    \ to(to), cost(cost) {}\n    edge(i64 src, i64 to, i64 cost) : src(src), to(to),\
    \ cost(cost) {}\n    bool operator <(const edge &u){\n        return this->cost\
    \ < u.cost;\n    };\n};\n\nusing Graph = vector<vector<edge>>;\nconst i64 INF\
    \ = numeric_limits<i64>::max();\n\nvector<i64> dijkstra(Graph G, i64 s){\n   \
    \ //\n    // Dijkstra \u6CD5 O(ElogV)\n    // Graph G : \u6709\u5411\u30B0\u30E9\
    \u30D5\n    // i64 s : \u59CB\u70B9\u306E\u756A\u53F7\n    //\n    i64 n = G.size();\n\
    \    vector<i64> dist(n, INF);\n    dist[s] = 0;\n    priority_queue<P, vector<P>,\
    \ greater<P>> que;\n    que.emplace(0, s);\n    while(!que.empty()){\n       \
    \ P t = que.top(); que.pop();\n        i64 cost = t.first, u = t.second;\n   \
    \     if(cost > dist[u]) continue;\n        for(auto e : G[u]){\n            i64\
    \ v = e.to;\n            if(cost + e.cost < dist[v]){\n                dist[v]\
    \ = cost + e.cost;\n                que.emplace(dist[v], v);\n            }\n\
    \        }\n    }\n    return dist;\n}\n\nvoid GRL_1_A(){\n    i64 v, e, r;\n\
    \    cin >> v >> e >> r;\n    Graph G(v);\n    for(i64 i = 0; i < e; ++i){\n \
    \       i64 s, t, d;\n        cin >> s >> t >> d;\n        G[s].emplace_back(s,\
    \ t, d);\n    }\n    auto dist = dijkstra(G, r);\n    for(auto d: dist){\n   \
    \     if(d == INF) cout << \"INF\" << endl;\n        else cout << d << endl;\n\
    \    }\n}\n\nint main(){\n    GRL_1_A(); // https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/GRL_1_A/judge/3892499/C++14\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <queue>\n#include <algorithm>\n\
    \nusing namespace std;\nusing i64 = long long int;\nusing P = pair<i64, i64>;\n\
    \nstruct edge{\n    i64 src, to, cost;\n    edge(i64 to, i64 cost) : src(-1),\
    \ to(to), cost(cost) {}\n    edge(i64 src, i64 to, i64 cost) : src(src), to(to),\
    \ cost(cost) {}\n    bool operator <(const edge &u){\n        return this->cost\
    \ < u.cost;\n    };\n};\n\nusing Graph = vector<vector<edge>>;\nconst i64 INF\
    \ = numeric_limits<i64>::max();\n\nvector<i64> dijkstra(Graph G, i64 s){\n   \
    \ //\n    // Dijkstra \u6CD5 O(ElogV)\n    // Graph G : \u6709\u5411\u30B0\u30E9\
    \u30D5\n    // i64 s : \u59CB\u70B9\u306E\u756A\u53F7\n    //\n    i64 n = G.size();\n\
    \    vector<i64> dist(n, INF);\n    dist[s] = 0;\n    priority_queue<P, vector<P>,\
    \ greater<P>> que;\n    que.emplace(0, s);\n    while(!que.empty()){\n       \
    \ P t = que.top(); que.pop();\n        i64 cost = t.first, u = t.second;\n   \
    \     if(cost > dist[u]) continue;\n        for(auto e : G[u]){\n            i64\
    \ v = e.to;\n            if(cost + e.cost < dist[v]){\n                dist[v]\
    \ = cost + e.cost;\n                que.emplace(dist[v], v);\n            }\n\
    \        }\n    }\n    return dist;\n}\n\nvoid GRL_1_A(){\n    i64 v, e, r;\n\
    \    cin >> v >> e >> r;\n    Graph G(v);\n    for(i64 i = 0; i < e; ++i){\n \
    \       i64 s, t, d;\n        cin >> s >> t >> d;\n        G[s].emplace_back(s,\
    \ t, d);\n    }\n    auto dist = dijkstra(G, r);\n    for(auto d: dist){\n   \
    \     if(d == INF) cout << \"INF\" << endl;\n        else cout << d << endl;\n\
    \    }\n}\n\nint main(){\n    GRL_1_A(); // https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/GRL_1_A/judge/3892499/C++14\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2020-04-01 13:58:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/src/Graph/Dijkstra.cpp
- /library/src/Graph/Dijkstra.cpp.html
title: src/Graph/Dijkstra.cpp
---
