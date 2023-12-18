---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/union-find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  - icon: ':heavy_check_mark:'
    path: src/Graph/kruskal.hpp
    title: Kruskal
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"src/test/verify/aoj-grl-2-a.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n#line\
    \ 2 \"src/template.hpp\"\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @docs docs/template.md\n */\n\n// #pragma GCC target(\"avx2\")\n// #pragma\
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
    \ inf = 0x1fffffffffffffffLL;\n\ntemplate <class T1, class T2> void input(vector<T1>\
    \ &v1, vector<T2> &v2){ rep(i, v1.size()) cin >> v1[i] >> v2[i]; }\ntemplate <class\
    \ T1, class T2, class T3> void input(vector<T1> &v1, vector<T2> &v2, vector<T3>\
    \ &v3) { rep(i, v1.size()) cin >> v1[i] >> v2[i] >> v3[i]; }\ntemplate <class\
    \ T1, class T2, class T3, class T4> void input(vector<T1> &v1, vector<T2> &v2,\
    \ vector<T3> &v3, vector<T4> &v4) { rep(i, v1.size()) cin >> v1[i] >> v2[i] >>\
    \ v3[i] >> v4[i]; }\n\ntemplate <class T> istream &operator>>(istream &is, vector<T>\
    \ &v) {\n    for(auto &x : v) {\n        is >> x;\n    }\n    return is;\n}\n\n\
    template <class T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n \
    \   for(int i = 0; i < (int)v.size(); i++) {\n        if(i != (int)v.size() -\
    \ 1)\n            os << v[i] << \" \";\n        else\n            os << v[i];\n\
    \    }\n    return os;\n}\n\ntemplate <class T, class U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <class T, class U>\nostream &operator<<(ostream &os, pair<T, U> &p) {\n\
    \    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate <typename\
    \ T, typename... Args>\nauto vec(T x, int arg, Args... args) {\n    if constexpr(sizeof...(args)\
    \ == 0)\n        return vector<T>(arg, x);\n    else\n        return vector(arg,\
    \ vec<T>(x, args...));\n}\n\ntemplate <class T> auto min(const T &a) { return\
    \ *min_element(all(a)); }\ntemplate <class T> auto max(const T &a) { return *max_element(all(a));\
    \ }\ntemplate <class T> bool chmin(T &a, const T &b) { return a > b ? a = b, true\
    \ : false; }\ntemplate <class T> bool chmax(T &a, const T &b) { return a < b ?\
    \ a = b, true : false; }\n\nconstexpr ll bit(ll x){ return 1LL << x; }\nconstexpr\
    \ ll msk(ll x){ return (1LL << x) - 1;}\nconstexpr bool stand(ll x, int i) { return\
    \ x & bit(i); }\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n#line 2 \"src/Graph/kruskal.hpp\"\
    \n\n/**\n * @brief Kruskal\n * @docs docs/kruskal.md\n */\n\n#line 2 \"src/Graph/graph-template.hpp\"\
    \n\n/**\n * @brief Graph Template\n * @docs docs/graph-template.md\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <typename T = int>\nstruct Edge\
    \ {\n    int from, to;\n    T cost;\n    int idx;\n\n    Edge() = default;\n\n\
    \    Edge(int from, int to, T cost = 1, int idx = -1)\n      : from(from)\n  \
    \    , to(to)\n      , cost(cost)\n      , idx(idx) {\n    }\n\n    operator int()\
    \ const { return to; }\n};\n\ntemplate <typename T = int>\nstruct Graph {\n  \
    \  vector<vector<Edge<T>>> g;\n    int es;\n\n    Graph() = default;\n\n    explicit\
    \ Graph(int n)\n      : g(n)\n      , es(0) {\n    }\n\n    size_t size() const\
    \ {\n        return g.size();\n    }\n\n    void resize(int n) {\n        g.resize(n);\n\
    \    }\n\n    void add_directed_edge(int from, int to, T cost = 1) {\n       \
    \ g[from].emplace_back(from, to, cost, es++);\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n\
    \        g[to].emplace_back(to, from, cost, es++);\n    }\n\n    void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n     \
    \   for(int i = 0; i < M; i++) {\n            int a, b;\n            cin >> a\
    \ >> b;\n            a += padding;\n            b += padding;\n            T c\
    \ = T(1);\n            if(weighted)\n                cin >> c;\n            if(directed)\n\
    \                add_directed_edge(a, b, c);\n            else\n             \
    \   add_edge(a, b, c);\n        }\n    }\n\n    void debug(){\n        rep(i,\
    \ g.size()){\n            cerr << i << \": \";\n            for(auto &e : g[i]){\n\
    \                cerr << e.to << \", \";\n            }\n            cerr << endl;\n\
    \        }\n    }\n\n    inline vector<Edge<T>>& operator[](const int& k) {\n\
    \        return g[k];\n    }\n\n    inline const vector<Edge<T>>& operator[](const\
    \ int& k) const {\n        return g[k];\n    }\n};\n\ntemplate <typename T = int>\n\
    using Edges = vector<Edge<T>>;\n#line 2 \"src/DataStructure/union-find.hpp\"\n\
    \n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n\nstruct UnionFind\
    \ {\n    vector<int> par;\n    UnionFind(int n) {\n        par.assign(n, -1);\n\
    \    };\n    int root(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = root(par[x]);\n    }\n    int size(int\
    \ x) {\n        x = root(x);\n        return -1 * par[x];\n    }\n    bool unite(int\
    \ x, int y) {\n        x = root(x);\n        y = root(y);\n        if(x == y)\n\
    \            return false;\n        if(size(x) < size(y))\n            swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n    bool same(int x, int y) {\n        return root(x) == root(y);\n  \
    \  }\n};\n#line 10 \"src/Graph/kruskal.hpp\"\n\ntemplate <typename T>\npair<T,\
    \ Edges<T>> kruskal(Graph<T> &G){\n    // \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\
    \u3067 G \u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\n    //\
    \ \u8FD4\u308A\u5024\u306F (cost, vector<Edge>)\n    int N = G.size();\n    UnionFind\
    \ uf(N);\n    Edges<T> edges;\n    for(int i = 0; i < N; i++){\n        for(auto\
    \ &edge: G[i]){\n            edges.emplace_back(edge);\n        }\n    }\n   \
    \ auto comp = [](const Edge<T> &a, const Edge<T> &b){\n        return a.cost <\
    \ b.cost;\n    };\n    sort(edges.begin(), edges.end(), comp);\n    T cost = (T)0;\n\
    \    Edges<T> mst;\n    for(auto &edge: edges){\n        if(uf.unite(edge.from,\
    \ edge.to)){\n            cost += edge.cost;\n            mst.emplace_back(edge);\n\
    \        }\n    }\n    if(uf.size(0) == N) return pair<T, Edges<T>>(cost, mst);\n\
    \    else return pair<T, Edges<T>>((T)-1, mst);\n}\n#line 5 \"src/test/verify/aoj-grl-2-a.test.cpp\"\
    \n\nint main(){\n    ll V, E;\n    cin >> V >> E;\n    Graph G(V);\n    G.read(E,\
    \ 0, true, false);\n    auto [cost, mst] = kruskal(G);\n    cout << cost << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../template.hpp\"\n#include \"../../Graph/kruskal.hpp\"\n\n\
    int main(){\n    ll V, E;\n    cin >> V >> E;\n    Graph G(V);\n    G.read(E,\
    \ 0, true, false);\n    auto [cost, mst] = kruskal(G);\n    cout << cost << endl;\n\
    }"
  dependsOn:
  - src/template.hpp
  - src/Graph/kruskal.hpp
  - src/Graph/graph-template.hpp
  - src/DataStructure/union-find.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-grl-2-a.test.cpp
  requiredBy: []
  timestamp: '2023-12-18 22:27:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-grl-2-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-grl-2-a.test.cpp
- /verify/src/test/verify/aoj-grl-2-a.test.cpp.html
title: src/test/verify/aoj-grl-2-a.test.cpp
---
