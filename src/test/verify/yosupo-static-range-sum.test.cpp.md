---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/cumulative-sum.hpp
    title: "\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B"
  - icon: ':question:'
    path: src/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"src/test/verify/yosupo-static-range-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 2 \"src/template.hpp\"\
    \n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template.md\n\
    \ */\n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing ull = unsigned long long;\nusing vl = vector<ll>;\n\
    using vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\n\
    using vp = vector<pl>;\nusing vvp = vector<vp>;\nusing vs = vector<string>;\n\
    using vvs = vector<vs>;\nusing vb = vector<bool>;\nusing vvb = vector<vb>;\nusing\
    \ vvvb = vector<vvb>;\nusing vd = vector<double>;\nusing vvd = vector<vd>;\nusing\
    \ vvvd = vector<vvd>;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define\
    \ _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(ll i = ll(a); i < ll(b);\
    \ ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n\nconstexpr ll inf = 0x1fffffffffffffffLL;\
    \ // 2.3 * 10^18\n\ntemplate <class T, class U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <class T, class U>\nostream &operator<<(ostream &os, pair<T, U> &p) {\n    os\
    \ << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate <class T>\n\
    istream &operator>>(istream &is, vector<T> &v) {\n    for(auto &x : v) {\n   \
    \     is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n    for(int i = 0; i < (int)v.size(); i++) {\n \
    \       if(i != (int)v.size() - 1)\n            os << v[i] << \" \";\n       \
    \ else\n            os << v[i];\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T, typename... Args>\nauto vec(T x, int arg, Args... args) {\n    if constexpr(sizeof...(args)\
    \ == 0)\n        return vector<T>(arg, x);\n    else\n        return vector(arg,\
    \ vec<T>(x, args...));\n}\n\ntemplate <class T>\nbool chmin(T &a, const T &b)\
    \ {\n    return a > b ? a = b, true : false;\n}\ntemplate <class T>\nbool chmax(T\
    \ &a, const T &b) {\n    return a < b ? a = b, true : false;\n}\n\nconstexpr ll\
    \ bit(ll x) {\n    return 1LL << x;\n}\nconstexpr ll msk(ll x) {\n    return (1LL\
    \ << x) - 1;\n}\nconstexpr bool stand(ll x, int i) {\n    return x & bit(i);\n\
    }\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n#line 1 \"src/DataStructure/cumulative-sum.hpp\"\ntemplate\
    \ <typename T = long long int>\nstruct CumulativeSum {\n  private:\n    bool built\
    \ = false;\n\n  public:\n    int n;\n    vector<T> wa;\n    CumulativeSum(int\
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
    \    }\n};\n#line 5 \"src/test/verify/yosupo-static-range-sum.test.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    cin >> N >> Q;\n    vl a(N);\n    cin >> a;\n \
    \   CumulativeSum cs(a);\n    while(Q--) {\n        int l, r;\n        cin >>\
    \ l >> r;\n        cout << cs.sum(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../template.hpp\"\n#include \"../../DataStructure/cumulative-sum.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vl a(N);\n    cin >>\
    \ a;\n    CumulativeSum cs(a);\n    while(Q--) {\n        int l, r;\n        cin\
    \ >> l >> r;\n        cout << cs.sum(l, r) << endl;\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/DataStructure/cumulative-sum.hpp
  isVerificationFile: true
  path: src/test/verify/yosupo-static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2025-01-16 14:57:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/test/verify/yosupo-static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/yosupo-static-range-sum.test.cpp
- /verify/src/test/verify/yosupo-static-range-sum.test.cpp.html
title: src/test/verify/yosupo-static-range-sum.test.cpp
---
