---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/abstract-cumulative-sum.hpp
    title: "\u62BD\u8C61\u5316\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: src/Math/algebraic-structure.hpp
    title: src/Math/algebraic-structure.hpp
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
  bundledCode: "#line 1 \"src/test/verify/yosupo-static-range-sum-abstract.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line\
    \ 2 \"src/template.hpp\"\n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n */\n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n//\
    \ #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\nusing namespace\
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
    \    }\n} iosetup;\n\n#line 2 \"src/Util/debug.hpp\"\n\n/**\n * @brief Debug\n\
    \ */\n\n#ifdef LOCAL\n#define debug_assert(exp) assert(exp)\n#else\n#define debug_assert(exp)\
    \ true\n#endif\n\n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \"\
    \ << #x << \" = \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n#line\
    \ 2 \"src/DataStructure/abstract-cumulative-sum.hpp\"\n\n/**\n * @brief \u62BD\
    \u8C61\u5316\u7D2F\u7A4D\u548C\n */\n\n#line 9 \"src/DataStructure/abstract-cumulative-sum.hpp\"\
    \n#include <concepts>\n#line 2 \"src/Math/algebraic-structure.hpp\"\n\n#line 5\
    \ \"src/Math/algebraic-structure.hpp\"\n\ntemplate <typename T>\nconcept HasInnerType\
    \ = requires() {\n    typename T::S;\n};\n\ntemplate <typename T>\nconcept HasIdentity\
    \ = requires() {\n    { T::e() } -> std::same_as<typename T::S>;\n};\n\ntemplate\
    \ <typename T>\nconcept HasInverse = requires() {\n    { T::inv(std::declval<typename\
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
    \        return T::op(T::inv(data[l]), data[r]);\n    }\n};\n#line 5 \"src/test/verify/yosupo-static-range-sum-abstract.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vl a(N);\n    cin >>\
    \ a;\n    AbstructCumulativeSum<AdditiveGroup<ll>> cs(a);\n    while(Q--) {\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << cs.sum(l, r) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../template.hpp\"\n#include \"../../DataStructure/abstract-cumulative-sum.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vl a(N);\n    cin >>\
    \ a;\n    AbstructCumulativeSum<AdditiveGroup<ll>> cs(a);\n    while(Q--) {\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << cs.sum(l, r) << '\\\
    n';\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/Util/debug.hpp
  - src/DataStructure/abstract-cumulative-sum.hpp
  - src/Math/algebraic-structure.hpp
  isVerificationFile: true
  path: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
  requiredBy: []
  timestamp: '2025-03-30 10:23:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/yosupo-static-range-sum-abstract.test.cpp
- /verify/src/test/verify/yosupo-static-range-sum-abstract.test.cpp.html
title: src/test/verify/yosupo-static-range-sum-abstract.test.cpp
---
