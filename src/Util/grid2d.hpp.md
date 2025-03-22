---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/test/verify/yuki-697.test.cpp
    title: src/test/verify/yuki-697.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Grid(2D)
    links: []
  bundledCode: "#line 2 \"src/Util/grid2d.hpp\"\n\n/**\n * @brief Grid(2D)\n */\n\n\
    template <typename T>\nstruct Grid2D {\n    int H, W;\n    vector<vector<T>> data;\n\
    \    vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};\n    vector<int> dy = {0, 0,\
    \ 1, -1, 1, -1, -1, 1};\n    Grid2D(int H, int W)\n        : H(H), W(W), data(H,\
    \ vector<T>(W)) {}\n    Grid2D(int H, int W, T x)\n        : H(H), W(W), data(H,\
    \ vector<T>(W, x)) {}\n    Grid2D(const vector<vector<T>> &data)\n        : H(data.size()),\
    \ W(data[0].size()), data(data) {}\n    vector<T> &operator[](int i) {\n     \
    \   return data[i];\n    }\n    void read() {\n        for(int i = 0; i < H; i++)\
    \ {\n            for(int j = 0; j < W; j++) {\n                cin >> data[i][j];\n\
    \            }\n        }\n    }\n    bool in(int i, int j) {\n        return\
    \ 0 <= i && i < H && 0 <= j && j < W;\n    }\n    int encode(int i, int j) {\n\
    \        return i * W + j;\n    }\n    pair<int, int> decode(int x) {\n      \
    \  return make_pair(x / W, x % W);\n    }\n    vector<pair<int, int>> next4(int\
    \ i, int j) {\n        return next(i, j, 4);\n    }\n    vector<pair<int, int>>\
    \ next8(int i, int j) {\n        return next(i, j, 8);\n    }\n\n  private:\n\
    \    vector<pair<int, int>> next(int i, int j, int k) {\n        vector<pair<int,\
    \ int>> res;\n        for(int t = 0; t < k; t++) {\n            int ni = i + dx[t],\
    \ nj = j + dy[t];\n            if(in(ni, nj)) res.push_back(make_pair(ni, nj));\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Grid(2D)\n */\n\ntemplate <typename T>\nstruct\
    \ Grid2D {\n    int H, W;\n    vector<vector<T>> data;\n    vector<int> dx = {1,\
    \ -1, 0, 0, 1, -1, 1, -1};\n    vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};\n\
    \    Grid2D(int H, int W)\n        : H(H), W(W), data(H, vector<T>(W)) {}\n  \
    \  Grid2D(int H, int W, T x)\n        : H(H), W(W), data(H, vector<T>(W, x)) {}\n\
    \    Grid2D(const vector<vector<T>> &data)\n        : H(data.size()), W(data[0].size()),\
    \ data(data) {}\n    vector<T> &operator[](int i) {\n        return data[i];\n\
    \    }\n    void read() {\n        for(int i = 0; i < H; i++) {\n            for(int\
    \ j = 0; j < W; j++) {\n                cin >> data[i][j];\n            }\n  \
    \      }\n    }\n    bool in(int i, int j) {\n        return 0 <= i && i < H &&\
    \ 0 <= j && j < W;\n    }\n    int encode(int i, int j) {\n        return i *\
    \ W + j;\n    }\n    pair<int, int> decode(int x) {\n        return make_pair(x\
    \ / W, x % W);\n    }\n    vector<pair<int, int>> next4(int i, int j) {\n    \
    \    return next(i, j, 4);\n    }\n    vector<pair<int, int>> next8(int i, int\
    \ j) {\n        return next(i, j, 8);\n    }\n\n  private:\n    vector<pair<int,\
    \ int>> next(int i, int j, int k) {\n        vector<pair<int, int>> res;\n   \
    \     for(int t = 0; t < k; t++) {\n            int ni = i + dx[t], nj = j + dy[t];\n\
    \            if(in(ni, nj)) res.push_back(make_pair(ni, nj));\n        }\n   \
    \     return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Util/grid2d.hpp
  requiredBy: []
  timestamp: '2025-03-22 12:22:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/test/verify/yuki-697.test.cpp
documentation_of: src/Util/grid2d.hpp
layout: document
redirect_from:
- /library/src/Util/grid2d.hpp
- /library/src/Util/grid2d.hpp.html
title: Grid(2D)
---
