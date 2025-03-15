---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-alds-1-14-b.test.cpp
    title: src/test/verify/aoj-alds-1-14-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-1-a.test.cpp
    title: src/test/verify/aoj-dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
    title: src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
    title: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  - icon: ':x:'
    path: src/test/verify/aoj-grl-1-a.test.cpp
    title: src/test/verify/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-2-a.test.cpp
    title: src/test/verify/aoj-grl-2-a.test.cpp
  - icon: ':x:'
    path: src/test/verify/aoj-grl-2-a2.test.cpp
    title: src/test/verify/aoj-grl-2-a2.test.cpp
  - icon: ':x:'
    path: src/test/verify/aoj-grl-3-c.test.cpp
    title: src/test/verify/aoj-grl-3-c.test.cpp
  - icon: ':x:'
    path: src/test/verify/aoj-grl-5-a.test.cpp
    title: src/test/verify/aoj-grl-5-a.test.cpp
  - icon: ':x:'
    path: src/test/verify/aoj-grl-6-a.test.cpp
    title: src/test/verify/aoj-grl-6-a.test.cpp
  - icon: ':x:'
    path: src/test/verify/yosupo-lca.test.cpp
    title: src/test/verify/yosupo-lca.test.cpp
  - icon: ':x:'
    path: src/test/verify/yosupo-static-range-sum.test.cpp
    title: src/test/verify/yosupo-static-range-sum.test.cpp
  - icon: ':x:'
    path: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':x:'
    path: src/test/verify/yuki-697.test.cpp
    title: src/test/verify/yuki-697.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/template.md
    document_title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n * @docs docs/template.md\n */\n\n// #pragma GCC target(\"avx2\"\
    )\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\n\
    using vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\nusing vp = vector<pl>;\n\
    using vvp = vector<vp>;\nusing vs = vector<string>;\nusing vvs = vector<vs>;\n\
    using vb = vector<bool>;\nusing vvb = vector<vb>;\nusing vvvb = vector<vvb>;\n\
    using vd = vector<double>;\nusing vvd = vector<vd>;\nusing vvvd = vector<vvd>;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for(ll i = ll(a); i < ll(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x),\
    \ std::end(x)\n\nconstexpr ll inf = 0x1fffffffffffffffLL; // 2.3 * 10^18\n\ntemplate\
    \ <class T, class U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class T, class U>\n\
    ostream &operator<<(ostream &os, pair<T, U> &p) {\n    os << p.first << \" \"\
    \ << p.second;\n    return os;\n}\n\ntemplate <class T>\nistream &operator>>(istream\
    \ &is, vector<T> &v) {\n    for(auto &x : v) {\n        is >> x;\n    }\n    return\
    \ is;\n}\n\ntemplate <class T>\nostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n    for(int i = 0; i < (int)v.size(); i++) {\n        if(i != (int)v.size()\
    \ - 1)\n            os << v[i] << \" \";\n        else\n            os << v[i];\n\
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
    \    }\n} iosetup;\n"
  code: "#pragma once\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs\
    \ docs/template.md\n */\n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using vl = vector<ll>;\nusing vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing\
    \ pl = pair<ll, ll>;\nusing vp = vector<pl>;\nusing vvp = vector<vp>;\nusing vs\
    \ = vector<string>;\nusing vvs = vector<vs>;\nusing vb = vector<bool>;\nusing\
    \ vvb = vector<vb>;\nusing vvvb = vector<vvb>;\nusing vd = vector<double>;\nusing\
    \ vvd = vector<vd>;\nusing vvvd = vector<vvd>;\n\n#define _overload3(_1, _2, _3,\
    \ name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(ll\
    \ i = ll(a); i < ll(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep,\
    \ )(__VA_ARGS__)\n#define all(x) std::begin(x), std::end(x)\n\nconstexpr ll inf\
    \ = 0x1fffffffffffffffLL; // 2.3 * 10^18\n\ntemplate <class T, class U>\nistream\
    \ &operator>>(istream &is, pair<T, U> &p) {\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return os;\n\
    }\n\ntemplate <class T>\nistream &operator>>(istream &is, vector<T> &v) {\n  \
    \  for(auto &x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n    for(int\
    \ i = 0; i < (int)v.size(); i++) {\n        if(i != (int)v.size() - 1)\n     \
    \       os << v[i] << \" \";\n        else\n            os << v[i];\n    }\n \
    \   return os;\n}\n\ntemplate <typename T, typename... Args>\nauto vec(T x, int\
    \ arg, Args... args) {\n    if constexpr(sizeof...(args) == 0)\n        return\
    \ vector<T>(arg, x);\n    else\n        return vector(arg, vec<T>(x, args...));\n\
    }\n\ntemplate <class T>\nbool chmin(T &a, const T &b) {\n    return a > b ? a\
    \ = b, true : false;\n}\ntemplate <class T>\nbool chmax(T &a, const T &b) {\n\
    \    return a < b ? a = b, true : false;\n}\n\nconstexpr ll bit(ll x) {\n    return\
    \ 1LL << x;\n}\nconstexpr ll msk(ll x) {\n    return (1LL << x) - 1;\n}\nconstexpr\
    \ bool stand(ll x, int i) {\n    return x & bit(i);\n}\n\nstruct IoSetup {\n \
    \   IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;"
  dependsOn: []
  isVerificationFile: false
  path: src/template.hpp
  requiredBy: []
  timestamp: '2025-01-16 14:57:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - src/test/verify/aoj-grl-3-c.test.cpp
  - src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  - src/test/verify/aoj-grl-2-a.test.cpp
  - src/test/verify/aoj-grl-5-a.test.cpp
  - src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  - src/test/verify/aoj-grl-6-a.test.cpp
  - src/test/verify/aoj-alds-1-14-b.test.cpp
  - src/test/verify/yosupo-lca.test.cpp
  - src/test/verify/yosupo-static-range-sum.test.cpp
  - src/test/verify/aoj-dsl-1-a.test.cpp
  - src/test/verify/aoj-grl-1-a.test.cpp
  - src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
  - src/test/verify/aoj-grl-2-a2.test.cpp
  - src/test/verify/yuki-697.test.cpp
documentation_of: src/template.hpp
layout: document
redirect_from:
- /library/src/template.hpp
- /library/src/template.hpp.html
title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
