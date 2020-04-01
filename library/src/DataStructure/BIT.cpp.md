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


# :warning: src/DataStructure/BIT.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/BIT.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-26 19:13:55+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/BIT.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

