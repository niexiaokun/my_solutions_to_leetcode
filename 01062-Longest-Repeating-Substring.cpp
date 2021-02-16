#include <bits/stdc++.h>

using namespace std;

//1062. 最长重复子串
//
//        给定字符串 S，找出最长重复子串的长度。如果不存在重复子串就返回 0。
//
//
//
//示例 1：
//
//输入："abcd"
//输出：0
//解释：没有重复子串。
//
//示例 2：
//
//输入："abbaba"
//输出：2
//解释：最长的重复子串为 "ab" 和 "ba"，每个出现 2 次。
//
//示例 3：
//
//输入："aabcaabdaab"
//输出：3
//解释：最长的重复子串为 "aab"，出现 3 次。
//
//示例 4：
//
//输入："aaaaa"
//输出：4
//解释：最长的重复子串为 "aaaa"，出现 2 次。
//
//
//
//提示：
//
//字符串 S 仅包含从 'a' 到 'z' 的小写英文字母。
//1 <= S.length <= 1500


class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        string_view ss(s);
        unordered_map<string_view, int> f;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j)
                ++f[s.substr(i, j - i + 1)];
        }
        int res = 0;
        for (const auto &p:f) {
            if (p.second > 1)
                res = max(res, (int) p.first.size());
        }
        return res;
    }
};


class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        string_view ss(s);
        int lo = 0, hi = n;
        while (lo < hi) {    //二分查找, 查找最短不重复子串长度, 从而得到最长重复子串
            int mid = (lo + hi) / 2;
            unordered_map<string_view, int> f;
            bool checked = true;
            for (int i = 0; i + mid <= n; ++i) {
                string_view sub = ss.substr(i, mid);
                if (f.count(sub)) {
                    checked = false;
                    break;
                }
                ++f[sub];
            }
            if (checked)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo - 1;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

