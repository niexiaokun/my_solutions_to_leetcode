#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


//259. 较小的三数之和
//
//给定一个长度为 n 的整数数组和一个目标值 target，寻找能够使条件 nums[i] + nums[j] + nums[k] < target 成立的三元组  i, j, k 个数（0 <= i < j < k < n）。
//
//示例：
//
//输入: nums = [-2,0,1,3], target = 2
//输出: 2
//解释: 因为一共有两个三元组满足累加和小于 2:
//[-2,0,1]
//[-2,0,3]
//
//进阶：是否能在 O(n2) 的时间复杂度内解决？


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


//class Solution {
//public:
//    int threeSumSmaller(vector<int>& nums, int target) {
//        int res=0;
//        int n=nums.size();
//        if(n<3)
//            return res;
//        sort(nums.begin(),nums.end());
////        utils::printVec(nums);
//        int l,r,mid,t;
//        for(int i=0;i<n-2;i++){
//            for(int j=i+1;j<n-1;j++){
//                l=j+1,r=n-1;
//                t=target-nums[i]-nums[j];
//                while(l<r){
//                    mid=(r-l)/2+l;
//                    if(nums[mid]==t)
//                        r=mid;
//                    else if(nums[mid]>t)
//                        r=mid;
//                    else
//                        l=mid+1;
//                }
////                printf("[ %d %d %d %d ]\n",nums[i],nums[j],nums[l],l-j);
//                res+=nums[l]>=t?l-1-j:l-j;
//            }
//        }
//        return res;
//    }
//};



class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res=0;
        int n=nums.size();
        if(n<3)
            return res;
        sort(nums.begin(),nums.end());
        int l,r,t;
        for(int i=0;i<n-2;i++){
            l=i+1,r=n-1;
            t=target-nums[i];
            while(l<r){
                if(nums[l]+nums[r]<t){
                    res+=r-l;
                    l++;
                }else
                    r--;
            }
        }
        return res;
    }
};



int main(int argc, char *argv[]){

    vector<int> nums{1, 0, -1, 0, -3, 0, -1, -2, 2, 2, 3};
    int target=0;
    cout<<Solution().threeSumSmaller(nums,target)<<endl;

    nums={-2,0,1,3};
    target=2;
    cout<<Solution().threeSumSmaller(nums,target)<<endl;




    return 0;
}