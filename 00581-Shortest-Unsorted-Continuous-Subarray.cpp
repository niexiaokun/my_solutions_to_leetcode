#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int a = -1;
        int last = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != nums[last])
                last = i;
            if (nums[i] > nums[i + 1]) {
                a = i;
                break;
            }
        }
        if (a == -1)
            return 0;
        a = last;
        int b = -1;
        last = n - 1;
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] != nums[last])
                last = i;
            if (nums[i] < nums[i - 1]) {
                b = i;
                break;
            }
        }
        b = last;
        int x1 = INT_MAX, x2 = INT_MIN;
        for (int i = a; i <= b; ++i) {
            x1 = min(x1, nums[i]);
            x2 = max(x2, nums[i]);
        }
        int aa = upper_bound(nums.begin(), nums.begin() + a, x1) - nums.begin();
        int bb = lower_bound(nums.begin() + b + 1, nums.end(), x2) - nums.begin();
        return bb - aa;
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums={0,1,2,4,8,3,3,2,7,8,4,5,7,6,6,6};
    cout<<Solution().findUnsortedSubarray(nums)<<endl;

    nums={1,2,3,4};
    cout<<Solution().findUnsortedSubarray(nums)<<endl;

    nums={1,2};
    cout<<Solution().findUnsortedSubarray(nums)<<endl;

    return 0;
}

