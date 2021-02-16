#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int> &nums) {
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        nums.erase(unique(nums.begin(), nums.end()), nums.end());
//        vector<int> res;
//        int j = 0;
//        for (int i = 1; i <= n; ++i) {
//            if (nums[j] == i)
//                ++j;
//            else
//                res.emplace_back(i);
//        }
//        return res;
//    }
//};


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        for (int &num:nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n)
                res.emplace_back(i + 1);
        }
        return res;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

