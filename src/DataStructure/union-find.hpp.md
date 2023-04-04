---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/aoj-dsl-1-a.test.cpp
    title: src/test/verify/aoj-dsl-1-a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"src/DataStructure/union-find.hpp\"\n\n#line 2 \"src/template.hpp\"\
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
    \  return a < b ? a = b, true : false;\n}\n#line 4 \"src/DataStructure/union-find.hpp\"\
    \n\n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n\nstruct UnionFind\
    \ {\n    vector<int> par;\n    UnionFind(int n) {\n        par.assign(n, -1);\n\
    \    };\n    int root(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = root(par[x]);\n    };\n    int size(int\
    \ x) {\n        x = root(x);\n        return -1 * par[x];\n    };\n    bool unite(int\
    \ x, int y) {\n        x = root(x);\n        y = root(y);\n        if(x == y)\n\
    \            return false;\n        if(size(x) < size(y))\n            swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n    bool same(int x, int y) {\n        return root(x) == root(y);\n  \
    \  };\n};\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\n/**\n * @brief Union-Find\n\
    \ * @docs docs/union-find.md\n */\n\nstruct UnionFind {\n    vector<int> par;\n\
    \    UnionFind(int n) {\n        par.assign(n, -1);\n    };\n    int root(int\
    \ x) {\n        if(par[x] < 0)\n            return x;\n        else\n        \
    \    return par[x] = root(par[x]);\n    };\n    int size(int x) {\n        x =\
    \ root(x);\n        return -1 * par[x];\n    };\n    bool unite(int x, int y)\
    \ {\n        x = root(x);\n        y = root(y);\n        if(x == y)\n        \
    \    return false;\n        if(size(x) < size(y))\n            swap(x, y);\n \
    \       par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \    bool same(int x, int y) {\n        return root(x) == root(y);\n    };\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/DataStructure/union-find.hpp
  requiredBy: []
  timestamp: '2023-04-04 12:45:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/test/verify/aoj-dsl-1-a.test.cpp
documentation_of: src/DataStructure/union-find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/union-find.hpp
- /library/src/DataStructure/union-find.hpp.html
title: Union-Find
---
TODO: かく