#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../template.hpp"
#include "../../DataStructure/cumulative-sum.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vl a(N);
    cin >> a;
    CumulativeSum cs(a);
    while(Q--) {
        int l, r;
        cin >> l >> r;
        cout << cs.sum(l, r) << endl;
    }
}