#include <bits/stdc++.h>

using namespace std;

//面试题 16.26. 计算器
//
//        给定一个包含正整数、加(+)、减(-)、乘(*)、除(/)的算数表达式(括号除外)，计算其结果。
//
//表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
//
//示例 1:
//
//输入: "3+2*2"
//输出: 7
//
//示例 2:
//
//输入: " 3/2 "
//输出: 1
//
//示例 3:
//
//输入: " 3+5 / 2 "
//输出: 5
//
//说明：
//
//你可以假设所给定的表达式都是有效的。
//请不要使用内置的库函数 eval。


class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<int> stk;
        int num = 0;
        char c = '+';
        s += c;
        for (int i = 0; i <= n; ++i) {
            if (s[i] == ' ')
                continue;
            else if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else {
                if (c == '*') {
                    num = num * stk.back();
                    stk.pop_back();
                    stk.emplace_back(num);
                } else if (c == '/') {
                    num = stk.back() / num;
                    stk.pop_back();
                    stk.emplace_back(num);
                } else {
                    num = c == '-' ? -num : num;
                    stk.emplace_back(num);
                }
                num = 0;
                c = s[i];
            }
        }
        int res = 0;
        for (int x : stk)
            res += x;
        return res;
    }
};

int main(int argc, char *argv[]){

    return 0;
}

