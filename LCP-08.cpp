#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements) {
        int n = increase.size();
        vector<int> a1(n + 1), a2(n + 1), a3(n + 1);
        for (int i = 1; i <= n; ++i) {
            a1[i] = a1[i - 1] + increase[i - 1][0];
            a2[i] = a2[i - 1] + increase[i - 1][1];
            a3[i] = a3[i - 1] + increase[i - 1][2];
        }
        int m = requirements.size();
        vector<int> res(m, -1);
        for (int i = 0; i < m; ++i) {
            int a = requirements[i][0], b = requirements[i][1], c = requirements[i][2];
            int x = lower_bound(a1.begin(), a1.end(), a) - a1.begin();
            int y = lower_bound(a2.begin(), a2.end(), b) - a2.begin();
            int z = lower_bound(a3.begin(), a3.end(), c) - a3.begin();
            if (x != n + 1 && y != n + 1 && z != n + 1)
                res[i] = max(x, max(y, z));
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

