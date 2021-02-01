#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//560. 和为K的子数组
//
//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
//
//示例 1 :
//
//输入:nums = [1,1,1], k = 2
//输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
//
//说明 :
//
//数组的长度为 [1, 20,000]。
//数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int res=0,sum=0;
        for(int num:nums){
            sum+=num;
            if(mp.count(sum-k))
                res+=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};

int main(int argc, char *argv[]){

    vector<int> nums{1,1,1};
    int k=2;
    cout<<Solution().subarraySum(nums,k)<<endl;

    nums={1};
    k=0;
    cout<<Solution().subarraySum(nums,k)<<endl;

    nums={-1,-1,1};
    k=1;
    cout<<Solution().subarraySum(nums,k)<<endl;

    nums={1,2,0,0,3,0,2};
    auto it = unique(nums.begin(),nums.end());
    cout<<*it<<endl;

    cout<<0%1<<endl;
    return 0;
}