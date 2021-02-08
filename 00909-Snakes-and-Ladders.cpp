#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        unordered_map<int, int> dist;
        queue<int> q;
        q.emplace(0);
        dist[0] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == n * n - 1)
                return dist[cur];
            for (int k = 1; k <= 6; ++k) {
                int next = cur + k;
                if (next >= n * n)
                    break;
                int x = next / n, y = next % n;
                if (x & 1)
                    y = n - 1 - y;
                x = n - 1 - x;
                if (board[x][y] != -1)
                    next = board[x][y] - 1;
                if (!dist.count(next)) {
                    dist[next] = dist[cur] + 1;
                    q.emplace(next);
                }
            }
        }
        return -1;
    }
};


int main(int argc, char* argv[]){


    return 0;
}

