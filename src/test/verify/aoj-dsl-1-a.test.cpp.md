---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/union-find.hpp
    title: Union-Find
  - icon: ':question:'
    path: src/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
  bundledCode: "#line 1 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\n#line 2 \"src/template.hpp\"\
    \n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n// #pragma GCC\
    \ target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
    unroll-loops\")\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll\
    \ = long long;\nusing ull = unsigned long long;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\nusing\
    \ vp = vector<pl>;\nusing vvp = vector<vp>;\nusing vs = vector<string>;\nusing\
    \ vvs = vector<vs>;\nusing vb = vector<bool>;\nusing vvb = vector<vb>;\nusing\
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
    \    }\n} iosetup;\n#line 3 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n\n#line\
    \ 2 \"src/DataStructure/union-find.hpp\"\n\n/**\n * @brief Union-Find\n * @docs\
    \ docs/union-find.md\n */\n\nstruct UnionFind {\n    vector<int> par;\n    UnionFind(int\
    \ n) {\n        par.assign(n, -1);\n    };\n    int find(int x) {\n        if(par[x]\
    \ < 0)\n            return x;\n        else\n            return par[x] = find(par[x]);\n\
    \    }\n    int size(int x) {\n        x = find(x);\n        return -1 * par[x];\n\
    \    }\n    bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if(x == y)\n            return false;\n        if(size(x) < size(y))\n\
    \            swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n   \
    \     return true;\n    }\n    bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n    vector<int> leaders() {\n        vector<int> res;\n\
    \        for(int i = 0; i < (int)par.size(); i++) {\n            if(par[i] < 0)\n\
    \                res.push_back(i);\n        }\n        return res;\n    }\n};\n\
    #line 5 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    UnionFind uf(n);\n    for(int i = 0; i < q; ++i) {\n\
    \        int com, x, y;\n        cin >> com >> x >> y;\n        if(com == 0)\n\
    \            uf.unite(x, y);\n        else\n            cout << uf.same(x, y)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\n#include\
    \ \"../../template.hpp\"\n\n#include \"../../DataStructure/union-find.hpp\"\n\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n    for(int\
    \ i = 0; i < q; ++i) {\n        int com, x, y;\n        cin >> com >> x >> y;\n\
    \        if(com == 0)\n            uf.unite(x, y);\n        else\n           \
    \ cout << uf.same(x, y) << endl;\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/DataStructure/union-find.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-dsl-1-a.test.cpp
  requiredBy: []
  timestamp: '2025-03-22 12:22:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-dsl-1-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-dsl-1-a.test.cpp
- /verify/src/test/verify/aoj-dsl-1-a.test.cpp.html
title: src/test/verify/aoj-dsl-1-a.test.cpp
---
