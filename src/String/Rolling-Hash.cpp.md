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
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/ALDS1_14_B/judge/3893675/C++14
  bundledCode: "#line 1 \"src/String/Rolling-Hash.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <string>\n\nusing namespace std;\nusing i64 = long long int;\n\
    using P = pair<i64, i64>;\n\nstruct RollingHash{\n    //\n    // !!!!!\u30D0\u30B0\
    \u304C\u3042\u308A\u307E\u3059!!!!!\n    // Rolling Hash \u69CB\u7BC9O(N)\n  \
    \  // get O(1) S[l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u3092\u8FD4\u3059\n    //\n\
    \    i64 m1 = 1000000007, m2 = 1000000009;\n    i64 b1 = 1009, b2 = 1007;\n  \
    \  vector<i64> h1, h2, p1, p2;\n    RollingHash(string s){\n        i64 n = s.length();\n\
    \        h1.resize(n + 1); h2.resize(n + 1); p1.resize(n + 1); p2.resize(n + 1);\n\
    \        h1[0] = s[0] % m1;\n        h2[0] = s[0] % m2;\n        p1[0] = p2[0]\
    \ = 1;\n        for(int i = 0; i < n; ++i){\n            h1[i + 1] = (h1[i] *\
    \ b1 % m1 + s[i]) % m1;\n            h2[i + 1] = (h2[i] * b2 % m2 + s[i]) % m2;\n\
    \            p1[i + 1] = p1[i] * b1 % m1;\n            p2[i + 1] = p2[i] * b2\
    \ % m2;\n        }\n    };\n    P get(i64 l, i64 r){\n        i64 hash1 = (h1[r]\
    \ + m1 - h1[l] * p1[r - l] % m1) % m1;\n        i64 hash2 = (h2[r] + m2 - h2[l]\
    \ * p2[r - l] % m2) % m2;\n        return P(hash1, hash2);\n    };\n};\n\nvoid\
    \ ALDS1_14_B(){\n    string t, p;\n    cin >> t >> p;\n    if(t.length() < p.length())\
    \ return;\n    RollingHash ht(t), hp(p);\n    for(int i = 0; i + p.length() <=\
    \ t.length(); ++i){\n        if(ht.get(i, i + p.length()) == hp.get(0, p.length()))\
    \ cout << i << endl;\n    }\n}\n\nint main(){\n    /* ALDS1_14_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/ALDS1_14_B/judge/3893675/C++14\
    \ */\n}\n"
  code: "#include <iostream>\n#include <vector>\n#include <string>\n\nusing namespace\
    \ std;\nusing i64 = long long int;\nusing P = pair<i64, i64>;\n\nstruct RollingHash{\n\
    \    //\n    // !!!!!\u30D0\u30B0\u304C\u3042\u308A\u307E\u3059!!!!!\n    // Rolling\
    \ Hash \u69CB\u7BC9O(N)\n    // get O(1) S[l, r) \u306E\u30CF\u30C3\u30B7\u30E5\
    \u3092\u8FD4\u3059\n    //\n    i64 m1 = 1000000007, m2 = 1000000009;\n    i64\
    \ b1 = 1009, b2 = 1007;\n    vector<i64> h1, h2, p1, p2;\n    RollingHash(string\
    \ s){\n        i64 n = s.length();\n        h1.resize(n + 1); h2.resize(n + 1);\
    \ p1.resize(n + 1); p2.resize(n + 1);\n        h1[0] = s[0] % m1;\n        h2[0]\
    \ = s[0] % m2;\n        p1[0] = p2[0] = 1;\n        for(int i = 0; i < n; ++i){\n\
    \            h1[i + 1] = (h1[i] * b1 % m1 + s[i]) % m1;\n            h2[i + 1]\
    \ = (h2[i] * b2 % m2 + s[i]) % m2;\n            p1[i + 1] = p1[i] * b1 % m1;\n\
    \            p2[i + 1] = p2[i] * b2 % m2;\n        }\n    };\n    P get(i64 l,\
    \ i64 r){\n        i64 hash1 = (h1[r] + m1 - h1[l] * p1[r - l] % m1) % m1;\n \
    \       i64 hash2 = (h2[r] + m2 - h2[l] * p2[r - l] % m2) % m2;\n        return\
    \ P(hash1, hash2);\n    };\n};\n\nvoid ALDS1_14_B(){\n    string t, p;\n    cin\
    \ >> t >> p;\n    if(t.length() < p.length()) return;\n    RollingHash ht(t),\
    \ hp(p);\n    for(int i = 0; i + p.length() <= t.length(); ++i){\n        if(ht.get(i,\
    \ i + p.length()) == hp.get(0, p.length())) cout << i << endl;\n    }\n}\n\nint\
    \ main(){\n    /* ALDS1_14_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/ALDS1_14_B/judge/3893675/C++14\
    \ */\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/String/Rolling-Hash.cpp
  requiredBy: []
  timestamp: '2019-09-26 18:16:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/Rolling-Hash.cpp
layout: document
redirect_from:
- /library/src/String/Rolling-Hash.cpp
- /library/src/String/Rolling-Hash.cpp.html
title: src/String/Rolling-Hash.cpp
---
