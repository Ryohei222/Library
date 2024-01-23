#pragma once

/**
 * @brief Grid(2D)
 * @docs docs/grid2d.md
 */

template <typename T>
struct Grid2D {
    int H, W;
    vector<vector<T>> data;
    vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};
    Grid2D(int H, int W)
        : H(H), W(W), data(H, vector<T>(W)) {}
    Grid2D(int H, int W, T x)
        : H(H), W(W), data(H, vector<T>(W, x)) {}
    Grid2D(const vector<vector<T>> &data)
        : H(data.size()), W(data[0].size()), data(data) {}
    vector<T> &operator[](int i) {
        return data[i];
    }
    void read() {
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> data[i][j];
            }
        }
    }
    bool in(int i, int j) {
        return 0 <= i && i < H && 0 <= j && j < W;
    }
    int encode(int i, int j) {
        return i * W + j;
    }
    pair<int, int> decode(int x) {
        return make_pair(x / W, x % W);
    }
    vector<pair<int, int>> next4(int i, int j) {
        return next(i, j, 4);
    }
    vector<pair<int, int>> next8(int i, int j) {
        return next(i, j, 8);
    }

  private:
    vector<pair<int, int>> next(int i, int j, int k) {
        vector<pair<int, int>> res;
        for(int t = 0; t < k; t++) {
            int ni = i + dx[t], nj = j + dy[t];
            if(in(ni, nj)) res.push_back(make_pair(ni, nj));
        }
        return res;
    }
};