#include <bits/stdc++.h>

using namespace std;

//417. 太平洋大西洋水流问题
//
//        给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
//
//规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
//
//请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
//
//
//
//提示：
//
//输出坐标的顺序不重要
//        m 和 n 都小于150
//
//
//
//        示例：
//
//
//
//给定下面的 5x5 矩阵:
//
//太平洋 ~   ~   ~   ~   ~
//~  1   2   2   3  (5) *
//~  3   2   3  (4) (4) *
//~  2   4  (5)  3   1  *
//~ (6) (7)  1   4   5  *
//~ (5)  1   1   2   4  *
//*   *   *   *   * 大西洋
//
//        返回:
//
//[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        if (m == 0)
            return res;
        int n = matrix[0].size();
        vector<vector<int>> nums(m + 2, vector<int>(n + 2));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                nums[i][j] = matrix[i - 1][j - 1];
            }
        }
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(m + 2, vector<int>(n + 2));
        for (int i = 1; i <= m; ++i) {
            q.emplace(i, 0, 1);
            vis[i][0] = 1;
            q.emplace(i, n + 1, 2);
            vis[i][n + 1] = 2;
        }
        for (int j = 1; j <= n; ++j) {
            q.emplace(0, j, 1);
            vis[0][j] = 1;
            q.emplace(m + 1, j, 2);
            vis[m + 1][j] = 2;
        }
        int d[4][2] = {{1,  0},
                       {0,  1},
                       {-1, 0},
                       {0,  -1}};
        while (!q.empty()) {
            auto[r, c, a]=q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int rr = r + d[k][0], cc = c + d[k][1];
                if (rr > 0 && rr <= m && cc > 0 && cc <= n && nums[rr][cc] >= nums[r][c]) {
                    if (a == 1) {
                        if (vis[rr][cc] == 1 || vis[rr][cc] == 3)
                            continue;
                        else if (vis[rr][cc] == 2) {
                            res.push_back({rr - 1, cc - 1});
                            vis[rr][cc] = 3;
                        } else
                            vis[rr][cc] = 1;
                        q.emplace(rr, cc, 1);
                    } else if (a == 2) {
                        if (vis[rr][cc] == 2 || vis[rr][cc] == 3)
                            continue;
                        else if (vis[rr][cc] == 1) {
                            res.push_back({rr - 1, cc - 1});
                            vis[rr][cc] = 3;
                        } else
                            vis[rr][cc] = 2;
                        q.emplace(rr, cc, 2);
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    vector<vector<int>> matrix={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution().pacificAtlantic(matrix);

    return 0;
}

