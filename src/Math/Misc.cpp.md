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
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_A/judge/3892592/C++14
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_B/judge/3892552/C++14
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_C/judge/3892620/C++14
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_D/judge/3892636/C++14
    - https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_E/judge/3892655/C++14
    - https://qiita.com/drken/items/b97ff231e43bce50199a
  bundledCode: "#line 1 \"src/Math/Misc.cpp\"\n#include <iostream>\n#include <vector>\n\
    #include <map>\n\nusing namespace std;\nusing i64 = long long int;\nusing P =\
    \ pair<i64, i64>;\n\ni64 gcd(i64 a, i64 b){\n    //\n    // Euclidean Algorithm\
    \ (\u304B\u3063\u3053\u3044\u3044) O(logN)\n    // i64 a, b: GCD\u3092\u6C42\u3081\
    \u308B\u6570 a > b \u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\n    //\n    if(a\
    \ % b == 0) return b;\n    else return gcd(b, a % b);\n}\n\ni64 lcm(i64 a, i64\
    \ b){\n    //\n    // a * b / gcd(a, b) O(logN)\n    //\n    return a * b / gcd(a,\
    \ b);\n}\n\ni64 extended_gcd(i64 a, i64 b, i64 &x, i64 &y){\n    //\n    // https://qiita.com/drken/items/b97ff231e43bce50199a\
    \ \u3092\u898B\u305F \u307E\u3060\u7406\u89E3\u3057\u3066\u3044\u306A\u3044\u3093\
    \u3067\u3059\u3051\u3069...\n    // \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
    \u30C9\u306E\u4E92\u9664\u6CD5 ax + by = gcd(a, b) \u3092\u6E80\u305F\u3059(x,\
    \ y)\u3092\u6C42\u3081\u308B O(logN)\n    //\n    if(b == 0){\n        x = 1;\n\
    \        y = 0;\n        return a;\n    }\n    i64 d = extended_gcd(b, a % b,\
    \ y, x);\n    y -= a / b * x;\n    return d;\n}\n\ni64 modpow(i64 x, i64 n){\n\
    \    //\n    // \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 O(logN)\n    // i64\
    \ x, n: x^n mod 1e9+7 \u3092\u6C42\u3081\u308B mod\u306E\u5024\u306E\u5909\u3048\
    \u5FD8\u308C\u306B\u6CE8\u610F(mod\u3092\u6E21\u3059\u3079\u304D?)\n    //\n \
    \   const i64 mod = 1000000007;\n    i64 res = 1;\n    while(n > 0){\n       \
    \ if(n & 1) res = res * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n\
    \    }\n    return res;\n}\n\nmap<i64, i64> prime_factorize(i64 n){\n    // \n\
    \    // \u3072\u305F\u3059\u3089\u5272\u308B\u3084\u3064 O(n^(1/2))\n    // i64\
    \ n : \u7D20\u56E0\u6570\u3092\u6C42\u3081\u308B\u6570\n    // map<i64, i64> \u306F\
    \ range-based for \u3092\u4F7F\u3046\u3068\u697D(C++11~?)\n    //\n    map<i64,\
    \ i64> mp;\n    for(i64 i = 2;  i * i <= n; ++i){\n        while(n % i == 0){\n\
    \            mp[i]++;\n            n /= i;\n        }\n    }\n    if(n != 1) mp[n]\
    \ = 1;\n    return mp;\n}\n\ni64 phi(i64 n){\n    // \n    // \u30AA\u30A4\u30E9\
    \u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570 O(n^(1/2))\n    //\
    \ \u7D20\u56E0\u6570\u3054\u3068\u306B\u6E1B\u3089\u3057\u3066\u3044\u304F\u611F\
    \u3058\n    // prime_factorize \u304C\u5FC5\u8981\n    //\n    map<i64, i64> factors\
    \ = prime_factorize(n);\n    i64 res = n;\n    for(auto f: factors){\n       \
    \ res -= res / f.first;\n    }\n    return res;\n}\n\nvoid NTL_1_A(){\n    i64\
    \ n;\n    cin >> n;\n    auto factors = prime_factorize(n);\n    cout << n <<\
    \ ':';\n    for(auto f : factors){\n        for(int i = 0; i < f.second; ++ i){\n\
    \            cout << ' ' << f.first;\n        }\n    }\n    cout << endl;\n}\n\
    \nvoid NTL_1_B(){\n    i64 m, n;\n    cin >> m >> n;\n    cout << modpow(m, n)\
    \ << endl;\n}\n\nvoid NTL_1_C(){\n    i64 n;\n    cin >> n;\n    vector<i64> a(n);\n\
    \    i64 ans = 1;\n    for(int i = 0; i < n; ++i){\n        cin >> a[i];\n   \
    \     ans = lcm(ans, a[i]);\n    }\n    cout << ans << endl;\n}\n\nvoid NTL_1_D(){\n\
    \    i64 n;\n    cin >> n;\n    cout << phi(n) << endl;\n}\n\nvoid NTL_1_E(){\n\
    \    i64 a, b;\n    cin >> a >> b;\n    i64 x, y;\n    extended_gcd(a, b, x, y);\n\
    \    cout << x << \" \" << y << endl;\n}\n\nint main(){\n    /* NTL_1_A(); /*\
    \ https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_A/judge/3892592/C++14\
    \ */\n    /* NTL_1_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_B/judge/3892552/C++14\
    \ */\n    /* NTL_1_C(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_C/judge/3892620/C++14\
    \ */\n    /* NTL_1_D(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_D/judge/3892636/C++14\
    \ */\n    /* NTL_1_E(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_E/judge/3892655/C++14\
    \ */\n}\n"
  code: "#include <iostream>\n#include <vector>\n#include <map>\n\nusing namespace\
    \ std;\nusing i64 = long long int;\nusing P = pair<i64, i64>;\n\ni64 gcd(i64 a,\
    \ i64 b){\n    //\n    // Euclidean Algorithm (\u304B\u3063\u3053\u3044\u3044\
    ) O(logN)\n    // i64 a, b: GCD\u3092\u6C42\u3081\u308B\u6570 a > b \u3092\u4EEE\
    \u5B9A\u3057\u3066\u3044\u308B\n    //\n    if(a % b == 0) return b;\n    else\
    \ return gcd(b, a % b);\n}\n\ni64 lcm(i64 a, i64 b){\n    //\n    // a * b / gcd(a,\
    \ b) O(logN)\n    //\n    return a * b / gcd(a, b);\n}\n\ni64 extended_gcd(i64\
    \ a, i64 b, i64 &x, i64 &y){\n    //\n    // https://qiita.com/drken/items/b97ff231e43bce50199a\
    \ \u3092\u898B\u305F \u307E\u3060\u7406\u89E3\u3057\u3066\u3044\u306A\u3044\u3093\
    \u3067\u3059\u3051\u3069...\n    // \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
    \u30C9\u306E\u4E92\u9664\u6CD5 ax + by = gcd(a, b) \u3092\u6E80\u305F\u3059(x,\
    \ y)\u3092\u6C42\u3081\u308B O(logN)\n    //\n    if(b == 0){\n        x = 1;\n\
    \        y = 0;\n        return a;\n    }\n    i64 d = extended_gcd(b, a % b,\
    \ y, x);\n    y -= a / b * x;\n    return d;\n}\n\ni64 modpow(i64 x, i64 n){\n\
    \    //\n    // \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 O(logN)\n    // i64\
    \ x, n: x^n mod 1e9+7 \u3092\u6C42\u3081\u308B mod\u306E\u5024\u306E\u5909\u3048\
    \u5FD8\u308C\u306B\u6CE8\u610F(mod\u3092\u6E21\u3059\u3079\u304D?)\n    //\n \
    \   const i64 mod = 1000000007;\n    i64 res = 1;\n    while(n > 0){\n       \
    \ if(n & 1) res = res * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n\
    \    }\n    return res;\n}\n\nmap<i64, i64> prime_factorize(i64 n){\n    // \n\
    \    // \u3072\u305F\u3059\u3089\u5272\u308B\u3084\u3064 O(n^(1/2))\n    // i64\
    \ n : \u7D20\u56E0\u6570\u3092\u6C42\u3081\u308B\u6570\n    // map<i64, i64> \u306F\
    \ range-based for \u3092\u4F7F\u3046\u3068\u697D(C++11~?)\n    //\n    map<i64,\
    \ i64> mp;\n    for(i64 i = 2;  i * i <= n; ++i){\n        while(n % i == 0){\n\
    \            mp[i]++;\n            n /= i;\n        }\n    }\n    if(n != 1) mp[n]\
    \ = 1;\n    return mp;\n}\n\ni64 phi(i64 n){\n    // \n    // \u30AA\u30A4\u30E9\
    \u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570 O(n^(1/2))\n    //\
    \ \u7D20\u56E0\u6570\u3054\u3068\u306B\u6E1B\u3089\u3057\u3066\u3044\u304F\u611F\
    \u3058\n    // prime_factorize \u304C\u5FC5\u8981\n    //\n    map<i64, i64> factors\
    \ = prime_factorize(n);\n    i64 res = n;\n    for(auto f: factors){\n       \
    \ res -= res / f.first;\n    }\n    return res;\n}\n\nvoid NTL_1_A(){\n    i64\
    \ n;\n    cin >> n;\n    auto factors = prime_factorize(n);\n    cout << n <<\
    \ ':';\n    for(auto f : factors){\n        for(int i = 0; i < f.second; ++ i){\n\
    \            cout << ' ' << f.first;\n        }\n    }\n    cout << endl;\n}\n\
    \nvoid NTL_1_B(){\n    i64 m, n;\n    cin >> m >> n;\n    cout << modpow(m, n)\
    \ << endl;\n}\n\nvoid NTL_1_C(){\n    i64 n;\n    cin >> n;\n    vector<i64> a(n);\n\
    \    i64 ans = 1;\n    for(int i = 0; i < n; ++i){\n        cin >> a[i];\n   \
    \     ans = lcm(ans, a[i]);\n    }\n    cout << ans << endl;\n}\n\nvoid NTL_1_D(){\n\
    \    i64 n;\n    cin >> n;\n    cout << phi(n) << endl;\n}\n\nvoid NTL_1_E(){\n\
    \    i64 a, b;\n    cin >> a >> b;\n    i64 x, y;\n    extended_gcd(a, b, x, y);\n\
    \    cout << x << \" \" << y << endl;\n}\n\nint main(){\n    /* NTL_1_A(); /*\
    \ https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_A/judge/3892592/C++14\
    \ */\n    /* NTL_1_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_B/judge/3892552/C++14\
    \ */\n    /* NTL_1_C(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_C/judge/3892620/C++14\
    \ */\n    /* NTL_1_D(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_D/judge/3892636/C++14\
    \ */\n    /* NTL_1_E(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_E/judge/3892655/C++14\
    \ */\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Misc.cpp
  requiredBy: []
  timestamp: '2019-09-26 11:05:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Misc.cpp
layout: document
redirect_from:
- /library/src/Math/Misc.cpp
- /library/src/Math/Misc.cpp.html
title: src/Math/Misc.cpp
---
