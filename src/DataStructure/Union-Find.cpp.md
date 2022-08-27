---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_1_A/judge/3892722/C++14
  bundledCode: "#line 1 \"src/DataStructure/Union-Find.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace std;\nusing i64\
    \ = long long int;\n\nstruct UnionFind{\n    vector<i64> par;\n    UnionFind(i64\
    \ n){\n        par.assign(n, -1);\n    };\n    i64 root(i64 x){\n        if(par[x]\
    \ < 0) return x;\n        else return par[x] = root(par[x]);\n    };\n    i64\
    \ size(i64 x){\n        x = root(x);\n        return -1 * par[x];\n    };\n  \
    \  bool unite(i64 x, i64 y){\n        x = root(x); y = root(y);\n        if(x\
    \ == y) return false;\n        if(size(x) > size(y)) par[y] = x;\n        else\
    \ par[x] = y;\n        return true;\n    }\n    bool same(i64 x, i64 y){\n   \
    \     return root(x) == root(y);\n    };\n};\n\nvoid DSL_1_A(){\n    i64 n, q;\n\
    \    cin >> n >> q;\n    UnionFind uf(n);\n    for(i64 i = 0; i < q; ++i){\n \
    \       i64 com, x, y;\n        cin >> com >> x >> y;\n        if(com == 0) uf.unite(x,\
    \ y);\n        else cout << uf.same(x, y) << endl;\n    }\n}\n\nint main(){\n\
    \    DSL_1_A(); // https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_1_A/judge/3892722/C++14\
    \ */\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n\nusing namespace std;\nusing i64 = long\
    \ long int;\n\nstruct UnionFind{\n    vector<i64> par;\n    UnionFind(i64 n){\n\
    \        par.assign(n, -1);\n    };\n    i64 root(i64 x){\n        if(par[x] <\
    \ 0) return x;\n        else return par[x] = root(par[x]);\n    };\n    i64 size(i64\
    \ x){\n        x = root(x);\n        return -1 * par[x];\n    };\n    bool unite(i64\
    \ x, i64 y){\n        x = root(x); y = root(y);\n        if(x == y) return false;\n\
    \        if(size(x) > size(y)) par[y] = x;\n        else par[x] = y;\n       \
    \ return true;\n    }\n    bool same(i64 x, i64 y){\n        return root(x) ==\
    \ root(y);\n    };\n};\n\nvoid DSL_1_A(){\n    i64 n, q;\n    cin >> n >> q;\n\
    \    UnionFind uf(n);\n    for(i64 i = 0; i < q; ++i){\n        i64 com, x, y;\n\
    \        cin >> com >> x >> y;\n        if(com == 0) uf.unite(x, y);\n       \
    \ else cout << uf.same(x, y) << endl;\n    }\n}\n\nint main(){\n    DSL_1_A();\
    \ // https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_1_A/judge/3892722/C++14\
    \ */\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/Union-Find.cpp
  requiredBy: []
  timestamp: '2022-08-27 18:30:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/Union-Find.cpp
layout: document
redirect_from:
- /library/src/DataStructure/Union-Find.cpp
- /library/src/DataStructure/Union-Find.cpp.html
title: src/DataStructure/Union-Find.cpp
---
