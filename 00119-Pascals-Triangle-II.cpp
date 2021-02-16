#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1, 1};
        vector<int> dp(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j)
                dp[j] = dp[j - 1] + dp[j];
        }
        return dp;
    }
};

int main(int argc, char* argv[]) {


    return 0;
}

