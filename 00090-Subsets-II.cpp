#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void dfs(const vector<int>& nums, int index, vector<bool> used, vector<int> record){
        if(index==nums.size()){
            res.push_back(record);
            return;
        }
        dfs(nums,index+1,used,record);
        if(index>0&&nums[index]==nums[index-1]&&!used[index-1])
            return;
        record.emplace_back(nums[index]);
        used[index]=true;
        dfs(nums,index+1,used,record);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> record;
        sort(nums.begin(),nums.end());
        dfs(nums,0,used,record);
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
