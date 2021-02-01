#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;



//315. 计算右侧小于当前元素的个数
//
//给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
//
//
//
//示例：
//
//输入：nums = [5,2,6,1]
//输出：[2,1,1,0]
//解释：
//5 的右侧有 2 个更小的元素 (2 和 1)
//2 的右侧仅有 1 个更小的元素 (1)
//6 的右侧有 1 个更小的元素 (1)
//1 的右侧有 0 个更小的元素
//
//
//
//        提示：
//
//0 <= nums.length <= 10^5
//-10^4 <= nums[i] <= 10^4


namespace utils{
    template <typename T>
    void printVec(const vector<T>& nums){
        if(nums.empty())
            return;
        cout<<"[ ";
        for(const T& u:nums)
            cout<<u<<" ";
        cout<<"]"<<endl;
    }
//
//template <typename T>
//void printVec(const vector<T>& nums, int l, int r){
//    if(l>r)
//        return;
//    cout<<"[ ";
//    for(int i=l;i<=r;i++)
//        cout<<nums[i]<<" ";
//    cout<<"]"<<endl;
//}
//
//template <typename T>
//void printVvec(const vector<vector<T>>& nums){
//    if(nums.empty())
//        return;
//    cout<<"["<<endl;
//    for(const vector<T>& v:nums) {
//        cout<<"[ ";
//        for (const T &u:v)
//            cout << u << " ";
//        cout<<"]"<<endl;
//    }
//    cout<<"]"<<endl;
//}
}

class Solution {
private:
    typedef pair<int,pair<int,int>> PIINT;
    void merge(vector<PIINT>& arr, vector<PIINT>& aux, int l, int mid, int r){
        for(int i=l;i<=r;i++)
            aux[i]=arr[i];
        int i=l,j=mid+1;
        for(int k=l;k<=r;k++){
            if(i>mid){
                arr[k]=aux[j];
                j++;
            }else if(j>r){
                arr[k]=aux[i];
                i++;
            }else if(aux[i].second.first>aux[j].second.first){
                arr[k]=aux[i];
                arr[k].second.second+=r-j+1;
                i++;
            }else{
                arr[k]=aux[j];
                j++;
            }
        }
    }
    void mergeSortCountSmaller(vector<PIINT>& arr, vector<PIINT>& aux, int l, int r){
        if(l>=r)
            return;
        int mid=(r-l)/2+l;
        mergeSortCountSmaller(arr,aux,l,mid);
        mergeSortCountSmaller(arr,aux,mid+1,r);
        merge(arr,aux,l,mid,r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        if(nums.size()==1)
            return {0};
        vector<PIINT> arr;
        arr.reserve(nums.size());
        for(int i=0;i<nums.size();i++)
            arr.push_back({i,{nums[i],0}});
        vector<PIINT> aux(nums.size());
        mergeSortCountSmaller(arr,aux,0,arr.size()-1);
        vector<int> ans(nums.size());
        for(auto& p:arr)
            ans[p.first]=p.second.second;
        return ans;
    }
};






int main(int argc, char *argv[]){

    vector<int> nums{5,2,6,1,4,3,2,1};
    utils::printVec(Solution().countSmaller(nums));


    return 0;
}
