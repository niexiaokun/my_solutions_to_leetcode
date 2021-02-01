#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//992. K 个不同整数的子数组
//
//给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
//
//（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
//
//返回 A 中好子数组的数目。
//
//
//
//示例 1：
//
//输入：A = [1,2,1,2,3], K = 2
//输出：7
//解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
//
//示例 2：
//
//输入：A = [1,2,1,3,4], K = 3
//输出：3
//解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
//
//
//
//提示：
//
//1 <= A.length <= 20000
//1 <= A[i] <= A.length
//1 <= K <= A.length


class Solution {
private:
    int subarrayofKMost(vector<int>& nums, int k){
        if(k==0)
            return 0;
        unordered_map<int,int> mp;
        int l=0,ans=0,cnt=0;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            if(mp[nums[r]]==1)
                cnt++;
            while(cnt>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                    cnt--;
                l++;
            }
            ans+=r-l+1; // [l,r]区间内以nums[r]结尾的子数组个数
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarrayofKMost(A,K)-subarrayofKMost(A,K-1);
    }
};



int main(int argc, char *argv[]){

    vector<int> nums{1,2,1,2,3};
    int k=2;
    cout<<Solution().subarraysWithKDistinct(nums,k)<<endl;

    nums={1,2,1,3,4};
    k=3;
    cout<<Solution().subarraysWithKDistinct(nums,k)<<endl;

    return 0;
}