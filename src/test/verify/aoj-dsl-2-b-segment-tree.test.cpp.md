---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/segment-tree.hpp
    title: Segment Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#line 2 \"src/template.hpp\"\
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
    \ 3 \"src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp\"\n\n#line 2 \"src/DataStructure/segment-tree.hpp\"\
    \n\n#line 2 \"src/Math/algebraic-structure.hpp\"\n\n#line 4 \"src/Math/algebraic-structure.hpp\"\
    \n#include <concepts>\n\ntemplate <typename T>\nconcept HasInnerType = requires()\
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
    \    static constexpr S inv(const S &a) { return a; }\n};\n#line 4 \"src/DataStructure/segment-tree.hpp\"\
    \n\n/**\n * @brief Segment Tree\n * @cite https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\
    \ (\u6539\u5909\u3042\u308A)\n */\n\ntemplate <MonoidConcept Monoid>\nstruct SegmentTree\
    \ {\n    using S = typename Monoid::S;\n\n  private:\n    int n, sz;\n\n    vector<S>\
    \ seg;\n\n  public:\n    SegmentTree() = default;\n\n    explicit SegmentTree(int\
    \ n)\n        : n(n) {\n        sz = 1;\n        while(sz < n)\n            sz\
    \ <<= 1;\n        seg.assign(2 * sz, Monoid::e());\n    }\n\n    explicit SegmentTree(const\
    \ vector<S> &v)\n        : SegmentTree((int)v.size()) {\n        build(v);\n \
    \   }\n\n    void build(const vector<S> &v) {\n        assert(n == (int)v.size());\n\
    \        for(int k = 0; k < n; k++)\n            seg[k + sz] = v[k];\n       \
    \ for(int k = sz - 1; k > 0; k--) {\n            seg[k] = Monoid::op(seg[2 * k\
    \ + 0], seg[2 * k + 1]);\n        }\n    }\n\n    void set(int k, const S &x)\
    \ {\n        k += sz;\n        seg[k] = x;\n        while(k >>= 1) {\n       \
    \     seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\
    \n    S get(int k) const { return seg[k + sz]; }\n\n    S operator[](int k) const\
    \ { return get(k); }\n\n    void apply(int k, const S &x) {\n        k += sz;\n\
    \        seg[k] = Monoid::op(seg[k], x);\n        while(k >>= 1) {\n         \
    \   seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);\n        }\n    }\n\n\
    \    S prod(int l, int r) const {\n        if(l >= r) return Monoid::e();\n  \
    \      S L = Monoid::e(), R = Monoid::e();\n        for(l += sz, r += sz; l <\
    \ r; l >>= 1, r >>= 1) {\n            if(l & 1) L = Monoid::op(L, seg[l++]);\n\
    \            if(r & 1) R = Monoid::op(seg[--r], R);\n        }\n        return\
    \ Monoid::op(L, R);\n    }\n\n    S all_prod() const { return seg[1]; }\n\n  \
    \  template <typename C>\n    int find_first(int l, const C &check) const {\n\
    \        if(l >= n) return n;\n        l += sz;\n        S sum = Monoid::e();\n\
    \        do {\n            while((l & 1) == 0)\n                l >>= 1;\n   \
    \         if(check(Monoid::op(sum, seg[l]))) {\n                while(l < sz)\
    \ {\n                    l <<= 1;\n                    auto nxt = Monoid::op(sum,\
    \ seg[l]);\n                    if(not check(nxt)) {\n                       \
    \ sum = nxt;\n                        l++;\n                    }\n          \
    \      }\n                return l + 1 - sz;\n            }\n            sum =\
    \ Monoid::op(sum, seg[l++]);\n        } while((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <typename C>\n    int find_last(int r, const C &check)\
    \ const {\n        if(r <= 0) return -1;\n        r += sz;\n        S sum = Monoid::e();\n\
    \        do {\n            r--;\n            while(r > 1 and (r & 1))\n      \
    \          r >>= 1;\n            if(check(Monoid::op(seg[r], sum))) {\n      \
    \          while(r < sz) {\n                    r = (r << 1) + 1;\n          \
    \          auto nxt = Monoid::op(seg[r], sum);\n                    if(not check(nxt))\
    \ {\n                        sum = nxt;\n                        r--;\n      \
    \              }\n                }\n                return r - sz;\n        \
    \    }\n            sum = Monoid::op(seg[r], sum);\n        } while((r & -r) !=\
    \ r);\n        return -1;\n    }\n};\n#line 5 \"src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp\"\
    \n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n    auto seg = SegmentTree<AdditiveGroup<ll>>(n);\n\
    \    rep(i, q) {\n        ll com, x, y;\n        cin >> com >> x >> y;\n     \
    \   if(com == 0) seg.apply(x - 1, y);\n        if(com == 1) cout << seg.prod(x\
    \ - 1, y) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#include\
    \ \"../../template.hpp\"\n\n#include \"../../DataStructure/segment-tree.hpp\"\n\
    \nint main() {\n    ll n, q;\n    cin >> n >> q;\n    auto seg = SegmentTree<AdditiveGroup<ll>>(n);\n\
    \    rep(i, q) {\n        ll com, x, y;\n        cin >> com >> x >> y;\n     \
    \   if(com == 0) seg.apply(x - 1, y);\n        if(com == 1) cout << seg.prod(x\
    \ - 1, y) << '\\n';\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/Util/debug.hpp
  - src/DataStructure/segment-tree.hpp
  - src/Math/algebraic-structure.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2025-03-30 10:41:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
- /verify/src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp.html
title: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
---
