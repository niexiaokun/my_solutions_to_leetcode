#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;


//321. 拼接最大数
//
//给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出
// k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
//
//求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
//
//说明: 请尽可能地优化你算法的时间和空间复杂度。
//
//示例 1:
//
//输入:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//输出:
//[9, 8, 6, 5, 3]
//
//示例 2:
//
//输入:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//输出:
//[6, 7, 6, 0, 4]
//
//示例 3:
//
//输入:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//输出:
//[9, 8, 9]


namespace utils
{
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
    void printVvec(const vector<vector<T>>& nums){
        if(nums.empty()){
            cout<<"[]"<<endl;
            return;
        }
        cout<<"["<<endl;
        for(const vector<T>& v:nums) {
            cout<<"[ ";
            for (const T &u:v)
                cout << u << " ";
            cout<<"]"<<endl;
        }
        cout<<"]"<<endl;
    }
};



class Solution {
private:
    vector<int> getSubsequence(vector<int>& nums, int remains){
        vector<int> stk;
        int popnums=nums.size()-remains;
        for(int i=0;i<nums.size();i++){
            while(!stk.empty()&&nums[i]>stk.back()&&popnums>0){
                stk.pop_back();
                popnums--;
            }
            stk.emplace_back(nums[i]);
        }
        while(stk.size()>remains)
            stk.pop_back();
        return stk;
    }
    vector<int> mergeSubsquences(const vector<int>& nums1, const vector<int>& nums2, int sz){
        vector<int> res(sz);
        if(nums1.empty()){
            for(int k=0;k<sz;k++)
                res[k]=nums2[k];
            return res;
        }else if(nums2.empty()){
            for(int k=0;k<sz;k++)
                res[k]=nums1[k];
            return res;
        }
        int i=0,j=0;
        for(int k=0;k<res.size();k++){
            if(i>=nums1.size()) {
                res[k] = nums2[j];
                j++;
            }
            else if(j>=nums2.size()) {
                res[k] = nums1[i];
                i++;
            }
            else if(compareSubsequences(nums1,nums2,i,j)>0){
                res[k]=nums1[i];
                i++;
            }else{
                res[k]=nums2[j];
                j++;
            }
        }
        return res;
    }
    int compareSubsequences(const vector<int>& nums1, const vector<int>& nums2, int index1, int index2){
        int diff;
        while(index1<nums1.size()&&index2<nums2.size()){
            diff=nums1[index1]-nums2[index2];
            if(diff!=0)
                return diff;
            index1++;
            index2++;
        }
        return (nums1.size()-index1)-(nums2.size()-index2);  //取长度大的 [0] [0,6]
//        return (nums2.size()-index2)-(nums1.size()-index1);
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> subsequence1,subsequence2;
        vector<int> subsequence;
        vector<int> maxsequence(k);
        int m=nums1.size(),n=nums2.size();
        int minlen1=max(0,k-n);
        int maxlen1=min(m,k);
        for(int i=minlen1;i<=maxlen1;i++){
            subsequence1=getSubsequence(nums1,i);
            subsequence2=getSubsequence(nums2,k-i);
//            utils::printVec(subsequence1);
//            utils::printVec(subsequence2);
            assert(subsequence1.size()+subsequence2.size()>=k);
            subsequence=mergeSubsquences(subsequence1,subsequence2,k);
//            utils::printVec(subsequence);
//            cout<<endl;
            if(compareSubsequences(subsequence,maxsequence,0,0)>0)
                maxsequence=subsequence;
        }
        return maxsequence;
    }
};


int main(int argc, char *argv[]){

    vector<int> nums1{3, 4, 6, 5};
    vector<int> nums2{9, 1, 2, 5, 8, 3};
    int k=5;
    utils::printVec(Solution().maxNumber(nums1,nums2,k));

    nums1={6,7};
    nums2={6,0,4};
    k=5;
    utils::printVec(Solution().maxNumber(nums1,nums2,k));

    nums1={3,9};
    nums2={8,9};
    k=3;
    utils::printVec(Solution().maxNumber(nums1,nums2,k));

    nums1={2,5,6,4,4,0};
    nums2={7,3,8,0,6,5,7,6,2};
    k=15;
    utils::printVec(Solution().maxNumber(nums1,nums2,k));

    vector<int> nums{1,2,3,3,3,4,7,7};
    cout<<lower_bound(nums.begin(),nums.end(),9)-nums.begin()<<endl;

    return 0;
}