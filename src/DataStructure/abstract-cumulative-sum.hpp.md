---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/algebraic-structure.hpp
    title: src/Math/algebraic-structure.hpp
  - icon: ':heavy_check_mark:'
    path: src/Util/debug.hpp
    title: Debug
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
    title: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u62BD\u8C61\u5316\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/abstract-cumulative-sum.hpp\"\n\n/**\n\
    \ * @brief \u62BD\u8C61\u5316\u7D2F\u7A4D\u548C\n */\n\n#include <vector>\n#include\
    \ <cassert>\n#include <concepts>\n#line 2 \"src/Util/debug.hpp\"\n\n/**\n * @brief\
    \ Debug\n */\n\n#ifdef LOCAL\n#define debug_assert(exp) assert(exp)\n#else\n#define\
    \ debug_assert(exp) true\n#endif\n\n#ifdef LOCAL\n#define dbg(x) std::cerr <<\
    \ __LINE__ << \" : \" << #x << \" = \" << (x) << std::endl\n#else\n#define dbg(x)\
    \ true\n#endif\n#line 2 \"src/Math/algebraic-structure.hpp\"\n\n#include <numeric>\n\
    #line 5 \"src/Math/algebraic-structure.hpp\"\n\ntemplate <typename T>\nconcept\
    \ HasInnerType = requires() {\n    typename T::S;\n};\n\ntemplate <typename T>\n\
    concept HasIdentity = requires() {\n    { T::e() } -> std::same_as<typename T::S>;\n\
    };\n\ntemplate <typename T>\nconcept HasInverse = requires() {\n    { T::inv(std::declval<typename\
    \ T::S>()) } -> std::same_as<typename T::S>;\n};\n\ntemplate <typename T>\nconcept\
    \ HasBinaryOperation = requires() {\n    { T::op(std::declval<typename T::S>(),\
    \ std::declval<typename T::S>()) } -> std::same_as<typename T::S>;\n};\n\ntemplate\
    \ <class T>\nconcept MonoidConcept = HasInnerType<T> && HasIdentity<T> && HasBinaryOperation<T>;\n\
    \ntemplate <class T>\nconcept GroupConcept = MonoidConcept<T> && HasInverse<T>;\n\
    \ntemplate <std::integral T>\nstruct MinMonoid {\n    using S = T;\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::max(); }\n    static constexpr\
    \ S op(const S &a, const S &b) { return std::min(a, b); }\n};\n\ntemplate <std::integral\
    \ T>\nstruct MaxMonoid {\n    using S = T;\n    static constexpr S e() { return\
    \ std::numeric_limits<S>::min(); }\n    static constexpr S op(const S &a, const\
    \ S &b) { return std::max(a, b); }\n};\n\ntemplate <typename T>\nstruct MultiplicativeMonoid\
    \ {\n    using S = T;\n    static constexpr S e() { return S(1); }\n    static\
    \ constexpr S op(const S &a, const S &b) { return a * b; }\n};\n\ntemplate <typename\
    \ T>\nstruct AdditiveGroup {\n    using S = T;\n    static constexpr S e() { return\
    \ S(); }\n    static constexpr S op(const S &a, const S &b) { return a + b; }\n\
    \    static constexpr S inv(const S &a) { return -a; }\n};\n\ntemplate <typename\
    \ T>\nstruct XORGroup {\n    using S = T;\n    static constexpr S e() { return\
    \ S(); }\n    static constexpr S op(const S &a, const S &b) { return a ^ b; }\n\
    \    static constexpr S inv(const S &a) { return a; }\n};\n#line 12 \"src/DataStructure/abstract-cumulative-sum.hpp\"\
    \n\ntemplate <GroupConcept T>\nstruct AbstructCumulativeSum {\n  private:\n  \
    \  bool built = false;\n\n  public:\n    using S = typename T::S;\n    int n;\n\
    \    std::vector<S> data;\n    AbstructCumulativeSum(int n)\n        : n(n), data(n\
    \ + 1, T::e()) {}\n    AbstructCumulativeSum(const std::vector<S> &a)\n      \
    \  : n((int)a.size()), data(n + 1, T::e()) {\n        for(int i = 0; i < n; i++)\n\
    \            add(i, a[i]);\n        build();\n    }\n    void build() {\n    \
    \    debug_assert(!built);\n        for(int i = 0; i < n; i++) {\n           \
    \ data[i + 1] = T::op(data[i], data[i + 1]);\n        }\n        built = true;\n\
    \    }\n    void add(int idx, S x) {\n        debug_assert(!built);\n        data[idx\
    \ + 1] = T::op(data[idx + 1], x);\n    }\n    S sum(int l, int r) {\n        debug_assert(built);\n\
    \        return T::op(T::inv(data[l]), data[r]);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u62BD\u8C61\u5316\u7D2F\u7A4D\u548C\n */\n\
    \n#include <vector>\n#include <cassert>\n#include <concepts>\n#include \"../Util/debug.hpp\"\
    \n#include \"../Math/algebraic-structure.hpp\"\n\ntemplate <GroupConcept T>\n\
    struct AbstructCumulativeSum {\n  private:\n    bool built = false;\n\n  public:\n\
    \    using S = typename T::S;\n    int n;\n    std::vector<S> data;\n    AbstructCumulativeSum(int\
    \ n)\n        : n(n), data(n + 1, T::e()) {}\n    AbstructCumulativeSum(const\
    \ std::vector<S> &a)\n        : n((int)a.size()), data(n + 1, T::e()) {\n    \
    \    for(int i = 0; i < n; i++)\n            add(i, a[i]);\n        build();\n\
    \    }\n    void build() {\n        debug_assert(!built);\n        for(int i =\
    \ 0; i < n; i++) {\n            data[i + 1] = T::op(data[i], data[i + 1]);\n \
    \       }\n        built = true;\n    }\n    void add(int idx, S x) {\n      \
    \  debug_assert(!built);\n        data[idx + 1] = T::op(data[idx + 1], x);\n \
    \   }\n    S sum(int l, int r) {\n        debug_assert(built);\n        return\
    \ T::op(T::inv(data[l]), data[r]);\n    }\n};"
  dependsOn:
  - src/Util/debug.hpp
  - src/Math/algebraic-structure.hpp
  isVerificationFile: false
  path: src/DataStructure/abstract-cumulative-sum.hpp
  requiredBy: []
  timestamp: '2025-03-30 10:23:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/yosupo-static-range-sum-abstract.test.cpp
documentation_of: src/DataStructure/abstract-cumulative-sum.hpp
layout: document
redirect_from:
- /library/src/DataStructure/abstract-cumulative-sum.hpp
- /library/src/DataStructure/abstract-cumulative-sum.hpp.html
title: "\u62BD\u8C61\u5316\u7D2F\u7A4D\u548C"
---
