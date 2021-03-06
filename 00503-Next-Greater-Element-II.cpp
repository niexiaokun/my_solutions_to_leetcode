#include <bits/stdc++.h>

using namespace std;


//503. 下一个更大元素 II
//
//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
//
//示例 1:
//
//输入: [1,2,1]
//输出: [2,-1,2]
//解释: 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数；
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
//
//注意: 输入数组的长度不会超过 10000。



class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0)
            return res;
        res.resize(n, -1);
        vector<int> stk1;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk1.empty() && nums[stk1.back()] <= nums[i])
                stk1.pop_back();
            if (!stk1.empty())
                res[i] = nums[stk1.back()];
            stk1.emplace_back(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!stk1.empty() && nums[stk1.back()] <= nums[i])
                stk1.pop_back();
            if (!stk1.empty() && res[i] == -1)
                res[i] = nums[stk1.back()];
            stk1.emplace_back(i);
        }
        return res;
    }
};



int main(int argc, char* argv[]) {

    return 0;
}

