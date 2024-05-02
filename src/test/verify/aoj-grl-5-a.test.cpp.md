---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/diameter.hpp
    title: Tree-Diameter
  - icon: ':question:'
    path: src/Graph/graph-template.hpp
    title: Graph Template
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"src/test/verify/aoj-grl-5-a.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\n#line\
    \ 2 \"src/template.hpp\"\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @docs docs/template.md\n */\n\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using vl = vector<ll>;\nusing vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing\
    \ pl = pair<ll, ll>;\nusing vp = vector<pl>;\nusing vvp = vector<vp>;\nusing vs\
    \ = vector<string>;\nusing vvs = vector<vs>;\nusing vb = vector<bool>;\nusing\
    \ vvb = vector<vb>;\nusing vvvb = vector<vvb>;\nusing vd = vector<double>;\nusing\
    \ vvd = vector<vd>;\nusing vvvd = vector<vvd>;\n\n#define _overload3(_1, _2, _3,\
    \ name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(ll\
    \ i = ll(a); i < ll(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep,\
    \ )(__VA_ARGS__)\n#define all(x) std::begin(x), std::end(x)\n#define make_unique(v)\
    \ v.erase(unique(all(v)), v.end());\n\nconstexpr ll inf = 0x1fffffffffffffffLL;\
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
    \    }\n} iosetup;\n#line 3 \"src/test/verify/aoj-grl-5-a.test.cpp\"\n\n#line\
    \ 2 \"src/Graph/diameter.hpp\"\n\n/**\n * @brief Tree-Diameter\n * @docs docs/diameter.md\n\
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
    \ 9 \"src/Graph/diameter.hpp\"\n\ntemplate <typename T = int>\ntuple<T, int, int>\
    \ diameter(Graph<T> &G) {\n    auto dfs = [&](auto &self, int v, int p) -> pair<T,\
    \ int> {\n        pair<T, int> ret(0, v);\n        for(auto &e : G[v]) {\n   \
    \         if(e.to == p) continue;\n            auto result = self(self, e.to,\
    \ v);\n            result.first += e.cost;\n            if(ret.first < result.first)\
    \ {\n                ret = result;\n            }\n        }\n        return ret;\n\
    \    };\n    auto [_, v1] = dfs(dfs, 0, -1);\n    auto [d, v2] = dfs(dfs, v1,\
    \ -1);\n    return tuple<T, int, int>(d, v1, v2);\n}\n#line 5 \"src/test/verify/aoj-grl-5-a.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    Graph T(n);\n    T.read(n - 1,\
    \ 0, true);\n    auto [d, v1, v2] = diameter(T);\n    cout << d << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include \"../../template.hpp\"\n\n#include \"../../Graph/diameter.hpp\"\n\n\
    int main() {\n    int n;\n    cin >> n;\n    Graph T(n);\n    T.read(n - 1, 0,\
    \ true);\n    auto [d, v1, v2] = diameter(T);\n    cout << d << endl;\n}"
  dependsOn:
  - src/template.hpp
  - src/Graph/diameter.hpp
  - src/Graph/graph-template.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-grl-5-a.test.cpp
  requiredBy: []
  timestamp: '2024-05-02 19:48:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/test/verify/aoj-grl-5-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-grl-5-a.test.cpp
- /verify/src/test/verify/aoj-grl-5-a.test.cpp.html
title: src/test/verify/aoj-grl-5-a.test.cpp
---
