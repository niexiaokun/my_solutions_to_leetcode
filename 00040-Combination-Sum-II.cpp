#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//40. 组合总和 II
//
//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次。
//
//说明：
//
//所有数字（包括目标数）都是正整数。
//解集不能包含重复的组合。
//
//示例 1:
//
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//        所求解集为:
//[
//[1, 7],
//[1, 2, 5],
//[2, 6],
//[1, 1, 6]
//]
//
//示例 2:
//
//输入: candidates = [2,5,2,1,2], target = 5,
//        所求解集为:
//[
//[1,2,2],
//[5]
//]


template <typename T>
void printVec(vector<T>& nums){
    if(nums.empty())
        return;
    cout<<"[ ";
    for(T& u:nums)
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
private:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates,vector<int> nums, int target, int index){
        for(int i=index;i<candidates.size();i++) {
            if(i>index&&candidates[i]==candidates[i-1])
                continue;
            if(target==candidates[i]){
                nums.emplace_back(candidates[i]);
                res.push_back(nums);
                return;
            }
            else if (target > candidates[i]) {
                nums.emplace_back(candidates[i]);
                dfs(candidates, nums, target - candidates[i], i + 1);
                nums.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
//        printVec(candidates);

        vector<int> nums;
        dfs(candidates,nums,target,0);

        return res;
    }
};




int main(int argc, char *argv[]){

    vector<int> candidates{10,1,2,7,6,1,5};
    int target=8;

//    printVec(candidates);
//    printVvec(Solution().combinationSum2(candidates,target));

    candidates={2,5,2,1,2};
    target=5;
    printVvec(Solution().combinationSum2(candidates,target));

    return 0;
}