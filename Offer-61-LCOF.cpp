#include <bits/stdc++.h>

using namespace std;

//剑指 Offer 61. 扑克牌中的顺子
//
//        从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
//
//
//
//示例 1:
//
//输入: [1,2,3,4,5]
//输出: True
//
//
//
//        示例 2:
//
//输入: [0,0,1,2,5]
//输出: True
//
//
//
//        限制：
//
//数组长度为 5
//
//数组的数取值为 [0, 13] .

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n && nums[i] == 0)
            ++i;
        if (i == n)
            return true;
        int cnt = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] == nums[j - 1])
                return false;
            cnt -= nums[j] - nums[j - 1] - 1;
        }
        return cnt >= 0;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

