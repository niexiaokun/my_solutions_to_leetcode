#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//39. 组合总和
//
//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//
//说明：
//
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。
//
//示例 1：
//
//输入：candidates = [2,3,6,7], target = 7,
//        所求解集为：
//[
//[7],
//[2,2,3]
//]
//
//示例 2：
//
//输入：candidates = [2,3,5], target = 8,
//        所求解集为：
//[
//[2,2,2,2],
//[2,3,3],
//[3,5]
//]
//
//
//
//提示：
//
//1 <= candidates.length <= 30
//1 <= candidates[i] <= 200
//candidate 中的每个元素都是独一无二的。
//1 <= target <= 500


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



class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int mod=10000000007;
        vector<long long> dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int num:nums){
                if(i>=num){
                    dp[i]+=dp[i-num]%mod;
                }
            }
        }
        return dp[target];
    }
};




int main(int argc, char *argv[]){

    vector<int> nums{1,2,3};
    int target=4;
    cout<<Solution().combinationSum4(nums,target)<<endl;

    nums={4,2,1};
    target=32;
    cout<<Solution().combinationSum4(nums,target)<<endl;

    nums={3,33,333};
    target=10000;
    cout<<Solution().combinationSum4(nums,target)<<endl;


    return 0;
}
