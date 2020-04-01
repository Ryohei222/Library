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


# :warning: src/DataStructure/Union-Find.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/Union-Find.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-26 11:24:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
    /* DSL_1_A(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_1_A/judge/3892722/C++14 */
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/Union-Find.cpp"
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
    /* DSL_1_A(); /* https://onlinejudge.u-aizu.ac.jp/status/users/kobaryo222/submissions/1/DSL_1_A/judge/3892722/C++14 */
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

