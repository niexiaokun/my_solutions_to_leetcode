#include <bits/stdc++.h>

using namespace std;

//面试题 17.23. 最大黑方阵
//
//        给定一个方阵，其中每个单元(像素)非黑即白。设计一个算法，找出 4 条边皆为黑色像素的最大子方阵。
//
//返回一个数组 [r, c, size] ，其中 r, c 分别代表子方阵左上角的行号和列号，size 是子方阵的边长。若有多个满足条件的子方阵，返回 r 最小的，若 r 相同，返回 c 最小的子方阵。若无满足条件的子方阵，返回空数组。
//
//示例 1:
//
//输入:
//[
//[1,0,1],
//[0,0,1],
//[0,0,1]
//]
//输出: [1,0,2]
//解释: 输入中 0 代表黑色，1 代表白色，标粗的元素即为满足条件的最大子方阵
//
//        示例 2:
//
//输入:
//[
//[0,1,1],
//[1,0,1],
//[1,1,0]
//]
//输出: [0,0,1]
//
//提示：
//
//matrix.length == matrix[0].length <= 200


class Solution {
public:
    vector<int> findSquare(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dp1(n, vector<int>(n));
        vector<vector<int>> dp2(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            dp1[i][0] = matrix[i][0] == 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0)
                    dp1[i][j] = dp1[i][j - 1] + 1;
            }
        }
        for (int j = 0; j < n; ++j)
            dp2[0][j] = matrix[0][j] == 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < n; ++i) {
                if (matrix[i][j] == 0)
                    dp2[i][j] = dp2[i - 1][j] + 1;
            }
        }
        int r = -1, c = -1, sz = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; i + k < n && j + k < n; ++k) {
                    if (matrix[i][j] == 0 && dp1[i][j + k] > k && dp1[i + k][j + k] > k && dp2[i + k][j] > k &&
                        dp2[i + k][j + k] > k &&
                        k + 1 > sz) {
                        r = i, c = j, sz = k + 1;
                    }
                }
            }
        }
        if (sz == 0)
            return {};
        return {r, c, sz};
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

