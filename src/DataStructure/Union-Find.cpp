#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"

#include <iostream>
#include <vector>

using namespace std;
using i64 = long long int;

struct UnionFind{
    vector<i64> par;
    UnionFind(i64 n){
        par.assign(n, -1);
    };
    i64 root(i64 x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    };
    i64 size(i64 x){
        x = root(x);
        return -1 * par[x];
    };
    bool unite(i64 x, i64 y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(size(x) > size(y)) par[y] = x;
        else par[x] = y;
        return true;
    }
    bool same(i64 x, i64 y){
        return root(x) == root(y);
    };
};

void DSL_1_A(){
    i64 n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for(i64 i = 0; i < q; ++i){
        i64 com, x, y;
        cin >> com >> x >> y;
        if(com == 0) uf.unite(x, y);
        else cout << uf.same(x, y) << endl;
    }
}

int main(){
    DSL_1_A(); // https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_1_A/judge/3892722/C++14 */
}