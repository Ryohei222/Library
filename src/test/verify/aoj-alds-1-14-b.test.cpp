#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#include "../../template.hpp"

#include "../../String/rolling-hash.hpp"

int main() {
    string T, P;
    cin >> T >> P;
    RollingHash rhT(T), rhP(P);
    Hash hashP = rhP.get(0, P.size());
    rep(i, T.size() - P.size() + 1) {
        Hash hashT = rhT.get(i, i + P.size());
        if(hashT == hashP) {
            cout << i << '\n';
        }
    }
}