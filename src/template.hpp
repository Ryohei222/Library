#pragma once

/**
 * @brief テンプレート
 * @docs docs/template.md
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define vm vector<mint>
#define vvm vector<vector<mint>>
#define vvvm vector<vector<vector<mint>>>
#define vp vector<pl>
#define vvp vector<vector<pl>>
#define vs vector<string>
#define vvs vector<vector<string>>

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) std::begin(x), std::end(x)
#define make_unique(v) v.erase(unique(all(v)), v.end());
#define sum(...) accumulate(all(__VA_ARGS__), 0LL)
#define inf (0x1fffffffffffffff)

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(int i = 0; i < (int)v.size(); i++) {
        if(i != (int)v.size() - 1)
            os << v[i] << " ";
        else
            os << v[i];
    }
    return os;
}

template <typename T, typename... Args>
auto make_v(T x, int arg, Args... args) {
    if constexpr(sizeof...(args) == 0)
        return vector<T>(arg, x);
    else
        return vector(arg, make_v<T>(x, args...));
}

template <class T>
auto min(const T& a) {
    return *min_element(all(a));
}

template <class T>
auto max(const T& a) {
    return *max_element(all(a));
}

template <class T>
bool chmin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}

template <class T>
bool chmax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;