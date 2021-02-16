#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int thirdMax(vector<int> &nums) {
//        int res1 = INT_MIN, res2 = INT_MIN, res3 = INT_MIN;
//        sort(nums.begin(), nums.end());
//        nums.erase(unique(nums.begin(), nums.end()), nums.end());
//        for (int i = 0; i < nums.size(); ++i) {
//            if (nums[i] > res1) {
//                res3 = res2;
//                res2 = res1;
//                res1 = nums[i];
//            } else if (nums[i] > res2) {
//                res3 = res2;
//                res2 = nums[i];
//            } else if (nums[i] > res3)
//                res3 = nums[i];
//        }
//        if (nums.size() < 3)
//            return res1;
//        return res3;
//    }
//};

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int res1 = INT_MIN, res2 = INT_MIN, res3 = INT_MIN;
        int tmp = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > res1) {
                res3 = res2;
                res2 = res1;
                res1 = nums[i];
            } else if (nums[i] < res1 && nums[i] > res2) {
                res3 = res2;
                res2 = nums[i];
            } else if (nums[i] < res2 && nums[i] > res3) {
                res3 = nums[i];
            }
            tmp = min(tmp, nums[i]);
        }
        if(res3 >= tmp && res2 > tmp)
            return res3;
        return res1;
    }
};


int main(int argc, char* argv[]) {



    return 0;
}

