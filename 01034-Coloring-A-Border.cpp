#include <bits/stdc++.h>

using namespace std;

//1034. 边框着色
//
//        给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。
//
//只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。
//
//连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。
//
//给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，并返回最终的网格 grid 。
//
//
//
//示例 1：
//
//输入：grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
//输出：[[3, 3], [3, 2]]
//
//示例 2：
//
//输入：grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
//输出：[[1, 3, 3], [2, 3, 3]]
//
//示例 3：
//
//输入：grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
//输出：[[2, 2, 2], [2, 1, 2], [2, 2, 2]]
//
//
//
//提示：
//
//1 <= grid.length <= 50
//1 <= grid[0].length <= 50
//1 <= grid[i][j] <= 1000
//0 <= r0 < grid.length
//0 <= c0 < grid[0].length
//1 <= color <= 1000


class Solution {
private:
    int m, n;
    int c1, c2;
    int d[4][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};
    vector<vector<int>> g;

    int dfs(const vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &vis) {
        vis[r][c] = true;
        int cnt = 0;
        int res = 1;
        for (int k = 0; k < 4; ++k) {
            int rr = r + d[k][0];
            int cc = c + d[k][1];
            if (rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] == c1) {
                ++cnt;
                if (!vis[rr][cc])
                    res += dfs(grid, rr, cc, vis);
            }
        }
        if (cnt < 4)
            g[r][c] = c2;
        return res;
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color) {
        m = grid.size();
        n = grid[0].size();
        c1 = grid[r0][c0];
        c2 = color;
        g = grid;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        if (dfs(grid, r0, c0, vis) == 1)
            g[r0][c0] = c2;
        return g;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

