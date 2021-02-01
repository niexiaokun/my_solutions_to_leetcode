#include <iostream>
#include <vector>
#include <set>

using namespace std;


//327. 区间和的个数
//
//给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
//区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
//
//说明:
//最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。
//
//示例:
//
//输入: nums = [-2,5,-1], lower = -2, upper = 2,
//        输出: 3
//解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。


class Solution {
private:
    int res=0;
    void mergeSort(vector<long>& nums, vector<long>& aux, int l, int r, int lower, int upper){
        if(l>=r)
            return;
        int mid=(r-l)/2+l;
        mergeSort(nums,aux,l,mid,lower,upper);
        mergeSort(nums,aux,mid+1,r,lower,upper);

        int i=l;
        int left=mid+1,right=mid+1;
        while(i<=mid){
            while(left<=r&&nums[left]-nums[i]<lower)   left++;
            while(right<=r&&nums[right]-nums[i]<=upper) right++;
            res+=right-left;
            i++;
        }

        if(nums[mid]<=nums[mid+1])
            return;

        for(int k=l;k<=r;k++)
            aux[k]=nums[k];
        i=l;
        int j=mid+1;
        for(int k=l;k<=r;k++){
            if(i>mid)
                nums[k]=aux[j++];
            else if(j>r)
                nums[k]=aux[i++];
            else if(aux[i]<=aux[j])
                nums[k]=aux[i++];
            else
                nums[k]=aux[j++];
        }
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> presum(nums.size()+1);
        for(int i=1;i<=nums.size();++i)
            presum[i]=nums[i-1]+presum[i-1];
        vector<long> aux(presum.size());
        mergeSort(presum,aux,0,presum.size()-1,lower,upper);
        return res;
    }
};

//class Solution {
//public:
//    int countRangeSum(vector<int>& nums, int lower, int upper) {
//        multiset<long> mset;
//        mset.insert(0);
//        long sum=0;
//        int res=0;
//        for(int i=0;i<nums.size();i++){
//            sum+=nums[i];
//            res+=distance(mset.lower_bound(sum-upper),mset.upper_bound((sum-lower)));
//            mset.insert(sum);
//        }
//        return res;
//    }
//};


int main(int argc, char *argv[]){

    vector<int> nums{-2,5,-1,0,1,0,1};
    int lower=-2;
    int upper=2;
    cout<<Solution().countRangeSum(nums,lower,upper)<<endl;

    nums={-2147483647,0,-2147483647,2147483647};
    lower=-564;
    upper=3864;
    cout<<Solution().countRangeSum(nums,lower,upper)<<endl;

    return 0;
}
