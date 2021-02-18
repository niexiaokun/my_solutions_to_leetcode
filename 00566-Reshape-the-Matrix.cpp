#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c)
            return nums;
        vector<vector<int>> res(r, vector<int>(c));
        int i = 0;
        while (i < m * n) {
            res[i / c][i % c] = nums[i / n][i % n];
            ++i;
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

