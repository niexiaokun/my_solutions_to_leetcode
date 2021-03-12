#include <bits/stdc++.h>

using namespace std;

//5682. 所有子字符串美丽值之和
//
//        一个字符串的 美丽值 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。
//
//比方说，"abaacc" 的美丽值为 3 - 1 = 2 。
//
//给你一个字符串 s ，请你返回它所有子字符串的 美丽值 之和。
//
//
//
//示例 1：
//
//输入：s = "aabcb"
//输出：5
//解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。
//
//示例 2：
//
//输入：s = "aabcbaa"
//输出：17
//
//
//
//提示：
//
//1 <= s.length <= 500
//s 只包含小写英文字母。



//class Solution {
//public:
//    int beautySum(string s) {
//        int n = s.size();
//        if (n == 1)
//            return 0;
//        int res = 0;
//        vector<vector<int>> f(26, vector<int>(n + 1));
//        for (int i = 0; i < n; ++i) {
//            int a = s[i] - 'a';
//            for (int j = 0; j < 26; ++j) {
//                f[j][i + 1] = f[j][i] + (a == j);
//            }
//        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                int a = INT_MIN, b = INT_MAX;
//                for (int k = 0; k < 26; ++k) {
//                    int x = f[k][j + 1] - f[k][i];
//                    if (x) {
//                        a = max(a, x);
//                        b = min(b, x);
//                    }
//                }
//                res += a - b;
//            }
//        }
//        return res;
//    }
//};


class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        if (n == 1)
            return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> f(26);
            for (int j = i; j < n; ++j) {
                ++f[s[j] - 'a'];
                int a = INT_MIN, b = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    if (f[k]) {
                        a = max(a, f[k]);
                        b = min(b, f[k]);
                    }
                }
                res += a - b;
            }
        }
        return res;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}
