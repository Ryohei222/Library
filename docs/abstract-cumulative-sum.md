## 抽象化累積和（Abstract Cumulative Sum）

### 計算量

- 初期化・構築: $O(n)$
- 区間クエリ: $O(1)$

### 使用例


```cpp
// XOR演算に対する群を定義
struct XorGroup {
    using S = int; // 要素の型
    static S op(S a, S b) { return a ^ b; } // 演算
    static S e() { return 0; } // 単位元
    static S inv(S a) { return a; } // 逆元（XORでは元と同じ）
};

// 長さ5の配列 [1, 2, 3, 4, 5] のXOR累積和を構築
vector<int> a = {1, 2, 3, 4, 5};
AbstructCumulativeSum<XorGroup> cs(a);

// 区間[1, 4)のXORを計算（a[1] ^ a[2] ^ a[3] = 2 ^ 3 ^ 4 = 5）
int xor_1_4 = cs.sum(1, 4);  // 5

// 区間[0, 5)のXORを計算（全要素のXOR）
int xor_all = cs.sum(0, 5);  // 1
```
