#include <bits/stdc++.h>

using namespace std;

//650. 只有两个键的键盘
//
//        最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：
//
//Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
//Paste (粘贴) : 你可以粘贴你上一次复制的字符。
//
//给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。
//
//示例 1:
//
//输入: 3
//输出: 3
//解释:
//最初, 我们只有一个字符 'A'。
//第 1 步, 我们使用 Copy All 操作。
//第 2 步, 我们使用 Paste 操作来获得 'AA'。
//第 3 步, 我们使用 Paste 操作来获得 'AAA'。
//
//说明:
//
//n 的取值范围是 [1, 1000] 。



class Solution {
private:
    vector<int> memo;

    int dfs(int n) {
        if (memo[n] != -1)
            return memo[n];
        int res = INT_MAX;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                res = min(res, dfs(n / i) + i);
            }
        }
        memo[n] = res == INT_MAX ? n : res;
        return memo[n];
    }

public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        memo = vector<int>(n + 1, -1);
        return dfs(n);
    }
};

int main(int argc, char* argv[]){

    return 0;
}
