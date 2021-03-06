#include <bits/stdc++.h>

using namespace std;

//30. 串联所有单词的子串
//
//        给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//
//注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
//
//
//
//示例 1：
//
//输入：
//s = "barfoothefoobarman",
//        words = ["foo","bar"]
//输出：[0,9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。
//
//示例 2：
//
//输入：
//s = "wordgoodgoodgoodbestword",
//        words = ["word","good","best","word"]
//输出：[]


class Solution {
private:
    bool check(unordered_map<string, int> f, string &s, int l, int len, int k) {
        for (int i = l; i < l + len; i += k) {
            string ss = s.substr(i, k);
            if (f.count(ss)) {
                if (f[ss] == 0)
                    return false;
                --f[ss];
            } else
                return false;
        }
        return true;
    }

public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int n = s.size();
        int m = words.size();
        vector<int> res;
        if (n == 0 || m == 0)
            return res;
        int k = words[0].size();
        int len = m * k;
        unordered_map<string, int> f;
        for (const string &s:words)
            ++f[s];
        for (int i = 0; i + len <= n; ++i) {
            if (check(f, s, i, len, k))
                res.emplace_back(i);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

