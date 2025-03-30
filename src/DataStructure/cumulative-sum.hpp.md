---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Util/debug.hpp
    title: Debug
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-static-range-sum.test.cpp
    title: src/test/verify/yosupo-static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/cumulative-sum.hpp\"\n\n/**\n * @brief\
    \ \u7D2F\u7A4D\u548C\n */\n\n#include <vector>\n#include <cassert>\n#include <concepts>\n\
    #line 2 \"src/Util/debug.hpp\"\n\n/**\n * @brief Debug\n */\n\n#ifdef LOCAL\n\
    #define debug_assert(exp) assert(exp)\n#else\n#define debug_assert(exp) true\n\
    #endif\n\n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \" << #x\
    \ << \" = \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n#line 11\
    \ \"src/DataStructure/cumulative-sum.hpp\"\n\ntemplate <std::integral T>\nstruct\
    \ CumulativeSum {\n  private:\n    bool built = false;\n\n  public:\n    int n;\n\
    \    std::vector<T> data;\n\n    CumulativeSum(int n)\n        : n(n), data(n\
    \ + 1, T()) {}\n    CumulativeSum(const std::vector<T> &a)\n        : n((int)a.size()),\
    \ data(n + 1, T()) {\n        for(int i = 0; i < n; i++)\n            add(i, a[i]);\n\
    \        build();\n    }\n\n    void build() {\n        debug_assert(!built);\n\
    \        for(int i = 0; i < n; i++) {\n            data[i + 1] = data[i] + data[i\
    \ + 1];\n        }\n        built = true;\n    }\n\n    void add(int idx, T x)\
    \ {\n        debug_assert(!built);\n        data[idx + 1] += x;\n    }\n\n   \
    \ T sum(int l, int r) {\n        debug_assert(built);\n        return data[r]\
    \ - data[l];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u7D2F\u7A4D\u548C\n */\n\n#include <vector>\n\
    #include <cassert>\n#include <concepts>\n#include \"../Util/debug.hpp\"\n\ntemplate\
    \ <std::integral T>\nstruct CumulativeSum {\n  private:\n    bool built = false;\n\
    \n  public:\n    int n;\n    std::vector<T> data;\n\n    CumulativeSum(int n)\n\
    \        : n(n), data(n + 1, T()) {}\n    CumulativeSum(const std::vector<T> &a)\n\
    \        : n((int)a.size()), data(n + 1, T()) {\n        for(int i = 0; i < n;\
    \ i++)\n            add(i, a[i]);\n        build();\n    }\n\n    void build()\
    \ {\n        debug_assert(!built);\n        for(int i = 0; i < n; i++) {\n   \
    \         data[i + 1] = data[i] + data[i + 1];\n        }\n        built = true;\n\
    \    }\n\n    void add(int idx, T x) {\n        debug_assert(!built);\n      \
    \  data[idx + 1] += x;\n    }\n\n    T sum(int l, int r) {\n        debug_assert(built);\n\
    \        return data[r] - data[l];\n    }\n};"
  dependsOn:
  - src/Util/debug.hpp
  isVerificationFile: false
  path: src/DataStructure/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2025-03-30 10:43:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/yosupo-static-range-sum.test.cpp
documentation_of: src/DataStructure/cumulative-sum.hpp
layout: document
redirect_from:
- /library/src/DataStructure/cumulative-sum.hpp
- /library/src/DataStructure/cumulative-sum.hpp.html
title: "\u7D2F\u7A4D\u548C"
---
