---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  - icon: ':x:'
    path: src/Graph/lca.hpp
    title: "LCA(\u30C0\u30D6\u30EA\u30F3\u30B0)"
  - icon: ':x:'
    path: src/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"src/test/verify/yosupo-lca.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"src/Graph/lca.hpp\"\n\n/**\n\
    \ * @brief LCA(\u30C0\u30D6\u30EA\u30F3\u30B0)\n * @docs docs/lca-doubling.md\n\
    \ */\n\n#line 2 \"src/Graph/graph-template.hpp\"\n\n/**\n * @brief Graph Template\n\
    \ * @docs docs/graph-template.md\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
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
    \ 9 \"src/Graph/lca.hpp\"\ntemplate <typename T = int>\nstruct LCA {\n    // N:\
    \ \u9802\u70B9\u6570, K: \u30C0\u30D6\u30EA\u30F3\u30B0\u3067 2^0, 2^1, 2^2 ,\
    \ ... \u500B\u5148\u306E\u9802\u70B9\u3092\u6301\u3064\u304C\u30012 \u306E\u4F55\
    \u4E57\u5148\u306E\u9802\u70B9\u307E\u3067\u6301\u3064\u304B\u3092\u8868\u3059\
    \n    int N, K;\n    vector<int> dist;\n    vector<vector<int>> doubling;\n  \
    \  LCA(Graph<T> G, int find) {\n        N = (int)G.size();\n        K = 1;\n \
    \       while((1LL << K) <= N)\n            K++;\n        dist.assign(N, -1);\n\
    \        doubling.assign(N, vector<int>(K, -1));\n        // \u6839\u304B\u3089\
    \ BFS \u3057\u3066\u5404\u9802\u70B9\u306E\u89AA\u3092\u6C42\u3081\u308B\n   \
    \     queue<int> que;\n        que.push(find);\n        dist[find] = 0;\n    \
    \    doubling[find][0] = find;\n        while(!que.empty()) {\n            int\
    \ t = que.front();\n            que.pop();\n            for(auto e : G[t]) {\n\
    \                if(dist[e.to] == -1) {\n                    dist[e.to] = dist[t]\
    \ + 1;\n                    doubling[e.to][0] = t;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        for(int k = 1; k < K; k++)\
    \ {\n            for(int i = 0; i < N; i++) {\n                doubling[i][k]\
    \ = doubling[doubling[i][k - 1]][k - 1];\n            }\n        }\n    }\n  \
    \  int query(int u, int v) {\n        if(dist[u] > dist[v]) swap(u, v);\n    \
    \    for(int k = 0; k < K; k++) {\n            if((dist[v] - dist[u]) & ((1LL)\
    \ << k)) v = doubling[v][k];\n        }\n        if(u == v) return u;\n      \
    \  for(int k = K - 1; k >= 0; k--) {\n            if(doubling[u][k] != doubling[v][k])\
    \ {\n                u = doubling[u][k];\n                v = doubling[v][k];\n\
    \            }\n        }\n        return doubling[u][0];\n    }\n};\n#line 2\
    \ \"src/template.hpp\"\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n\
    \ * @docs docs/template.md\n */\n\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\nusing\
    \ vp = vector<pl>;\nusing vvp = vector<vp>;\nusing vs = vector<string>;\nusing\
    \ vvs = vector<vs>;\nusing vb = vector<bool>;\nusing vvb = vector<vb>;\nusing\
    \ vvvb = vector<vvb>;\nusing vd = vector<double>;\nusing vvd = vector<vd>;\nusing\
    \ vvvd = vector<vvd>;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define\
    \ _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(ll i = ll(a); i < ll(b);\
    \ ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n#define make_unique(v) v.erase(unique(all(v)),\
    \ v.end());\n#define sum(...) accumulate(all(__VA_ARGS__), 0LL)\n\nconstexpr ll\
    \ inf = 0x1fffffffffffffffLL;\n\ntemplate <class T, class U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <class T, class U>\nostream &operator<<(ostream &os, pair<T, U> &p) {\n\
    \    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate <class\
    \ T1, class T2>\nvoid input(vector<T1> &v1, vector<T2> &v2) {\n    rep(i, v1.size())\
    \ cin >> v1[i] >> v2[i];\n}\ntemplate <class T1, class T2, class T3>\nvoid input(vector<T1>\
    \ &v1, vector<T2> &v2, vector<T3> &v3) {\n    rep(i, v1.size()) cin >> v1[i] >>\
    \ v2[i] >> v3[i];\n}\ntemplate <class T1, class T2, class T3, class T4>\nvoid\
    \ input(vector<T1> &v1, vector<T2> &v2, vector<T3> &v3, vector<T4> &v4) {\n  \
    \  rep(i, v1.size()) cin >> v1[i] >> v2[i] >> v3[i] >> v4[i];\n}\n\ntemplate <class\
    \ T>\nistream &operator>>(istream &is, vector<T> &v) {\n    for(auto &x : v) {\n\
    \        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n    for(int i = 0; i < (int)v.size(); i++) {\n \
    \       if(i != (int)v.size() - 1)\n            os << v[i] << \" \";\n       \
    \ else\n            os << v[i];\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T, typename... Args>\nauto vec(T x, int arg, Args... args) {\n    if constexpr(sizeof...(args)\
    \ == 0)\n        return vector<T>(arg, x);\n    else\n        return vector(arg,\
    \ vec<T>(x, args...));\n}\n\ntemplate <class T>\nauto min(const T &a) {\n    return\
    \ *min_element(all(a));\n}\ntemplate <class T>\nauto max(const T &a) {\n    return\
    \ *max_element(all(a));\n}\ntemplate <class T>\nbool chmin(T &a, const T &b) {\n\
    \    return a > b ? a = b, true : false;\n}\ntemplate <class T>\nbool chmax(T\
    \ &a, const T &b) {\n    return a < b ? a = b, true : false;\n}\n\nconstexpr ll\
    \ bit(ll x) {\n    return 1LL << x;\n}\nconstexpr ll msk(ll x) {\n    return (1LL\
    \ << x) - 1;\n}\nconstexpr bool stand(ll x, int i) {\n    return x & bit(i);\n\
    }\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n#line 5 \"src/test/verify/yosupo-lca.test.cpp\"\n\nint main()\
    \ {\n    ll N, Q;\n    cin >> N >> Q;\n    Graph<> G(N);\n    vl p(N - 1);\n \
    \   cin >> p;\n    rep(i, N - 1) G.add_edge(p[i], i + 1);\n    LCA<> lca(G, 0);\n\
    \    rep(i, Q) {\n        ll u, v;\n        cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../Graph/lca.hpp\"\
    \n#include \"../../template.hpp\"\n\nint main() {\n    ll N, Q;\n    cin >> N\
    \ >> Q;\n    Graph<> G(N);\n    vl p(N - 1);\n    cin >> p;\n    rep(i, N - 1)\
    \ G.add_edge(p[i], i + 1);\n    LCA<> lca(G, 0);\n    rep(i, Q) {\n        ll\
    \ u, v;\n        cin >> u >> v;\n        cout << lca.query(u, v) << endl;\n  \
    \  }\n}"
  dependsOn:
  - src/Graph/lca.hpp
  - src/Graph/graph-template.hpp
  - src/template.hpp
  isVerificationFile: true
  path: src/test/verify/yosupo-lca.test.cpp
  requiredBy: []
  timestamp: '2024-01-23 19:55:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/test/verify/yosupo-lca.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/yosupo-lca.test.cpp
- /verify/src/test/verify/yosupo-lca.test.cpp.html
title: src/test/verify/yosupo-lca.test.cpp
---
