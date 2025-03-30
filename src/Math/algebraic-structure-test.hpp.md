---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/algebraic-structure.hpp
    title: src/Math/algebraic-structure.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \    static constexpr S inv(const S &a) { return a; }\n};\n#line 3 \"src/Math/algebraic-structure-test.hpp\"\
    \n\nstatic_assert(MonoidConcept<MinMonoid<int>>);\nstatic_assert(MonoidConcept<MaxMonoid<int>>);\n\
    static_assert(MonoidConcept<MultiplicativeMonoid<int>>);\nstatic_assert(!GroupConcept<MinMonoid<int>>);\n\
    static_assert(!GroupConcept<MaxMonoid<int>>);\nstatic_assert(!GroupConcept<MultiplicativeMonoid<int>>);\n\
    \nstatic_assert(MonoidConcept<AdditiveGroup<int>>);\nstatic_assert(GroupConcept<AdditiveGroup<int>>);\n\
    static_assert(MonoidConcept<XORGroup<int>>);\nstatic_assert(GroupConcept<XORGroup<int>>);\n"
  code: '#pragma once

    #include "algebraic-structure.hpp"


    static_assert(MonoidConcept<MinMonoid<int>>);

    static_assert(MonoidConcept<MaxMonoid<int>>);

    static_assert(MonoidConcept<MultiplicativeMonoid<int>>);

    static_assert(!GroupConcept<MinMonoid<int>>);

    static_assert(!GroupConcept<MaxMonoid<int>>);

    static_assert(!GroupConcept<MultiplicativeMonoid<int>>);


    static_assert(MonoidConcept<AdditiveGroup<int>>);

    static_assert(GroupConcept<AdditiveGroup<int>>);

    static_assert(MonoidConcept<XORGroup<int>>);

    static_assert(GroupConcept<XORGroup<int>>);

    '
  dependsOn:
  - src/Math/algebraic-structure.hpp
  isVerificationFile: false
  path: src/Math/algebraic-structure-test.hpp
  requiredBy: []
  timestamp: '2025-03-30 10:23:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/algebraic-structure-test.hpp
layout: document
redirect_from:
- /library/src/Math/algebraic-structure-test.hpp
- /library/src/Math/algebraic-structure-test.hpp.html
title: src/Math/algebraic-structure-test.hpp
---
