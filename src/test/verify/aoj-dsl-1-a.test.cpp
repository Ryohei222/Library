#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"
#include "../../template.hpp"
#include "../../DataStructure/union-find.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for(int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0)
            uf.unite(x, y);
        else
            cout << uf.same(x, y) << endl;
    }
}