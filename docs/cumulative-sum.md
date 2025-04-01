## 累積和（Cumulative Sum）

### 計算量

- 初期化・構築: $O(n)$
- 区間和クエリ: $O(1)$

### 使用例

```cpp
// 長さ5の配列 [1, 2, 3, 4, 5] の累積和を構築
vector<int> a = {1, 2, 3, 4, 5};
CumulativeSum<int> cs(a);

// 区間[1, 4)の和を計算（a[1] + a[2] + a[3] = 2 + 3 + 4 = 9）
int sum_1_4 = cs.sum(1, 4);  // 9

// 区間[0, 5)の和を計算（全要素の和 = 15）
int sum_all = cs.sum(0, 5);  // 15
```


```cpp
// 長さ5の累積和を初期化
CumulativeSum<int> cs(5);

// 値を追加
cs.add(0, 1);
cs.add(1, 2);
cs.add(2, 3);
cs.add(3, 4);
cs.add(4, 5);

// 累積和を構築
cs.build();

// 区間和を計算
int sum_1_4 = cs.sum(1, 4);  // 9
```