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
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_2_B/judge/3893779/C++14
  bundledCode: "#line 1 \"src/DataStructure/BIT.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n\nusing namespace std;\nusing i64 = long long int;\n\nstruct BIT{\n\
    \    vector<i64> bit;\n    i64 n;\n    void add(i64 i, i64 x){\n        ++i;\n\
    \        while(i <= n){\n            bit[i] += x;\n            i += i & -i;\n\
    \        }\n    };\n    BIT(i64 sz){\n        n = sz;\n        bit.assign(n +\
    \ 1, 0);\n    };\n    BIT(vector<i64> a){\n        n = a.size();\n        bit.assign(n\
    \ + 1, 0);\n        for(i64 i = 0; i < a.size(); ++i){\n            add(i, a[i]);\n\
    \        }\n    };\n    i64 sum(i64 i){\n        i64 ret = 0;\n        ++i;\n\
    \        while(i > 0){\n            ret += bit[i];\n            i -= i & -i;\n\
    \        }\n        return ret;\n    };\n    i64 sum(i64 l, i64 r){\n        if(l\
    \ == 0) return sum(r - 1);\n        else return sum(r - 1) - sum(l - 1);\n   \
    \ };\n};\n\nvoid DSL_2_B(){\n    i64 n, q;\n    cin >> n >> q;\n    BIT bit(n);\n\
    \    for(i64 i = 0; i < q; ++i){\n        i64 com, x, y;\n        cin >> com >>\
    \ x >> y;\n        if(com == 0) bit.add(x - 1, y);\n        if(com == 1) cout\
    \ << bit.sum(x - 1, y) << endl;\n    }\n}\n\nint main(){\n    /* DSL_2_B(); /*\
    \ https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_2_B/judge/3893779/C++14\
    \ */\n}\n"
  code: "#include <iostream>\n#include <vector>\n\nusing namespace std;\nusing i64\
    \ = long long int;\n\nstruct BIT{\n    vector<i64> bit;\n    i64 n;\n    void\
    \ add(i64 i, i64 x){\n        ++i;\n        while(i <= n){\n            bit[i]\
    \ += x;\n            i += i & -i;\n        }\n    };\n    BIT(i64 sz){\n     \
    \   n = sz;\n        bit.assign(n + 1, 0);\n    };\n    BIT(vector<i64> a){\n\
    \        n = a.size();\n        bit.assign(n + 1, 0);\n        for(i64 i = 0;\
    \ i < a.size(); ++i){\n            add(i, a[i]);\n        }\n    };\n    i64 sum(i64\
    \ i){\n        i64 ret = 0;\n        ++i;\n        while(i > 0){\n           \
    \ ret += bit[i];\n            i -= i & -i;\n        }\n        return ret;\n \
    \   };\n    i64 sum(i64 l, i64 r){\n        if(l == 0) return sum(r - 1);\n  \
    \      else return sum(r - 1) - sum(l - 1);\n    };\n};\n\nvoid DSL_2_B(){\n \
    \   i64 n, q;\n    cin >> n >> q;\n    BIT bit(n);\n    for(i64 i = 0; i < q;\
    \ ++i){\n        i64 com, x, y;\n        cin >> com >> x >> y;\n        if(com\
    \ == 0) bit.add(x - 1, y);\n        if(com == 1) cout << bit.sum(x - 1, y) <<\
    \ endl;\n    }\n}\n\nint main(){\n    /* DSL_2_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_2_B/judge/3893779/C++14\
    \ */\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BIT.cpp
  requiredBy: []
  timestamp: '2019-09-26 19:13:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/BIT.cpp
layout: document
redirect_from:
- /library/src/DataStructure/BIT.cpp
- /library/src/DataStructure/BIT.cpp.html
title: src/DataStructure/BIT.cpp
---
