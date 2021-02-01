#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//491. 递增子序列
//
//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
//
//示例:
//
//输入: [4, 6, 7, 7]
//输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//
//说明:
//
//给定数组的长度不会超过15。
//数组中的整数范围是 [-100,100]。
//给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。


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


class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start, vector<int> v){
        if(v.size()>=2)
            res.push_back(v);
        if(start==nums.size()){
            return;
        }
        unordered_set<int> mset;
        for(int i=start;i<nums.size();i++){
            if(mset.count(nums[i]))
                continue;
            mset.insert(nums[i]);
            if(v.empty()||nums[i]>=v.back())
            {
                v.emplace_back(nums[i]);
                dfs(nums,i+1,v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        dfs(nums,0,v);
        return res;
    }
};



int main(int argc, char *argv[]){

    vector<int> nums{4,6,7,7};
    utils::printVvec(Solution().findSubsequences(nums));

    return 0;
}