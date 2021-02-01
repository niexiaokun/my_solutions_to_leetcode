#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//611. 有效三角形的个数
//
//给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
//
//示例 1:
//
//输入: [2,2,3,4]
//输出: 3
//解释:
//有效的组合是:
//2,3,4 (使用第一个 2)
//2,3,4 (使用第二个 2)
//2,2,3
//
//注意:
//
//数组长度不超过1000。
//数组里整数的范围为 [0, 1000]。


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        sort(nums.begin(),nums.end());
        int l,r,res=0;
        for(int i=0;i<n-2;i++){
            l=i+1,r=i+1;
            while(l<n-1){

            }
        }
        return res;
    }
};


int main(int argc, char *argv[]){

    vector<int> nums={2,2,3,4};
    cout<<Solution().triangleNumber(nums)<<endl;

    nums={2,2,3,4,3,3,4,5,6,4,2};
    cout<<Solution().triangleNumber(nums)<<endl;

    return 0;
}