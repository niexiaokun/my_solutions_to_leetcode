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

//class Solution {
//private:
//    vector<vector<int>> res;
//    void dfs(vector<int>& candidates, int target, int index, vector<int> nums){
//        if(index==candidates.size()||target<candidates[index])
//            return;
//        if(candidates[index]==target){
//            nums.emplace_back(target);
//            res.push_back(nums);
//            return;
//        }
//        dfs(candidates,target,index+1,nums);
//        nums.emplace_back(candidates[index]);
//        dfs(candidates,target-candidates[index],index,nums);
//    }
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        sort(candidates.begin(),candidates.end());
//        vector<int> nums;
//        dfs(candidates,target,0,nums);
//        return res;
//    }
//};


class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, int index, vector<int> nums){
        for(int i=index;i<candidates.size();i++){
            if(target==candidates[i]){
                nums.emplace_back(candidates[i]);
                res.push_back(nums);
                return;
            }else if(target>candidates[i]){
                nums.emplace_back(candidates[i]);
                dfs(candidates,target-candidates[i],i,nums);
                nums.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        printVec(candidates);

        vector<int> nums;
        dfs(candidates,target,0,nums);
        return res;
    }
};


int main(int argc, char *argv[]){

    vector<int> candidates{2,7,6,3,5,1};
    int target=9;

    printVec(candidates);
    printVvec(Solution().combinationSum(candidates,target));


    return 0;
}
