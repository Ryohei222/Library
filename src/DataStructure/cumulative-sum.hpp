template <typename T = long long int>
struct CumulativeSum {
  private:
    bool built = false;

  public:
    int n;
    vector<T> wa;
    CumulativeSum(int n)
        : n(n), wa(n + 1, T(0)) {}
    CumulativeSum(const vector<T> &a)
        : n((int)a.size()), wa(n + 1, T(0)) {
        for(int i = 0; i < n; i++)
            add(i, a[i]);
        build();
    }
    /**
     * @brief 累積和を構築する
     *
     */
    void build() {
        assert(!built);
        for(int i = 0; i < n; i++) {
            wa[i + 1] = wa[i] + wa[i + 1];
        }
        built = true;
    }
    /**
     * @brief wa[idx + 1] += x
     *
     * @param idx 加算する位置 (0-indexed)
     * @param x 加算する値
     */
    void add(int idx, T x) {
        assert(!built);
        wa[idx + 1] += x;
    }
    /**
     * @brief [l, r) の和, wa[r] - wa[l]
     *
     * @param l 左端の位置 (0-indexed, 閉区間)
     * @param r 右端の位置 (0-indexed, 開区間)
     * @return T 区間の総和
     */
    T sum(int l, int r) {
        assert(built);
        return wa[r] - wa[l];
    }
};