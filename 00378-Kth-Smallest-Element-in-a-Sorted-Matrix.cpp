#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;


//378. 有序矩阵中第K小的元素
//
//给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
//请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
//
//
//
//示例：
//
//matrix = [
//[ 1,  5,  9],
//[10, 11, 13],
//[12, 13, 15]
//],
//k = 8,
//
//        返回 13。
//
//
//
//提示：
//你可以假设 k 的值永远是有效的，1 ≤ k ≤ n^2 。


class Solution {
    using PIINT=pair<int,pair<int,int>>;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==1){
            assert(k==1);
            return matrix[0][0];
        }
        int n=matrix.size();
        priority_queue<PIINT,vector<PIINT>,greater<PIINT>> pq;
        for(int i=0;i<n;i++)
            pq.push({matrix[i][0],{i,0}});
        PIINT elem;
        for(int i=0;i<k;i++){
            elem=pq.top();
            pq.pop();
            if(elem.second.second<n-1) {
                int x = elem.second.first;
                int y = elem.second.second + 1;
                pq.push({matrix[x][y], {x, y}});
            }
        }
        return elem.first;
    }
};


int main(int argc, char *argv[]){

    vector<vector<int>> matrix{{1,5,9,12},{10,11,13,14},{12,13,15,16}};
    int k=10;
    cout<<Solution().kthSmallest(matrix,k)<<endl;

    return 0;
}