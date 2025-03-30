---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/cumulative-sum.hpp
    title: "\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B"
  - icon: ':heavy_check_mark:'
    path: src/Util/debug.hpp
    title: Debug
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"src/test/verify/yosupo-static-range-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 2 \"src/template.hpp\"\
    \n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n// #pragma GCC\
    \ target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
    unroll-loops\")\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll\
    \ = long long;\nusing ull = unsigned long long;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\nusing\
    \ vp = vector<pl>;\nusing vvp = vector<vp>;\nusing vs = vector<string>;\nusing\
    \ vvs = vector<vs>;\nusing vb = vector<bool>;\nusing vvb = vector<vb>;\nusing\
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
    \    }\n} iosetup;\n\n#line 2 \"src/Util/debug.hpp\"\n\n/**\n * @brief Debug\n\
    \ */\n\n#ifdef LOCAL\n#define debug_assert(exp) assert(exp)\n#else\n#define debug_assert(exp)\
    \ true\n#endif\n\n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \"\
    \ << #x << \" = \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n#line\
    \ 4 \"src/DataStructure/cumulative-sum.hpp\"\n#include <concepts>\n\ntemplate\
    \ <std::integral T>\nstruct CumulativeSum {\n  private:\n    bool built = false;\n\
    \n  public:\n    int n;\n    std::vector<T> data;\n    CumulativeSum(int n)\n\
    \        : n(n), data(n + 1, T()) {}\n    CumulativeSum(const std::vector<T> &a)\n\
    \        : n((int)a.size()), data(n + 1, T()) {\n        for(int i = 0; i < n;\
    \ i++)\n            add(i, a[i]);\n        build();\n    }\n    /**\n     * @brief\
    \ \u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\n     *\n     */\n    void\
    \ build() {\n#ifdef LOCAL\n        assert(!built);\n#endif\n        for(int i\
    \ = 0; i < n; i++) {\n            data[i + 1] = data[i] + data[i + 1];\n     \
    \   }\n        built = true;\n    }\n    /**\n     * @brief data[idx + 1] += x\n\
    \     *\n     * @param idx \u52A0\u7B97\u3059\u308B\u4F4D\u7F6E (0-indexed)\n\
    \     * @param x \u52A0\u7B97\u3059\u308B\u5024\n     */\n    void add(int idx,\
    \ T x) {\n#ifdef LOCAL\n        assert(!built);\n#endif\n        assert(!built);\n\
    \        data[idx + 1] += x;\n    }\n    /**\n     * @brief [l, r) \u306E\u548C\
    , data[r] - data[l]\n     *\n     * @param l \u5DE6\u7AEF\u306E\u4F4D\u7F6E (0-indexed,\
    \ \u9589\u533A\u9593)\n     * @param r \u53F3\u7AEF\u306E\u4F4D\u7F6E (0-indexed,\
    \ \u958B\u533A\u9593)\n     * @return T \u533A\u9593\u306E\u7DCF\u548C\n     */\n\
    \    T sum(int l, int r) {\n#ifdef LOCAL\n        assert(built);\n#endif\n   \
    \     return data[r] - data[l];\n    }\n};\n#line 5 \"src/test/verify/yosupo-static-range-sum.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vl a(N);\n    cin >>\
    \ a;\n    CumulativeSum cs(a);\n    while(Q--) {\n        int l, r;\n        cin\
    \ >> l >> r;\n        cout << cs.sum(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../template.hpp\"\n#include \"../../DataStructure/cumulative-sum.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vl a(N);\n    cin >>\
    \ a;\n    CumulativeSum cs(a);\n    while(Q--) {\n        int l, r;\n        cin\
    \ >> l >> r;\n        cout << cs.sum(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/Util/debug.hpp
  - src/DataStructure/cumulative-sum.hpp
  isVerificationFile: true
  path: src/test/verify/yosupo-static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-30 10:22:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/yosupo-static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/yosupo-static-range-sum.test.cpp
- /verify/src/test/verify/yosupo-static-range-sum.test.cpp.html
title: src/test/verify/yosupo-static-range-sum.test.cpp
---
