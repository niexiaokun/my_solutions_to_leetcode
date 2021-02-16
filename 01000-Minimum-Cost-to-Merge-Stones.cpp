#include <bits/stdc++.h>

using namespace std;

//1000. 合并石头的最低成本
//
//        有 N 堆石头排成一排，第 i 堆中有 stones[i] 块石头。
//
//每次移动（move）需要将连续的 K 堆石头合并为一堆，而这个移动的成本为这 K 堆石头的总数。
//
//找出把所有石头合并成一堆的最低成本。如果不可能，返回 -1 。
//
//
//
//示例 1：
//
//输入：stones = [3,2,4,1], K = 2
//输出：20
//解释：
//从 [3, 2, 4, 1] 开始。
//合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
//合并 [4, 1]，成本为 5，剩下 [5, 5]。
//合并 [5, 5]，成本为 10，剩下 [10]。
//总成本 20，这是可能的最小值。
//
//示例 2：
//
//输入：stones = [3,2,4,1], K = 3
//输出：-1
//解释：任何合并操作后，都会剩下 2 堆，我们无法再进行合并。所以这项任务是不可能完成的。.
//
//示例 3：
//
//输入：stones = [3,5,1,2,6], K = 3
//输出：25
//解释：
//从 [3, 5, 1, 2, 6] 开始。
//合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
//合并 [3, 8, 6]，成本为 17，剩下 [17]。
//总成本 25，这是可能的最小值。
//
//
//
//提示：
//
//1 <= stones.length <= 30
//2 <= K <= 30
//1 <= stones[i] <= 100


class Solution {
public:
    int mergeStones(vector<int> &stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0)
            return -1;
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + stones[i - 1];
        for (int i = 0; i + K <= n; ++i)
            dp[i][i + K - 1] = pre[i + K] - pre[i];
        for (int t = K + 1; t <= n; ++t) {
            for (int l = 0; l + t <= n; ++l) {
                int r = l + t - 1;
                dp[l][r] = INT_MAX;
                for (int x = l; x < r; x += K - 1)
                    dp[l][r] = min(dp[l][r], dp[l][x] + dp[x + 1][r]);
                if ((r - l) % (K - 1) == 0)
                    dp[l][r] += pre[r + 1] - pre[l];
            }
        }
        return dp[0][n - 1];
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

