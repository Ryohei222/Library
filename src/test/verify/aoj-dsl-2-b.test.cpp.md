---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/fenwick-tree.hpp
    title: Fenwick tree
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
  bundledCode: "#line 1 \"src/test/verify/aoj-dsl-2-b.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#line 2 \"src/template.hpp\"\
    \n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template.md\n\
    \ */\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pl = pair<ll, ll>;\n#define vl vector<ll>\n#define vvl vector<vector<ll>>\n\
    #define vvvl vector<vector<vector<ll>>>\n#define vm vector<mint>\n#define vvm\
    \ vector<vector<mint>>\n#define vvvm vector<vector<vector<mint>>>\n#define vp\
    \ vector<pl>\n#define vvp vector<vector<pl>>\n#define vs vector<string>\n#define\
    \ vvs vector<vector<string>>\n\n#define _overload3(_1, _2, _3, name, ...) name\n\
    #define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a); i\
    \ < int(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n#define make_unique(v) v.erase(unique(all(v)),\
    \ v.end());\n#define sum(...) accumulate(all(__VA_ARGS__), 0LL)\n#define inf (0x1fffffffffffffff)\n\
    \ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& v) {\n    for(auto&\
    \ x : v) {\n        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\n\
    ostream& operator<<(ostream& os, const vector<T>& v) {\n    for(int i = 0; i <\
    \ (int)v.size(); i++) {\n        if(i != (int)v.size() - 1)\n            os <<\
    \ v[i] << \" \";\n        else\n            os << v[i];\n    }\n    return os;\n\
    }\n\ntemplate <typename T, typename... Args>\nauto make_v(T x, int arg, Args...\
    \ args) {\n    if constexpr(sizeof...(args) == 0)\n        return vector<T>(arg,\
    \ x);\n    else\n        return vector(arg, make_v<T>(x, args...));\n}\n\ntemplate\
    \ <class T>\nauto min(const T& a) {\n    return *min_element(all(a));\n}\n\ntemplate\
    \ <class T>\nauto max(const T& a) {\n    return *max_element(all(a));\n}\n\ntemplate\
    \ <class T>\nbool chmin(T& a, const T& b) {\n    return a > b ? a = b, true :\
    \ false;\n}\n\ntemplate <class T>\nbool chmax(T& a, const T& b) {\n    return\
    \ a < b ? a = b, true : false;\n}\n\nstruct IoSetup {\n    IoSetup() {\n     \
    \   cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout << fixed\
    \ << setprecision(10);\n        cerr << fixed << setprecision(10);\n    }\n} iosetup;\n\
    #line 2 \"src/DataStructure/fenwick-tree.hpp\"\n\n/**\n * @brief Fenwick tree\n\
    \ * @docs docs/fenwick-tree.md\n */\n\ntemplate<typename T = long long int>\n\
    struct FenwickTree{\n    int n;\n    vector<T> bit;\n    FenwickTree(int n) :\
    \ n(n) {\n        bit.assign(n + 1, T(0));\n    };\n    FenwickTree(const vector<T>\
    \ &a){\n        n = (int)a.size();\n        bit.assign(n + 1, T(0));\n       \
    \ for(int i = 0; i < n; ++i){\n            apply(i, a[i]);\n        }\n    };\n\
    \    void apply(int idx, T x){\n        ++idx;\n        while(idx <= n){\n   \
    \         bit[idx] += x;\n            idx += idx & -idx;\n        }\n    };\n\
    \    T prod(int r){\n        T ret = T(0);\n        ++r;\n        while(r > 0){\n\
    \            ret += bit[r];\n            r -= r & -r;\n        }\n        return\
    \ ret;\n    };\n    T prod(int l, int r){\n        if(l == 0) return prod(r -\
    \ 1);\n        else return prod(r - 1) - prod(l - 1);\n    };\n};\n#line 4 \"\
    src/test/verify/aoj-dsl-2-b.test.cpp\"\n\nint main(){\n    ll n, q;\n    cin >>\
    \ n >> q;\n    FenwickTree bit(n);\n    rep(i, q){\n        ll com, x, y;\n  \
    \      cin >> com >> x >> y;\n        if(com == 0) bit.apply(x - 1, y);\n    \
    \    if(com == 1) cout << bit.prod(x - 1, y) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#include\
    \ \"../../template.hpp\"\n#include \"../../DataStructure/fenwick-tree.hpp\"\n\n\
    int main(){\n    ll n, q;\n    cin >> n >> q;\n    FenwickTree bit(n);\n    rep(i,\
    \ q){\n        ll com, x, y;\n        cin >> com >> x >> y;\n        if(com ==\
    \ 0) bit.apply(x - 1, y);\n        if(com == 1) cout << bit.prod(x - 1, y) <<\
    \ endl;\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/DataStructure/fenwick-tree.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-dsl-2-b.test.cpp
  requiredBy: []
  timestamp: '2023-11-02 05:34:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-dsl-2-b.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-dsl-2-b.test.cpp
- /verify/src/test/verify/aoj-dsl-2-b.test.cpp.html
title: src/test/verify/aoj-dsl-2-b.test.cpp
---
