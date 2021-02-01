#include <iostream>
#include <vector>


using namespace std;


//713. 乘积小于K的子数组
//
//给定一个正整数数组 nums。
//
//找出该数组内乘积小于 k 的连续的子数组的个数。
//
//示例 1:
//
//输入: nums = [10,5,2,6], k = 100
//输出: 8
//解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
//需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
//
//说明:
//
//0 < nums.length <= 50000
//0 < nums[i] < 1000
//0 <= k < 10^6

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        if(nums.size()==1)
            return nums[0]<k? 1:0;
        int prod=1;
        int l=0;
        int res=0;
        for(int r=0;r<nums.size();r++){
            prod*=nums[r];
            while(l<=r&&prod>=k){
                prod/=nums[l];
                l++;
            }
            if(prod<k)
                res+=r-l+1;
        }
        return res;
    }
};

int main(int argc, char *argv[]){

    vector<int> nums{10,5,2,6};
    int k=100;
    cout<<Solution().numSubarrayProductLessThanK(nums,k)<<endl;

    nums={1,2,3};
    k=0;
    cout<<Solution().numSubarrayProductLessThanK(nums,k)<<endl;

    nums={1,1,1};
    k=1;
    cout<<Solution().numSubarrayProductLessThanK(nums,k)<<endl;


    return 0;
}