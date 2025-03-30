---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/segment-tree.hpp
    title: Segment Tree
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
    \n\n/**\n * @brief Segment Tree\n */\n\ntemplate <typename T, typename F>\nstruct\
    \ SegmentTree {\n    int n, sz;\n    vector<T> seg;\n    T id;\n    F f;\n   \
    \ SegmentTree(int n, const F f, const T id)\n        : n(n), f(f), id(id) {\n\
    \        sz = 1;\n        while(sz < n)\n            sz <<= 1;\n        seg.assign(2\
    \ * sz, id);\n    }\n    SegmentTree(const vector<T> &v, const F f, const T id)\n\
    \        : id(id), f(f) {\n        n = (int)v.size();\n        sz = 1;\n     \
    \   while(sz < n)\n            sz *= 2;\n        seg.assign(2 * sz, id);\n   \
    \     build(v);\n    }\n    void build(const vector<T> &v) {\n        for(int\
    \ i = 0; i < n; i++)\n            seg[sz + i] = v[i];\n        for(int i = sz\
    \ - 1; i > 0; --i)\n            seg[i] = f(seg[i * 2], seg[i * 2 + 1]);\n    }\n\
    \    void set(int idx, T x) {\n        seg[sz + idx] = x;\n        int par = (sz\
    \ + idx) >> 1;\n        while(par > 0) {\n            seg[par] = f(seg[par * 2],\
    \ seg[par * 2 + 1]);\n            par >>= 1;\n        }\n    }\n    T get(int\
    \ idx) {\n        return seg[sz + idx];\n    }\n    void apply(int idx, T x) {\n\
    \        set(idx, f(x, get(idx)));\n    }\n    T prod(int l, int r) {\n      \
    \  T sl = id, sr = id;\n        l += sz, r += sz;\n        while(l < r) {\n  \
    \          if(l & 1) sl = f(sl, seg[l++]);\n            if(r & 1) sr = f(seg[--r],\
    \ sr);\n            l >>= 1, r >>= 1;\n        }\n        return f(sl, sr);\n\
    \    }\n};\n\n// https://ei1333.github.io/library/structure/segment-tree/segment-tree.hpp\n\
    \ntemplate <typename T, typename F>\nSegmentTree<T, F> get_segment_tree(int N,\
    \ const F &f, const T &ti) {\n    return SegmentTree{N, f, ti};\n}\n\ntemplate\
    \ <typename T, typename F>\nSegmentTree<T, F> get_segment_tree(const vector<T>\
    \ &v, const F &f, const T &ti) {\n    return SegmentTree{v, f, ti};\n}\n#line\
    \ 5 \"src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp\"\n\nint main() {\n  \
    \  ll n, q;\n    cin >> n >> q;\n    auto f = [](ll a, ll b) {\n        return\
    \ a + b;\n    };\n    auto seg = get_segment_tree(n, f, 0ll);\n    rep(i, q) {\n\
    \        ll com, x, y;\n        cin >> com >> x >> y;\n        if(com == 0) seg.apply(x\
    \ - 1, y);\n        if(com == 1) cout << seg.prod(x - 1, y) << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#include\
    \ \"../../template.hpp\"\n\n#include \"../../DataStructure/segment-tree.hpp\"\n\
    \nint main() {\n    ll n, q;\n    cin >> n >> q;\n    auto f = [](ll a, ll b)\
    \ {\n        return a + b;\n    };\n    auto seg = get_segment_tree(n, f, 0ll);\n\
    \    rep(i, q) {\n        ll com, x, y;\n        cin >> com >> x >> y;\n     \
    \   if(com == 0) seg.apply(x - 1, y);\n        if(com == 1) cout << seg.prod(x\
    \ - 1, y) << '\\n';\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/Util/debug.hpp
  - src/DataStructure/segment-tree.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2025-03-30 10:22:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
- /verify/src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp.html
title: src/test/verify/aoj-dsl-2-b-segment-tree.test.cpp
---
