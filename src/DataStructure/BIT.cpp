#include <iostream>
#include <vector>

using namespace std;
using i64 = long long int;

struct BIT{
    vector<i64> bit;
    i64 n;
    void add(i64 i, i64 x){
        ++i;
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    };
    BIT(i64 sz){
        n = sz;
        bit.assign(n + 1, 0);
    };
    BIT(vector<i64> a){
        n = a.size();
        bit.assign(n + 1, 0);
        for(i64 i = 0; i < a.size(); ++i){
            add(i, a[i]);
        }
    };
    i64 sum(i64 i){
        i64 ret = 0;
        ++i;
        while(i > 0){
            ret += bit[i];
            i -= i & -i;
        }
        return ret;
    };
    i64 sum(i64 l, i64 r){
        if(l == 0) return sum(r - 1);
        else return sum(r - 1) - sum(l - 1);
    };
};

void DSL_2_B(){
    i64 n, q;
    cin >> n >> q;
    BIT bit(n);
    for(i64 i = 0; i < q; ++i){
        i64 com, x, y;
        cin >> com >> x >> y;
        if(com == 0) bit.add(x - 1, y);
        if(com == 1) cout << bit.sum(x - 1, y) << endl;
    }
}

int main(){
    /* DSL_2_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_2_B/judge/3893779/C++14 */
}