#include <iostream>
#include <vector>


using namespace std;


//153. 寻找旋转排序数组中的最小值
//
//假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。
//
//请找出其中最小的元素。
//
//
//
//示例 1：
//
//输入：nums = [3,4,5,1,2]
//输出：1
//
//示例 2：
//
//输入：nums = [4,5,6,7,0,1,2]
//输出：0
//
//示例 3：
//
//输入：nums = [1]
//输出：1
//
//
//
//提示：
//
//1 <= nums.length <= 5000
//-5000 <= nums[i] <= 5000
//nums 中的所有整数都是 唯一 的
//nums 原来是一个升序排序的数组，但在预先未知的某个点上进行了旋转


class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int l=0,r=nums.size()-1;
        if(nums[l]<nums[r])
            return nums[0];
        while(l<=r){
            int mid=(r-l)/2+l;
            if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            if(nums[mid]<nums[mid-1])
                return nums[mid];
            if(nums[mid]>nums[0])
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};


int main(int argc, char *argv[]){

    vector<int> nums{11,13,15,17};
    cout<<Solution().findMin(nums)<<endl;

    nums={4,5,6,7,0,1,2};
    cout<<Solution().findMin(nums)<<endl;

    nums={3,4,5,1,2};
    cout<<Solution().findMin(nums)<<endl;

    nums={1};
    cout<<Solution().findMin(nums)<<endl;

    nums={5,1,2,3,4};
    cout<<Solution().findMin(nums)<<endl;

    nums={5,1,2,3,4};
    cout<<Solution().findMin(nums)<<endl;

    return 0;
}
