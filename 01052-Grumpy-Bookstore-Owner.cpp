#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int x) {
        int n = customers.size();
        int cnt = 0;
        for (int i = 0; i < x; ++i) {
            if (grumpy[i])
                cnt += customers[i];
        }
        int sum = cnt;
        for (int i = x; i < n; ++i) {
            if (grumpy[i])
                cnt += customers[i];
            if (grumpy[i - x])
                cnt -= customers[i - x];
            sum = max(sum, cnt);
        }
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0)
                sum += customers[i];
        }
        return sum;
    }
};



int main(int argc, char* argv[]) {


    return 0;
}

