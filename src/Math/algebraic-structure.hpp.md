---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/abstract-cumulative-sum.hpp
    title: "\u62BD\u8C61\u5316\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/segment-tree.hpp
    title: Segment Tree
  - icon: ':warning:'
    path: src/Math/algebraic-structure-test.hpp
    title: src/Math/algebraic-structure-test.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
    title: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
    title: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/algebraic-structure.hpp\"\n\n#include <numeric>\n\
    #include <concepts>\n\ntemplate <typename T>\nconcept HasInnerType = requires()\
    \ {\n    typename T::S;\n};\n\ntemplate <typename T>\nconcept HasIdentity = requires()\
    \ {\n    { T::e() } -> std::same_as<typename T::S>;\n};\n\ntemplate <typename\
    \ T>\nconcept HasInverse = requires() {\n    { T::inv(std::declval<typename T::S>())\
    \ } -> std::same_as<typename T::S>;\n};\n\ntemplate <typename T>\nconcept HasBinaryOperation\
    \ = requires() {\n    { T::op(std::declval<typename T::S>(), std::declval<typename\
    \ T::S>()) } -> std::same_as<typename T::S>;\n};\n\ntemplate <class T>\nconcept\
    \ MonoidConcept = HasInnerType<T> && HasIdentity<T> && HasBinaryOperation<T>;\n\
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
    \    static constexpr S inv(const S &a) { return a; }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n#include <concepts>\n\ntemplate <typename\
    \ T>\nconcept HasInnerType = requires() {\n    typename T::S;\n};\n\ntemplate\
    \ <typename T>\nconcept HasIdentity = requires() {\n    { T::e() } -> std::same_as<typename\
    \ T::S>;\n};\n\ntemplate <typename T>\nconcept HasInverse = requires() {\n   \
    \ { T::inv(std::declval<typename T::S>()) } -> std::same_as<typename T::S>;\n\
    };\n\ntemplate <typename T>\nconcept HasBinaryOperation = requires() {\n    {\
    \ T::op(std::declval<typename T::S>(), std::declval<typename T::S>()) } -> std::same_as<typename\
    \ T::S>;\n};\n\ntemplate <class T>\nconcept MonoidConcept = HasInnerType<T> &&\
    \ HasIdentity<T> && HasBinaryOperation<T>;\n\ntemplate <class T>\nconcept GroupConcept\
    \ = MonoidConcept<T> && HasInverse<T>;\n\ntemplate <std::integral T>\nstruct MinMonoid\
    \ {\n    using S = T;\n    static constexpr S e() { return std::numeric_limits<S>::max();\
    \ }\n    static constexpr S op(const S &a, const S &b) { return std::min(a, b);\
    \ }\n};\n\ntemplate <std::integral T>\nstruct MaxMonoid {\n    using S = T;\n\
    \    static constexpr S e() { return std::numeric_limits<S>::min(); }\n    static\
    \ constexpr S op(const S &a, const S &b) { return std::max(a, b); }\n};\n\ntemplate\
    \ <typename T>\nstruct MultiplicativeMonoid {\n    using S = T;\n    static constexpr\
    \ S e() { return S(1); }\n    static constexpr S op(const S &a, const S &b) {\
    \ return a * b; }\n};\n\ntemplate <typename T>\nstruct AdditiveGroup {\n    using\
    \ S = T;\n    static constexpr S e() { return S(); }\n    static constexpr S op(const\
    \ S &a, const S &b) { return a + b; }\n    static constexpr S inv(const S &a)\
    \ { return -a; }\n};\n\ntemplate <typename T>\nstruct XORGroup {\n    using S\
    \ = T;\n    static constexpr S e() { return S(); }\n    static constexpr S op(const\
    \ S &a, const S &b) { return a ^ b; }\n    static constexpr S inv(const S &a)\
    \ { return a; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/algebraic-structure.hpp
  requiredBy:
  - src/Math/algebraic-structure-test.hpp
  - src/DataStructure/segment-tree.hpp
  - src/DataStructure/abstract-cumulative-sum.hpp
  timestamp: '2025-03-30 10:23:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  - src/test/verify/yosupo-static-range-sum-abstract.test.cpp
documentation_of: src/Math/algebraic-structure.hpp
layout: document
redirect_from:
- /library/src/Math/algebraic-structure.hpp
- /library/src/Math/algebraic-structure.hpp.html
title: src/Math/algebraic-structure.hpp
---
