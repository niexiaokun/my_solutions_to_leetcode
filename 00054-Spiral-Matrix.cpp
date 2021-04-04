#include <bits/stdc++.h>

using namespace std;

//54. 螺旋矩阵
//
//        给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//
//
//
//示例 1：
//
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
//
//示例 2：
//
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//
//提示：
//
//m == matrix.length
//        n == matrix[i].length
//1 <= m, n <= 10
//-100 <= matrix[i][j] <= 100


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0)
            return res;
        int n = matrix[0].size();
        if(n == 0)
            return res;
        int up = 0, right = n - 1, down = m - 1, left = 0;
        while(left <= right && up <= down){
            for(int i = left; i <= right; ++i)
                res.emplace_back(matrix[up][i]);
            ++up;
            if(up > down)
                break;
            for(int i = up; i <= down; ++i)
                res.emplace_back(matrix[i][right]);
            --right;
            if(right < left)
                break;
            for(int i = right; i >= left; --i)
                res.emplace_back(matrix[down][i]);
            --down;
            if(down < up)
                break;
            for(int i = down; i >= up; --i)
                res.emplace_back(matrix[i][left]);
            ++left;
        }
        return res;
    }
};

int main(int argc, char *argv[]){

    return 0;
}

