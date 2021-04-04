#include <bits/stdc++.h>

using namespace std;

//1049. 最后一块石头的重量 II
//
//有一堆石头，每块石头的重量都是正整数。
//
//每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//
//如果 x == y，那么两块石头都会被完全粉碎；
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
//
//最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
//
//
//
//示例：
//
//输入：[2,7,4,1,8,1]
//输出：1
//解释：
//组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
//组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
//组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
//组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
//
//
//
//提示：
//
//1 <= stones.length <= 30
//1 <= stones[i] <= 1000


class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int v = sum / 2;
        int n = stones.size();
        vector<vector<int>> dp(v + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= v; ++j) {
                if (j >= stones[i])
                    dp[j][i] = max(dp[j][i - 1], dp[j - stones[i - 1]][i - 1] + stones[i - 1]);
                else
                    dp[j][i] = dp[j][i - 1];
            }
        }
        return sum - dp[v][n] * 2;
    }
};


int main(int argc, char *argv[]) {

    vector<int> nums = {31, 26, 33, 21, 40};

    cout << Solution().lastStoneWeightII(nums) << endl;

    return 0;
}

