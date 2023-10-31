#pragma once

#include "../template.hpp"
#include "../Math/modint.hpp"

const uint32_t rhmod1 = 1'000'000'007ll, rhmod2 = 1'000'000'009ll;
using rhmint1 = LazyMontgomeryModInt<rhmod1>;
using rhmint2 = LazyMontgomeryModInt<rhmod2>;

struct Hash{
    rhmint1 hash1;
    rhmint2 hash2;
    int length;
    Hash(rhmint1 h1, rhmint2 h2, int length){
        
    }
}

struct RollingHash {
    vector<rhmint1> hash1, pow1;
    vector<rhmint2> hash2, pow2;
    string s;
    int n;
    const rhmint1 base1 = 1009;
    const rhmint2 base2 = 1007;
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
        rhmint1 h1 = hash1[r] - hash1[l] * pow1[r - l];
        rhmint2 h2 = hash2[r] - hash2[l] * pow2[r - l];
        return Hash(h1.get(), h2.get());
    }
    Hash concat(Hash a, Hash b, int len_b){
        rhmint1 h1a = a.first, h1b = b.first;
        rhmint2 h2a = a.second, h2b = b.second;
        rhmint1 h1 = h1a * pow1[len_b] + h1b;
        rhmint2 h2 = h2a * pow2[len_b] + h2b;
        return Hash(h1.get(), h2.get());
    }
};