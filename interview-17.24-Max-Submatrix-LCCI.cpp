#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;


//面试题 17.24. 最大子矩阵
//
//给定一个正整数、负整数和 0 组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。
//
//返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，r2, c2 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。
//
//注意：本题相对书上原题稍作改动
//
//        示例：
//
//输入：
//[
//[-1,0],
//[0,-1]
//]
//输出：[0,1,0,1]
//解释：输入中标粗的元素即为输出所表示的矩阵
//
//
//
//        说明：
//
//1 <= matrix.length, matrix[0].length <= 200

namespace utils{
    template <typename T>
    void printVec(const vector<T>& nums){
        if(nums.empty())
            return;
        cout<<"[ ";
        for(const T& u:nums)
            cout<<u<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVec(const vector<T>& nums, int l, int r){
        if(l>r)
            return;
        cout<<"[ ";
        for(int i=l;i<=r;i++)
            cout<<nums[i]<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVvec(const vector<vector<T>>& nums){
        if(nums.empty())
            return;
        cout<<"["<<endl;
        for(const vector<T>& v:nums) {
            cout<<"[ ";
            for (const T &u:v)
                cout << u << " ";
            cout<<"]"<<endl;
        }
        cout<<"]"<<endl;
    }
}

//class Solution {
//public:
//    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
//        int m=matrix.size();
//        int n=matrix[0].size();
//        vector<int> ans(4);
//        int cmin;
//        int dpsum_max=matrix[0][0];
//        int dpsum_min,dpsum;
//        for(int r1=0;r1<m;r1++){
//            vector<int> dp(n);
//            for(int r2=r1;r2<m;r2++){
//                cmin=-1;
//                dpsum_min=dpsum=0;
//                for(int c2=0;c2<n;c2++){
//                    dp[c2]+=matrix[r2][c2];
//                    dpsum+=dp[c2];
//                    if(dpsum-dpsum_min>dpsum_max){
//                        dpsum_max=dpsum-dpsum_min;
//                        ans={r1,cmin+1,r2,c2};
//                    }
//                    if(dpsum<dpsum_min){
//                        dpsum_min=dpsum;
//                        cmin=c2;
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//};


class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> presum(n,vector<int>(m+1));
        for(int c=0;c<n;c++){
            for(int r=0;r<m;r++){
                presum[c][r+1]=presum[c][r]+matrix[r][c];
            }
        }
        vector<int> ans(4);
        int cmin;
        int dpsum_max=matrix[0][0];
        int dpsum_min,dpsum;
        for(int r1=0;r1<m;r1++){
            for(int r2=r1;r2<m;r2++){
                cmin=-1;
                dpsum_min=dpsum=0;
                for(int c2=0;c2<n;c2++){
                    dpsum+=presum[c2][r2+1]-presum[c2][r1];
                    if(dpsum-dpsum_min>dpsum_max){
                        dpsum_max=dpsum-dpsum_min;
                        ans={r1,cmin+1,r2,c2};
                    }
                    if(dpsum<dpsum_min){
                        dpsum_min=dpsum;
                        cmin=c2;
                    }
                }
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]){

    vector<vector<int>> matrix={{3151, -640, 965, -1028, 2752, 407, -3605, 3822},
                                {199, -1324, 4120, -3604, -2489, 688, -3387, 693},
                                {232, -1357, -1904, -3874, 389, 4892, 4953, 2026},
                                {-3543, -3952, 4894, 476, 2049, -4907, -1278, 528},
                                {-639, 2117, -3267, -1706, 2253, -559, 4522, 2536},
                                {-2926, -582, -1572, 3750, 4487, -2988, 1746, -3075},
                                {3909, 3128, 1994, 3479, 3713, -2951, 3182, 4346},
                                {3463, -77, -3474, 1025, 3466, -2539, -4890, 871},
                                {-4853, 4617, 1733, 2745, 3823, -1327, -2342, 4386},
                                {-3396, -2758, -804, 1161, -974, 504, -4452, 3484}};
    utils::printVec(Solution().getMaxMatrix(matrix));

    matrix={{-1,0},{0,-1}};
    utils::printVec(Solution().getMaxMatrix(matrix));

    matrix={{-1, -2, -9, 6}, {8, -9, -3, -6}, {2, 9, -7, -6}};
    utils::printVec(Solution().getMaxMatrix(matrix));
    
    return 0;
}