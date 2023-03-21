---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-1-a.test.cpp
    title: src/test/verify/aoj-grl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing i64 = long long;\n\nstruct IoSetup {\n    IoSetup() {\n      \
    \  cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout << fixed\
    \ << setprecision(10);\n        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x),\
    \ std::end(x)\n#define uniq(a)   \\\n    sort(all(a)); \\\n    a.erase(unique(all(a)),\
    \ end(a))\n#define sum(...) accumulate(all(__VA_ARGS__), 0LL)\n\ntemplate <class\
    \ T>\nauto min(const T& a) {\n    return *min_element(all(a));\n}\ntemplate <class\
    \ T>\nauto max(const T& a) {\n    return *max_element(all(a));\n}\ntemplate <class\
    \ T>\nbool chmin(T& a, const T& b) {\n    return a > b ? a = b, true : false;\n\
    }\ntemplate <class T>\nbool chmax(T& a, const T& b) {\n    return a < b ? a =\
    \ b, true : false;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing i64 = long long;\n\
    \nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define\
    \ _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a); i < int(b);\
    \ ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n#define uniq(a)   \\\n    sort(all(a));\
    \ \\\n    a.erase(unique(all(a)), end(a))\n#define sum(...) accumulate(all(__VA_ARGS__),\
    \ 0LL)\n\ntemplate <class T>\nauto min(const T& a) {\n    return *min_element(all(a));\n\
    }\ntemplate <class T>\nauto max(const T& a) {\n    return *max_element(all(a));\n\
    }\ntemplate <class T>\nbool chmin(T& a, const T& b) {\n    return a > b ? a =\
    \ b, true : false;\n}\ntemplate <class T>\nbool chmax(T& a, const T& b) {\n  \
    \  return a < b ? a = b, true : false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/template.hpp
  requiredBy: []
  timestamp: '2023-03-21 22:14:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-grl-1-a.test.cpp
documentation_of: src/template.hpp
layout: document
redirect_from:
- /library/src/template.hpp
- /library/src/template.hpp.html
title: src/template.hpp
---
