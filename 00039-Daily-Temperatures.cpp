#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);
        unordered_map<int, int> f;
        for (int i = n - 1; i >= 0; --i) {
            int index = INT_MAX;
            for (const auto &p:f) {
                if (p.first > nums[i] && p.second < index) {
                    index = p.second;
                }
            }
            if (index != INT_MAX)
                res[i] = index - i;
            else
                res[i] = 0;
            f[nums[i]] = i;
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    
    return 0;
}

