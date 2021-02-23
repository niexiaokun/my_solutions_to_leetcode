#include <bits/stdc++.h>

using namespace std;

//1438. 绝对差不超过限制的最长连续子数组
//
//        给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
//
//如果不存在满足条件的子数组，则返回 0 。
//
//
//
//示例 1：
//
//输入：nums = [8,2,4,7], limit = 4
//输出：2
//解释：所有子数组如下：
//[8] 最大绝对差 |8-8| = 0 <= 4.
//[8,2] 最大绝对差 |8-2| = 6 > 4.
//[8,2,4] 最大绝对差 |8-2| = 6 > 4.
//[8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
//[2] 最大绝对差 |2-2| = 0 <= 4.
//[2,4] 最大绝对差 |2-4| = 2 <= 4.
//[2,4,7] 最大绝对差 |2-7| = 5 > 4.
//[4] 最大绝对差 |4-4| = 0 <= 4.
//[4,7] 最大绝对差 |4-7| = 3 <= 4.
//[7] 最大绝对差 |7-7| = 0 <= 4.
//因此，满足题意的最长子数组的长度为 2 。
//
//示例 2：
//
//输入：nums = [10,1,2,4,7,2], limit = 5
//输出：4
//解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
//
//示例 3：
//
//输入：nums = [4,2,2,2,4,4,2,2], limit = 0
//输出：3
//
//
//
//提示：
//
//1 <= nums.length <= 10^5
//1 <= nums[i] <= 10^9
//0 <= limit <= 10^9


//class Solution {
//public:
//    int longestSubarray(vector<int> &nums, int limit) {
//        int n = nums.size();
//        if (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()) <= limit)
//            return n;
//        int l = 0;
//        int r = n;
//        while (l < r) {
//            int mid = (l + r) / 2;
//            deque<int> dq1, dq2;
//            for (int i = 0; i < mid; ++i) {
//                while (!dq1.empty() && nums[i] < dq1.back())
//                    dq1.pop_back();
//                dq1.emplace_back(nums[i]);
//                while (!dq2.empty() && nums[i] > dq2.back())
//                    dq2.pop_back();
//                dq2.emplace_back(nums[i]);
//            }
//            int a = dq2.front() - dq1.front();
//            if (a <= limit) {
//                l = mid + 1;
//                continue;
//            }
//            bool flag = false;
//            for (int i = mid; i < n; ++i) {
//                while (!dq1.empty() && nums[i] < dq1.back())
//                    dq1.pop_back();
//                dq1.emplace_back(nums[i]);
//                if (nums[i - mid] == dq1.front())
//                    dq1.pop_front();
//                while (!dq2.empty() && nums[i] > dq2.back())
//                    dq2.pop_back();
//                dq2.emplace_back(nums[i]);
//                if (nums[i - mid] == dq2.front())
//                    dq2.pop_front();
//                a = dq2.front() - dq1.front();
//                if (a <= limit) {
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag)
//                l = mid + 1;
//            else
//                r = mid;
//        }
//        return l - 1;
//    }
//};


//class Solution {
//public:
//    int longestSubarray(vector<int> &nums, int limit) {
//        int n = nums.size();
//        int j = 0;
//        int i = 0;
//        int res = 0;
//        multiset<int> ms;
//        while(i < n){
//            ms.insert(nums[i]);
//            while(ms.size() > 1 && *ms.rbegin() - *ms.begin() > limit)
//                ms.erase(ms.lower_bound(nums[j++]));          //multset解法
//            res = max(res, (int)ms.size());
//            ++i;
//        }
//        return res;
//    }
//};


class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = nums.size();
        int j = 0;
        int i = 0;
        int res = 0;
        deque<int> dq1, dq2;
        while (i < n) {
            while (!dq1.empty() && nums[i] < dq1.back())   //两个最大最小单调队列
                dq1.pop_back();
            dq1.emplace_back(nums[i]);
            while (!dq2.empty() && nums[i] > dq2.back())
                dq2.pop_back();
            dq2.emplace_back(nums[i]);
            while(dq2.front() - dq1.front() > limit){
                if(nums[j] == dq1.front())
                    dq1.pop_front();
                if(nums[j] == dq2.front())
                    dq2.pop_front();
                ++j;
            }
            res = max(res, i - j + 1);
            ++i;
        }
        return res;
    }
};


int main(int argc, char* argv[]) {



    return 0;
}

