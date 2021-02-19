#include <bits/stdc++.h>

using namespace std;

//面试题 01.08. 零矩阵
//
//        编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
//
//
//
//示例 1：
//
//输入：
//[
//[1,1,1],
//[1,0,1],
//[1,1,1]
//]
//输出：
//[
//[1,0,1],
//[0,0,0],
//[1,0,1]
//]
//
//示例 2：
//
//输入：
//[
//[0,1,2,0],
//[3,4,5,2],
//[1,3,1,5]
//]
//输出：
//[
//[0,0,0,0],
//[0,4,5,0],
//[0,3,1,0]
//]


class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        unordered_set<int> g1, g2;
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    g1.insert(i);
                    g2.insert(j);
                }
            }
        }
        for (int x:g1) {
            fill(matrix[x].begin(), matrix[x].end(), 0);
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

