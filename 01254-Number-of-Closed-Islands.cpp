#include <bits/stdc++.h>

using namespace std;

//1254. 统计封闭岛屿的数目
//
//        有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。
//
//我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。
//
//如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。
//
//请返回封闭岛屿的数目。
//
//
//
//示例 1：
//
//输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
//输出：2
//解释：
//灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
//
//示例 2：
//
//输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//输出：1
//
//示例 3：
//
//输入：grid = [[1,1,1,1,1,1,1],
//[1,0,0,0,0,0,1],
//[1,0,1,1,1,0,1],
//[1,0,1,0,1,0,1],
//[1,0,1,1,1,0,1],
//[1,0,0,0,0,0,1],
//[1,1,1,1,1,1,1]]
//输出：2
//
//
//
//提示：
//
//1 <= grid.length, grid[0].length <= 100
//0 <= grid[i][j] <=1


class Solution {
    int m, n;
    vector<vector<bool>> vis;
    int d[4][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};

    void dfs(const vector<vector<int>> &grid, int r, int c) {
        vis[r][c] = true;
        for (int k = 0; k < 4; ++k) {
            int rr = r + d[k][0], cc = c + d[k][1];
            if (rr >= 0 && rr < m && cc >= 0 && cc < n && !vis[rr][cc] && grid[rr][cc] == 0)
                dfs(grid, rr, cc);
        }
    }

public:
    int closedIsland(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            if (!vis[0][i] && grid[0][i] == 0)
                dfs(grid, 0, i);
            if (!vis[m - 1][i] && grid[m - 1][i] == 0)
                dfs(grid, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            if (!vis[i][0] && grid[i][0] == 0)
                dfs(grid, i, 0);
            if (!vis[i][n - 1] && grid[i][n - 1] == 0)
                dfs(grid, i, n - 1);
        }
        int res = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    dfs(grid, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {


    return 0;
}

