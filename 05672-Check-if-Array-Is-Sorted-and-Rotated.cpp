#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> &nums) {
        if (is_sorted(nums.begin(), nums.end()))
            return true;
        int n = nums.size();
        for (int x = 1; x < n; ++x) {
            vector<int> tmp(n);
            for (int i = 0; i < n; ++i)
                tmp[i] = nums[(i + x) % n];
            if (is_sorted(tmp.begin(), tmp.end()))
                return true;
        }
        return false;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

