#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    q.emplace(n * i + j, 0);
                    vis[i][j] = true;
                }
            }
        }
        int d[4][2] = {{1,  0},
                       {0,  1},
                       {-1, 0},
                       {0,  -1}};
        while (!q.empty()) {
            auto[pos, z]=q.front();
            q.pop();
            int r = pos / n, c = pos % n;
            if (matrix[r][c])
                res[r][c] = z;
            for (int k = 0; k < 4; ++k) {
                int rr = r + d[k][0];
                int cc = c + d[k][1];
                if (rr>=0&&rr<m&&cc>=0&&cc<n&&!vis[rr][cc]) {
                    q.emplace(rr * n + cc, z + 1);
                    vis[rr][cc] = true;
                }
            }
        }
        return res;
    }
};


int main(int argc, char* argv[]){

    return 0;
}
