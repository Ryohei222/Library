#include <iostream>
#include <vector>
#include <string>

using namespace std;
using i64 = long long int;
using P = pair<i64, i64>;

struct RollingHash{
    //
    // !!!!!バグがあります!!!!!
    // Rolling Hash 構築O(N)
    // get O(1) S[l, r) のハッシュを返す
    //
    i64 m1 = 1000000007, m2 = 1000000009;
    i64 b1 = 1009, b2 = 1007;
    vector<i64> h1, h2, p1, p2;
    RollingHash(string s){
        i64 n = s.length();
        h1.resize(n + 1); h2.resize(n + 1); p1.resize(n + 1); p2.resize(n + 1);
        h1[0] = s[0] % m1;
        h2[0] = s[0] % m2;
        p1[0] = p2[0] = 1;
        for(int i = 0; i < n; ++i){
            h1[i + 1] = (h1[i] * b1 % m1 + s[i]) % m1;
            h2[i + 1] = (h2[i] * b2 % m2 + s[i]) % m2;
            p1[i + 1] = p1[i] * b1 % m1;
            p2[i + 1] = p2[i] * b2 % m2;
        }
    };
    P get(i64 l, i64 r){
        i64 hash1 = (h1[r] + m1 - h1[l] * p1[r - l] % m1) % m1;
        i64 hash2 = (h2[r] + m2 - h2[l] * p2[r - l] % m2) % m2;
        return P(hash1, hash2);
    };
};

void ALDS1_14_B(){
    string t, p;
    cin >> t >> p;
    if(t.length() < p.length()) return;
    RollingHash ht(t), hp(p);
    for(int i = 0; i + p.length() <= t.length(); ++i){
        if(ht.get(i, i + p.length()) == hp.get(0, p.length())) cout << i << endl;
    }
}

int main(){
    /* ALDS1_14_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/ALDS1_14_B/judge/3893675/C++14 */
}