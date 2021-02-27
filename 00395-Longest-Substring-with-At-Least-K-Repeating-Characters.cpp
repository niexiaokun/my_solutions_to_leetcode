#include <bits/stdc++.h>

using namespace std;

//395. 至少有K个重复字符的最长子串
//
//        给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
//
//
//
//示例 1：
//
//输入：s = "aaabb", k = 3
//输出：3
//解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
//
//示例 2：
//
//输入：s = "ababbc", k = 2
//输出：5
//解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
//
//
//
//提示：
//
//1 <= s.length <= 10^4
//s 仅由小写英文字母组成
//1 <= k <= 10^5



class Solution {
private:
    int sub(string &s, int l, int r, int k) {
        if (r - l + 1 < k)
            return 0;
        unordered_map<char, int> f;
        for (int i = l; i <= r; ++i)
            ++f[s[i]];
        bool flag = true;
        for (auto &p:f)
            if (p.second < k) {
                flag = false;
                break;
            }
        if (flag)
            return r - l + 1;
        int res = 0;
        int j = l;
        for (int i = l; i <= r; ++i) {
            if (f[s[i]] < k) {
                res = max(res, sub(s, j, i - 1, k));
                j = i + 1;
            }
        }
        res = max(res, sub(s, j, r, k));
        return res;
    }

public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return sub(s, 0, n - 1, k);
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

