#include <bits/stdc++.h>

using namespace std;

//5691. 通过最少操作次数使数组的和相等
//
//        给你两个长度可能不等的整数数组 nums1 和 nums2 。两个数组中的所有值都在 1 到 6 之间（包含 1 和 6）。
//
//每次操作中，你可以选择 任意 数组中的任意一个整数，将它变成 1 到 6 之间 任意 的值（包含 1 和 6）。
//
//请你返回使 nums1 中所有数的和与 nums2 中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 -1 。
//
//
//
//示例 1：
//
//输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
//输出：3
//解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
//- 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
//- 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
//- 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
//
//示例 2：
//
//输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
//输出：-1
//解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
//
//示例 3：
//
//输入：nums1 = [6,6], nums2 = [1]
//输出：3
//解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
//- 将 nums1[0] 变为 2 。 nums1 = [2,6], nums2 = [1] 。
//- 将 nums1[1] 变为 2 。 nums1 = [2,2], nums2 = [1] 。
//- 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [4] 。
//
//
//
//提示：
//
//1 <= nums1.length, nums2.length <= 105
//1 <= nums1[i], nums2[i] <= 6


class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2)
            return 0;
        if(sum1 > sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        int n=nums1.size()+nums2.size();
        vector<int> tmp(n);
        int i=0;
        for(int x:nums1)
            tmp[i++]=6-x;
        for(int x:nums2)
            tmp[i++]=x-1;
        sort(tmp.begin(),tmp.end(),greater<int>());
        i=0;
        int cnt = 0;
        int delta = sum2 - sum1;
        for(;i<n;++i){
            if(tmp[i]>=delta)
                return cnt + 1;
            else {
                ++cnt;
                delta-=tmp[i];
            }
        }
        return -1;
    }
};


//class Solution {
//private:
//    int work(vector<int>& f, int sum, int target){
//        if(sum==target)
//            return 0;
//        int cnt = 0;
//        if(sum>target){
//            for(int i=6;i>1;--i){
//                int x=f[i]*(i-1);
//                int a=sum-target;
//                if(x>=a){
//                    cnt+=(a-1)/(i-1)+1;
//                    return cnt;
//                } else {
//                    cnt += f[i];
//                    sum-=x;
//                }
//            }
//        }else{
//            for(int i=1;i<6;++i){
//                int x=f[i]*(6-i);
//                int a=target-sum;
//                if(x>=a){
//                    cnt+=(a-1)/(6-i)+1;
//                    return cnt;
//                } else {
//                    cnt += f[i];
//                    sum+=x;
//                }
//            }
//        }
//        return -1;
//    }
//public:
//    int minOperations(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> f1(7), f2(7);
//        int a = 0;
//        int b = 0;
//        for(int x:nums1) {
//            ++f1[x];
//            a+=x;
//        }
//        for(int x:nums2) {
//            ++f2[x];
//            b+=x;
//        }
//        if(a == b)
//            return 0;
//        if(a > b){
//            swap(a, b);
//            swap(f1, f2);
//        }
//
//        int res = INT_MAX;
//        for(int i=a;i<=b;++i){
//            int cnt1 = work(f1,a,i);
//            int cnt2 = work(f2,b,i);
//            if(cnt1!=-1&&cnt2!=-1)
//                res=min(res,cnt1+cnt2);
//        }
//        return res==INT_MAX?-1:res;
//    }
//};


int main(int argc, char* argv[]) {

    vector<int> nums1={1,2,3,4,5,6};
    vector<int> nums2={1,1,2,2,2,2};
    cout<<Solution().minOperations(nums1,nums2)<<endl;

    nums1={1,5,5,2,1,1,1,1,4,4,4,1,5,2,2,4,6,5,1,5,3,5,6,2,3,1,5,4,4,1,2,4,1,1,6,3,6,4,4,4,3,5,5,5,2,6,4,2,5,4,2,6,3,4,6,1,5,3,2,3,5,2,1,3,2,4,4,4,5,3,5,5,4,1,1,6,5,6,3,5,3,6,5,6,5,4,4,4,5,6,6,6,4,2,4,6,1,2,1,5,3,4,5,5,6,6,1,4,3,1,5,3,4,1,2,1,4,4,5,6,5,3,1,5,1,3,3,6,5,3,5,6,2,6,3,1,2,3,3,1,1,4,3,2,6,6,2,1,2,4,3,5,5,4,3,1,1,5,2,5,1,4,5,6,4,5,2,1,2,5,3,2,6,3,4,3,4,5,4,6,3,4,4,3,3,4,2,2,6,2,6,3,1,1,5,3,1,1,4,2,5,5,5,4,3,6,5,5,5,1,1,3,6,2,3,6,3,4,2,5,4,4,3,5,6,4,3,5,1,1,3,3,1,1,6,4,6,2,1,4,3,5,5};
    nums2={1,2,5,4,3,3,5,1,1,6,2,5,4,4,5,6,6,4,2,5,6,2,3,4,5,2,4,4,3,6,6,5,4,1,2,1,2,3,3,2,6,1,1,1,1,3,5,6,2,1,1,1,4,6,5};
    cout<<Solution().minOperations(nums1,nums2)<<endl;

    return 0;
}

