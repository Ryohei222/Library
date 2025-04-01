---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/union-find.hpp
    title: Union-Find
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
  bundledCode: "#line 1 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\n#line 2 \"src/template.hpp\"\
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
    \ 3 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n\n#line 2 \"src/DataStructure/union-find.hpp\"\
    \n\n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n\nstruct UnionFind\
    \ {\n    vector<int> par;\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     * @param n \u8981\u7D20\u6570\n     * @note \u6642\u9593\u8A08\
    \u7B97\u91CF: O(n)\n     */\n    UnionFind(int n) {\n        par.assign(n, -1);\n\
    \    };\n    /**\n     * @brief \u9802\u70B9x\u306E\u6839\u3092\u6C42\u3081\u308B\
    \n     * @param x \u9802\u70B9\n     * @return int \u6839\u306E\u9802\u70B9\u756A\
    \u53F7\n     * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n\
    \     *       \u03B1(n)\u306F\u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\u95A2\u6570\u306E\
    \u9006\u95A2\u6570\u3067\u3001\u307B\u307CO(1)\u3068\u8003\u3048\u3066\u826F\u3044\
    \n     */\n    int find(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = find(par[x]);\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\
    \u30BA\u3092\u6C42\u3081\u308B\n     * @param x \u9802\u70B9\n     * @return int\
    \ \u96C6\u5408\u306E\u30B5\u30A4\u30BA\n     * @note \u6642\u9593\u8A08\u7B97\u91CF\
    : \u511F\u5374O(\u03B1(n))\n     */\n    int size(int x) {\n        x = find(x);\n\
    \        return -1 * par[x];\n    }\n    /**\n     * @brief \u9802\u70B9x\u3068\
    \u9802\u70B9y\u304C\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\
    \n     * @param x \u9802\u70B9\n     * @param y \u9802\u70B9\n     * @return bool\
    \ \u4F75\u5408\u306B\u6210\u529F\u3057\u305F\u304B\u3069\u3046\u304B\uFF08\u65E2\
    \u306B\u540C\u3058\u96C6\u5408\u306E\u5834\u5408\u306Ffalse\uFF09\n     * @note\
    \ \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     *       \u5C0F\
    \u3055\u3044\u65B9\u306E\u96C6\u5408\u3092\u5927\u304D\u3044\u65B9\u306B\u4F75\
    \u5408\u3059\u308B\uFF08union by size\uFF09\n     */\n    bool unite(int x, int\
    \ y) {\n        x = find(x);\n        y = find(y);\n        if(x == y)\n     \
    \       return false;\n        if(size(x) < size(y))\n            swap(x, y);\n\
    \        par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \    /**\n     * @brief \u9802\u70B9x\u3068\u9802\u70B9y\u304C\u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n     * @param x \u9802\u70B9\n     * @param y \u9802\u70B9\n     * @return\
    \ bool \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u306A\u3089true\n    \
    \ * @note \u6642\u9593\u8A08\u7B97\u91CF: \u511F\u5374O(\u03B1(n))\n     */\n\
    \    bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n  \
    \  /**\n     * @brief \u5404\u96C6\u5408\u306E\u4EE3\u8868\u5143\uFF08\u6839\uFF09\
    \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\n     * @return vector<int>\
    \ \u4EE3\u8868\u5143\u306E\u30EA\u30B9\u30C8\n     * @note \u6642\u9593\u8A08\u7B97\
    \u91CF: O(n)\n     */\n    vector<int> leaders() {\n        vector<int> res;\n\
    \        for(int i = 0; i < (int)par.size(); i++) {\n            if(par[i] < 0)\n\
    \                res.push_back(i);\n        }\n        return res;\n    }\n};\n\
    #line 5 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    UnionFind uf(n);\n    for(int i = 0; i < q; ++i) {\n\
    \        int com, x, y;\n        cin >> com >> x >> y;\n        if(com == 0)\n\
    \            uf.unite(x, y);\n        else\n            cout << uf.same(x, y)\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\n#include\
    \ \"../../template.hpp\"\n\n#include \"../../DataStructure/union-find.hpp\"\n\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n    for(int\
    \ i = 0; i < q; ++i) {\n        int com, x, y;\n        cin >> com >> x >> y;\n\
    \        if(com == 0)\n            uf.unite(x, y);\n        else\n           \
    \ cout << uf.same(x, y) << '\\n';\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/Util/debug.hpp
  - src/DataStructure/union-find.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-dsl-1-a.test.cpp
  requiredBy: []
  timestamp: '2025-04-01 15:31:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-dsl-1-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-dsl-1-a.test.cpp
- /verify/src/test/verify/aoj-dsl-1-a.test.cpp.html
title: src/test/verify/aoj-dsl-1-a.test.cpp
---
