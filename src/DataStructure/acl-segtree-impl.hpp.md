---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30BB\u30B0\u6728 \u30C1\u30FC\u30C8\u30B7\u30FC\u30C8"
    links:
    - https://betrue12.hateblo.jp/entry/2020/09/23/005940
  bundledCode: "#line 2 \"src/DataStructure/acl-segtree-impl.hpp\"\n\n/**\n * @brief\
    \ \u30BB\u30B0\u6728 \u30C1\u30FC\u30C8\u30B7\u30FC\u30C8\n * @cite https://betrue12.hateblo.jp/entry/2020/09/23/005940\
    \ (\u6539\u5909\u3042\u308A)\n */\n\n#include <numeric>\n#include <algorithm>\n\
    \n#include <atcoder/segtree>\n#include <atcoder/lazysegtree>\n\nstruct RangeAddRangeMin\
    \ {\n    using S = long long;\n    using F = long long;\n\n    static constexpr\
    \ S inf = std::numeric_limits<S>::max();\n\n    static constexpr S op(S a, S b)\
    \ { return std::min(a, b); }\n    static constexpr S e() { return inf; }\n   \
    \ static constexpr S mapping(F f, S x) { return f + x; }\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ 0; }\n\n    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n};\n\nstruct RangeAddRangeMax {\n    using S = long long;\n    using F\
    \ = long long;\n\n    static constexpr S minf = std::numeric_limits<S>::min();\n\
    \n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static constexpr\
    \ S e() { return minf; }\n    static constexpr S mapping(F f, S x) { return f\
    \ + x; }\n    static constexpr F composition(F f, F g) { return f + g; }\n   \
    \ static constexpr F id() { return 0; }\n\n    using segtree = atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};\n\nstruct RangeAddRangeSum {\n    struct\
    \ S {\n        long long value;\n        int size;\n    };\n    using F = long\
    \ long;\n\n    static constexpr S op(S a, S b) { return {a.value + b.value, a.size\
    \ + b.size}; }\n    static constexpr S e() { return {0, 0}; }\n    static constexpr\
    \ S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ 0; }\n    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n};\n\nstruct RangeUpdateRangeMin {\n    using S = long long;\n    using\
    \ F = long long;\n\n    static constexpr S inf = std::numeric_limits<S>::max();\n\
    \    static constexpr F id = std::numeric_limits<S>::max();\n\n    static constexpr\
    \ S op(S a, S b) { return std::min(a, b); }\n    static constexpr S e() { return\
    \ inf; }\n    static constexpr S mapping(F f, S x) { return (f == id ? x : f);\
    \ }\n    static constexpr F composition(F f, F g) { return (f == id ? g : f);\
    \ }\n    static constexpr F id() { return id; }\n    using segtree = atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};\n\nstruct RangeUpdateRangeMax {\n \
    \   using S = long long;\n    using F = long long;\n\n    static constexpr S minf\
    \ = std::numeric_limits<S>::min();\n    static constexpr F id = std::numeric_limits<S>::max();\n\
    \n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static constexpr\
    \ S e() { return minf; }\n    static constexpr S mapping(F f, S x) { return (f\
    \ == id ? x : f); }\n    static constexpr F composition(F f, F g) { return (f\
    \ == id ? g : f); }\n    static constexpr F id() { return id; }\n    using segtree\
    \ = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;\n};\n\nstruct\
    \ RangeUpdateRangeSum {\n    struct S {\n        long long value;\n        int\
    \ size;\n    };\n    using F = long long;\n\n    static constexpr const F ID =\
    \ std::numeric_limits<F>::max();\n\n    static constexpr S op(S a, S b) { return\
    \ {a.value + b.value, a.size + b.size}; }\n    static constexpr S e() { return\
    \ {0, 0}; }\n    static constexpr S mapping(F f, S x) {\n        if(f != ID) x.value\
    \ = f * x.size;\n        return x;\n    }\n    static constexpr F composition(F\
    \ f, F g) { return (f == ID ? g : f); }\n    static constexpr F id() { return\
    \ ID; }\n    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u30BB\u30B0\u6728 \u30C1\u30FC\u30C8\u30B7\
    \u30FC\u30C8\n * @cite https://betrue12.hateblo.jp/entry/2020/09/23/005940 (\u6539\
    \u5909\u3042\u308A)\n */\n\n#include <numeric>\n#include <algorithm>\n\n#include\
    \ <atcoder/segtree>\n#include <atcoder/lazysegtree>\n\nstruct RangeAddRangeMin\
    \ {\n    using S = long long;\n    using F = long long;\n\n    static constexpr\
    \ S inf = std::numeric_limits<S>::max();\n\n    static constexpr S op(S a, S b)\
    \ { return std::min(a, b); }\n    static constexpr S e() { return inf; }\n   \
    \ static constexpr S mapping(F f, S x) { return f + x; }\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ 0; }\n\n    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n};\n\nstruct RangeAddRangeMax {\n    using S = long long;\n    using F\
    \ = long long;\n\n    static constexpr S minf = std::numeric_limits<S>::min();\n\
    \n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static constexpr\
    \ S e() { return minf; }\n    static constexpr S mapping(F f, S x) { return f\
    \ + x; }\n    static constexpr F composition(F f, F g) { return f + g; }\n   \
    \ static constexpr F id() { return 0; }\n\n    using segtree = atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};\n\nstruct RangeAddRangeSum {\n    struct\
    \ S {\n        long long value;\n        int size;\n    };\n    using F = long\
    \ long;\n\n    static constexpr S op(S a, S b) { return {a.value + b.value, a.size\
    \ + b.size}; }\n    static constexpr S e() { return {0, 0}; }\n    static constexpr\
    \ S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ 0; }\n    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n};\n\nstruct RangeUpdateRangeMin {\n    using S = long long;\n    using\
    \ F = long long;\n\n    static constexpr S inf = std::numeric_limits<S>::max();\n\
    \    static constexpr F id = std::numeric_limits<S>::max();\n\n    static constexpr\
    \ S op(S a, S b) { return std::min(a, b); }\n    static constexpr S e() { return\
    \ inf; }\n    static constexpr S mapping(F f, S x) { return (f == id ? x : f);\
    \ }\n    static constexpr F composition(F f, F g) { return (f == id ? g : f);\
    \ }\n    static constexpr F id() { return id; }\n    using segtree = atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};\n\nstruct RangeUpdateRangeMax {\n \
    \   using S = long long;\n    using F = long long;\n\n    static constexpr S minf\
    \ = std::numeric_limits<S>::min();\n    static constexpr F id = std::numeric_limits<S>::max();\n\
    \n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static constexpr\
    \ S e() { return minf; }\n    static constexpr S mapping(F f, S x) { return (f\
    \ == id ? x : f); }\n    static constexpr F composition(F f, F g) { return (f\
    \ == id ? g : f); }\n    static constexpr F id() { return id; }\n    using segtree\
    \ = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;\n};\n\nstruct\
    \ RangeUpdateRangeSum {\n    struct S {\n        long long value;\n        int\
    \ size;\n    };\n    using F = long long;\n\n    static constexpr const F ID =\
    \ std::numeric_limits<F>::max();\n\n    static constexpr S op(S a, S b) { return\
    \ {a.value + b.value, a.size + b.size}; }\n    static constexpr S e() { return\
    \ {0, 0}; }\n    static constexpr S mapping(F f, S x) {\n        if(f != ID) x.value\
    \ = f * x.size;\n        return x;\n    }\n    static constexpr F composition(F\
    \ f, F g) { return (f == ID ? g : f); }\n    static constexpr F id() { return\
    \ ID; }\n    using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/acl-segtree-impl.hpp
  requiredBy: []
  timestamp: '2025-03-30 12:49:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/acl-segtree-impl.hpp
layout: document
redirect_from:
- /library/src/DataStructure/acl-segtree-impl.hpp
- /library/src/DataStructure/acl-segtree-impl.hpp.html
title: "\u30BB\u30B0\u6728 \u30C1\u30FC\u30C8\u30B7\u30FC\u30C8"
---
