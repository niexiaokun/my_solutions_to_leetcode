#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        int cur = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i])
                cur = cur + 1;
            else
                cur = 0;
            res = max(res, cur);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

