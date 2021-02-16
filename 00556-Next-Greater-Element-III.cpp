#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        int k = n;
        vector<int> nums;
        while (k) {
            nums.emplace_back(k % 10);
            k /= 10;
        }
        if (nums.size() == 1)
            return -1;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] < nums[i - 1])
                break;
            ++i;
        }
        if (i == nums.size())
            return -1;
        auto it = upper_bound(nums.begin(), nums.begin() + i, nums[i]);
        swap(nums[i], *it);
        sort(nums.begin(), nums.begin() + i, greater<int>());
        long long res = 0;
        for (int i = (int) nums.size() - 1; i >= 0; --i)
            res = res * 10 + nums[i];
        if (res > INT_MAX)
            return -1;
        return (int) res;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

