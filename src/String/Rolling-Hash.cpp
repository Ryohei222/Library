struct RollingHash {
    ll m1 = 1000000007, ll = 1000000009;
    ll b1 = 1009, ll = 1007;
    vector<ll> h1, h2, p1, p2;
    RollingHash(string s) {
        ll n = s.length();
        h1.resize(n + 1);
        h2.resize(n + 1);
        p1.resize(n + 1);
        p2.resize(n + 1);
        h1[0] = s[0] % m1;
        h2[0] = s[0] % m2;
        p1[0] = p2[0] = 1;
        for(int i = 0; i < n; ++i) {
            h1[i + 1] = (h1[i] * b1 % m1 + s[i]) % m1;
            h2[i + 1] = (h2[i] * b2 % m2 + s[i]) % m2;
            p1[i + 1] = p1[i] * b1 % m1;
            p2[i + 1] = p2[i] * b2 % m2;
        }
    };
    P get(ll l, ll r) {
        ll hash1 = (h1[r] + m1 - h1[l] * p1[r - l] % m1) % m1;
        ll hash2 = (h2[r] + m2 - h2[l] * p2[r - l] % m2) % m2;
        return pair<ll, ll>(hash1, hash2);
    };
};