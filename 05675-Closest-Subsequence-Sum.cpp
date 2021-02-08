#include <bits/stdc++.h>

using namespace std;

//5675. 最接近目标值的子序列和
//
//        给你一个整数数组 nums 和一个目标值 goal 。
//
//你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal) 。
//
//返回 abs(sum - goal) 可能的 最小值 。
//
//注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
//
//
//
//示例 1：
//
//输入：nums = [5,-7,3,5], goal = 6
//输出：0
//解释：选择整个数组作为选出的子序列，元素和为 6 。
//子序列和与目标值相等，所以绝对差为 0 。
//
//示例 2：
//
//输入：nums = [7,-9,15,-2], goal = -5
//输出：1
//解释：选出子序列 [7,-9,-2] ，元素和为 -4 。
//绝对差为 abs(-4 - (-5)) = abs(1) = 1 ，是可能的最小值。
//
//示例 3：
//
//输入：nums = [1,2,3], goal = -7
//输出：7
//
//
//
//提示：
//
//1 <= nums.length <= 40
//-10^7 <= nums[i] <= 10^7
//-10^9 <= goal <= 10^9



//class Solution {
//public:
//    int minAbsDifference(vector<int>& nums, int goal) {
//        int n=nums.size();
//        if(n==1)
//            return min(goal,abs(nums[0]-goal));
//        int m=n/2;
//        vector<int> tmp;
//        for(int i=0;i<(1<<m);++i){
//            int a=0;
//            for(int j=0;j<m;++j){
//                if((i>>j)&1)
//                    a+=nums[j];
//            }
//            tmp.emplace_back(a);
//        }
//        sort(tmp.begin(),tmp.end());
//        int res = INT_MAX;
//        int x;
//        for(int i=0;i<(1<<(n-m));++i){
//            int b=0;
//            for(int j=m;j<n;++j){
//                if((i>>(j-m))&1)
//                    b+=nums[j];
//            }
//            int p=lower_bound(tmp.begin(),tmp.end(),goal-b)-tmp.begin();
//            if(p==tmp.size()){
//                res=min(res,abs(tmp[p-1]+b-goal));
//            }else{
//                res=min(res,abs(tmp[p]+b-goal));
//                if(p>0)
//                    res=min(res, abs(tmp[p-1]+b-goal));
//            }
//        }
//        return res;
//    }
//};


class Solution {
private:
    void dfs(const vector<int> &nums, int n, int index, int sum, vector<int> &res) {
        if (index == n) {
            res.emplace_back(sum);
            return;
        }
        dfs(nums, n, index + 1, sum, res);
        dfs(nums, n, index + 1, sum + nums[index], res);
    }

public:
    int minAbsDifference(vector<int> &nums, int goal) {
        int n = nums.size();
        int m = n / 2;
        vector<int> a, b;
        dfs(nums, m, 0, 0, a);
        dfs(nums, n, m, 0, b);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int res = INT_MAX;
        int i = 0, j = (int) b.size() - 1;
        while (i < a.size() && j >= 0) {
            int sum = a[i] + b[j];
            if (sum == goal)
                return 0;
            else if (sum > goal)
                --j;
            else
                ++i;
            res = min(res, abs(sum - goal));
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums = {3346, -3402, -9729, 7432, 2475, 6852, 5960, -7497, 3229, 6713, 8949, 9156, 3945, -8686, 1528,
                        5022, -9791, -3782, -191, -9820, 7720, -6067, -83, 6793, 340, 7793, 8742, 8067};
    int goal = -20357;
    cout << Solution().minAbsDifference(nums, goal) << endl;

    nums = {3530, -1549, 6835, -587, 3787, -1033, 4205, 1006, 5918, -2940, 6101, 3169, 3930, -7006, -7889, -5758, -3246,
            -5098, -2489, -9144, -6617, -1703, -4898, 5721, -6758, 3078, -3859, -9902, -7079, 4014, -8334, 8009};
    goal = 842213514;
    cout << Solution().minAbsDifference(nums, goal) << endl;

    return 0;
}

