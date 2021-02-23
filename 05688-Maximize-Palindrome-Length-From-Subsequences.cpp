#include <bits/stdc++.h>

using namespace std;

//5688. 由子序列构造的最长回文串的长度
//
//        给你两个字符串 word1 和 word2 ，请你按下述方法构造一个字符串：
//
//从 word1 中选出某个 非空 子序列 subsequence1 。
//从 word2 中选出某个 非空 子序列 subsequence2 。
//连接两个子序列 subsequence1 + subsequence2 ，得到字符串。
//
//返回可按上述方法构造的最长 回文串 的 长度 。如果无法构造回文串，返回 0 。
//
//字符串 s 的一个 子序列 是通过从 s 中删除一些（也可能不删除）字符而不更改其余字符的顺序生成的字符串。
//
//回文串 是正着读和反着读结果一致的字符串。
//
//
//
//示例 1：
//
//输入：word1 = "cacb", word2 = "cbba"
//输出：5
//解释：从 word1 中选出 "ab" ，从 word2 中选出 "cba" ，得到回文串 "abcba" 。
//
//示例 2：
//
//输入：word1 = "ab", word2 = "ab"
//输出：3
//解释：从 word1 中选出 "ab" ，从 word2 中选出 "a" ，得到回文串 "aba" 。
//
//示例 3：
//
//输入：word1 = "aa", word2 = "bb"
//输出：0
//解释：无法按题面所述方法构造回文串，所以返回 0 。
//
//提示：
//
//1 <= word1.length, word2.length <= 1000
//word1 和 word2 由小写英文字母组成


//class Solution {
//public:
//    int longestPalindrome(string s1, string s2) {
//        int m = s1.size();
//        string s = s1 + s2;
//        int n = s.size();
//        vector<vector<int>> dp(n, vector<int>(n));      //[l...r] s[l]==s[r]
//        vector<vector<int>> dp1(n, vector<int>(n, 1));  //[l...r] s[l]不一定等于s[r], 初始化为 1，, 任意的子串至少包含一个长度为1的回文
//        for (int i = 0; i < n; ++i)
//            dp[i][i] = 1;
//        for (int t = 2; t <= n; ++t) {
//            for (int l = 0; l + t <= n; ++l) {
//                int r = l + t - 1;
//                if (t == 2) {
//                    if (s[l] == s[r])
//                        dp[l][r] = dp1[l][r] = 2;
//                } else {
//                    if (s[l] == s[r])
//                        dp[l][r] = dp1[l][r] = dp1[l + 1][r - 1] + 2;
//                    dp1[l][r] = max(dp1[l][r], max(dp1[l + 1][r], dp1[l][r - 1]));
//                }
//            }
//        }
//        int res = 0;
//        for (int i = 0; i < m; ++i) {
//            for (int j = m; j < n; ++j)
//                res = max(res, dp[i][j]);
//        }
//        return res;
//    }
//};

//class Solution {
//public:
//    int longestPalindrome(string s1, string s2) {
//        int m = s1.size();
//        string s = s1 + s2;
//        int n = s.size();
//        vector<vector<int>> dp(n, vector<int>(n));
//        vector<vector<int>> dp1(n, vector<int>(n));
//        for (int i = 0; i < n; ++i)
//            dp[i][i] = dp1[i][i] = 1;
//        for (int t = 2; t <= n; ++t) {
//            for (int l = 0; l + t <= n; ++l) {
//                int r = l + t - 1;
//                if (s[l] == s[r])
//                    dp[l][r] = dp1[l][r] = dp1[l + 1][r - 1] + 2;
//                dp1[l][r] = max(dp1[l][r], max(dp1[l + 1][r], dp1[l][r - 1]));
//            }
//        }
//        int res = 0;
//        for (int i = 0; i < m; ++i) {
//            for (int j = m; j < n; ++j)
//                res = max(res, dp[i][j]);
//        }
//        return res;
//    }
//};

class Solution {
private:
    void getPalindrome(const string &s, vector<vector<int>> &dp) {
        int n = s.size();
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int t = 2; t <= n; ++t) {
            for (int i = 0; i + t <= n; ++i) {
                int j = i + t - 1;
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if (s[i] == s[j])
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);

            }
        }
    }

public:
    int longestPalindrome(string s1, string s2) {
        reverse(s2.begin(), s2.end());
        s1 = " " + s1;
        s2 = " " + s2;
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (s1[i] == s2[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        vector<vector<int>> g1(m + 1, vector<int>(m));
        vector<vector<int>> g2(n + 1, vector<int>(n));
        getPalindrome(s1, g1);
        getPalindrome(s2, g2);
        int res = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (f[i][j])
                    res = max(res, f[i][j] * 2 + max(g1[i + 1][m - 1], g2[j + 1][n - 1]));
            }
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    string word1 = "cacb", word2 = "cbba";
    cout << Solution().longestPalindrome(word1, word2) << endl;

    word1 = "rhuzwqohquamvsz";
    word2 = "kvunbxje";
    cout << Solution().longestPalindrome(word1, word2) << endl;

    return 0;
}

