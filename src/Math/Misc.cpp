#include <iostream>
#include <vector>
#include <map>

using namespace std;
using i64 = long long int;
using P = pair<i64, i64>;

i64 gcd(i64 a, i64 b){
    //
    // Euclidean Algorithm (かっこいい) O(logN)
    // i64 a, b: GCDを求める数 a > b を仮定している
    //
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

i64 lcm(i64 a, i64 b){
    //
    // a * b / gcd(a, b) O(logN)
    //
    return a * b / gcd(a, b);
}

i64 extended_gcd(i64 a, i64 b, i64 &x, i64 &y){
    //
    // https://qiita.com/drken/items/b97ff231e43bce50199a を見た まだ理解していないんですけど...
    // 拡張ユークリッドの互除法 ax + by = gcd(a, b) を満たす(x, y)を求める O(logN)
    //
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    i64 d = extended_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

i64 modpow(i64 x, i64 n){
    //
    // 繰り返し二乗法 O(logN)
    // i64 x, n: x^n mod 1e9+7 を求める modの値の変え忘れに注意(modを渡すべき?)
    //
    const i64 mod = 1000000007;
    i64 res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

map<i64, i64> prime_factorize(i64 n){
    // 
    // ひたすら割るやつ O(n^(1/2))
    // i64 n : 素因数を求める数
    // map<i64, i64> は range-based for を使うと楽(C++11~?)
    //
    map<i64, i64> mp;
    for(i64 i = 2;  i * i <= n; ++i){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if(n != 1) mp[n] = 1;
    return mp;
}

i64 phi(i64 n){
    // 
    // オイラーのトーシェント関数 O(n^(1/2))
    // 素因数ごとに減らしていく感じ
    // prime_factorize が必要
    //
    map<i64, i64> factors = prime_factorize(n);
    i64 res = n;
    for(auto f: factors){
        res -= res / f.first;
    }
    return res;
}

void NTL_1_A(){
    i64 n;
    cin >> n;
    auto factors = prime_factorize(n);
    cout << n << ':';
    for(auto f : factors){
        for(int i = 0; i < f.second; ++ i){
            cout << ' ' << f.first;
        }
    }
    cout << endl;
}

void NTL_1_B(){
    i64 m, n;
    cin >> m >> n;
    cout << modpow(m, n) << endl;
}

void NTL_1_C(){
    i64 n;
    cin >> n;
    vector<i64> a(n);
    i64 ans = 1;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ans = lcm(ans, a[i]);
    }
    cout << ans << endl;
}

void NTL_1_D(){
    i64 n;
    cin >> n;
    cout << phi(n) << endl;
}

void NTL_1_E(){
    i64 a, b;
    cin >> a >> b;
    i64 x, y;
    extended_gcd(a, b, x, y);
    cout << x << " " << y << endl;
}

int main(){
    /* NTL_1_A(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_A/judge/3892592/C++14 */
    /* NTL_1_B(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_B/judge/3892552/C++14 */
    /* NTL_1_C(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_C/judge/3892620/C++14 */
    /* NTL_1_D(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_D/judge/3892636/C++14 */
    /* NTL_1_E(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/NTL_1_E/judge/3892655/C++14 */
}