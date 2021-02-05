#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;++i){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int j=i+1,k=n-1;
            bool lastMatch=false;
            while(j<k){
                int tt=nums[i]+nums[j]+nums[k];
                if(tt==0){
                    if(lastMatch&&nums[j]==nums[j-1]){
                        ++j,--k;
                        continue;
                    }
                    res.push_back({nums[i],nums[j],nums[k]});
                    ++j, --k;
                    lastMatch=true;
                }else {
                    if(tt>0)
                        --k;
                    else
                        ++j;
                    lastMatch=false;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
