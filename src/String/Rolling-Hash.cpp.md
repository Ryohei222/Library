---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/String/Rolling-Hash.cpp\"\nstruct RollingHash {\n  \
    \  ll m1 = 1000000007, ll = 1000000009;\n    ll b1 = 1009, ll = 1007;\n    vector<ll>\
    \ h1, h2, p1, p2;\n    RollingHash(string s) {\n        ll n = s.length();\n \
    \       h1.resize(n + 1);\n        h2.resize(n + 1);\n        p1.resize(n + 1);\n\
    \        p2.resize(n + 1);\n        h1[0] = s[0] % m1;\n        h2[0] = s[0] %\
    \ m2;\n        p1[0] = p2[0] = 1;\n        for(int i = 0; i < n; ++i) {\n    \
    \        h1[i + 1] = (h1[i] * b1 % m1 + s[i]) % m1;\n            h2[i + 1] = (h2[i]\
    \ * b2 % m2 + s[i]) % m2;\n            p1[i + 1] = p1[i] * b1 % m1;\n        \
    \    p2[i + 1] = p2[i] * b2 % m2;\n        }\n    };\n    P get(ll l, ll r) {\n\
    \        ll hash1 = (h1[r] + m1 - h1[l] * p1[r - l] % m1) % m1;\n        ll hash2\
    \ = (h2[r] + m2 - h2[l] * p2[r - l] % m2) % m2;\n        return pair<ll, ll>(hash1,\
    \ hash2);\n    };\n};\n"
  code: "struct RollingHash {\n    ll m1 = 1000000007, ll = 1000000009;\n    ll b1\
    \ = 1009, ll = 1007;\n    vector<ll> h1, h2, p1, p2;\n    RollingHash(string s)\
    \ {\n        ll n = s.length();\n        h1.resize(n + 1);\n        h2.resize(n\
    \ + 1);\n        p1.resize(n + 1);\n        p2.resize(n + 1);\n        h1[0] =\
    \ s[0] % m1;\n        h2[0] = s[0] % m2;\n        p1[0] = p2[0] = 1;\n       \
    \ for(int i = 0; i < n; ++i) {\n            h1[i + 1] = (h1[i] * b1 % m1 + s[i])\
    \ % m1;\n            h2[i + 1] = (h2[i] * b2 % m2 + s[i]) % m2;\n            p1[i\
    \ + 1] = p1[i] * b1 % m1;\n            p2[i + 1] = p2[i] * b2 % m2;\n        }\n\
    \    };\n    P get(ll l, ll r) {\n        ll hash1 = (h1[r] + m1 - h1[l] * p1[r\
    \ - l] % m1) % m1;\n        ll hash2 = (h2[r] + m2 - h2[l] * p2[r - l] % m2) %\
    \ m2;\n        return pair<ll, ll>(hash1, hash2);\n    };\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/Rolling-Hash.cpp
  requiredBy: []
  timestamp: '2023-10-30 05:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/Rolling-Hash.cpp
layout: document
redirect_from:
- /library/src/String/Rolling-Hash.cpp
- /library/src/String/Rolling-Hash.cpp.html
title: src/String/Rolling-Hash.cpp
---
