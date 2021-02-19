#include <bits/stdc++.h>

using namespace std;

//面试题 16.19. 水域大小
//
//        你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
//
//示例：
//
//输入：
//[
//[0,2,1,0],
//[0,1,0,1],
//[1,1,0,1],
//[0,1,0,1]
//]
//输出： [1,2,4]
//
//提示：
//
//0 < len(land) <= 1000
//0 < len(land[i]) <= 1000


class Solution {
public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        int m = land.size();
        int n = land[0].size();
        int d[8][2] = {{1,  0},
                       {0,  1},
                       {-1, 0},
                       {0,  -1},
                       {1,  1},
                       {1,  -1},
                       {-1, 1},
                       {-1, -1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> res;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && land[i][j] == 0) {
                    q.emplace(i, j);
                    vis[i][j] = true;
                    int cnt = 0;
                    while (!q.empty()) {
                        auto[r, c]=q.front();
                        q.pop();
                        ++cnt;
                        for (int k = 0; k < 8; ++k) {
                            int rr = r + d[k][0], cc = c + d[k][1];
                            if (rr >= 0 && rr < m && cc >= 0 && cc < n && land[rr][cc] == 0 && !vis[rr][cc]) {
                                vis[rr][cc] = true;
                                q.emplace(rr, cc);
                            }
                        }
                    }
                    res.emplace_back(cnt);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

