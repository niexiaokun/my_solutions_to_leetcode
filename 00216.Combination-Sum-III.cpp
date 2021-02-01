#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

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
private:
    vector<vector<int>> res;
    void dfs(int index,int k,int target,vector<int> nums){
        if(k==0)
            return;
        for(int i=index;i<=9;i++){
            if(target==i){
                if(k==1) {
                    nums.emplace_back(i);
                    res.push_back(nums);
                    return;
                }
            }else if(target>i){
                nums.emplace_back(i);
                dfs(i+1,k-1,target-i,nums);
                nums.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        dfs(1,k,n,nums);
        return res;
    }
};


int main(int argc, char *argv[]){

    int k=3, n=7;
    printVvec(Solution().combinationSum3(k,n));

    k=3, n=9;
    printVvec(Solution().combinationSum3(k,n));

    return 0;
}
