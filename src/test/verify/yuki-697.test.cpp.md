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
    path: src/Util/grid2d.hpp
    title: Grid(2D)
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
    PROBLEM: https://yukicoder.me/problems/no/697
    links:
    - https://yukicoder.me/problems/no/697
  bundledCode: "#line 1 \"src/test/verify/yuki-697.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/697\"\n#line 2 \"src/template.hpp\"\n\n/**\n\
    \ * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n// #pragma GCC target(\"\
    avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\n\
    using vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\nusing vp = vector<pl>;\n\
    using vvp = vector<vp>;\nusing vs = vector<string>;\nusing vvs = vector<vs>;\n\
    using vb = vector<bool>;\nusing vvb = vector<vb>;\nusing vvvb = vector<vvb>;\n\
    using vd = vector<double>;\nusing vvd = vector<vd>;\nusing vvvd = vector<vvd>;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for(ll i = ll(a); i < ll(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x),\
    \ std::end(x)\n\nconstexpr ll inf = 0x1fffffffffffffffLL; // 2.3 * 10^18\n\ntemplate\
    \ <class T, class U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class T, class U>\n\
    ostream &operator<<(ostream &os, pair<T, U> &p) {\n    os << p.first << \" \"\
    \ << p.second;\n    return os;\n}\n\ntemplate <class T>\nistream &operator>>(istream\
    \ &is, vector<T> &v) {\n    for(auto &x : v) {\n        is >> x;\n    }\n    return\
    \ is;\n}\n\ntemplate <class T>\nostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n    for(int i = 0; i < (int)v.size(); i++) {\n        if(i != (int)v.size()\
    \ - 1)\n            os << v[i] << \" \";\n        else\n            os << v[i];\n\
    \    }\n    return os;\n}\n\ntemplate <typename T, typename... Args>\nauto vec(T\
    \ x, int arg, Args... args) {\n    if constexpr(sizeof...(args) == 0)\n      \
    \  return vector<T>(arg, x);\n    else\n        return vector(arg, vec<T>(x, args...));\n\
    }\n\ntemplate <class T>\nbool chmin(T &a, const T &b) {\n    return a > b ? a\
    \ = b, true : false;\n}\ntemplate <class T>\nbool chmax(T &a, const T &b) {\n\
    \    return a < b ? a = b, true : false;\n}\n\nconstexpr ll bit(ll x) {\n    return\
    \ 1LL << x;\n}\nconstexpr ll msk(ll x) {\n    return (1LL << x) - 1;\n}\nconstexpr\
    \ bool stand(ll x, int i) {\n    return x & bit(i);\n}\n\nstruct IoSetup {\n \
    \   IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n\n#line 2 \"src/Util/debug.hpp\"\n\n/**\n * @brief Debug\n\
    \ */\n\n#ifdef LOCAL\n#define debug_assert(exp) assert(exp)\n#else\n#define debug_assert(exp)\
    \ true\n#endif\n\n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \"\
    \ << #x << \" = \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n#line\
    \ 3 \"src/test/verify/yuki-697.test.cpp\"\n\n#line 2 \"src/DataStructure/union-find.hpp\"\
    \n\n/**\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n\nstruct UnionFind\
    \ {\n    vector<int> par;\n    UnionFind(int n) {\n        par.assign(n, -1);\n\
    \    };\n    int find(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = find(par[x]);\n    }\n    int size(int\
    \ x) {\n        x = find(x);\n        return -1 * par[x];\n    }\n    bool unite(int\
    \ x, int y) {\n        x = find(x);\n        y = find(y);\n        if(x == y)\n\
    \            return false;\n        if(size(x) < size(y))\n            swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n    bool same(int x, int y) {\n        return find(x) == find(y);\n  \
    \  }\n    vector<int> leaders() {\n        vector<int> res;\n        for(int i\
    \ = 0; i < (int)par.size(); i++) {\n            if(par[i] < 0)\n             \
    \   res.push_back(i);\n        }\n        return res;\n    }\n};\n#line 2 \"src/Util/grid2d.hpp\"\
    \n\n/**\n * @brief Grid(2D)\n */\n\ntemplate <typename T>\nstruct Grid2D {\n \
    \   int H, W;\n    vector<vector<T>> data;\n    vector<int> dx = {1, -1, 0, 0,\
    \ 1, -1, 1, -1};\n    vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};\n    Grid2D(int\
    \ H, int W)\n        : H(H), W(W), data(H, vector<T>(W)) {}\n    Grid2D(int H,\
    \ int W, T x)\n        : H(H), W(W), data(H, vector<T>(W, x)) {}\n    Grid2D(const\
    \ vector<vector<T>> &data)\n        : H(data.size()), W(data[0].size()), data(data)\
    \ {}\n    vector<T> &operator[](int i) {\n        return data[i];\n    }\n   \
    \ void read() {\n        for(int i = 0; i < H; i++) {\n            for(int j =\
    \ 0; j < W; j++) {\n                cin >> data[i][j];\n            }\n      \
    \  }\n    }\n    bool in(int i, int j) {\n        return 0 <= i && i < H && 0\
    \ <= j && j < W;\n    }\n    int encode(int i, int j) {\n        return i * W\
    \ + j;\n    }\n    pair<int, int> decode(int x) {\n        return make_pair(x\
    \ / W, x % W);\n    }\n    vector<pair<int, int>> next4(int i, int j) {\n    \
    \    return next(i, j, 4);\n    }\n    vector<pair<int, int>> next8(int i, int\
    \ j) {\n        return next(i, j, 8);\n    }\n\n  private:\n    vector<pair<int,\
    \ int>> next(int i, int j, int k) {\n        vector<pair<int, int>> res;\n   \
    \     for(int t = 0; t < k; t++) {\n            int ni = i + dx[t], nj = j + dy[t];\n\
    \            if(in(ni, nj)) res.push_back(make_pair(ni, nj));\n        }\n   \
    \     return res;\n    }\n};\n#line 6 \"src/test/verify/yuki-697.test.cpp\"\n\n\
    int main() {\n    ll H, W;\n    cin >> H >> W;\n    Grid2D<int> grid(H, W);\n\
    \    grid.read();\n    UnionFind uf(H * W);\n    for(int i = 0; i < H; i++) {\n\
    \        for(int j = 0; j < W; j++) {\n            for(auto [ni, nj] : grid.next4(i,\
    \ j)) {\n                if(grid[i][j] == grid[ni][nj]) {\n                  \
    \  uf.unite(grid.encode(i, j), grid.encode(ni, nj));\n                }\n    \
    \        }\n        }\n    }\n    ll ans = 0;\n    for(auto i : uf.leaders())\
    \ {\n        auto [nx, ny] = grid.decode(i);\n        if(grid[nx][ny] == 1) ans++;\n\
    \    }\n    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/697\"\n#include \"../../template.hpp\"\
    \n\n#include \"../../DataStructure/union-find.hpp\"\n#include \"../../Util/grid2d.hpp\"\
    \n\nint main() {\n    ll H, W;\n    cin >> H >> W;\n    Grid2D<int> grid(H, W);\n\
    \    grid.read();\n    UnionFind uf(H * W);\n    for(int i = 0; i < H; i++) {\n\
    \        for(int j = 0; j < W; j++) {\n            for(auto [ni, nj] : grid.next4(i,\
    \ j)) {\n                if(grid[i][j] == grid[ni][nj]) {\n                  \
    \  uf.unite(grid.encode(i, j), grid.encode(ni, nj));\n                }\n    \
    \        }\n        }\n    }\n    ll ans = 0;\n    for(auto i : uf.leaders())\
    \ {\n        auto [nx, ny] = grid.decode(i);\n        if(grid[nx][ny] == 1) ans++;\n\
    \    }\n    cout << ans << '\\n';\n}"
  dependsOn:
  - src/template.hpp
  - src/Util/debug.hpp
  - src/DataStructure/union-find.hpp
  - src/Util/grid2d.hpp
  isVerificationFile: true
  path: src/test/verify/yuki-697.test.cpp
  requiredBy: []
  timestamp: '2025-03-30 10:22:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/yuki-697.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/yuki-697.test.cpp
- /verify/src/test/verify/yuki-697.test.cpp.html
title: src/test/verify/yuki-697.test.cpp
---
