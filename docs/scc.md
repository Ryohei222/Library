## 概要

$G$ に対して DFS しての帰りがけ順を求める。$G$ の辺を逆にしたグラフ $G'$ に対して、帰りがけ順が最も大きい頂点から DFS を行う。このとき、ある頂点からたどり付けた頂点集合はその頂点を含む強連結成分になっている。

## 計算量

$\mathcal{O}(|V| + |E|)$ 