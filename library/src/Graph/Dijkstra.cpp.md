---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: src/Graph/Dijkstra.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/Dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 13:58:33+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A">https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using i64 = long long int;
using P = pair<i64, i64>;

struct edge{
    i64 src, to, cost;
    edge(i64 to, i64 cost) : src(-1), to(to), cost(cost) {}
    edge(i64 src, i64 to, i64 cost) : src(src), to(to), cost(cost) {}
    bool operator <(const edge &u){
        return this->cost < u.cost;
    };
};

using Graph = vector<vector<edge>>;
const i64 INF = numeric_limits<i64>::max();

vector<i64> dijkstra(Graph G, i64 s){
    //
    // Dijkstra 法 O(ElogV)
    // Graph G : 有向グラフ
    // i64 s : 始点の番号
    //
    i64 n = G.size();
    vector<i64> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    while(!que.empty()){
        P t = que.top(); que.pop();
        i64 cost = t.first, u = t.second;
        if(cost > dist[u]) continue;
        for(auto e : G[u]){
            i64 v = e.to;
            if(cost + e.cost < dist[v]){
                dist[v] = cost + e.cost;
                que.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

void GRL_1_A(){
    i64 v, e, r;
    cin >> v >> e >> r;
    Graph G(v);
    for(i64 i = 0; i < e; ++i){
        i64 s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(s, t, d);
    }
    auto dist = dijkstra(G, r);
    for(auto d: dist){
        if(d == INF) cout << "INF" << endl;
        else cout << d << endl;
    }
}

int main(){
    GRL_1_A(); // https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/GRL_1_A/judge/3892499/C++14
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/Dijkstra.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using i64 = long long int;
using P = pair<i64, i64>;

struct edge{
    i64 src, to, cost;
    edge(i64 to, i64 cost) : src(-1), to(to), cost(cost) {}
    edge(i64 src, i64 to, i64 cost) : src(src), to(to), cost(cost) {}
    bool operator <(const edge &u){
        return this->cost < u.cost;
    };
};

using Graph = vector<vector<edge>>;
const i64 INF = numeric_limits<i64>::max();

vector<i64> dijkstra(Graph G, i64 s){
    //
    // Dijkstra 法 O(ElogV)
    // Graph G : 有向グラフ
    // i64 s : 始点の番号
    //
    i64 n = G.size();
    vector<i64> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    while(!que.empty()){
        P t = que.top(); que.pop();
        i64 cost = t.first, u = t.second;
        if(cost > dist[u]) continue;
        for(auto e : G[u]){
            i64 v = e.to;
            if(cost + e.cost < dist[v]){
                dist[v] = cost + e.cost;
                que.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

void GRL_1_A(){
    i64 v, e, r;
    cin >> v >> e >> r;
    Graph G(v);
    for(i64 i = 0; i < e; ++i){
        i64 s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(s, t, d);
    }
    auto dist = dijkstra(G, r);
    for(auto d: dist){
        if(d == INF) cout << "INF" << endl;
        else cout << d << endl;
    }
}

int main(){
    GRL_1_A(); // https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/GRL_1_A/judge/3892499/C++14
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

