---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/template.cpp\"\n#include <bits/stdc++.h>\n#include <atcoder/all>\n\
    \nusing namespace std;\nusing namespace atcoder;\n\n#define _overload3(_1, _2,\
    \ _3, name, ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b)\
    \ for(int i = int(a); i < int(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__,\
    \ repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))\n#define sum(...) accumulate(all(__VA_ARGS__),0LL)\n\
    \ntemplate <class T> auto min(const T& a){ return *min_element(all(a)); }\ntemplate\
    \ <class T> auto max(const T& a){ return *max_element(all(a)); }\ntemplate <class\
    \ T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }\ntemplate\
    \ <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false;\
    \ }\n \nusing i64 = long long;\nusing P = pair<i64, i64>;\n\nint main(){\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n}\n"
  code: "#include <bits/stdc++.h>\n#include <atcoder/all>\n\nusing namespace std;\n\
    using namespace atcoder;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define\
    \ _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a); i < int(b);\
    \ ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n#define uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))\n\
    #define sum(...) accumulate(all(__VA_ARGS__),0LL)\n\ntemplate <class T> auto min(const\
    \ T& a){ return *min_element(all(a)); }\ntemplate <class T> auto max(const T&\
    \ a){ return *max_element(all(a)); }\ntemplate <class T> bool chmin(T& a, const\
    \ T& b) { return a > b ? a = b, true : false; }\ntemplate <class T> bool chmax(T&\
    \ a, const T& b) { return a < b ? a = b, true : false; }\n \nusing i64 = long\
    \ long;\nusing P = pair<i64, i64>;\n\nint main(){\n    cin.tie(nullptr);\n   \
    \ ios::sync_with_stdio(false);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/template.cpp
  requiredBy: []
  timestamp: '2022-09-02 20:16:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/template.cpp
layout: document
redirect_from:
- /library/src/template.cpp
- /library/src/template.cpp.html
title: src/template.cpp
---
