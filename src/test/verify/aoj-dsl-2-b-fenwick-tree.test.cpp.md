---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/fenwick-tree.hpp
    title: Fenwick Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#line 2 \"src/template.hpp\"\
    \n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template.md\n\
    \ */\n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\n\
    using vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\nusing vp = vector<pl>;\n\
    using vvp = vector<vp>;\nusing vs = vector<string>;\nusing vvs = vector<vs>;\n\
    using vb = vector<bool>;\nusing vvb = vector<vb>;\nusing vvvb = vector<vvb>;\n\
    using vd = vector<double>;\nusing vvd = vector<vd>;\nusing vvvd = vector<vvd>;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for(ll i = ll(a); i < ll(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x),\
    \ std::end(x)\n#define make_unique(v) v.erase(unique(all(v)), v.end());\n\nconstexpr\
    \ ll inf = 0x1fffffffffffffffLL; // 2.3 * 10^18\n\ntemplate <class T, class U>\n\
    istream &operator>>(istream &is, pair<T, U> &p) {\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return os;\n\
    }\n\ntemplate <class T1, class T2>\nvoid input(vector<T1> &v1, vector<T2> &v2)\
    \ {\n    rep(i, v1.size()) cin >> v1[i] >> v2[i];\n}\ntemplate <class T1, class\
    \ T2, class T3>\nvoid input(vector<T1> &v1, vector<T2> &v2, vector<T3> &v3) {\n\
    \    rep(i, v1.size()) cin >> v1[i] >> v2[i] >> v3[i];\n}\ntemplate <class T1,\
    \ class T2, class T3, class T4>\nvoid input(vector<T1> &v1, vector<T2> &v2, vector<T3>\
    \ &v3, vector<T4> &v4) {\n    rep(i, v1.size()) cin >> v1[i] >> v2[i] >> v3[i]\
    \ >> v4[i];\n}\n\ntemplate <class T>\nistream &operator>>(istream &is, vector<T>\
    \ &v) {\n    for(auto &x : v) {\n        is >> x;\n    }\n    return is;\n}\n\n\
    template <class T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n \
    \   for(int i = 0; i < (int)v.size(); i++) {\n        if(i != (int)v.size() -\
    \ 1)\n            os << v[i] << \" \";\n        else\n            os << v[i];\n\
    \    }\n    return os;\n}\n\ntemplate <typename T, typename... Args>\nauto vec(T\
    \ x, int arg, Args... args) {\n    if constexpr(sizeof...(args) == 0)\n      \
    \  return vector<T>(arg, x);\n    else\n        return vector(arg, vec<T>(x, args...));\n\
    }\n\ntemplate <class T>\nbool chmin(T &a, const T &b) {\n    return a > b ? a\
    \ = b, true : false;\n}\ntemplate <class T>\nbool chmax(T &a, const T &b) {\n\
    \    return a < b ? a = b, true : false;\n}\n\nconstexpr ll bit(ll x) {\n    return\
    \ 1LL << x;\n}\nconstexpr ll msk(ll x) {\n    return (1LL << x) - 1;\n}\nconstexpr\
    \ bool stand(ll x, int i) {\n    return x & bit(i);\n}\n\nstruct IoSetup {\n \
    \   IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n#line 3 \"src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp\"\
    \n\n#line 2 \"src/DataStructure/fenwick-tree.hpp\"\n\n/**\n * @brief Fenwick Tree\n\
    \ * @docs docs/fenwick-tree.md\n */\n\ntemplate <typename T = long long int>\n\
    struct FenwickTree {\n    int n;\n    vector<T> bit;\n    FenwickTree(int n)\n\
    \        : n(n) {\n        bit.assign(n + 1, T(0));\n    }\n    FenwickTree(const\
    \ vector<T> &a) {\n        n = (int)a.size();\n        bit.assign(n + 1, T(0));\n\
    \        for(int i = 0; i < n; ++i) {\n            apply(i, a[i]);\n        }\n\
    \    }\n    void apply(int idx, T x) {\n        ++idx;\n        while(idx <= n)\
    \ {\n            bit[idx] += x;\n            idx += idx & -idx;\n        }\n \
    \   }\n    void set(int idx, T x) {\n        T pre = prod(idx, idx + 1);\n   \
    \     apply(idx, x - pre);\n    }\n    T prod(int r) {\n        T ret = T(0);\n\
    \        ++r;\n        while(r > 0) {\n            ret += bit[r];\n          \
    \  r -= r & -r;\n        }\n        return ret;\n    }\n    T prod(int l, int\
    \ r) {\n        if(l == 0)\n            return prod(r - 1);\n        else\n  \
    \          return prod(r - 1) - prod(l - 1);\n    }\n};\n#line 5 \"src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp\"\
    \n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n    FenwickTree bit(n);\n\
    \    rep(i, q) {\n        ll com, x, y;\n        cin >> com >> x >> y;\n     \
    \   if(com == 0) bit.apply(x - 1, y);\n        if(com == 1) cout << bit.prod(x\
    \ - 1, y) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#include\
    \ \"../../template.hpp\"\n\n#include \"../../DataStructure/fenwick-tree.hpp\"\n\
    \nint main() {\n    ll n, q;\n    cin >> n >> q;\n    FenwickTree bit(n);\n  \
    \  rep(i, q) {\n        ll com, x, y;\n        cin >> com >> x >> y;\n       \
    \ if(com == 0) bit.apply(x - 1, y);\n        if(com == 1) cout << bit.prod(x -\
    \ 1, y) << endl;\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/DataStructure/fenwick-tree.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
  requiredBy: []
  timestamp: '2024-04-06 12:47:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
- /verify/src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp.html
title: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
---
