#include <bits/stdc++.h>

using namespace std;

//679. 24 点游戏
//
//        你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
//
//示例 1:
//
//输入: [4, 1, 8, 7]
//输出: True
//        解释: (8-4) * (7-1) = 24
//
//示例 2:
//
//输入: [1, 2, 1, 2]
//输出: False
//
//        注意:
//
//除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
//每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
//你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。


class Solution {
private:
    bool res;

    void dfs(const vector<double> &nums) {
        if (nums.size() == 1) {
            if (abs(nums[0] - 24) < 1e-6)
                res = true;
            return;
        }
        int n = nums.size();
        vector<bool> vis(n, true);
        for (int i = 0; i < n - 1; i++) {
            vis[i] = false;
            for (int j = i + 1; j < n; ++j) {
                if (j == i)
                    continue;
                vis[j] = false;
                vector<double> tmp;
                tmp.emplace_back((double) nums[i] + nums[j]);
                for (int k = 0; k < n; ++k) {
                    if (vis[k])
                        tmp.emplace_back(nums[k]);
                }
                dfs(tmp);
                tmp[0] = (double) nums[i] - nums[j];
                dfs(tmp);
                tmp[0] = (double) nums[j] - nums[i];
                dfs(tmp);
                tmp[0] = (double) nums[i] * nums[j];
                dfs(tmp);
                tmp[0] = (double) nums[i] / nums[j];
                dfs(tmp);
                tmp[0] = (double) nums[j] / nums[i];
                dfs(tmp);
                vis[j] = true;
            }
            vis[i] = true;
        }
    }

public:
    bool judgePoint24(vector<int> &nums) {
        int n = nums.size();
        vector<double> tmp(n);
        for (int i = 0; i < n; ++i)
            tmp[i] = nums[i];
        dfs(tmp);
        return res;
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums={3,3,8,8};
    cout<<boolalpha<<Solution().judgePoint24(nums)<<endl;

    return 0;
}

