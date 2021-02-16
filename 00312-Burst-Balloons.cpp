#include <bits/stdc++.h>

using namespace std;

//312. 戳气球
//
//        有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
//
//现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
//
//求所能获得硬币的最大数量。
//
//
//示例 1：
//
//输入：nums = [3,1,5,8]
//输出：167
//解释：
//nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
//
//示例 2：
//
//输入：nums = [1,5]
//输出：10
//
//
//
//提示：
//
//n == nums.length
//1 <= n <= 500
//0 <= nums[i] <= 100


//class Solution {
//private:
//    vector<vector<int>> memo;
//
//    int solve(const vector<int> &values, int l, int r) {
//        if (l + 1 == r) {
//            return 0;
//        }
//        if (memo[l][r] != -1)
//            return memo[l][r];
//        int res = 0;
//        int cur = values[l] * values[r];
//        for (int i = l + 1; i < r; ++i) {    //逆向思维, 一个个恢复气球, 考虑第 i 个气球 则(l,i)和(i,r)没有气球
//            res = max(res, values[i] * cur + solve(values, l, i) + solve(values, i, r));
//        }
//        memo[l][r] = res;
//        return res;
//    }
//
//public:
//    int maxCoins(vector<int> &nums) {
//        int n = nums.size();
//        vector<int> values(n + 2, 1);
//        for (int i = 1; i <= n; ++i)
//            values[i] = nums[i - 1];
//        memo.resize(n + 1, vector<int>(n + 2, -1));
//        return solve(values, 0, n + 1);
//    }
//};

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        vector<int> values(n+2,1);
        for(int i=1;i<=n;++i)
            values[i]=nums[i-1];
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        for(int t=1;t<=n;++t){
            for(int l=0;l+t<=n;++l){
                int r=l+t+1;
                for(int i=l+1;i<r;++i){  //正向思维,考虑第i个气球 (l,i)和(i,r)没有气球(气球已经被戳破了)
                    dp[l][r]=max(dp[l][r],values[l]*values[i]*values[r]+dp[l][i]+dp[i][r]);
                }
            }
        }
        return dp[0][n+1];
    }
};


int main(int argc, char* argv[]) {

    vector<int> nums={3,1,5,8};
    cout<<Solution().maxCoins(nums)<<endl;

    nums={8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2,2};
    cout<<Solution().maxCoins(nums)<<endl;

    return 0;
}

