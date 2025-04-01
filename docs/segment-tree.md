## セグメント木（Segment Tree）

## 使用例

```cpp
// 最小値を管理するセグメント木
SegmentTree<MinMonoid<int>> seg(10); // 長さ10の配列を管理

// 値を設定
seg.set(0, 5);
seg.set(1, 3);
seg.set(2, 7);
// ...

// 区間[1, 4)の最小値を取得
int min_val = seg.prod(1, 4);

// 値を更新（MinMonoidの場合は min(現在値, x) となる）
seg.apply(2, 1);

// ある値より小さい要素がある最初の位置を探す
int pos = seg.find_first(0, [](int x) { return x < 3; });
```
