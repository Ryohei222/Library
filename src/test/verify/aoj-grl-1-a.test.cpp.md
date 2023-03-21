---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: src/Graph/graph-template.hpp
    title: src/Graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"src/test/verify/aoj-grl-1-a.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\n\n#line\
    \ 1 \"src/template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    using i64 = long long;\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n\n#define _overload3(_1,\
    \ _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a,\
    \ b) for(int i = int(a); i < int(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__,\
    \ repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ uniq(a)   \\\n    sort(all(a)); \\\n    a.erase(unique(all(a)), end(a))\n#define\
    \ sum(...) accumulate(all(__VA_ARGS__), 0LL)\n\ntemplate <class T>\nauto min(const\
    \ T& a) {\n    return *min_element(all(a));\n}\ntemplate <class T>\nauto max(const\
    \ T& a) {\n    return *max_element(all(a));\n}\ntemplate <class T>\nbool chmin(T&\
    \ a, const T& b) {\n    return a > b ? a = b, true : false;\n}\ntemplate <class\
    \ T>\nbool chmax(T& a, const T& b) {\n    return a < b ? a = b, true : false;\n\
    }\n#line 2 \"src/Graph/dijkstra.hpp\"\n\n/**\n * @brief Dijkstra\n * @docs docs/dijkstra.md\n\
    \ */\n\n#line 2 \"src/Graph/graph-template.hpp\"\n\n/*\n** @ei1333 \u3055\u3093\
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
    \ <typename T = int>\nusing Edges = vector<Edge<T>>;\n#line 9 \"src/Graph/dijkstra.hpp\"\
    \n\ntemplate <typename T>\nvector<T> dijkstra(Graph<T> &G, int s) {\n    const\
    \ auto INF = numeric_limits<T>::max();\n    using P = pair<T, int>;\n    int n\
    \ = G.size();\n    vector<T> dist(n, INF);\n    dist[s] = 0;\n    priority_queue<P,\
    \ vector<P>, greater<P>> que;\n    que.emplace(0, s);\n    while(!que.empty())\
    \ {\n        P t = que.top();\n        que.pop();\n        T cost = t.first;\n\
    \        int u = t.second;\n        if(cost > dist[u]) continue;\n        for(auto\
    \ e : G[u]) {\n            T v = e.to;\n            if(cost + e.cost < dist[v])\
    \ {\n                dist[v] = cost + e.cost;\n                que.emplace(dist[v],\
    \ v);\n            }\n        }\n    }\n    return dist;\n}\n#line 5 \"src/test/verify/aoj-grl-1-a.test.cpp\"\
    \n\nint main() {\n    i64 v, e, r;\n    cin >> v >> e >> r;\n    Graph<i64> G(v);\n\
    \    G.read(e, 0, true, true);\n    auto dist = dijkstra(G, r);\n    const i64\
    \ INF = std::numeric_limits<i64>::max();\n    for(auto d : dist) {\n        if(d\
    \ == INF)\n            cout << \"INF\" << endl;\n        else\n            cout\
    \ << d << endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../template.hpp\"\n#include \"../../Graph/dijkstra.hpp\"\n\n\
    int main() {\n    i64 v, e, r;\n    cin >> v >> e >> r;\n    Graph<i64> G(v);\n\
    \    G.read(e, 0, true, true);\n    auto dist = dijkstra(G, r);\n    const i64\
    \ INF = std::numeric_limits<i64>::max();\n    for(auto d : dist) {\n        if(d\
    \ == INF)\n            cout << \"INF\" << endl;\n        else\n            cout\
    \ << d << endl;\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/Graph/dijkstra.hpp
  - src/Graph/graph-template.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-grl-1-a.test.cpp
  requiredBy: []
  timestamp: '2023-03-22 00:40:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-grl-1-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-grl-1-a.test.cpp
- /verify/src/test/verify/aoj-grl-1-a.test.cpp.html
title: src/test/verify/aoj-grl-1-a.test.cpp
---
