#define PROBLEM "https://yukicoder.me/problems/no/697"
#include "../../template.hpp"

#include "../../DataStructure/union-find.hpp"
#include "../../Util/grid2d.hpp"

int main() {
    ll H, W;
    cin >> H >> W;
    Grid2D<int> grid(H, W);
    grid.read();
    UnionFind uf(H * W);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(auto [ni, nj] : grid.next4(i, j)) {
                if(grid[i][j] == grid[ni][nj]) {
                    uf.unite(grid.encode(i, j), grid.encode(ni, nj));
                }
            }
        }
    }
    ll ans = 0;
    for(auto i : uf.leaders()) {
        auto [nx, ny] = grid.decode(i);
        if(grid[nx][ny] == 1) ans++;
    }
    cout << ans << '\n';
}