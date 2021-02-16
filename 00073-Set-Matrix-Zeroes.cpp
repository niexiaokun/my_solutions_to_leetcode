#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> g1, g2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    g1.insert(i);
                    g2.insert(j);
                }
            }
        }
        for (int x:g1) {
            for (int j = 0; j < n; ++j)
                matrix[x][j] = 0;
        }
        for (int x:g2) {
            for (int i = 0; i < m; ++i)
                matrix[i][x] = 0;
        }
    }
};

int main(int argc, char* argv[]) {


    return 0;
}

