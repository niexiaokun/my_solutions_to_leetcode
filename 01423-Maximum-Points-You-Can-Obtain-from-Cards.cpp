#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int t = n - k;
        int tmp = 0;
        for (int i = 0; i < t; ++i)
            tmp += cardPoints[i];
        int res = tmp;
        for (int i = t; i < n; ++i) {
            tmp += cardPoints[i] - cardPoints[i - t];
            res = min(res, tmp);
        }
        return sum - res;
    }
};


int main(int argc, char* argv[]){

    return 0;
}
