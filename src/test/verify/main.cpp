#line 2 "/home/kobayashi/Library/src/template.hpp"

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define vm vector<mint>
#define vvm vector<vector<mint>>
#define vvvm vector<vector<vector<mint>>>
#define vp vector<pl>
#define vvp vector<vector<pl>>
#define vs vector<string>
#define vvs vector<vector<string>>

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) std::begin(x), std::end(x)
#define make_unique(v) v.erase(unique(all(v)), v.end());
#define sum(...) accumulate(all(__VA_ARGS__), 0LL)
#define inf (0x1fffffffffffffff)

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(int i = 0; i < (int)v.size(); i++) {
        if(i != (int)v.size() - 1)
            os << v[i] << " ";
        else
            os << v[i];
    }
    return os;
}

template <typename T, typename... Args>
auto make_v(T x, int arg, Args... args) {
    if constexpr(sizeof...(args) == 0)
        return vector<T>(arg, x);
    else
        return vector(arg, make_v<T>(x, args...));
}

template <class T>
auto min(const T& a) {
    return *min_element(all(a));
}

template <class T>
auto max(const T& a) {
    return *max_element(all(a));
}

template <class T>
bool chmin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}

template <class T>
bool chmax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;
#line 2 "/home/kobayashi/Library/src/Graph/lca.hpp"

#line 2 "/home/kobayashi/Library/src/Graph/graph-template.hpp"

/*
** @ei1333 さんのテンプレート(https://github.com/ei1333/library/blob/master/graph/graph-template.hpp) より
*/
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1)
      : from(from)
      , to(to)
      , cost(cost)
      , idx(idx) {
    }

    operator int() const { return to; }
};

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n)
      : g(n)
      , es(0) {
    }

    size_t size() const {
        return g.size();
    }

    void resize(int n) {
        g.resize(n);
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if(weighted)
                cin >> c;
            if(directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }

    void debug(){
        rep(i, g.size()){
            cerr << i << ": ";
            for(auto &e : g[i]){
                cerr << e.to << ", ";
            }
            cerr << endl;
        }
    }

    inline vector<Edge<T>>& operator[](const int& k) {
        return g[k];
    }

    inline const vector<Edge<T>>& operator[](const int& k) const {
        return g[k];
    }
};

template <typename T = int>
using Edges = vector<Edge<T>>;
#line 5 "/home/kobayashi/Library/src/Graph/lca.hpp"
template<typename T = int>
struct LCA{  
    // N: 頂点数, K: ダブリングで 2^0, 2^1, 2^2 , ... 個先の頂点を持つが、2 の何乗先の頂点まで持つかを表す
    int N, K;
    vector<int> dist;
    vector<vector<int>> doubling;
    LCA(Graph<T> G, int root){
        N = (int)G.size();
        K = 1;
        while((1LL<<K) <= N) K++;
        dist.assign(N, -1);
        doubling.assign(N, vector<int>(K, -1));
        // 根から BFS して各頂点の親を求める
        queue<int> que;
        que.push(root);
        dist[root] = 0;
        doubling[root][0] = root;
        while(!que.empty()){
            int t = que.front(); que.pop();
            for(auto e : G[t]){
                if(dist[e.to] == -1){
                    dist[e.to] = dist[t] + 1;
                    doubling[e.to][0] = t;
                    que.push(e.to);
                }
            }
        }
        for(int k = 1; k < K; k++){
            for(int i = 0; i < N; i++){
                doubling[i][k] = doubling[doubling[i][k - 1]][k - 1];
            }
        }
    }
    int query(int u, int v){
        if(dist[u] > dist[v]) swap(u, v);
        for(int k = 0; k < K; k++){
            if((dist[v] - dist[u]) & ((1LL) << k)) v = doubling[v][k];
        }
        if(u == v) return u;
        for(int k = K - 1; k >= 0; k--){
            if(doubling[u][k] != doubling[v][k]){
                u = doubling[u][k];
                v = doubling[v][k];
            }
        }
        return doubling[u][0];
    }
};
#line 3 "yosupo-lca.test.cpp"

int main(){
    ll N, Q;
    cin >> N >> Q;
    Graph<> G(N);
    vl p(N - 1);
    cin >> p;
    rep(i, N - 1) G.add_edge(p[i], i + 1);
    LCA<> lca(G, 0);
    rep(i, Q){
        ll u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}
