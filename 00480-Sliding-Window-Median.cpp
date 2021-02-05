#include <bits/stdc++.h>

using namespace std;

//480. 滑动窗口中位数
//
//        中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
//
//例如：
//
//[2,3,4]，中位数是 3
//[2,3]，中位数是 (2 + 3) / 2 = 2.5
//
//给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
//
//
//
//示例：
//
//给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
//
//窗口位置                      中位数
//---------------               -----
//[1  3  -1] -3  5  3  6  7       1
//1 [3  -1  -3] 5  3  6  7      -1
//1  3 [-1  -3  5] 3  6  7      -1
//1  3  -1 [-3  5  3] 6  7       3
//1  3  -1  -3 [5  3  6] 7       5
//1  3  -1  -3  5 [3  6  7]      6
//
//因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。
//
//
//
//提示：
//
//你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
//与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。



class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> g1,g2;
        for(int i=0;i<k;++i)
            g2.insert(nums[i]);
        for(int i=0;i<k/2;++i){
            g1.insert(*g2.begin());
            g2.erase(g2.begin());
        }
        vector<double> res;
        if(k&1)
            res.emplace_back(*g2.begin());
        else
            res.emplace_back(((double) *g1.rbegin() + *g2.begin()) / 2);
        for(int i=k;i<nums.size();++i) {
            if (nums[i] >= *g2.begin()) {
                g1.insert(*g2.begin());
                g2.erase(g2.begin());
                g2.insert(nums[i]);
            } else {
                g1.insert(nums[i]);
            }
            auto t = g1.find(nums[i - k]);
            if (t != g1.end()) {
                g1.erase(t);
            } else {
                g2.insert(*g1.rbegin());
                g1.erase(prev(g1.end()));
                t = g2.find(nums[i - k]);
                g2.erase(t);
            }
            if(k&1)
                res.emplace_back(*g2.begin());
            else
                res.emplace_back(((double) *g1.rbegin() + *g2.begin()) / 2);
        }
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
