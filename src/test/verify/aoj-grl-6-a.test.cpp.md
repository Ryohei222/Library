---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Flow/ford-fulkerson.hpp
    title: Ford-Fulkerson
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"src/test/verify/aoj-grl-6-a.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n#line 2 \"src/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pl = pair<ll, ll>;\n#define vl vector<ll>\n#define vvl vector<vector<ll>>\n\
    #define vvvl vector<vector<vector<ll>>>\n#define vm vector<mint>\n#define vvm\
    \ vector<vector<mint>>\n#define vvvm vector<vector<vector<mint>>>\n#define vp\
    \ vector<pl>\n#define vvp vector<vector<pl>>\n#define vs vector<string>\n#define\
    \ vvs vector<vector<string>>\n\n#define _overload3(_1, _2, _3, name, ...) name\n\
    #define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a); i\
    \ < int(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n#define make_unique(v) v.erase(unique(all(v)),\
    \ v.end());\n#define sum(...) accumulate(all(__VA_ARGS__), 0LL)\n#define inf (0x1fffffffffffffff)\n\
    \ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for(auto&\
    \ x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\n\
    ostream& operator<<(ostream& os, const vector<T>& v) {\n    for(int i = 0; i <\
    \ (int)v.size(); i++) {\n        if(i != (int)v.size() - 1)\n            os <<\
    \ v[i] << \" \";\n        else\n            os << v[i];\n    }\n    return os;\n\
    }\n\ntemplate <typename T, typename... Args>\nauto make_v(T x, int arg, Args...\
    \ args) {\n    if constexpr(sizeof...(args) == 0)\n        return vector<T>(arg,\
    \ x);\n    else\n        return vector(arg, make_v<T>(x, args...));\n}\n\ntemplate\
    \ <class T>\nauto min(const T& a) {\n    return *min_element(all(a));\n}\n\ntemplate\
    \ <class T>\nauto max(const T& a) {\n    return *max_element(all(a));\n}\n\ntemplate\
    \ <class T>\nbool chmin(T& a, const T& b) {\n    return a > b ? a = b, true :\
    \ false;\n}\n\ntemplate <class T>\nbool chmax(T& a, const T& b) {\n    return\
    \ a < b ? a = b, true : false;\n}\n\nstruct IoSetup {\n    IoSetup() {\n     \
    \   cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout << fixed\
    \ << setprecision(10);\n        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n\
    #line 2 \"src/Flow/ford-fulkerson.hpp\"\n\n/**\n * @brief Ford-Fulkerson\n * @docs\
    \ docs/ford-fulkerson.md\n */\n\ntemplate <typename T>\nstruct FordFulkerson {\n\
    \    struct Edge {\n        int to, rev_idx;\n        T cap;\n    };\n    int\
    \ N;\n    vector<vector<Edge>> G;\n    vector<bool> vis;\n\n    FordFulkerson(int\
    \ N)\n      : N(N), G(N), vis(N) {}\n\n    void add_edge(int from, int to, T cap)\
    \ {\n        G[from].emplace_back((Edge){to, (int)G[to].size(), cap}); // e.from\
    \ = G[e.to][e.rev_idx].to;\n        G[to].emplace_back((Edge){from, (int)G[from].size()\
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
    \       }\n    }\n\n    void debug() {\n        cerr << \"---------\" << endl;\n\
    \        for(int i = 0; i < N; i++) {\n            for(auto &e : G[i]) {\n   \
    \             if(e.to < i) continue;\n                cerr << i << \" -> \" <<\
    \ e.to << \": \" << G[e.to][e.rev_idx].cap << endl;\n            }\n        }\n\
    \    }\n};\n#line 4 \"src/test/verify/aoj-grl-6-a.test.cpp\"\n\nint main() {\n\
    \    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> flow(V);\n    rep(i,\
    \ E) {\n        ll u, v, c;\n        cin >> u >> v >> c;\n        flow.add_edge(u,\
    \ v, c);\n    }\n    cout << flow.max_flow(0, V - 1) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n#include\
    \ \"../../template.hpp\"\n#include \"../../Flow/ford-fulkerson.hpp\"\n\nint main()\
    \ {\n    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> flow(V);\n    rep(i,\
    \ E) {\n        ll u, v, c;\n        cin >> u >> v >> c;\n        flow.add_edge(u,\
    \ v, c);\n    }\n    cout << flow.max_flow(0, V - 1) << endl;\n}"
  dependsOn:
  - src/template.hpp
  - src/Flow/ford-fulkerson.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-grl-6-a.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 19:51:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-grl-6-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-grl-6-a.test.cpp
- /verify/src/test/verify/aoj-grl-6-a.test.cpp.html
title: src/test/verify/aoj-grl-6-a.test.cpp
---
