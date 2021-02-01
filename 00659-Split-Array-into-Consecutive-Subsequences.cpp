#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


//659. 分割数组为连续子序列
//
//给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。
//
//如果可以完成上述分割，则返回 true ；否则，返回 false 。
//
//
//
//示例 1：
//
//输入: [1,2,3,3,4,5]
//输出: True
//        解释:
//你可以分割出这样两个连续子序列 :
//1, 2, 3
//3, 4, 5
//
//
//
//示例 2：
//
//输入: [1,2,3,3,4,4,5,5]
//输出: True
//        解释:
//你可以分割出这样两个连续子序列 :
//1, 2, 3, 4, 5
//3, 4, 5
//
//
//
//示例 3：
//
//输入: [1,2,3,4,4,5]
//输出: False
//
//
//
//提示：
//
//输入的数组长度范围为 [1, 10000]


class Solution {
    using PIL=pair<int,int>;
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        unordered_map<int,int> f,sub;
        for(int num:nums)
            f[num]++;
        for(int i:nums){
            if(f[i]==0)
                continue;
            if(f[i]&&sub[i-1]>0){
                f[i]--;
                sub[i-1]--;
                sub[i]++;
            }else if(f[i]&&f[i+1]&&f[i+2]){
                f[i]--;
                f[i+1]--;
                f[i+2]--;
                sub[i+2]++;
            }else
                return false;
        }
        return true;
    }
};


int main(int argc, char *argv[]){

    vector<int> nums{1,2,3,3,4,5};
    cout<<Solution().isPossible(nums)<<endl;

    nums={1,2,3,3,4,4,5,5};
    cout<<Solution().isPossible(nums)<<endl;

    nums={1,2,3,4,4,5};
    cout<<Solution().isPossible(nums)<<endl;

    return 0;
}