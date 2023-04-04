---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/DataStructure/union-find.hpp
    title: Union-Find
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/aoj-dsl-1-a.test.cpp
    title: src/test/verify/aoj-dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-1-a.test.cpp
    title: src/test/verify/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-3-c.test.cpp
    title: src/test/verify/aoj-grl-3-c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nusing i64 = long long;\n\nstruct IoSetup {\n    IoSetup()\
    \ {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n       \
    \ cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define\
    \ _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a); i < int(b);\
    \ ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n#define uniq(a)   \\\n    sort(all(a));\
    \ \\\n    a.erase(unique(all(a)), end(a))\n#define sum(...) accumulate(all(__VA_ARGS__),\
    \ 0LL)\n\ntemplate <class T>\nauto min(const T& a) {\n    return *min_element(all(a));\n\
    }\ntemplate <class T>\nauto max(const T& a) {\n    return *max_element(all(a));\n\
    }\ntemplate <class T>\nbool chmin(T& a, const T& b) {\n    return a > b ? a =\
    \ b, true : false;\n}\ntemplate <class T>\nbool chmax(T& a, const T& b) {\n  \
    \  return a < b ? a = b, true : false;\n}\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing\
    \ i64 = long long;\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(10);\n\
    \        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n\n#define _overload3(_1,\
    \ _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a,\
    \ b) for(int i = int(a); i < int(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__,\
    \ repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ uniq(a)   \\\n    sort(all(a)); \\\n    a.erase(unique(all(a)), end(a))\n#define\
    \ sum(...) accumulate(all(__VA_ARGS__), 0LL)\n\ntemplate <class T>\nauto min(const\
    \ T& a) {\n    return *min_element(all(a));\n}\ntemplate <class T>\nauto max(const\
    \ T& a) {\n    return *max_element(all(a));\n}\ntemplate <class T>\nbool chmin(T&\
    \ a, const T& b) {\n    return a > b ? a = b, true : false;\n}\ntemplate <class\
    \ T>\nbool chmax(T& a, const T& b) {\n    return a < b ? a = b, true : false;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/template.hpp
  requiredBy:
  - src/DataStructure/union-find.hpp
  timestamp: '2023-04-04 12:45:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - src/test/verify/aoj-grl-3-c.test.cpp
  - src/test/verify/aoj-grl-1-a.test.cpp
  - src/test/verify/aoj-dsl-1-a.test.cpp
documentation_of: src/template.hpp
layout: document
redirect_from:
- /library/src/template.hpp
- /library/src/template.hpp.html
title: src/template.hpp
---
