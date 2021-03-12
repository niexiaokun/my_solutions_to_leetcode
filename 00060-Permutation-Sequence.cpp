#include <bits/stdc++.h>

using namespace std;

//60. 排列序列
//
//        给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
//
//按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//
//给定 n 和 k，返回第 k 个排列。
//
//
//
//示例 1：
//
//输入：n = 3, k = 3
//输出："213"
//
//示例 2：
//
//输入：n = 4, k = 9
//输出："2314"
//
//示例 3：
//
//输入：n = 3, k = 1
//输出："123"
//
//
//
//提示：
//
//1 <= n <= 9
//1 <= k <= n!


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n, 1);
        for (int i = 1; i < n; ++i)
            nums[i] = nums[i - 1] * i;
        vector<bool> used(n + 1, false);
        string res;
        --k;
        for (int i = n - 1; i >= 0; --i) {
            int tmp = k / nums[i];
            for (int j = 1; j <= n; ++j) {
                if (used[j])
                    continue;
                if (tmp == 0) {
                    used[j] = true;
                    res += ('0' + j);
                    k %= nums[i];
                    break;
                }
                --tmp;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    cout << Solution().getPermutation(3, 3) << endl;
    return 0;
}