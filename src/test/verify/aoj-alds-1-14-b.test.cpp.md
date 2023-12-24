---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: src/String/rolling-hash.hpp
    title: Rolling Hash
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"src/test/verify/aoj-alds-1-14-b.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n#line 2 \"src/template.hpp\"\
    \n\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template.md\n\
    \ */\n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\n\
    using vvvl = vector<vvl>;\nusing pl = pair<ll, ll>;\nusing vp = vector<pl>;\n\
    using vvp = vector<vp>;\nusing vs = vector<string>;\nusing vvs = vector<vs>;\n\
    using vb = vector<bool>;\nusing vvb = vector<vb>;\nusing vvvb = vector<vvb>;\n\
    using vd = vector<double>;\nusing vvd = vector<vd>;\nusing vvvd = vector<vvd>;\n\
    \n#define _overload3(_1, _2, _3, name, ...) name\n#define _rep(i, n) repi(i, 0,\
    \ n)\n#define repi(i, a, b) for(ll i = ll(a); i < ll(b); ++i)\n#define rep(...)\
    \ _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)\n#define all(x) std::begin(x),\
    \ std::end(x)\n#define make_unique(v) v.erase(unique(all(v)), v.end());\n#define\
    \ sum(...) accumulate(all(__VA_ARGS__), 0LL)\n\nconstexpr ll inf = 0x1fffffffffffffffLL;\n\
    \ntemplate <class T1, class T2> void input(vector<T1> &v1, vector<T2> &v2){ rep(i,\
    \ v1.size()) cin >> v1[i] >> v2[i]; }\ntemplate <class T1, class T2, class T3>\
    \ void input(vector<T1> &v1, vector<T2> &v2, vector<T3> &v3) { rep(i, v1.size())\
    \ cin >> v1[i] >> v2[i] >> v3[i]; }\ntemplate <class T1, class T2, class T3, class\
    \ T4> void input(vector<T1> &v1, vector<T2> &v2, vector<T3> &v3, vector<T4> &v4)\
    \ { rep(i, v1.size()) cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; }\n\ntemplate <class\
    \ T> istream &operator>>(istream &is, vector<T> &v) {\n    for(auto &x : v) {\n\
    \        is >> x;\n    }\n    return is;\n}\n\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n    for(int i = 0; i < (int)v.size(); i++) {\n \
    \       if(i != (int)v.size() - 1)\n            os << v[i] << \" \";\n       \
    \ else\n            os << v[i];\n    }\n    return os;\n}\n\ntemplate <class T,\
    \ class U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n    is >> p.first\
    \ >> p.second;\n    return is;\n}\n\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return os;\n\
    }\n\ntemplate <typename T, typename... Args>\nauto vec(T x, int arg, Args... args)\
    \ {\n    if constexpr(sizeof...(args) == 0)\n        return vector<T>(arg, x);\n\
    \    else\n        return vector(arg, vec<T>(x, args...));\n}\n\ntemplate <class\
    \ T> auto min(const T &a) { return *min_element(all(a)); }\ntemplate <class T>\
    \ auto max(const T &a) { return *max_element(all(a)); }\ntemplate <class T> bool\
    \ chmin(T &a, const T &b) { return a > b ? a = b, true : false; }\ntemplate <class\
    \ T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }\n\n\
    constexpr ll bit(ll x){ return 1LL << x; }\nconstexpr ll msk(ll x){ return (1LL\
    \ << x) - 1;}\nconstexpr bool stand(ll x, int i) { return x & bit(i); }\n\nstruct\
    \ IoSetup {\n    IoSetup() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(10);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\n#line 2 \"src/String/rolling-hash.hpp\"\n\n/**\n * @brief\
    \ Rolling Hash\n * @docs docs/rolling-hash.md\n */\n\n#line 2 \"src/Math/modint.hpp\"\
    \n\n/**\n * @brief Modint\n * @cite https://nyaannyaan.github.io/library/modint/modint.hpp\n\
    \ */\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n    using mint\
    \ = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = mod;\n        for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    \
    \    return ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr\
    \ u32 n2 = -u64(mod) % mod;\n    static_assert(mod < (1 << 30), \"invalid, mod\
    \ >= 2 ^ 30\");\n    static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\
    \    static_assert(r * mod == 1, \"this code has bugs.\");\n\n    u32 a;\n\n \
    \   constexpr LazyMontgomeryModInt() : a(0) {}\n    constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n            : a(reduce(u64(b % mod + mod) * n2)){};\n\n    static\
    \ constexpr u32 reduce(const u64 &b) {\n        return (b + u64(u32(b) * u32(-r))\
    \ * mod) >> 32;\n    }\n\n    constexpr mint &operator+=(const mint &b) {\n  \
    \      if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n        return *this;\n\
    \    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if (i32(a -=\
    \ b.a) < 0) a += 2 * mod;\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator*=(const mint &b) {\n        a = reduce(u64(a) * b.a);\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n        *this\
    \ *= b.inverse();\n        return *this;\n    }\n\n    constexpr mint operator+(const\
    \ mint &b) const { return mint(*this) += b; }\n    constexpr mint operator-(const\
    \ mint &b) const { return mint(*this) -= b; }\n    constexpr mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n    constexpr mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n    constexpr bool operator==(const\
    \ mint &b) const {\n        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a\
    \ - mod : b.a);\n    }\n    constexpr bool operator!=(const mint &b) const {\n\
    \        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n\
    \    }\n    constexpr mint operator-() const { return mint() - mint(*this); }\n\
    \    constexpr mint operator+() const { return mint(*this); }\n\n    constexpr\
    \ mint pow(u64 n) const {\n        mint ret(1), mul(*this);\n        while (n\
    \ > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n      \
    \      n >>= 1;\n        }\n        return ret;\n    }\n\n    constexpr mint inverse()\
    \ const {\n        int x = get(), y = mod, u = 1, v = 0, t = 0, tmp = 0;\n   \
    \     while (y > 0) {\n            t = x / y;\n            x -= t * y, u -= t\
    \ * v;\n            tmp = x, x = y, y = tmp;\n            tmp = u, u = v, v =\
    \ tmp;\n        }\n        return mint{u};\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n        return os << b.get();\n    }\n\n    friend istream\
    \ &operator>>(istream &is, mint &b) {\n        int64_t t;\n        is >> t;\n\
    \        b = LazyMontgomeryModInt<mod>(t);\n        return (is);\n    }\n\n  \
    \  constexpr u32 get() const {\n        u32 ret = reduce(a);\n        return ret\
    \ >= mod ? ret - mod : ret;\n    }\n\n    static constexpr u32 get_mod() { return\
    \ mod; }\n};\n\n// constexpr long long mod = 1000000007;\nconstexpr long long\
    \ mod = 998244353;\nusing mint = LazyMontgomeryModInt<mod>;\nusing vm = vector<mint>;\n\
    using vvm = vector<vm>;\nusing vvvm = vector<vvm>;\n#line 9 \"src/String/rolling-hash.hpp\"\
    \n\nconst uint32_t rhmod1 = 1'000'000'007ll, rhmod2 = 1'000'000'009ll;\nusing\
    \ rhmint1 = LazyMontgomeryModInt<rhmod1>;\nusing rhmint2 = LazyMontgomeryModInt<rhmod2>;\n\
    \nstruct Hash{\n    rhmint1 hash1;\n    rhmint2 hash2;\n    int length;\n    Hash(rhmint1\
    \ h1, rhmint2 h2, int length): hash1(h1), hash2(h2), length(length) {}\n    constexpr\
    \ bool operator==(const Hash &b){\n        return hash1 == b.hash1 && hash2 ==\
    \ b.hash2;\n    }\n    constexpr bool operator!=(const Hash &b){\n        return\
    \ hash1 != b.hash1 || hash2 != b.hash2;\n    }\n};\n\nstruct RollingHash {\n \
    \   static rhmint1 base1;\n    static rhmint2 base2;\n    vector<rhmint1> hash1,\
    \ pow1;\n    vector<rhmint2> hash2, pow2;\n    string s;\n    int n;\n    RollingHash(string\
    \ _s) {\n        s = _s;\n        if(base1 == 0) generate_base();\n        build();\n\
    \    }\n    void build(){\n        n = (int)s.size();\n        hash1.resize(n\
    \ + 1);\n        hash2.resize(n + 1);\n        pow1.resize(n + 1);\n        pow2.resize(n\
    \ + 1);\n        hash1[0] = rhmint1(s[0]);\n        hash2[0] = rhmint2(s[0]);\n\
    \        pow1[0] = 1;\n        pow2[0] = 1;\n        for(int i = 0; i < n; ++i)\
    \ {\n            hash1[i + 1] = hash1[i] * base1 + rhmint1(s[i]);\n          \
    \  hash2[i + 1] = hash2[i] * base2 + rhmint2(s[i]);\n            pow1[i + 1] =\
    \ pow1[i] * base1;\n            pow2[i + 1] = pow2[i] * base2;\n        }\n  \
    \  }\n    // \u53C2\u8003: https://ei1333.github.io/library/string/rolling-hash.hpp\n\
    \    static void generate_base() {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution< uint64_t > rand1(1, rhmod1 - 1);\n        uniform_int_distribution<\
    \ uint64_t > rand2(1, rhmod2 - 1);\n        base1 = rhmint1(rand1(mt));\n    \
    \    base2 = rhmint2(rand2(mt));\n    }\n    Hash get(int l, int r) {\n      \
    \  rhmint1 h1 = hash1[r] - hash1[l] * pow1[r - l];\n        rhmint2 h2 = hash2[r]\
    \ - hash2[l] * pow2[r - l];\n        return Hash(h1, h2, r - l);\n    }\n    Hash\
    \ concat(Hash a, Hash b){\n        rhmint1 h1a = a.hash1, h1b = b.hash1;\n   \
    \     rhmint2 h2a = a.hash2, h2b = b.hash2;\n        rhmint1 h1 = h1a * pow1[b.length]\
    \ + h1b;\n        rhmint2 h2 = h2a * pow2[b.length] + h2b;\n        return Hash(h1,\
    \ h2, a.length + b.length);\n    }\n};\n\nrhmint1 RollingHash::base1 = 0;\nrhmint2\
    \ RollingHash::base2 = 0;\n#line 4 \"src/test/verify/aoj-alds-1-14-b.test.cpp\"\
    \n\nint main(){\n    string T, P;\n    cin >> T >> P;\n    RollingHash rhT(T),\
    \ rhP(P);\n    Hash hashP = rhP.get(0, P.size());\n    rep(i, T.size() - P.size()\
    \ + 1){\n        Hash hashT = rhT.get(i, i + P.size());\n        if(hashT == hashP){\n\
    \            cout << i << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    #include \"../../template.hpp\"\n#include \"../../String/rolling-hash.hpp\"\n\n\
    int main(){\n    string T, P;\n    cin >> T >> P;\n    RollingHash rhT(T), rhP(P);\n\
    \    Hash hashP = rhP.get(0, P.size());\n    rep(i, T.size() - P.size() + 1){\n\
    \        Hash hashT = rhT.get(i, i + P.size());\n        if(hashT == hashP){\n\
    \            cout << i << endl;\n        }\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/String/rolling-hash.hpp
  - src/Math/modint.hpp
  isVerificationFile: true
  path: src/test/verify/aoj-alds-1-14-b.test.cpp
  requiredBy: []
  timestamp: '2023-12-18 22:27:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/test/verify/aoj-alds-1-14-b.test.cpp
layout: document
redirect_from:
- /verify/src/test/verify/aoj-alds-1-14-b.test.cpp
- /verify/src/test/verify/aoj-alds-1-14-b.test.cpp.html
title: src/test/verify/aoj-alds-1-14-b.test.cpp
---
