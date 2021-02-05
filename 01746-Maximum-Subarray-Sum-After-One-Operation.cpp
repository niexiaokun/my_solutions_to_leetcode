#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int maxSumAfterOperation(vector<int>& nums) {
//        int n=nums.size();
//        vector<vector<int>> dp(n,vector<int>(2));
//        dp[0][0]=nums[0]*nums[0];
//        int cur=nums[0];
//        for(int i=1;i<n;++i){
//            dp[i][0]=max(nums[i]*nums[i], nums[i]*nums[i]+cur);
//            cur=max(nums[i], nums[i]+cur);
//        }
//        dp[n-1][1]=nums[n-1];
//        for(int i=n-2;i>=0;--i){
//            dp[i][1]=max(nums[i], nums[i]+dp[i+1][1]);
//        }
//        int res=dp[n-1][0];
//        for(int i=0;i<n-1;++i){
//            res=max(res,max(dp[i][0],dp[i][0]+dp[i+1][1]));
//        }
//        return res;
//    }
//};

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n=nums.size();
        int replace=nums[0]*nums[0];
        int noreplace=nums[0];
        int res=replace;
        for(int i=1;i<n;++i){
            replace=max(nums[i]*nums[i]+max(noreplace,0),nums[i]+replace);
            noreplace=nums[i]+max(noreplace,0);
            res=max(res,replace);
        }
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
