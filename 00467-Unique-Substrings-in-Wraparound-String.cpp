#include <bits/stdc++.h>

using namespace std;

//467. 环绕字符串中唯一的子字符串
//
//        把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//
//现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。
//
//注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。
//
//
//
//示例 1:
//
//输入: "a"
//输出: 1
//解释: 字符串 S 中只有一个"a"子字符。
//
//
//
//示例 2:
//
//输入: "cac"
//输出: 2
//解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。.
//
//
//
//示例 3:
//
//输入: "zab"
//输出: 6
//解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.


//class Solution {
//public:
//    int findSubstringInWraproundString(string p) {
//        int n = p.size();
//        if (n == 0)
//            return 0;
//        vector<int> dp(n);
//        vector<int> f(26);
//        dp[0] = 1;
//        f[p[0] - 'a'] = 1;
//        for (int i = 1; i < n; ++i) {
//            if ((p[i] - p[i - 1] - 1) % 26 == 0)
//                dp[i] = dp[i - 1] + 1;
//            else
//                dp[i] = 1;
//            f[p[i] - 'a'] = max(f[p[i] - 'a'], dp[i]);
//        }
//        return accumulate(f.begin(), f.end(), 0);
//    }
//};

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if (n == 0)
            return 0;
        vector<int> f(26);
        int cur = 1;
        f[p[0] - 'a'] = 1;
        for (int i = 1; i < n; ++i) {
            if ((p[i] - p[i - 1] - 1) % 26 == 0)
                ++cur;
            else
                cur = 1;
            f[p[i] - 'a'] = max(f[p[i] - 'a'], cur);
        }
        return accumulate(f.begin(), f.end(), 0);
    }
};

int main(int argc, char* argv[]){

    return 0;
}
