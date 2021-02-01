#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//class Solution {
//private:
//    int dfs(int coinIndex, vector<int>& coins, int amount){  //超时
//        if(amount==0)
//            return 0;
//        if(coinIndex>=coins.size()||amount<0)
//            return -1;
//
//        int maxval=amount/coins[coinIndex];
//        int minCoins=INT32_MAX;
//        for(int k=0;k<=maxval;k++){
//            int res=dfs(coinIndex+1,coins,amount-k*coins[coinIndex]);
//            if(res!=-1)
//                minCoins=min(minCoins,k+res);
//        }
//        return (minCoins==INT32_MAX)? -1:minCoins;
//    }
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        if(amount==0)
//            return 0;
//        return dfs(0,coins,amount);
//    }
//};

//class Solution {
//private:
//    int dfs(vector<int>& coins, int amount, vector<int>& memo){
//        if(memo[amount]!=-2)
//            return memo[amount];
//        int minCoins=INT32_MAX;
//        for(int coin:coins){
//            if(amount>=coin){
//                int res=dfs(coins,amount-coin,memo);
//                if(res!=-1)
//                    minCoins=min(minCoins,res+1);
//            }
//        }
//        memo[amount] = (minCoins==INT32_MAX)? -1:minCoins;
//        return memo[amount];
//    }
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        if(amount==0)
//            return 0;
//        vector<int> memo(amount+1,-2);
//        memo[0]=0;
//        return dfs(coins,amount,memo);
//    }
//};

//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        if(amount==0)
//            return 0;
//        vector<int> dp(amount+1,INT32_MAX);
//        dp[0]=0;
//        for(int i=1;i<=amount;i++)
//            for(int coin:coins)
//                if(i>=coin&&dp[i-coin]!=INT32_MAX)
//                    dp[i]=min(dp[i],dp[i-coin]+1);
//
//        return dp[amount]==INT32_MAX? -1:dp[amount];
//    }
//};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        sort(coins.begin(),coins.end());
        vector<bool> visited(amount+1,false);
        int res=0;
        queue<int> q;
        q.push(amount);
        visited[amount]=true;
        while(!q.empty()){
            res++;
            for(int i=q.size();i>0;i--){
                int cur=q.front();
                q.pop();
                int next;
                for(int coin:coins){
                    next=cur-coin;
                    if(next==0)
                        return res;
                    else if(next>0){
                        if(!visited[next]){
                            visited[next]=true;
                            q.push(next);
                        }
                    }else
                        break;
                }
            }
        }
        return -1;
    }
};


int main(int argc, char *argv[]){

    vector<int> coins{1,2,5};
    int amount=11;
    cout<<Solution().coinChange(coins,amount)<<endl;

    coins={27,40,244,168,383};
    amount=6989;
    cout<<Solution().coinChange(coins,amount)<<endl;

    coins={346,29,395,188,155,109};
    amount=9401;
    cout<<Solution().coinChange(coins,amount)<<endl;

    return 0;
}