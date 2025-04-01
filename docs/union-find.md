## Union-Find（素集合データ構造）

## 使用例

```cpp
// 10頂点のUnion-Find
UnionFind uf(10);

// 0と1を同じグループに
uf.unite(0, 1);
// 2と3を同じグループに
uf.unite(2, 3);
// 0と3を同じグループに（0,1,2,3が同じグループになる）
uf.unite(0, 3);

// 0と2が同じグループか確認（true）
bool same_group = uf.same(0, 2);

// 0のグループのサイズを取得（4）
int group_size = uf.size(0);

// すべての根（代表元）のリストを取得
vector<int> roots = uf.leaders();
```
