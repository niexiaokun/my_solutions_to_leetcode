#include <bits/stdc++.h>

using namespace std;

//227. 基本计算器 II
//
//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//
//整数除法仅保留整数部分。
//
//
//
//示例 1：
//
//输入：s = "3+2*2"
//输出：7
//
//示例 2：
//
//输入：s = " 3/2 "
//输出：1
//
//示例 3：
//
//输入：s = " 3+5 / 2 "
//输出：5
//
//
//
//提示：
//
//1 <= s.length <= 3 * 105
//s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
//        s 表示一个 有效表达式
//表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
//        题目数据保证答案是一个 32-bit 整数


class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<int> stk;
        int num = 0;
        char c = '+';
        s += '*';
        for (int i = 0; i <= n; ++i) {
            if (s[i] == ' ')
                continue;
            else if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else {
                if (c == '+')
                    stk.emplace_back(num);
                else if (c == '-')
                    stk.emplace_back(-1 * num);
                else if (c == '*') {
                    num *= stk.back();
                    stk.pop_back();
                    stk.emplace_back(num);
                } else if (c == '/') {
                    num = stk.back() / num;
                    stk.pop_back();
                    stk.emplace_back(num);
                }
                num = 0;
                c = s[i];
            }
        }
        int res = 0;
        for (int i = 0; i < stk.size(); ++i)
            res += stk[i];
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

