#pragma once

/**
 * @brief Rolling Hash
 * @docs docs/rolling-hash.md
 */

#include "../Math/modint.hpp"

const uint32_t rhmod1 = 1'000'000'007ll, rhmod2 = 1'000'000'009ll;
using rhmint1 = LazyMontgomeryModInt<rhmod1>;
using rhmint2 = LazyMontgomeryModInt<rhmod2>;

struct Hash{
    rhmint1 hash1;
    rhmint2 hash2;
    int length;
    Hash(rhmint1 h1, rhmint2 h2, int length): hash1(h1), hash2(h2), length(length) {}
    constexpr bool operator==(const Hash &b){
        return hash1 == b.hash1 && hash2 == b.hash2;
    }
    constexpr bool operator!=(const Hash &b){
        return hash1 != b.hash1 || hash2 != b.hash2;
    }
};

struct RollingHash {
    static rhmint1 base1;
    static rhmint2 base2;
    vector<rhmint1> hash1, pow1;
    vector<rhmint2> hash2, pow2;
    string s;
    int n;
    RollingHash(string _s) {
        s = _s;
        if(base1 == 0) generate_base();
        build();
    };
    void build(){
        n = (int)s.size();
        hash1.resize(n + 1);
        hash2.resize(n + 1);
        pow1.resize(n + 1);
        pow2.resize(n + 1);
        hash1[0] = rhmint1(s[0]);
        hash2[0] = rhmint2(s[0]);
        pow1[0] = 1;
        pow2[0] = 1;
        for(int i = 0; i < n; ++i) {
            hash1[i + 1] = hash1[i] * base1 + rhmint1(s[i]);
            hash2[i + 1] = hash2[i] * base2 + rhmint2(s[i]);
            pow1[i + 1] = pow1[i] * base1;
            pow2[i + 1] = pow2[i] * base2;
        }
    }
    // 参考: https://ei1333.github.io/library/string/rolling-hash.hpp
    static void generate_base() {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution< uint64_t > rand1(1, rhmod1 - 1);
        uniform_int_distribution< uint64_t > rand2(1, rhmod2 - 1);
        base1 = rhmint1(rand1(mt));
        base2 = rhmint2(rand2(mt));
    }
    Hash get(int l, int r) {
        rhmint1 h1 = hash1[r] - hash1[l] * pow1[r - l];
        rhmint2 h2 = hash2[r] - hash2[l] * pow2[r - l];
        return Hash(h1, h2, r - l);
    }
    Hash concat(Hash a, Hash b){
        rhmint1 h1a = a.hash1, h1b = b.hash1;
        rhmint2 h2a = a.hash2, h2b = b.hash2;
        rhmint1 h1 = h1a * pow1[b.length] + h1b;
        rhmint2 h2 = h2a * pow2[b.length] + h2b;
        return Hash(h1, h2, a.length + b.length);
    }
};

rhmint1 RollingHash::base1 = 0;
rhmint2 RollingHash::base2 = 0;