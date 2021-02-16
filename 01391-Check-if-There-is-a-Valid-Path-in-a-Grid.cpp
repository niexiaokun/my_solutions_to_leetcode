#include <bits/stdc++.h>

using namespace std;

//1391. 检查网格中是否存在有效路径
//
//        给你一个 m x n 的网格 grid。网格里的每个单元都代表一条街道。grid[i][j] 的街道可以是：
//
//1 表示连接左单元格和右单元格的街道。
//2 表示连接上单元格和下单元格的街道。
//3 表示连接左单元格和下单元格的街道。
//4 表示连接右单元格和下单元格的街道。
//5 表示连接左单元格和上单元格的街道。
//6 表示连接右单元格和上单元格的街道。
//
//你最开始从左上角的单元格 (0,0) 开始出发，网格中的「有效路径」是指从左上方的单元格 (0,0) 开始、一直到右下方的 (m-1,n-1) 结束的路径。该路径必须只沿着街道走。
//
//注意：你 不能 变更街道。
//
//如果网格中存在有效的路径，则返回 true，否则返回 false 。
//
//
//
//示例 1：
//
//输入：grid = [[2,4,3],[6,5,2]]
//输出：true
//解释：如图所示，你可以从 (0, 0) 开始，访问网格中的所有单元格并到达 (m - 1, n - 1) 。
//
//示例 2：
//
//输入：grid = [[1,2,1],[1,2,1]]
//输出：false
//解释：如图所示，单元格 (0, 0) 上的街道没有与任何其他单元格上的街道相连，你只会停在 (0, 0) 处。
//
//示例 3：
//
//输入：grid = [[1,1,2]]
//        输出：false
//解释：你会停在 (0, 1)，而且无法到达 (0, 2) 。
//
//示例 4：
//
//输入：grid = [[1,1,1,1,1,1,3]]
//        输出：true
//
//示例 5：
//
//输入：grid = [[2],[2],[2],[2],[2],[2],[6]]
//输出：true
//
//
//
//提示：
//
//m == grid.length
//        n == grid[i].length
//1 <= m, n <= 300
//1 <= grid[i][j] <= 6


class Solution {
private:
    int m, n;
    int k[4][2] = {{-1, 0},
                   {0,  -1},
                   {0,  1},
                   {1,  0}};
    int d[6][2] = {{1, 2},
                   {0, 3},
                   {1, 3},
                   {2, 3},
                   {0, 1},
                   {0, 2}};

    void dfs(const vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &vis) {
        vis[r][c] = true;
        for (int i = 0; i < 2; ++i) {
            int j = d[grid[r][c] - 1][i];
            int rr = r + k[j][0], cc = c + k[j][1];
            if (rr >= 0 && rr < m && cc >= 0 && cc < n && !vis[rr][cc]) {
                for (int p = 0; p < 2; ++p) {
                    if (j + d[grid[rr][cc] - 1][p] == 3) {
                        // printf("(%d,%d)->(%d,%d)\n",r,c,rr,cc);
                        dfs(grid, rr, cc, vis);
                        break;
                    }
                }
            }
        }
    }

public:
    bool hasValidPath(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        dfs(grid, 0, 0, vis);
        return vis[m - 1][n - 1];
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

