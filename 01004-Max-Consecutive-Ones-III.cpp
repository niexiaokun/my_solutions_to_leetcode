#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//1004. 最大连续1的个数 III
//
//给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
//
//返回仅包含 1 的最长（连续）子数组的长度。
//
//
//
//示例 1：
//
//输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
//输出：6
//解释：
//[1,1,1,0,0,1,1,1,1,1,1]
//粗体数字从 0 翻转到 1，最长的子数组长度为 6。
//
//示例 2：
//
//输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
//输出：10
//解释：
//[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//粗体数字从 0 翻转到 1，最长的子数组长度为 10。
//
//
//
//提示：
//
//1 <= A.length <= 20000
//0 <= K <= A.length
//        A[i] 为 0 或 1

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int n = A.size();
        int l = 0;
        int cnt = 0;
        int res = 0;
        for (int r = 0; r < n; ++r) {
            if (A[r] == 0)
                ++cnt;
            while (cnt > K) {
                if (A[l] == 0)
                    --cnt;
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};


//class Solution {
//public:
//    int longestOnes(vector<int> &A, int K) {
//        int n = A.size();
//        int lo = K;
//        int hi = n;
//        while (lo < hi) {
//            int mid = (lo + hi) / 2;
//            bool flag = false;
//            int cnt = 0;
//            for (int i = 0; i < mid; ++i) {
//                if (A[i] == 0)
//                    ++cnt;
//            }
//            if (cnt <= K) {
//                lo = mid + 1;
//                continue;
//            }
//            for (int i = mid; i < n; ++i) {
//                if (A[i] == 0)
//                    ++cnt;
//                if (A[i - mid] == 0)
//                    --cnt;
//                if (cnt <= K) {
//                    lo = mid + 1;
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag)
//                lo = mid + 1;
//            else
//                hi = mid;
//        }
//        return lo;
//    }
//};


int main(int argc, char *argv[]) {

    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << Solution().longestOnes(nums, k) << endl;

    nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    k = 3;
    cout << Solution().longestOnes(nums, k) << endl;

    nums = {0, 0, 0, 1};
    k = 3;
    cout << Solution().longestOnes(nums, k) << endl;

    return 0;
}