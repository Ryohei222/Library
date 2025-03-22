---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/fenwick-tree.hpp
    title: Fenwick Tree
  - icon: ':question:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
  - icon: ':x:'
    path: src/Graph/hld.hpp
    title: Heavy-Light Decomposition
  - icon: ':question:'
    path: src/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"src/test/verify/yosupo-vertex-add-path-sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#line\
    \ 2 \"src/template.hpp\"\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n */\n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n//\
    \ #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing ull = unsigned long long;\nusing vl = vector<ll>;\n\
    using vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\n\
    using vp = vector<pl>;\nusing vvp = vector<vp>;\nusing vs = vector<string>;\n\
    using vvs = vector<vs>;\nusing vb = vector<bool>;\nusing vvb = vector<vb>;\nusing\
    \ vvvb = vector<vvb>;\nusing vd = vector<double>;\nusing vvd = vector<vd>;\nusing\
    \ vvvd = vector<vvd>;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define\
    \ _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(ll i = ll(a); i < ll(b);\
    \ ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n\nconstexpr ll inf = 0x1fffffffffffffffLL;\
    \ // 2.3 * 10^18\n\ntemplate <class T, class U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <class T, class U>\nostream &operator<<(ostream &os, pair<T, U> &p) {\n    os\
    \ << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate <class T>\n\
    istream &operator>>(istream &is, vector<T> &v) {\n    for(auto &x : v) {\n   \
    \     is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n    for(int i = 0; i < (int)v.size(); i++) {\n \
    \       if(i != (int)v.size() - 1)\n            os << v[i] << \" \";\n       \
    \ else\n            os << v[i];\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T, typename... Args>\nauto vec(T x, int arg, Args... args) {\n    if constexpr(sizeof...(args)\
    \ == 0)\n        return vector<T>(arg, x);\n    else\n        return vector(arg,\
    \ vec<T>(x, args...));\n}\n\ntemplate <class T>\nbool chmin(T &a, const T &b)\
    \ {\n    return a > b ? a = b, true : false;\n}\ntemplate <class T>\nbool chmax(T\
    \ &a, const T &b) {\n    return a < b ? a = b, true : false;\n}\n\nconstexpr ll\
    \ bit(ll x) {\n    return 1LL << x;\n}\nconstexpr ll msk(ll x) {\n    return (1LL\
    \ << x) - 1;\n}\nconstexpr bool stand(ll x, int i) {\n    return x & bit(i);\n\
    }\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n#line 3 \"src/test/verify/yosupo-vertex-add-path-sum.test.cpp\"\
    \n\n#line 2 \"src/DataStructure/fenwick-tree.hpp\"\n\n/**\n * @brief Fenwick Tree\n\
    \ */\n\ntemplate <typename T = long long int>\nstruct FenwickTree {\n    int n;\n\
    \    vector<T> bit;\n    FenwickTree(int n)\n        : n(n) {\n        bit.assign(n\
    \ + 1, T(0));\n    }\n    FenwickTree(const vector<T> &a) {\n        n = (int)a.size();\n\
    \        bit.assign(n + 1, T(0));\n        for(int i = 0; i < n; ++i) {\n    \
    \        apply(i, a[i]);\n        }\n    }\n    void apply(int idx, T x) {\n \
    \       ++idx;\n        while(idx <= n) {\n            bit[idx] += x;\n      \
    \      idx += idx & -idx;\n        }\n    }\n    void set(int idx, T x) {\n  \
    \      T pre = prod(idx, idx + 1);\n        apply(idx, x - pre);\n    }\n    T\
    \ prod(int r) {\n        T ret = T(0);\n        ++r;\n        while(r > 0) {\n\
    \            ret += bit[r];\n            r -= r & -r;\n        }\n        return\
    \ ret;\n    }\n    T prod(int l, int r) {\n        if(l == 0)\n            return\
    \ prod(r - 1);\n        else\n            return prod(r - 1) - prod(l - 1);\n\
    \    }\n};\n#line 2 \"src/Graph/hld.hpp\"\n\n#line 2 \"src/Graph/graph-template.hpp\"\
    \n\n/**\n * @brief Graph Template\n * @cite https://github.com/ei1333/library/blob/master/graph/graph-template.hpp\
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
    \        }\n    }\n};\n#line 6 \"src/test/verify/yosupo-vertex-add-path-sum.test.cpp\"\
    \n\nint main() {\n    ll N, Q;\n    cin >> N >> Q;\n    vl a(N);\n    cin >> a;\n\
    \    Graph<ll> G(N);\n    G.read(N - 1, 0);\n    auto hld = HeavyLightDecomposition(G);\n\
    \    hld.build();\n    FenwickTree seg(N);\n    rep(i, N) {\n        seg.set(hld.order[i],\
    \ a[i]);\n    }\n    while(Q--) {\n        ll t, x, y;\n        cin >> t >> x\
    \ >> y;\n        if(t == 0) {\n            seg.apply(hld.order[x], y);\n     \
    \   } else {\n            ll ans = 0;\n            auto paths = hld.path_vertex(x,\
    \ y);\n            for(auto [p, q] : paths) {\n                ans += seg.prod(p,\
    \ q);\n            }\n            cout << ans << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include \"../../template.hpp\"\n\n#include \"../../DataStructure/fenwick-tree.hpp\"\
    \n#include \"../../Graph/hld.hpp\"\n\nint main() {\n    ll N, Q;\n    cin >> N\
    \ >> Q;\n    vl a(N);\n    cin >> a;\n    Graph<ll> G(N);\n    G.read(N - 1, 0);\n\
    \    auto hld = HeavyLightDecomposition(G);\n    hld.build();\n    FenwickTree\
    \ seg(N);\n    rep(i, N) {\n        seg.set(hld.order[i], a[i]);\n    }\n    while(Q--)\
    \ {\n        ll t, x, y;\n        cin >> t >> x >> y;\n        if(t == 0) {\n\
    \            seg.apply(hld.order[x], y);\n        } else {\n            ll ans\
    \ = 0;\n            auto paths = hld.path_vertex(x, y);\n            for(auto\
    \ [p, q] : paths) {\n                ans += seg.prod(p, q);\n            }\n \
    \           cout << ans << endl;\n        }\n    }\n}\n"
  dependsOn:
  - src/template.hpp
  - src/DataStructure/fenwick-tree.hpp
  - src/Graph/hld.hpp
  - src/Graph/graph-template.hpp
  isVerificationFile: true
  path: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-22 12:22:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/yosupo-vertex-add-path-sum.test.cpp
- /verify/src/test/verify/yosupo-vertex-add-path-sum.test.cpp.html
title: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
---
