#include "graph-template.cpp"

//
template<typename T>
struct LCA{  
    // N: 頂点数, K: ダブリングで 2^0, 2^1, 2^2 , ... 個先の頂点を持つが、2 の何乗先の頂点まで持つかを表す
    int N, K = 20;
    vector<int> dist;
    // doubling[i][j] := 頂点 i の 2^j 個先(親)の頂点番号
    vector<vector<int>> doubling;
    // par: 根
    LCA(Graph<T> G, int par){
        N = G.size();
        dist.assign(N, -1);
        doubling.assign(N, vector<int>(K, -1));
        // 根から BFS して各頂点の親を求める
        queue<int> que;
        que.push(par);
        dist[par] = 0;
        doubling[par][0] = par;
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
        // d(par, u) = d(par, v) が成り立つように v を動かす
        for(int k = 0; k < K; k++){
            if((dist[v] - dist[u]) & ((1LL) << k)) v = doubling[v][k];
        }
        // u が v の祖先ならば u が (u, v) の LCA
        if(u == v) return u;
        for(int k = K - 1; k >= 0; k--){
            // doubling[u][k] != doubling[v][k] ならば (u, v) の LCA は少なくとも u, v の (2^k) + 1 個先の頂点
            if(doubling[u][k] != doubling[v][k]){
                u = doubling[u][k];
                v = doubling[v][k];
            }
        }
        // u, v に格納されている頂点は (u, v) の LCA の 1 つ手前なので
        return doubling[u][0];
    }
};

void GRL_5_C(){
    int n;
    cin >> n;
    Graph<int> G(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; k++){
            int to;
            cin >> to;
            G[i].emplace_back(to);
            G[to].emplace_back(i);
        }
    }
    LCA<int> lca(G, 0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}