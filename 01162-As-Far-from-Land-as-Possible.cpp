#include <bits/stdc++.h>

using namespace std;

//1162. 地图分析
//
//        你现在手里有一份大小为 N x N 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。
//
//我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。
//
//如果网格上只有陆地或者海洋，请返回 -1。
//
//
//
//示例 1：
//
//输入：[[1,0,1],[0,0,0],[1,0,1]]
//输出：2
//解释：
//海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
//
//示例 2：
//
//输入：[[1,0,0],[0,0,0],[0,0,0]]
//输出：4
//解释：
//海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
//
//
//
//提示：
//
//1 <= grid.length == grid[0].length <= 100
//grid[i][j] 不是 0 就是 1


//class Solution {
//public:
//    int maxDistance(vector<vector<int>> &grid) {
//        int m = grid.size();
//        int n = grid[0].size();
//        int d[4][2] = {{1,  0},
//                       {0,  1},
//                       {-1, 0},
//                       {0,  -1}};
//        int res = 0;
//        queue<pair<int, int>> q;
//        int cnt = 0;
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (grid[i][j] == 1) {
//                    int p = i * n + j;
//                    q.emplace(p, p);
//                    ++cnt;
//                }
//            }
//        }
//        if (cnt == 0 || cnt == m * n)
//            return -1;
//
//        vector<vector<bool>> vis(m, vector<bool>(n, false));
//        while (!q.empty()) {
//            auto[s, p]=q.front();
//            int r = p / n, c = p % n;
//            q.pop();
//            for (int k = 0; k < 4; ++k) {
//                int rr = r + d[k][0], cc = c + d[k][1];
//                if (rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] == 0 && !vis[rr][cc]) {
//                    vis[rr][cc] = true;
//                    res = max(res, abs(rr - s / n) + abs(cc - s % n));
//                    q.emplace(s, rr * n + cc);
//                }
//            }
//        }
//        return res;
//    }
//};


class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int d[4][2] = {{1,  0},
                       {0,  1},
                       {-1, 0},
                       {0,  -1}};
        int res = 0;
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int p = i * n + j;
                    q.emplace(p, 0);
                    ++cnt;
                }
            }
        }
        if (cnt == 0 || cnt == m * n)
            return -1;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        while (!q.empty()) {
            auto[p, dis]=q.front();
            int r = p / n, c = p % n;
            q.pop();
            res = max(res, dis);
            for (int k = 0; k < 4; ++k) {
                int rr = r + d[k][0], cc = c + d[k][1];
                if (rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] == 0 && !vis[rr][cc]) {
                    vis[rr][cc] = true;
                    q.emplace(rr * n + cc, dis + 1);
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

