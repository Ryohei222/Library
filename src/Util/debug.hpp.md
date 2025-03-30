---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/abstract-cumulative-sum.hpp
    title: "\u62BD\u8C61\u5316\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/cumulative-sum.hpp
    title: "\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    path: src/test/verify/aoj-grl-5-a.test.cpp
    title: src/test/verify/aoj-grl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-grl-6-a.test.cpp
    title: src/test/verify/aoj-grl-6-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-lca.test.cpp
    title: src/test/verify/yosupo-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
    title: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-static-range-sum.test.cpp
    title: src/test/verify/yosupo-static-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: src/test/verify/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yuki-697.test.cpp
    title: src/test/verify/yuki-697.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Debug
    links: []
  bundledCode: "#line 2 \"src/Util/debug.hpp\"\n\n/**\n * @brief Debug\n */\n\n#ifdef\
    \ LOCAL\n#define debug_assert(exp) assert(exp)\n#else\n#define debug_assert(exp)\
    \ true\n#endif\n\n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \"\
    \ << #x << \" = \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n"
  code: "#pragma once\n\n/**\n * @brief Debug\n */\n\n#ifdef LOCAL\n#define debug_assert(exp)\
    \ assert(exp)\n#else\n#define debug_assert(exp) true\n#endif\n\n#ifdef LOCAL\n\
    #define dbg(x) std::cerr << __LINE__ << \" : \" << #x << \" = \" << (x) << std::endl\n\
    #else\n#define dbg(x) true\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: src/Util/debug.hpp
  requiredBy:
  - src/template.hpp
  - src/DataStructure/cumulative-sum.hpp
  - src/DataStructure/abstract-cumulative-sum.hpp
  timestamp: '2025-03-30 10:12:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
  - src/test/verify/yosupo-static-range-sum-abstract.test.cpp
  - src/test/verify/aoj-grl-1-a.test.cpp
  - src/test/verify/aoj-dsl-2-b-fenwick-tree.test.cpp
  - src/test/verify/aoj-grl-2-a2.test.cpp
  - src/test/verify/yuki-697.test.cpp
documentation_of: src/Util/debug.hpp
layout: document
redirect_from:
- /library/src/Util/debug.hpp
- /library/src/Util/debug.hpp.html
title: Debug
---
