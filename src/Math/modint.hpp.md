---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/String/rolling-hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/test/verify/aoj-alds-1-14-b.test.cpp
    title: src/test/verify/aoj-alds-1-14-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Modint
    links:
    - https://nyaannyaan.github.io/library/modint/modint.hpp
  bundledCode: "#line 2 \"src/Math/modint.hpp\"\n\n/**\n * @brief Modint\n * @cite\
    \ https://nyaannyaan.github.io/library/modint/modint.hpp\n */\n\ntemplate <uint32_t\
    \ mod>\nstruct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    static constexpr u32 get_r() {\n        u32 ret = mod;\n        for (i32\
    \ i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n        return ret;\n    }\n\n   \
    \ static constexpr u32 r = get_r();\n    static constexpr u32 n2 = -u64(mod) %\
    \ mod;\n    static_assert(mod < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n    static_assert((mod\
    \ & 1) == 1, \"invalid, mod % 2 == 0\");\n    static_assert(r * mod == 1, \"this\
    \ code has bugs.\");\n\n    u32 a;\n\n    constexpr LazyMontgomeryModInt() : a(0)\
    \ {}\n    constexpr LazyMontgomeryModInt(const int64_t &b)\n            : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n    static constexpr u32 reduce(const u64 &b) {\n\
    \        return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n    }\n\n    constexpr\
    \ mint &operator+=(const mint &b) {\n        if (i32(a += b.a - 2 * mod) < 0)\
    \ a += 2 * mod;\n        return *this;\n    }\n\n    constexpr mint &operator-=(const\
    \ mint &b) {\n        if (i32(a -= b.a) < 0) a += 2 * mod;\n        return *this;\n\
    \    }\n\n    constexpr mint &operator*=(const mint &b) {\n        a = reduce(u64(a)\
    \ * b.a);\n        return *this;\n    }\n\n    constexpr mint &operator/=(const\
    \ mint &b) {\n        *this *= b.inverse();\n        return *this;\n    }\n\n\
    \    constexpr mint operator+(const mint &b) const { return mint(*this) += b;\
    \ }\n    constexpr mint operator-(const mint &b) const { return mint(*this) -=\
    \ b; }\n    constexpr mint operator*(const mint &b) const { return mint(*this)\
    \ *= b; }\n    constexpr mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n    constexpr bool operator==(const mint &b) const {\n        return\
    \ (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n    }\n    constexpr\
    \ bool operator!=(const mint &b) const {\n        return (a >= mod ? a - mod :\
    \ a) != (b.a >= mod ? b.a - mod : b.a);\n    }\n    constexpr mint operator-()\
    \ const { return mint() - mint(*this); }\n    constexpr mint operator+() const\
    \ { return mint(*this); }\n\n    constexpr mint pow(u64 n) const {\n        mint\
    \ ret(1), mul(*this);\n        while (n > 0) {\n            if (n & 1) ret *=\
    \ mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    constexpr mint inverse() const {\n        int x = get(),\
    \ y = mod, u = 1, v = 0, t = 0, tmp = 0;\n        while (y > 0) {\n          \
    \  t = x / y;\n            x -= t * y, u -= t * v;\n            tmp = x, x = y,\
    \ y = tmp;\n            tmp = u, u = v, v = tmp;\n        }\n        return mint{u};\n\
    \    }\n\n    friend ostream &operator<<(ostream &os, const mint &b) {\n     \
    \   return os << b.get();\n    }\n\n    friend istream &operator>>(istream &is,\
    \ mint &b) {\n        int64_t t;\n        is >> t;\n        b = LazyMontgomeryModInt<mod>(t);\n\
    \        return (is);\n    }\n\n    constexpr u32 get() const {\n        u32 ret\
    \ = reduce(a);\n        return ret >= mod ? ret - mod : ret;\n    }\n\n    static\
    \ constexpr u32 get_mod() { return mod; }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Modint\n * @cite https://nyaannyaan.github.io/library/modint/modint.hpp\n\
    \ */\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n    using mint\
    \ = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = mod;\n        for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    \
    \    return ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr\
    \ u32 n2 = -u64(mod) % mod;\n    static_assert(mod < (1 << 30), \"invalid, mod\
    \ >= 2 ^ 30\");\n    static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\
    \    static_assert(r * mod == 1, \"this code has bugs.\");\n\n    u32 a;\n\n \
    \   constexpr LazyMontgomeryModInt() : a(0) {}\n    constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n            : a(reduce(u64(b % mod + mod) * n2)){};\n\n    static\
    \ constexpr u32 reduce(const u64 &b) {\n        return (b + u64(u32(b) * u32(-r))\
    \ * mod) >> 32;\n    }\n\n    constexpr mint &operator+=(const mint &b) {\n  \
    \      if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n        return *this;\n\
    \    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if (i32(a -=\
    \ b.a) < 0) a += 2 * mod;\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator*=(const mint &b) {\n        a = reduce(u64(a) * b.a);\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n        *this\
    \ *= b.inverse();\n        return *this;\n    }\n\n    constexpr mint operator+(const\
    \ mint &b) const { return mint(*this) += b; }\n    constexpr mint operator-(const\
    \ mint &b) const { return mint(*this) -= b; }\n    constexpr mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n    constexpr mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n    constexpr bool operator==(const\
    \ mint &b) const {\n        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a\
    \ - mod : b.a);\n    }\n    constexpr bool operator!=(const mint &b) const {\n\
    \        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n\
    \    }\n    constexpr mint operator-() const { return mint() - mint(*this); }\n\
    \    constexpr mint operator+() const { return mint(*this); }\n\n    constexpr\
    \ mint pow(u64 n) const {\n        mint ret(1), mul(*this);\n        while (n\
    \ > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n      \
    \      n >>= 1;\n        }\n        return ret;\n    }\n\n    constexpr mint inverse()\
    \ const {\n        int x = get(), y = mod, u = 1, v = 0, t = 0, tmp = 0;\n   \
    \     while (y > 0) {\n            t = x / y;\n            x -= t * y, u -= t\
    \ * v;\n            tmp = x, x = y, y = tmp;\n            tmp = u, u = v, v =\
    \ tmp;\n        }\n        return mint{u};\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n        return os << b.get();\n    }\n\n    friend istream\
    \ &operator>>(istream &is, mint &b) {\n        int64_t t;\n        is >> t;\n\
    \        b = LazyMontgomeryModInt<mod>(t);\n        return (is);\n    }\n\n  \
    \  constexpr u32 get() const {\n        u32 ret = reduce(a);\n        return ret\
    \ >= mod ? ret - mod : ret;\n    }\n\n    static constexpr u32 get_mod() { return\
    \ mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/modint.hpp
  requiredBy:
  - src/String/rolling-hash.hpp
  timestamp: '2023-11-02 07:47:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/test/verify/aoj-alds-1-14-b.test.cpp
documentation_of: src/Math/modint.hpp
layout: document
redirect_from:
- /library/src/Math/modint.hpp
- /library/src/Math/modint.hpp.html
title: Modint
---
