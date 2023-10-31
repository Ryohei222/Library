#line 1 "aoj-alds-1-14-b.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#line 2 "/home/mikunyan/Library/src/template.hpp"

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
#line 2 "/home/mikunyan/Library/src/String/rolling-hash.hpp"

#line 2 "/home/mikunyan/Library/src/Math/modint.hpp"

// 出典: https://nyaannyaan.github.io/library/modint/modint.hpp

template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");
  static_assert(r * mod == 1, "this code has bugs.");

  u32 a;

  constexpr LazyMontgomeryModInt() : a(0) {}
  constexpr LazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static constexpr u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  constexpr mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  constexpr mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
  constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
  constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
  constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
  constexpr bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr mint operator-() const { return mint() - mint(*this); }
  constexpr mint operator+() const { return mint(*this); }

  constexpr mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  constexpr mint inverse() const {
    int x = get(), y = mod, u = 1, v = 0, t = 0, tmp = 0;
    while (y > 0) {
      t = x / y;
      x -= t * y, u -= t * v;
      tmp = x, x = y, y = tmp;
      tmp = u, u = v, v = tmp;
    }
    return mint{u};
  }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }

  constexpr u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static constexpr u32 get_mod() { return mod; }
};
#line 5 "/home/mikunyan/Library/src/String/rolling-hash.hpp"

using Hash = pair<int, int>;

struct RollingHash {
    static const uint32_t mod1 = 1'000'000'007ll, mod2 = 1'000'000'009ll;
    using mint1 = LazyMontgomeryModInt<mod1>;
    using mint2 = LazyMontgomeryModInt<mod2>;
    vector<mint1> hash1, pow1;
    vector<mint2> hash2, pow2;
    string s;
    int n;
    const mint1 base1 = 1009;
    const mint2 base2 = 1007;
    RollingHash(string _s) {
        s = _s;
        build();
    };
    void build(){
        n = (int)s.size();
        hash1.resize(n + 1);
        hash2.resize(n + 1);
        pow1.resize(n + 1);
        pow2.resize(n + 1);
        hash1[0] = mint1(s[0]);
        hash2[0] = mint2(s[0]);
        pow1[0] = 1;
        pow2[0] = 1;
        for(int i = 0; i < n; ++i) {
            hash1[i + 1] = hash1[i] * base1 + mint1(s[i]);
            hash2[i + 1] = hash2[i] * base2 + mint2(s[i]);
            pow1[i + 1] = pow1[i] * base1;
            pow2[i + 1] = pow2[i] * base2;
        }
    }
    Hash get(int l, int r) {
        mint1 h1 = hash1[r] - hash1[l] * pow1[r - l];
        mint2 h2 = hash2[r] - hash2[l] * pow2[r - l];
        return Hash(h1.get(), h2.get());
    }
    Hash concat(Hash a, Hash b, int len_b){
        mint1 h1a = a.first, h1b = b.first;
        mint2 h2a = a.second, h2b = b.second;
        mint1 h1 = h1a * pow1[len_b] + h1b;
        mint2 h2 = h2a * pow2[len_b] + h2b;
        return Hash(h1.get(), h2.get());
    }
};
#line 4 "aoj-alds-1-14-b.test.cpp"

int main(){
    string T, P;
    cin >> T >> P;
    RollingHash rhT(T), rhP(P);
    Hash hashP = rhP.get(0, P.size());
    rep(i, T.size() - P.size() + 1){
        Hash hashT = rhT.get(i, i + P.size());
        if(hashT == hashP){
            cout << i << endl;
        }
    }
}
