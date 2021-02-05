#include <bits/stdc++.h>

using namespace std;


//656. 金币路径
//
//        给定一个数组 A（下标从 1 开始）包含 N 个整数：A1，A2，……，AN 和一个整数 B。你可以从数组 A 中的任何一个位置（下标为 i）跳到下标 i+1，i+2，……，i+B 的任意一个可以跳到的位置上。如果你在下标为 i 的位置上，你需要支付 Ai 个金币。如果 Ai 是 -1，意味着下标为 i 的位置是不可以跳到的。
//
//现在，你希望花费最少的金币从数组 A 的 1 位置跳到 N 位置，你需要输出花费最少的路径，依次输出所有经过的下标（从 1 到 N）。
//
//如果有多种花费最少的方案，输出字典顺序最小的路径。
//
//如果无法到达 N 位置，请返回一个空数组。
//
//
//
//样例 1 :
//
//输入: [1,2,4,-1,2], 2
//输出: [1,3,5]
//
//
//
//样例 2 :
//
//输入: [1,2,4,-1,2], 1
//输出: []
//
//
//
//注释 :
//
//路径 Pa1，Pa2，……，Pan 是字典序小于 Pb1，Pb2，……，Pbm 的，当且仅当第一个 Pai 和 Pbi 不同的 i 满足 Pai < Pbi，如果不存在这样的 i 那么满足 n < m。
//A1 >= 0。 A2, ..., AN （如果存在） 的范围是 [-1, 100]。
//A 数组的长度范围 [1, 1000].
//B 的范围 [1, 100].


//class Solution {
//private:
//    vector<int> memo;
//
//    int dfs(vector<int> &nums, int k, int index, vector<int> &next) {
//        if (index + 1 == nums.size())
//            return 0;
//        if (memo[index] != -1)
//            return memo[index];
//        int res = INT_MAX;
//        for (int i = index + 1; i < nums.size(); ++i) {
//            if (nums[i] == -1)
//                continue;
//            if (i > index + k)
//                break;
//            int cost = dfs(nums, k, i, next);
//            if (cost != INT_MAX && nums[index] + cost < res) {
//                res = nums[index] + cost;
//                next[index] = i;
//            }
//        }
//        memo[index] = res;
//        return res;
//    }
//
//public:
//    vector<int> cheapestJump(vector<int> &A, int B) {
//        int n = A.size();
//        vector<int> next(n);
//        memo = vector<int>(n, -1);
//        if (dfs(A, B, 0, next) == INT_MAX)
//            return {};
//        vector<int> res = {1};
//        int i = 0;
//        while (i != n - 1) {
//            res.emplace_back(next[i] + 1);
//            i = next[i];
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<int> cheapestJump(vector<int> &A, int B) {
        int n = A.size();
        if(A[n-1]==-1)
            return {};
        vector<int> dp(n,INT_MAX);
        vector<int> next(n);
        dp[n-1]=0;
        for(int i=n-1;i>=0;--i){
            for(int k=1;k<=B;++k){
                if(i-k<0)
                    break;
                if(A[i-k]==-1||dp[i]==INT_MAX)
                    continue;
                if(dp[i]+A[i-k]<=dp[i-k]){
                    dp[i-k]=dp[i]+A[i-k];
                    next[i-k]=i;
                }
            }
        }
        if(dp[0]==INT_MAX)
            return {};
        vector<int> res={1};
        int i=0;
        while(i!=n-1){
            res.emplace_back(next[i]+1);
            i=next[i];
        }
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
