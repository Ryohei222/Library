---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/yosupo-static-range-sum.test.cpp
    title: src/test/verify/yosupo-static-range-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/cumulative-sum.hpp\"\ntemplate <typename\
    \ T = long long int>\nstruct CumulativeSum {\n  private:\n    bool built = false;\n\
    \n  public:\n    int n;\n    vector<T> wa;\n    CumulativeSum(int n)\n       \
    \ : n(n), wa(n + 1, T(0)) {}\n    CumulativeSum(const vector<T> &a)\n        :\
    \ n((int)a.size()), wa(n + 1, T(0)) {\n        for(int i = 0; i < n; i++)\n  \
    \          add(i, a[i]);\n        build();\n    }\n    /**\n     * @brief \u7D2F\
    \u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\n     *\n     */\n    void build()\
    \ {\n        assert(!built);\n        for(int i = 0; i < n; i++) {\n         \
    \   wa[i + 1] = wa[i] + wa[i + 1];\n        }\n        built = true;\n    }\n\
    \    /**\n     * @brief wa[idx + 1] += x\n     *\n     * @param idx \u52A0\u7B97\
    \u3059\u308B\u4F4D\u7F6E (0-indexed)\n     * @param x \u52A0\u7B97\u3059\u308B\
    \u5024\n     */\n    void add(int idx, T x) {\n        assert(!built);\n     \
    \   wa[idx + 1] += x;\n    }\n    /**\n     * @brief [l, r) \u306E\u548C, wa[r]\
    \ - wa[l]\n     *\n     * @param l \u5DE6\u7AEF\u306E\u4F4D\u7F6E (0-indexed,\
    \ \u9589\u533A\u9593)\n     * @param r \u53F3\u7AEF\u306E\u4F4D\u7F6E (0-indexed,\
    \ \u958B\u533A\u9593)\n     * @return T \u533A\u9593\u306E\u7DCF\u548C\n     */\n\
    \    T sum(int l, int r) {\n        assert(built);\n        return wa[r] - wa[l];\n\
    \    }\n};\n"
  code: "template <typename T = long long int>\nstruct CumulativeSum {\n  private:\n\
    \    bool built = false;\n\n  public:\n    int n;\n    vector<T> wa;\n    CumulativeSum(int\
    \ n)\n        : n(n), wa(n + 1, T(0)) {}\n    CumulativeSum(const vector<T> &a)\n\
    \        : n((int)a.size()), wa(n + 1, T(0)) {\n        for(int i = 0; i < n;\
    \ i++)\n            add(i, a[i]);\n        build();\n    }\n    /**\n     * @brief\
    \ \u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\n     *\n     */\n    void\
    \ build() {\n        assert(!built);\n        for(int i = 0; i < n; i++) {\n \
    \           wa[i + 1] = wa[i] + wa[i + 1];\n        }\n        built = true;\n\
    \    }\n    /**\n     * @brief wa[idx + 1] += x\n     *\n     * @param idx \u52A0\
    \u7B97\u3059\u308B\u4F4D\u7F6E (0-indexed)\n     * @param x \u52A0\u7B97\u3059\
    \u308B\u5024\n     */\n    void add(int idx, T x) {\n        assert(!built);\n\
    \        wa[idx + 1] += x;\n    }\n    /**\n     * @brief [l, r) \u306E\u548C\
    , wa[r] - wa[l]\n     *\n     * @param l \u5DE6\u7AEF\u306E\u4F4D\u7F6E (0-indexed,\
    \ \u9589\u533A\u9593)\n     * @param r \u53F3\u7AEF\u306E\u4F4D\u7F6E (0-indexed,\
    \ \u958B\u533A\u9593)\n     * @return T \u533A\u9593\u306E\u7DCF\u548C\n     */\n\
    \    T sum(int l, int r) {\n        assert(built);\n        return wa[r] - wa[l];\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2024-05-02 19:48:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/test/verify/yosupo-static-range-sum.test.cpp
documentation_of: src/DataStructure/cumulative-sum.hpp
layout: document
redirect_from:
- /library/src/DataStructure/cumulative-sum.hpp
- /library/src/DataStructure/cumulative-sum.hpp.html
title: "\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B"
---
