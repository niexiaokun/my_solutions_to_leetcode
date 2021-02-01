#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//215. 数组中的第K个最大元素
//
//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//示例 1:
//
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
//
//示例 2:
//
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4
//
//说明:
//
//你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。



template <typename T>
void printVec(const vector<T>& nums){
    if(nums.empty())
        return;
    cout<<"[ ";
    for(const T& u:nums)
        cout<<u<<" ";
    cout<<"]"<<endl;
}

template <typename T>
void printVvec(const vector<vector<T>>& nums){
    if(nums.empty())
        return;
    cout<<"["<<endl;
    for(const vector<T>& v:nums) {
        cout<<"[ ";
        for (const T &u:v)
            cout << u << " ";
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
}

class Solution {
private:
    int partition(vector<int>& nums, int l, int r, int k){
        swap(nums[l],nums[rand()%(r-l+1)+l]);
//        printVec(nums);
        int v=nums[l];
        int i=l,j=r+1;
        while(i<j){
            while(i+1<=r&&nums[++i]>v);
            while(j-1>=l&&nums[--j]<v);
            if(i>=j)
                break;
            swap(nums[i],nums[j]);
        }
        swap(nums[l],nums[j]);
//        printVec(nums);
        return j;
    }
    int findKLargest(vector<int>& nums, int l, int r, int k){
//        if(l>=r)
//            return l+1==k? nums[l]:-1;
//        int p=partition(nums,l,r,k);
//        if(p+1==k)
//            return nums[p];
//        else if(p+1<k)
//            return findKLargest(nums,p+1,r,k);
//        else
//            return findKLargest(nums,l,p-1,k);

        while(l<=r){
            int p=partition(nums,l,r,k);
            if(p+1==k)
                return nums[p];
            else if(p+1>k)
                r=p-1;
            else
                l=p+1;
        }
        return -1;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return findKLargest(nums,0,nums.size()-1,k);
    }
};


int main(int argc, char *argv[]){

    vector<int> nums{3,2,1,5,6,4};
    int k=2;
    cout<<Solution().findKthLargest(nums,k)<<endl;

    nums={3,2,3,1,2,4,5,5,6};
    k=4;
    cout<<Solution().findKthLargest(nums,k)<<endl;

    nums={3,3,3,3,3,3,3,3};;
    k=1;
    cout<<Solution().findKthLargest(nums,k)<<endl;

    nums={-1,2,0};
    k=2;
    cout<<Solution().findKthLargest(nums,k)<<endl;

    return 0;
}
