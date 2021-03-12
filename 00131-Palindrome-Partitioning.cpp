#include <bits/stdc++.h>

using namespace std;

//131. 分割回文串
//
//        给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//
//回文串 是正着读和反着读都一样的字符串。
//
//
//
//示例 1：
//
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
//
//示例 2：
//
//输入：s = "a"
//输出：[["a"]]
//
//
//
//提示：
//
//1 <= s.length <= 16
//s 仅由小写英文字母组成


class Solution {
private:
    vector<vector<string>> res;

    void dfs(const string &s, int index, const vector<vector<bool>> &dp, vector<string> &tmp) {
        if (index == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (dp[index][i]) {
                tmp.emplace_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, dp, tmp);
                tmp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for (int i = 0; i < n - 1; ++i)
            dp[i][i + 1] = s[i] == s[i + 1];
        for (int t = 3; t <= n; ++t) {
            for (int i = 0; i + t <= n; ++i) {
                int j = i + t - 1;
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }
        vector<string> tmp;
        dfs(s, 0, dp, tmp);
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

