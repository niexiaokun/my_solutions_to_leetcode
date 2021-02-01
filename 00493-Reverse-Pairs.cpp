#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//493. 翻转对
//
//给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
//
//你需要返回给定数组中的重要翻转对的数量。
//
//示例 1:
//
//输入: [1,3,2,3,1]
//输出: 2
//
//示例 2:
//
//输入: [2,4,3,5,1]
//输出: 3
//
//注意:
//
//给定数组的长度不会超过50000。
//输入数组中的所有数字都在32位整数的表示范围内。

namespace utils{
    template <typename T>
    void printVec(const vector<T>& nums){
        if(nums.empty()){
            cout<<"[]"<<endl;
            return;
        }
        cout<<"[ ";
        for(const T& u:nums)
            cout<<u<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVec(const vector<T>& nums, int l, int r){
        if(l>r)
            return;
        cout<<"[ ";
        for(int i=l;i<=r;i++)
            cout<<nums[i]<<" ";
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
}


class Solution {
private:
    int res=0;
    void mergeSort(vector<int>& nums, vector<int>& aux, int l, int r){
        if(l>=r)
            return;
        int mid=(r-l)/2+l;
        mergeSort(nums,aux,l,mid);
        mergeSort(nums,aux,mid+1,r);

        int i=l,j=mid+1;
        while(i<=mid){
            while(j<=r&&(long long)nums[i]-(long long)nums[j]>(long long)nums[j]) j++;
            res+=j-mid-1;
            i++;
        }

        if(nums[mid]<=nums[mid+1])
            return;

        for(int k=l;k<=r;k++)
            aux[k]=nums[k];
        i=l,j=mid+1;
        for(int k=l;k<=r;k++) {  //归并过程
            if (i > mid)
                nums[k] = aux[j++];
            else if (j > r)
                nums[k] = aux[i++];
            else if (aux[i] <= aux[j])
                nums[k] = aux[i++];
            else
                nums[k] = aux[j++];
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        vector<int> aux(nums.size());
        mergeSort(nums,aux,0,nums.size()-1);
        return res;
    }
};



int main(int argc, char *argv[]){

    vector<int> nums{1,3,2,3,1};
    cout<<Solution().reversePairs(nums)<<endl;

    nums={2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647};
    cout<<Solution().reversePairs(nums)<<endl;
    utils::printVec(nums);

    nums={1,2,3,3,3,4,5,5,6,7,7,8};
    cout<<lower_bound(nums.begin(),nums.end(),3)-nums.begin()<<endl;
    cout<<upper_bound(nums.begin(),nums.end(),3)-nums.begin()<<endl;

    return 0;
}