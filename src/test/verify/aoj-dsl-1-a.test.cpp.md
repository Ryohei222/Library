---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/union-find.hpp
    title: Union-Find
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
  bundledCode: "#line 1 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n#line 2 \"src/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing i64 = long long;\n\
    \nstruct IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n\n#define _overload3(_1, _2, _3, name, ...) name\n#define\
    \ _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for(int i = int(a); i < int(b);\
    \ ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n\
    #define all(x) std::begin(x), std::end(x)\n#define uniq(a)   \\\n    sort(all(a));\
    \ \\\n    a.erase(unique(all(a)), end(a))\n#define sum(...) accumulate(all(__VA_ARGS__),\
    \ 0LL)\n\ntemplate <class T>\nauto min(const T& a) {\n    return *min_element(all(a));\n\
    }\ntemplate <class T>\nauto max(const T& a) {\n    return *max_element(all(a));\n\
    }\ntemplate <class T>\nbool chmin(T& a, const T& b) {\n    return a > b ? a =\
    \ b, true : false;\n}\ntemplate <class T>\nbool chmax(T& a, const T& b) {\n  \
    \  return a < b ? a = b, true : false;\n}\n#line 2 \"src/DataStructure/union-find.hpp\"\
    \n\n#line 4 \"src/DataStructure/union-find.hpp\"\n\n/**\n * @brief Union-Find\n\
    \ * @docs docs/union-find.md\n */\n\nstruct UnionFind {\n    vector<int> par;\n\
    \    UnionFind(int n) {\n        par.assign(n, -1);\n    };\n    int root(int\
    \ x) {\n        if(par[x] < 0)\n            return x;\n        else\n        \
    \    return par[x] = root(par[x]);\n    };\n    int size(int x) {\n        x =\
    \ root(x);\n        return -1 * par[x];\n    };\n    bool unite(int x, int y)\
    \ {\n        x = root(x);\n        y = root(y);\n        if(x == y)\n        \
    \    return false;\n        if(size(x) < size(y))\n            swap(x, y);\n \
    \       par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \    bool same(int x, int y) {\n        return root(x) == root(y);\n    };\n};\n\
    #line 4 \"src/test/verify/aoj-dsl-1-a.test.cpp\"\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    UnionFind uf(n);\n    for(int i = 0; i < q; ++i) {\n\
    \        int com, x, y;\n        cin >> com >> x >> y;\n        if(com == 0)\n\
    \            uf.unite(x, y);\n        else\n            cout << uf.same(x, y)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n#include\
    \ \"../../template.hpp\"\n#include \"../../DataStructure/union-find.hpp\"\n\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n    for(int\
    \ i = 0; i < q; ++i) {\n        int com, x, y;\n        cin >> com >> x >> y;\n\
    \        if(com == 0)\n            uf.unite(x, y);\n        else\n           \
    \ cout << uf.same(x, y) << endl;\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/DataStructure/union-find.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-dsl-1-a.test.cpp
  requiredBy: []
  timestamp: '2023-04-04 12:46:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/test/verify/aoj-dsl-1-a.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-dsl-1-a.test.cpp
- /verify/src/test/verify/aoj-dsl-1-a.test.cpp.html
title: src/test/verify/aoj-dsl-1-a.test.cpp
---
