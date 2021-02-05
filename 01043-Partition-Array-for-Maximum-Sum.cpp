#include <bits/stdc++.h>

using namespace std;


//class Solution {
//private:
//    vector<int> memo;
//    int dfs(const vector<int>& arr, int index, int k){
//        if(index==arr.size())
//            return 0;
//        if(memo[index]!=-1)
//            return memo[index];
//        int res=0;
//        int tmp=0;
//        for(int t=1;t<=k&&index+t<=arr.size();++t){
//            tmp=max(tmp, arr[index+t-1]);
//            res=max(res,tmp*t+dfs(arr,index+t,k));
//        }
//        memo[index]=res;
//        return res;
//    }
//public:
//    int maxSumAfterPartitioning(vector<int> &arr, int k) {
//        memo=vector<int>(arr.size(),-1);
//        return dfs(arr, 0, k);
//    }
//};


class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n);
        int tmp = 0;
        for (int i = 0; i < k; ++i) {
            tmp = max(tmp, arr[i]);
            dp[i] = tmp * (i + 1);
        }
        for (int i = k; i < n; ++i) {
            tmp = arr[i];
            for (int t = 1; t <= k; ++t) {
                dp[i] = max(dp[i], dp[i - t] + t * tmp);
                tmp = max(tmp, arr[i - t]);
            }
        }
        return dp[n - 1];
    }
};


int main(int argc, char* argv[]){

    return 0;
}
