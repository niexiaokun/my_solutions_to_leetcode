#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int h = 0; h < n / 2; ++h) {
            int L = n - 1 - h * 2;
            for (int t = 1; t <= L; ++t) {
                int x = h, y = h + t;
                int tmp = matrix[x][y];
                matrix[x][y] = matrix[n - 1 - y][x];
                matrix[n - 1 - y][x] = matrix[n - 1 - x][n - 1 - y];
                matrix[n - 1 - x][n - 1 - y] = matrix[y][n - 1 - x];
                matrix[y][n - 1 - x] = tmp;
            }
        }
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

