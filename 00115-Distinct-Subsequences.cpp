#include <bits/stdc++.h>

using namespace std;

//115. 不同的子序列
//
//        给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
//
//字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
//
//题目数据保证答案符合 32 位带符号整数范围。
//
//
//
//示例 1：
//
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//(上箭头符号 ^ 表示选取的字母)
//        rabbbit
//        ^^^^ ^^
//        rabbbit
//        ^^ ^^^^
//        rabbbit
//        ^^^ ^^^
//
//        示例 2：
//
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。
//(上箭头符号 ^ 表示选取的字母)
//        babgbag
//        ^^ ^
//        babgbag
//        ^^    ^
//        babgbag
//        ^    ^^
//        babgbag
//          ^  ^^
//        babgbag
//            ^^^
//
//
//
//        提示：
//
//0 <= s.length, t.length <= 1000
//s 和 t 由英文字母组成


class Solution {
private:
    vector<vector<int>> memo;

    int dfs(const string &s, const string &t, int index1, int index2) {
        if (index2 == t.size())
            return 1;
        else if (index1 == s.size())
            return 0;
        if (memo[index1][index2] != -1)
            return memo[index1][index2];
        int res = dfs(s, t, index1 + 1, index2);
        if (s[index1] == t[index2])
            res += dfs(s, t, index1 + 1, index2 + 1);
        memo[index1][index2] = res;
        return res;
    }

public:
    int numDistinct(string s, string t) {
        memo.resize(s.size(), vector<int>(t.size(), -1));
        return dfs(s, t, 0, 0);
    }
};


int main(int argc, char *argv[]){

    return 0;
}

