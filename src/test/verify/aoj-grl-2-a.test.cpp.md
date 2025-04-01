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
    path: src/Util/debug.hpp
    title: Debug
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
    \    }\n} iosetup;\n\n#line 2 \"src/Util/debug.hpp\"\n\n/**\n * @brief Debug\n\
    \ */\n\n#ifdef LOCAL\n#define debug_assert(exp) assert(exp)\n#else\n#define debug_assert(exp)\
    \ true\n#endif\n\n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \"\
    \ << #x << \" = \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n#line\
    \ 4 \"src/test/verify/aoj-grl-2-a.test.cpp\"\n\n#line 2 \"src/Graph/kruskal.hpp\"\
    \n\n/**\n * @brief Kruskal\n * @docs docs/kruskal.md\n */\n\n#line 2 \"src/Graph/graph-template.hpp\"\
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
    \          }\n            cerr << '\\n';\n        }\n    }\n\n    inline vector<Edge<T>>&\
    \ operator[](const int& k) {\n        return g[k];\n    }\n\n    inline const\
    \ vector<Edge<T>>& operator[](const int& k) const {\n        return g[k];\n  \
    \  }\n};\n\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n#line\
    \ 9 \"src/Graph/kruskal.hpp\"\n\n#line 2 \"src/DataStructure/union-find.hpp\"\n\
    \n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n\nstruct UnionFind\
    \ {\n    vector<int> par;\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     * @param n \u8981\u7D20\u6570\n     * @note \u6642\u9593\u8A08\
    \u7B97\u91CF: O(n)\n     */\n    UnionFind(int n) {\n        par.assign(n, -1);\n\
    \    };\n    /**\n     * @brief \u9802\u70B9x\u306E\u6839\u3092\u6C42\u3081\u308B\
    \n     * @param x \u9802\u70B9\n     * @return int \u6839\u306E\u9802\u70B9\u756A\
    \u53F7\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n\
    \     *       \u03B1(n)\u306F\u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\u95A2\u6570\u306E\
    \u9006\u95A2\u6570\u3067\u3001\u307B\u307CO(1)\u3068\u8003\u3048\u3066\u826F\u3044\
    \n     */\n    int find(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = find(par[x]);\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\
    \u30BA\u3092\u6C42\u3081\u308B\n     * @param x \u9802\u70B9\n     * @return int\
    \ \u96C6\u5408\u306E\u30B5\u30A4\u30BA\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : \u511F\u5374O(\u03B1(n))\n     */\n    int size(int x) {\n        x = find(x);\n\
    \        return -1 * par[x];\n    }\n    /**\n     * @brief \u9802\u70B9x\u3068\
    \u9802\u70B9y\u304C\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\
    \n     * @param x \u9802\u70B9\n     * @param y \u9802\u70B9\n     * @return bool\
    \ \u4F75\u5408\u306B\u6210\u529F\u3057\u305F\u304B\u3069\u3046\u304B\uFF08\u65E2\
    \u306B\u540C\u3058\u96C6\u5408\u306E\u5834\u5408\u306Ffalse\uFF09\n     * @note\
    \ \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     *       \u5C0F\
    \u3055\u3044\u65B9\u306E\u96C6\u5408\u3092\u5927\u304D\u3044\u65B9\u306B\u4F75\
    \u5408\u3059\u308B\uFF08union by size\uFF09\n     */\n    bool unite(int x, int\
    \ y) {\n        x = find(x);\n        y = find(y);\n        if(x == y)\n     \
    \       return false;\n        if(size(x) < size(y))\n            swap(x, y);\n\
    \        par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \    /**\n     * @brief \u9802\u70B9x\u3068\u9802\u70B9y\u304C\u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n     * @param x \u9802\u70B9\n     * @param y \u9802\u70B9\n     * @return\
    \ bool \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u306A\u3089true\n    \
    \ * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     */\n\
    \    bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n  \
    \  /**\n     * @brief \u5404\u96C6\u5408\u306E\u4EE3\u8868\u5143\uFF08\u6839\uFF09\
    \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\n     * @return vector<int>\
    \ \u4EE3\u8868\u5143\u306E\u30EA\u30B9\u30C8\n     * @note \u6642\u9593\u8A08\u7B97\
    \u91CF: O(n)\n     */\n    vector<int> leaders() {\n        vector<int> res;\n\
    \        for(int i = 0; i < (int)par.size(); i++) {\n            if(par[i] < 0)\n\
    \                res.push_back(i);\n        }\n        return res;\n    }\n};\n\
    #line 11 \"src/Graph/kruskal.hpp\"\n\ntemplate <typename T>\npair<T, Edges<T>>\
    \ kruskal(Graph<T> &G) {\n    // \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\u3067 G\
    \ \u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\n    // \u8FD4\u308A\
    \u5024\u306F (cost, vector<Edge>)\n    int N = G.size();\n    UnionFind uf(N);\n\
    \    Edges<T> edges;\n    for(int i = 0; i < N; i++) {\n        for(auto &edge\
    \ : G[i]) {\n            edges.emplace_back(edge);\n        }\n    }\n    auto\
    \ comp = [](const Edge<T> &a, const Edge<T> &b) {\n        return a.cost < b.cost;\n\
    \    };\n    sort(edges.begin(), edges.end(), comp);\n    T cost = (T)0;\n   \
    \ Edges<T> mst;\n    for(auto &edge : edges) {\n        if(uf.unite(edge.from,\
    \ edge.to)) {\n            cost += edge.cost;\n            mst.emplace_back(edge);\n\
    \        }\n    }\n    if(uf.size(0) == N)\n        return pair<T, Edges<T>>(cost,\
    \ mst);\n    else\n        return pair<T, Edges<T>>((T)-1, mst);\n}\n#line 6 \"\
    src/test/verify/aoj-grl-2-a.test.cpp\"\n\nint main() {\n    ll V, E;\n    cin\
    \ >> V >> E;\n    Graph G(V);\n    G.read(E, 0, true, false);\n    auto [cost,\
    \ mst] = kruskal(G);\n    cout << cost << '\\n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../template.hpp\"\n\n#include \"../../Graph/kruskal.hpp\"\n\n\
    int main() {\n    ll V, E;\n    cin >> V >> E;\n    Graph G(V);\n    G.read(E,\
    \ 0, true, false);\n    auto [cost, mst] = kruskal(G);\n    cout << cost << '\\\
    n';\n}"
  dependsOn:
  - src/template.hpp
  - src/Util/debug.hpp
  - src/Graph/kruskal.hpp
  - src/Graph/graph-template.hpp
  - src/DataStructure/union-find.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-grl-2-a.test.cpp
  requiredBy: []
  timestamp: '2025-04-01 15:31:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-grl-2-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-grl-2-a.test.cpp
- /verify/src/test/verify/aoj-grl-2-a.test.cpp.html
title: src/test/verify/aoj-grl-2-a.test.cpp
---
