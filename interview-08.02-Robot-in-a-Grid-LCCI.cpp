#include <bits/stdc++.h>

using namespace std;

//面试题 08.02. 迷路的机器人
//
//        设想有个机器人坐在一个网格的左上角，网格 r 行 c 列。机器人只能向下或向右移动，但不能走到一些被禁止的网格（有障碍物）。设计一种算法，寻找机器人从左上角移动到右下角的路径。
//
//网格中的障碍物和空位置分别用 1 和 0 来表示。
//
//返回一条可行的路径，路径由经过的网格的行号和列号组成。左上角为 0 行 0 列。如果没有可行的路径，返回空数组。
//
//示例 1:
//
//输入:
//[
//[0,0,0],
//[0,1,0],
//[0,0,0]
//]
//输出: [[0,0],[0,1],[0,2],[1,2],[2,2]]
//解释:
//输入中标粗的位置即为输出表示的路径，即
//0行0列（左上角） -> 0行1列 -> 0行2列 -> 1行2列 -> 2行2列（右下角）
//
//说明：r 和 c 的值均不超过 100。


class Solution {
private:
    int m, n;
    vector<int> from;

    void dfs(vector<vector<int>> &obstacleGrid, int x, vector<vector<bool>> &vis) {
        int r = x / n, c = x % n;
        vis[r][c] = true;
        int rr = r + 1, cc = c;
        int y;
        if (rr < m && !vis[rr][cc]) {
            y = rr * n + cc;
            from[y] = x;
            dfs(obstacleGrid, y, vis);
        }
        rr = r, cc = cc + 1;
        if (cc < n && !vis[rr][cc]) {
            y = rr * n + cc;
            from[y] = x;
            dfs(obstacleGrid, y, vis);
        }
    }

public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> res;
        m = obstacleGrid.size();
        if (m == 0)
            return res;
        n = obstacleGrid[0].size();
        if (n == 0)
            return res;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return res;
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    vis[i][j] = true;
            }
        }
        from.resize(m * n, -1);
        from[0] = 0;
        dfs(obstacleGrid, 0, vis);
        if (from[m * n - 1] == -1)
            return res;
        int x = m * n - 1;
        while (x != 0) {
            res.push_back({x / n, x % n});
            x = from[x];
        }
        res.push_back({0, 0});
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char* argv[]) {


}

