#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include "../../template.hpp"
#include "../../Graph/diameter.hpp"

int main(){
    int n;
    cin >> n;
    Graph T(n);
    T.read(n - 1, 0, true);
    auto [d, v1, v2] = diameter(T);
    cout << d << endl;
}