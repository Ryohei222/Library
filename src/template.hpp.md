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
    path: src/test/verify/aoj-dsl-2-b.test.cpp
    title: src/test/verify/aoj-dsl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-1-a.test.cpp
    title: src/test/verify/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-2-a.test.cpp
    title: src/test/verify/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-2-a2.test.cpp
    title: src/test/verify/aoj-grl-2-a2.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-3-c.test.cpp
    title: src/test/verify/aoj-grl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-6-a.test.cpp
    title: src/test/verify/aoj-grl-6-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-lca.test.cpp
    title: src/test/verify/yosupo-lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/template.md
    document_title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n * @docs docs/template.md\n */\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing pl = pair<ll, ll>;\n#define vl\
    \ vector<ll>\n#define vvl vector<vector<ll>>\n#define vvvl vector<vector<vector<ll>>>\n\
    #define vm vector<mint>\n#define vvm vector<vector<mint>>\n#define vvvm vector<vector<vector<mint>>>\n\
    #define vp vector<pl>\n#define vvp vector<vector<pl>>\n#define vs vector<string>\n\
    #define vvs vector<vector<string>>\n\n#define _overload3(_1, _2, _3, name, ...)\
    \ name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a);\
    \ i < int(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
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
    \ << setprecision(10);\n        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n"
  code: "#pragma once\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs\
    \ docs/template.md\n */\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing pl = pair<ll, ll>;\n#define vl vector<ll>\n#define\
    \ vvl vector<vector<ll>>\n#define vvvl vector<vector<vector<ll>>>\n#define vm\
    \ vector<mint>\n#define vvm vector<vector<mint>>\n#define vvvm vector<vector<vector<mint>>>\n\
    #define vp vector<pl>\n#define vvp vector<vector<pl>>\n#define vs vector<string>\n\
    #define vvs vector<vector<string>>\n\n#define _overload3(_1, _2, _3, name, ...)\
    \ name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a);\
    \ i < int(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
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
    \ << setprecision(10);\n        cerr << fixed << setprecision(10);\n    }\n} iosetup;"
  dependsOn: []
  isVerificationFile: false
  path: src/template.hpp
  requiredBy: []
  timestamp: '2023-11-02 05:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-alds-1-14-b.test.cpp
  - src/test/verify/aoj-dsl-2-b.test.cpp
  - src/test/verify/aoj-grl-1-a.test.cpp
  - src/test/verify/aoj-grl-3-c.test.cpp
  - src/test/verify/aoj-grl-2-a.test.cpp
  - src/test/verify/aoj-dsl-1-a.test.cpp
  - src/test/verify/yosupo-lca.test.cpp
  - src/test/verify/aoj-grl-2-a2.test.cpp
  - src/test/verify/aoj-grl-6-a.test.cpp
documentation_of: src/template.hpp
layout: document
redirect_from:
- /library/src/template.hpp
- /library/src/template.hpp.html
title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
