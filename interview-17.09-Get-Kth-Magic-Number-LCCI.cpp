#include <bits/stdc++.h>

using namespace std;

//面试题 17.09. 第 k 个数
//
//        有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
//
//示例 1:
//
//输入: k = 5
//
//输出: 9



class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> nums(k);
        nums[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < k; ++i) {
            nums[i] = min(nums[p1] * 3, min(nums[p2] * 5, nums[p3] * 7));
            if (nums[i] == nums[p1] * 3)
                ++p1;
            if (nums[i] == nums[p2] * 5)
                ++p2;
            if (nums[i] == nums[p3] * 7)
                ++p3;
        }
        return nums.back();
    }
};


int main(int argc, char* argv[]) {


}

