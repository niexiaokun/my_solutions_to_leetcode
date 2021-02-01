#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//523. 连续的子数组和
//
//给定一个包含 非负数 的数组和一个目标 整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，且总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。
//
//
//
//示例 1：
//
//输入：[23,2,4,6,7], k = 6
//输出：True
//        解释：[2,4] 是一个大小为 2 的子数组，并且和为 6。
//
//示例 2：
//
//输入：[23,2,6,4,7], k = 6
//输出：True
//        解释：[23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
//
//
//
//说明：
//
//数组的长度不会超过 10,000 。
//你可以认为所有数字总和在 32 位有符号整数范围内。


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        k=abs(k);
        unordered_map<int,int> mp;
        mp[0]=-1;
        int res=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(k)
                sum%=k;
            if(mp.count(sum)){
                if(i-mp[sum]>=2)
                    return true;
            }
            else
                mp[sum]=i;
        }
        return false;
    }
};


int main(int argc, char *argv[]){

    vector<int> nums{0,0};
    int k=-1;
    cout<<Solution().checkSubarraySum(nums,k)<<endl;

    nums={23,2,4,6,7};
    k=9;
    cout<<Solution().checkSubarraySum(nums,k)<<endl;

    nums={0,0};
    k=0;
    cout<<Solution().checkSubarraySum(nums,k)<<endl;

    nums={0};
    k=-1;
    cout<<Solution().checkSubarraySum(nums,k)<<endl;

    nums={1,0};
    k=2;
    cout<<Solution().checkSubarraySum(nums,k)<<endl;

    nums={2,3,4,5};
    k=0;
    cout<<Solution().checkSubarraySum(nums,k)<<endl;

    return 0;
}