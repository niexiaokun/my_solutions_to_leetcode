#include <bits/stdc++.h>

using namespace std;

//22. 括号生成
//
//        数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//
//
//
//示例 1：
//
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
//
//示例 2：
//
//输入：n = 1
//输出：["()"]
//
//
//
//提示：
//
//1 <= n <= 8


class Solution {
private:
    vector<string> res;

    void dfs(int n, int m, int index, string s) {
        if (m * 2 == n) {
            s.resize(n, ')');
            res.emplace_back(s);
            return;
        }
        if (index - m < m) {
            s += ")";
            dfs(n, m, index + 1, s);
            s.pop_back();
        }
        s += "(";
        dfs(n, m + 1, index + 1, s);
    }

public:
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(n * 2, 0, 0, s);
        return res;
    }
};


int main(int argc, char *argv[]){

    return 0;
}

