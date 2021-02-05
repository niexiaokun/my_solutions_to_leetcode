#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double cur = 0;
        for (int i = 0; i < k; ++i)
            cur += nums[i];
        double res = cur;
        for (int i = k; i < nums.size(); ++i) {
            cur += nums[i] - nums[i - k];
            res = max(res, cur);
        }
        return res / k;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
