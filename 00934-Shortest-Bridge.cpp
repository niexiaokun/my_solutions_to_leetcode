#include <bits/stdc++.h>

using namespace std;

//934. 最短的桥
//
//        在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）
//
//现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。
//
//返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）
//
//
//
//示例 1：
//
//输入：[[0,1],[1,0]]
//输出：1
//
//示例 2：
//
//输入：[[0,1,0],[0,0,0],[0,0,1]]
//输出：2
//
//示例 3：
//
//输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//输出：1
//
//
//
//提示：
//
//1 <= A.length = A[0].length <= 100
//A[i][j] == 0 或 A[i][j] == 1


class Solution {
public:
    int shortestBridge(vector<vector<int>> &nums) {
        int m = nums.size();
        int n = nums[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int i = 0, j = 0;
        bool flag = false;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (nums[i][j] == 1) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        int d[4][2] = {{1,  0},
                       {0,  1},
                       {-1, 0},
                       {0,  -1}};
        q.emplace(i, j);
        vis[i][j] = true;
        while (!q.empty()) {
            auto[r, c]=q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int rr = r + d[k][0], cc = c + d[k][1];
                if (rr >= 0 && rr < m && cc >= 0 && cc < n && nums[rr][cc] == 1 && !vis[rr][cc]) {
                    vis[rr][cc] = true;
                    q.emplace(rr, cc);
                }
            }
        }
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (vis[i][j])
                    q.emplace(i * n + j, 0);
            }
        }
        while (!q.empty()) {
            auto[p, dis]=q.front();
            q.pop();
            int r = p / n, c = p % n;
            for (int k = 0; k < 4; ++k) {
                int rr = r + d[k][0], cc = c + d[k][1];
                if (rr >= 0 && rr < m && cc >= 0 && cc < n && !vis[rr][cc]) {
                    if (nums[rr][cc] == 1)
                        return dis;
                    else {
                        vis[rr][cc] = true;
                        q.emplace(rr * n + cc, dis + 1);
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

