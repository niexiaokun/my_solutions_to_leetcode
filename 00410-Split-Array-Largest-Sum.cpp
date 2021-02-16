#include <bits/stdc++.h>

using namespace std;

//410. 分割数组的最大值
//
//        给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。
//
//设计一个算法使得这 m 个子数组各自和的最大值最小。
//
//
//
//示例 1：
//
//输入：nums = [7,2,5,10,8], m = 2
//输出：18
//解释：
//一共有四种方法将 nums 分割为 2 个子数组。 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
//因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
//
//示例 2：
//
//输入：nums = [1,2,3,4,5], m = 2
//输出：9
//
//示例 3：
//
//输入：nums = [1,4,4], m = 3
//输出：4
//
//
//
//提示：
//
//1 <= nums.length <= 1000
//0 <= nums[i] <= 106
//1 <= m <= min(50, nums.length)


//class Solution {
//private:
//    vector<vector<int>> memo;
//    vector<int> pre;
//    int dfs(const vector<int> &nums, int index, int left) {  //记忆花搜索
//        if (memo[index][left] != -1)
//            return memo[index][left];
//        if (left == 1) {
//            memo[index][left] = pre.back() - pre[index];
//            return memo[index][left];
//        }
//        int res = INT_MAX;
//        for (int i = index; i <= (int) nums.size() - left; ++i) {
//            int tmp = pre[i+1]-pre[index];
//            res = min(res, max(tmp, dfs(nums, i + 1, left - 1)));
//        }
//        memo[index][left] = res;
//        return res;
//    }
//
//public:
//    int splitArray(vector<int> &nums, int m) {
//        pre.resize(nums.size()+1);
//        for(int i=1;i<=nums.size();++i)
//            pre[i]=pre[i-1]+nums[i-1];
//        memo.resize(nums.size(), vector<int>(m + 1, -1));
//        return dfs(nums, 0, m);
//    }
//};

//class Solution {
//public:
//    int splitArray(vector<int> &nums, int m) {
//        int n = nums.size();
//        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
//        int tmp = INT_MIN;
//        for (int i = 0; i < m; ++i) {
//            tmp = max(tmp, nums[i]);
//            dp[i][i] = tmp;
//        }
//        vector<int> pre(n + 1);
//        for (int i = 1; i <= n; ++i) {
//            pre[i] = pre[i - 1] + nums[i - 1];
//            dp[i - 1][0] = pre[i];
//        }
//        for (int i = 2; i < n; ++i) {    //动态规划
//            for (int j = 1; j < min(m, i); ++j) {
//                for (int k = j - 1; k < i; ++k) {
//                    dp[i][j] = min(dp[i][j], max(pre[i + 1] - pre[k + 1], dp[k][j - 1]));
//                }
//            }
//        }
//        return dp[n - 1][m - 1];
//    }
//};


class Solution {
private:
    bool check(const vector<int> &nums, int x, int m) {
        int sum = 0;
        int cnt = 1;    //初始为1
        for (int u:nums) {
            if (sum + u > x) {
                ++cnt;
                sum = u;
            } else
                sum += u;
        }
        return cnt <= m;
    }

public:
    int splitArray(vector<int> &nums, int m) {
        int lo = 0, hi = 0;
        for (int x:nums) {
            lo = max(lo, x);
            hi += x;
        }
        while (lo < hi) {   //二分查找
            int mid = (lo + hi) / 2;
            if (check(nums, mid, m))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};


int main(int argc, char* argv[]) {



    return 0;
}

