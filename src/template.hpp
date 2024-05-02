#pragma once

/**
 * @brief テンプレート
 * @docs docs/template.md
 */

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using pl = pair<ll, ll>;
using vp = vector<pl>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(ll i = ll(a); i < ll(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) std::begin(x), std::end(x)
#define make_unique(v) v.erase(unique(all(v)), v.end());

constexpr ll inf = 0x1fffffffffffffffLL; // 2.3 * 10^18

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for(auto &x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int)v.size(); i++) {
        if(i != (int)v.size() - 1)
            os << v[i] << " ";
        else
            os << v[i];
    }
    return os;
}

template <typename T, typename... Args>
auto vec(T x, int arg, Args... args) {
    if constexpr(sizeof...(args) == 0)
        return vector<T>(arg, x);
    else
        return vector(arg, vec<T>(x, args...));
}

template <class T>
bool chmin(T &a, const T &b) {
    return a > b ? a = b, true : false;
}
template <class T>
bool chmax(T &a, const T &b) {
    return a < b ? a = b, true : false;
}

constexpr ll bit(ll x) {
    return 1LL << x;
}
constexpr ll msk(ll x) {
    return (1LL << x) - 1;
}
constexpr bool stand(ll x, int i) {
    return x & bit(i);
}

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;