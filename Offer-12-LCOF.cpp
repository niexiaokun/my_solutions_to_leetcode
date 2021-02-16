#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<bool>> vis;
    vector<vector<char>> board;
    int d[4][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};

    bool dfs(int r, int c, const string &s, int index) {
        if (index == s.size())
            return true;
        vis[r][c] = true;
        for (int k = 0; k < 4; ++k) {
            int rr = r + d[k][0], cc = c + d[k][1];
            if (rr >= 0 && rr < m && cc >= 0 && cc < n && !vis[rr][cc] && board[rr][cc] == s[index]) {
                if (dfs(rr, cc, s, index + 1))
                    return true;
            }
        }
        vis[r][c] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        this->board = board;
        m = board.size();
        n = board[0].size();
        unordered_map<char, vector<pair<int, int>>> f;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f[board[i][j]].emplace_back(i, j);
            }
        }
        vis.resize(m, vector<bool>(n, false));
        if (!f.count(word[0]))
            return false;
        for (auto[x, y]:f[word[0]]) {
            if (dfs(x, y, word, 1))
                return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {


    return 0;
}

