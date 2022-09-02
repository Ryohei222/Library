---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Graph/lca.cpp
    title: src/Graph/lca.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/graph-template.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<typename T>\nstruct Edge{\n   \
    \ int to, int from;\n    T cost;\n    Edge(int to) : to(to) {}\n    Edge(int to,\
    \ T cost) : to(to), cost(cost) {}\n    Edge(int from, int to, T cost) : from(from),\
    \ to(to), cost(cost) {}\n};\n\ntemplate<typename T>\nusing Graph = vector<vector<Edge<T>>>;\n"
  code: "#include <iostream>\n#include <vector>\n\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct Edge{\n    int to, int from;\n    T cost;\n    Edge(int to) : to(to)\
    \ {}\n    Edge(int to, T cost) : to(to), cost(cost) {}\n    Edge(int from, int\
    \ to, T cost) : from(from), to(to), cost(cost) {}\n};\n\ntemplate<typename T>\n\
    using Graph = vector<vector<Edge<T>>>;"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/graph-template.cpp
  requiredBy:
  - src/Graph/lca.cpp
  timestamp: '2022-09-02 20:16:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/graph-template.cpp
layout: document
redirect_from:
- /library/src/Graph/graph-template.cpp
- /library/src/Graph/graph-template.cpp.html
title: src/Graph/graph-template.cpp
---
