#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


//18. 四数之和
//
//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
// 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
//注意：
//
//答案中不可以包含重复的四元组。
//
//示例：
//
//给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//[-1,  0, 0, 1],
//[-2, -1, 1, 2],
//[-2,  0, 0, 2]
//]

namespace utils{
    template <typename T>
    void printVec(const vector<T>& v){
        if(v.empty())
            return;
        cout<<"[";
        for(const T& num:v)
            cout<<num<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVvec(const vector<vector<T>>& v){
        if(v.empty())
            return;
        cout<<"["<<endl;
        for(const vector<T>& u:v)
            printVec(u);
        cout<<"]"<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
//        utils::printVec(nums);
        vector<vector<int>> res;
        int n=nums.size();
        if(n<4)
            return res;
        int l,r,t;
        for(int i=0;i<n-3;i++){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                l=j+1,r=n-1;
                t=target-nums[i]-nums[j];
                while(l<r) {
                    if (nums[l] + nums[r] == t) {
                        if(l>j+1&&nums[l]==nums[l-1]){
                            l++;
                            continue;
                        }
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    } else if (nums[l] + nums[r] > t)
                        r--;
                    else
                        l++;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]){

    vector<int> nums{1, 0, -1, 0, -3, 0, -1, -2, 2, 2, 3};
    int target=0;
    utils::printVvec(Solution().fourSum(nums,target));
    return 0;
}