#include <bits/stdc++.h>

using namespace std;

//1577. 数的平方等于两数乘积的方法数
//
//        给你两个整数数组 nums1 和 nums2 ，请你返回根据以下规则形成的三元组的数目（类型 1 和类型 2 ）：
//
//类型 1：三元组 (i, j, k) ，如果 nums1[i]2 == nums2[j] * nums2[k] 其中 0 <= i < nums1.length 且 0 <= j < k < nums2.length
//        类型 2：三元组 (i, j, k) ，如果 nums2[i]2 == nums1[j] * nums1[k] 其中 0 <= i < nums2.length 且 0 <= j < k < nums1.length
//
//
//
//        示例 1：
//
//输入：nums1 = [7,4], nums2 = [5,2,8,9]
//输出：1
//解释：类型 1：(1,1,2), nums1[1]^2 = nums2[1] * nums2[2] (4^2 = 2 * 8)
//
//示例 2：
//
//输入：nums1 = [1,1], nums2 = [1,1,1]
//输出：9
//解释：所有三元组都符合题目要求，因为 1^2 = 1 * 1
//类型 1：(0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2), nums1[i]^2 = nums2[j] * nums2[k]
//类型 2：(0,0,1), (1,0,1), (2,0,1), nums2[i]^2 = nums1[j] * nums1[k]
//
//示例 3：
//
//输入：nums1 = [7,7,8,3], nums2 = [1,2,9,7]
//输出：2
//解释：有两个符合题目要求的三元组
//        类型 1：(3,0,2), nums1[3]^2 = nums2[0] * nums2[2]
//类型 2：(3,0,1), nums2[3]^2 = nums1[0] * nums1[1]
//
//示例 4：
//
//输入：nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
//输出：0
//解释：不存在符合题目要求的三元组
//
//
//
//        提示：
//
//1 <= nums1.length, nums2.length <= 1000
//1 <= nums1[i], nums2[i] <= 10^5



class Solution {
public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<long, int> f1, f2;
        int res = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = i + 1; j < nums1.size(); ++j) {
                f1[(long long) nums1[i] * nums1[j]]++;
            }
        }
        long long t = 0;
        for (int x:nums2) {
            t = (long long) x * x;
            if (f1.count(t))
                res += f1[t];
        }
        for (int i = 0; i < nums2.size(); ++i) {
            for (int j = i + 1; j < nums2.size(); ++j) {
                f2[(long long) nums2[i] * nums2[j]]++;
            }
        }
        for (int x:nums1) {
            t = (long long) x * x;
            if (f2.count(t))
                res += f2[t];
        }
        return res;
    }
};


int main(int argc, char* argv[]){

    return 0;
}
