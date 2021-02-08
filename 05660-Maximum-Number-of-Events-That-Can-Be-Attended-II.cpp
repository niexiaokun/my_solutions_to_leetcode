#include <bits/stdc++.h>

using namespace std;

//5660. 最多可以参加的会议数目 II
//
//给你一个 events 数组，其中 events[i] = [startDayi, endDayi, valuei] ，表示第 i 个会议在 startDayi 天开始，第 endDayi 天结束，如果你参加这个会议，你能得到价值 valuei 。同时给你一个整数 k 表示你能参加的最多会议数目。
//
//你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 完整 地参加完这个会议。会议结束日期是包含在会议内的，也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。
//
//请你返回能得到的会议价值 最大和 。
//
//
//
//示例 1：
//
//输入：events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
//输出：7
//解释：选择绿色的活动会议 0 和 1，得到总价值和为 4 + 3 = 7 。
//
//示例 2：
//
//输入：events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
//输出：10
//解释：参加会议 2 ，得到价值和为 10 。
//你没法再参加别的会议了，因为跟会议 2 有重叠。你 不 需要参加满 k 个会议。
//
//示例 3：
//
//输入：events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
//输出：9
//解释：尽管会议互不重叠，你只能参加 3 个会议，所以选择价值最大的 3 个会议。
//
//
//
//提示：
//
//1 <= k <= events.length
//1 <= k * events.length <= 10^6
//1 <= startDayi <= endDayi <= 10^9
//1 <= valuei <= 10^6



class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>> dp(n,vector<int>(k+1));
        sort(events.begin(),events.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });
        vector<int> endtime={events[0][1]};
        for(int i=1;i<=k;++i)
            dp[0][i]=events[0][2];
        for(int i=1;i<n;++i){
            int p=lower_bound(endtime.begin(),endtime.end(),events[i][0])-endtime.begin();
            for(int j=1;j<=k;++j){
                if(p>0)
                    dp[i][j]=dp[p-1][j-1]+events[i][2];
                else
                    dp[i][j]=events[i][2];
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
            endtime.emplace_back(events[i][1]);
        }
        return dp[n-1][k];
    }
};

//class Solution {
//private:
//    vector<int> tmp;
//    vector<vector<int>> memo;
//    int dfs(const vector<vector<int>>& events, int k, int index){
//        if(k==0)
//            return 0;
//        if(index==events.size())
//            return 0;
//        if(memo[index][k]!=-1)
//            return memo[index][k];
//        int res=0;
//        int p=upper_bound(tmp.begin(),tmp.end(),events[index][1])-tmp.begin();
//        res=max(dfs(events,k,index+1),events[index][2]+dfs(events,k-1,p));
//        memo[index][k]=res;
//        return res;
//    }
//public:
//    int maxValue(vector<vector<int>>& events, int k) {
//        int n=events.size();
//        sort(events.begin(),events.end(),[](const vector<int>& a, const vector<int>& b){
//            return a[0]<b[0];
//        });
//        for(int i=0;i<n;++i)
//            tmp.emplace_back(events[i][0]);
//        memo=vector<vector<int>>(n,vector<int>(k+1,-1));
//        return dfs(events,k,0);
//    }
//};

int main(int argc, char* argv[]){

    vector<vector<int>> events={{1,2,4},{3,4,3},{2,3,1}};
    int k=2;
    cout<<Solution().maxValue(events,k)<<endl;

    events={{19,42,7},{41,73,15},{52,73,84},{84,92,96},{6,64,50},{12,56,27},{22,74,44},{38,85,61}};
    k=5;
    cout<<Solution().maxValue(events,k)<<endl;
    return 0;
}

