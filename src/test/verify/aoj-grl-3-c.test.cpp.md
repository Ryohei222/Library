---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/graph-template.hpp
    title: src/Graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/Graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"src/test/verify/aoj-grl-3-c.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\n\n#line\
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
    }\n#line 2 \"src/Graph/scc.hpp\"\n\n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\n * @docs docs/scc.md\n */\n\n#line 2 \"src/Graph/graph-template.hpp\"\
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
    \  }\n\n    inline vector<Edge<T>>& operator[](const int& k) {\n        return\
    \ g[k];\n    }\n\n    inline const vector<Edge<T>>& operator[](const int& k) const\
    \ {\n        return g[k];\n    }\n};\n\ntemplate <typename T = int>\nusing Edges\
    \ = vector<Edge<T>>;\n#line 9 \"src/Graph/scc.hpp\"\n\ntemplate <typename T>\n\
    struct SCC {\n    Graph<T> G, rG;\n    SCC(Graph<T> G)\n      : G{G} {}\n    Graph<T>\
    \ dag;\n    vector<bool> used;\n    // group[i] := i \u756A\u76EE\u306E\u9802\u70B9\
    \u304C\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\n   \
    \ // component[i] := i \u756A\u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u5C5E\
    \u3059\u308B\u9802\u70B9\u306E\u96C6\u5408\n    vector<int> order, group;\n  \
    \  vector<vector<int>> component;\n    void build() {\n        int N = G.size();\n\
    \        used.resize(N, false);\n        for(int i = 0; i < N; i++) {\n      \
    \      if(!used[i]) {\n                dfs(i);\n            }\n        }\n   \
    \     using Pi = pair<int, int>;\n        vector<Pi> sorted;\n        for(int\
    \ i = 0; i < N; i++) {\n            sorted.emplace_back(i, order[i]);\n      \
    \  }\n        sort(sorted.begin(), sorted.end(), greater<Pi>());\n        // \u9006\
    \u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\u3067 DFS \u3092\u884C\u3046\n\
    \        rG.resize(N);\n        for(int i = 0; i < N; i++) {\n            for(Edge<T>\
    \ e : G[i]) {\n                rG.add_directed_edge(e.to, e.from);\n         \
    \   }\n        }\n        group.resize(N, -1);\n        int cnt = 0;\n       \
    \ for(int i = 0; i < N; i++) {\n            int t = sorted[i].second;\n      \
    \      if(group[t] != -1) continue;\n            rdfs(t, cnt);\n            cnt++;\n\
    \        }\n        dag.resize(cnt);\n        component.resize(cnt);\n       \
    \ for(int i = 0; i < N; i++) {\n            component[group[i]].push_back(i);\n\
    \            for(Edge<T> e : G[i]) {\n                if(group[i] == group[e.to])\
    \ continue;\n                dag.add_directed_edge(group[i], group[e.to]);\n \
    \           }\n        }\n    }\n    void dfs(int v) {\n        if(used[v]) return;\n\
    \        used[v] = true;\n        for(Edge<T> e : G[v])\n            dfs(e.to);\n\
    \        order.push_back(v);\n    }\n    void rdfs(int v, int cnt) {\n       \
    \ if(group[v] != -1) return;\n        group[v] = cnt;\n        for(Edge<T> e :\
    \ rG[v])\n            rdfs(e.to, cnt);\n    }\n};\n#line 5 \"src/test/verify/aoj-grl-3-c.test.cpp\"\
    \n\nint main() {\n    int V, E, Q;\n    cin >> V >> E;\n    Graph<int> G(V);\n\
    \    G.read(E, 0, false, true);\n    SCC<int> scc(G);\n    cin >> Q;\n    scc.build();\n\
    \    rep(i, Q) {\n        int u, v;\n        cin >> u >> v;\n        cout << (scc.group[u]\
    \ == scc.group[v]) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include \"../../template.hpp\"\n#include \"../../Graph/scc.hpp\"\n\nint main()\
    \ {\n    int V, E, Q;\n    cin >> V >> E;\n    Graph<int> G(V);\n    G.read(E,\
    \ 0, false, true);\n    SCC<int> scc(G);\n    cin >> Q;\n    scc.build();\n  \
    \  rep(i, Q) {\n        int u, v;\n        cin >> u >> v;\n        cout << (scc.group[u]\
    \ == scc.group[v]) << endl;\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/Graph/scc.hpp
  - src/Graph/graph-template.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-grl-3-c.test.cpp
  requiredBy: []
  timestamp: '2023-03-24 13:28:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-grl-3-c.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-grl-3-c.test.cpp
- /verify/src/test/verify/aoj-grl-3-c.test.cpp.html
title: src/test/verify/aoj-grl-3-c.test.cpp
---