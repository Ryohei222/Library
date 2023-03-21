#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) std::begin(x), std::end(x)
#define uniq(a)   \
    sort(all(a)); \
    a.erase(unique(all(a)), end(a))
#define sum(...) accumulate(all(__VA_ARGS__), 0LL)

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