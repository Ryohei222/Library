---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Math/algebraic-structure-test.hpp
    title: src/Math/algebraic-structure-test.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/algebraic-structure.hpp\"\n\n#include <numeric>\n\
    #include <concepts>\n\ntemplate <typename T>\nconcept inner_type = requires()\
    \ {\n    typename T::S;\n};\n\ntemplate <typename T>\nconcept identity = requires()\
    \ {\n    { T::e() } -> std::same_as<typename T::S>; // \u5358\u4F4D\u5143\n};\n\
    \ntemplate <typename T>\nconcept inverse = requires() {\n    { T::inv(std::declval<typename\
    \ T::S>()) } -> std::same_as<typename T::S>; // \u9006\u5143\n};\n\ntemplate <typename\
    \ T>\nconcept binary_operation = requires() {\n    { T::op(std::declval<typename\
    \ T::S>(), std::declval<typename T::S>()) } -> std::same_as<typename T::S>; //\
    \ \u4E8C\u9805\u6F14\u7B97\n};\n\ntemplate <class T>\nconcept MonoidConcept =\
    \ inner_type<T> && identity<T> && binary_operation<T>;\n\ntemplate <class T>\n\
    concept GroupConcept = MonoidConcept<T> && inverse<T>;\n\ntemplate <std::integral\
    \ T>\nstruct MinMonoid {\n    using S = T;\n    static constexpr S e() { return\
    \ std::numeric_limits<S>::max(); }\n    static constexpr S op(const S &a, const\
    \ S &b) { return std::min(a, b); }\n};\n\ntemplate <std::integral T>\nstruct MaxMonoid\
    \ {\n    using S = T;\n    static constexpr S e() { return std::numeric_limits<S>::min();\
    \ }\n    static constexpr S op(const S &a, const S &b) { return std::max(a, b);\
    \ }\n};\n\ntemplate <typename T>\nstruct MultiplicativeMonoid {\n    using S =\
    \ T;\n    static constexpr S e() { return S(1); }\n    static constexpr S op(const\
    \ S &a, const S &b) { return a * b; }\n};\n\ntemplate <typename T>\nstruct AdditiveGroup\
    \ {\n    using S = T;\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr S op(const S &a, const S &b) { return a + b; }\n    static constexpr\
    \ S inv(const S &a) { return -a; }\n};\n\ntemplate <typename T>\nstruct XORGroup\
    \ {\n    using S = T;\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr S op(const S &a, const S &b) { return a ^ b; }\n    static constexpr\
    \ S inv(const S &a) { return a; }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n#include <concepts>\n\ntemplate <typename\
    \ T>\nconcept inner_type = requires() {\n    typename T::S;\n};\n\ntemplate <typename\
    \ T>\nconcept identity = requires() {\n    { T::e() } -> std::same_as<typename\
    \ T::S>; // \u5358\u4F4D\u5143\n};\n\ntemplate <typename T>\nconcept inverse =\
    \ requires() {\n    { T::inv(std::declval<typename T::S>()) } -> std::same_as<typename\
    \ T::S>; // \u9006\u5143\n};\n\ntemplate <typename T>\nconcept binary_operation\
    \ = requires() {\n    { T::op(std::declval<typename T::S>(), std::declval<typename\
    \ T::S>()) } -> std::same_as<typename T::S>; // \u4E8C\u9805\u6F14\u7B97\n};\n\
    \ntemplate <class T>\nconcept MonoidConcept = inner_type<T> && identity<T> &&\
    \ binary_operation<T>;\n\ntemplate <class T>\nconcept GroupConcept = MonoidConcept<T>\
    \ && inverse<T>;\n\ntemplate <std::integral T>\nstruct MinMonoid {\n    using\
    \ S = T;\n    static constexpr S e() { return std::numeric_limits<S>::max(); }\n\
    \    static constexpr S op(const S &a, const S &b) { return std::min(a, b); }\n\
    };\n\ntemplate <std::integral T>\nstruct MaxMonoid {\n    using S = T;\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::min(); }\n    static constexpr\
    \ S op(const S &a, const S &b) { return std::max(a, b); }\n};\n\ntemplate <typename\
    \ T>\nstruct MultiplicativeMonoid {\n    using S = T;\n    static constexpr S\
    \ e() { return S(1); }\n    static constexpr S op(const S &a, const S &b) { return\
    \ a * b; }\n};\n\ntemplate <typename T>\nstruct AdditiveGroup {\n    using S =\
    \ T;\n    static constexpr S e() { return S(); }\n    static constexpr S op(const\
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
  timestamp: '2025-03-30 09:54:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/algebraic-structure.hpp
layout: document
redirect_from:
- /library/src/Math/algebraic-structure.hpp
- /library/src/Math/algebraic-structure.hpp.html
title: src/Math/algebraic-structure.hpp
---
