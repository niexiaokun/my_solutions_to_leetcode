#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 5545
//class Solution {
//private:
//    vector<int> memo;
//    int choose(vector<pair<int,int>>& players, int index){
//        if(index==0)
//            memo[index] = players[0].second;
//        if(memo[index]!=-1)
//            return memo[index];
//        int i = index - 1;
//        int tmp=0;
//        for(; i>=0; i--){
//            if(players[i].second<=players[index].second)
//                tmp=max(tmp,choose(players,i));
//        }
//        memo[index] = players[index].second+tmp;
//        return memo[index];
//    }
//public:
//    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//        vector<pair<int,int>> players;
//        for(int i=0; i<ages.size(); i++){
//            players.push_back(make_pair(ages[i],scores[i]));
//        }
//        sort(players.begin(),players.end(),[](pair<int,int>& a1, pair<int,int>&a2){
//            return a1.first<a2.first || (a1.first==a2.first&&a1.second<a2.second);
//        });
//        memo = vector<int>(ages.size(),-1);
//        int res = 0;
//        for(int i=0;i<ages.size();i++)
//            res = max(res,choose(players,i));
//        return res;
//    }
//};


class Solution {
private:

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> players;
        for(int i=0; i<ages.size(); i++){
            players.push_back(make_pair(ages[i],scores[i]));
        }
        sort(players.begin(),players.end(),[](pair<int,int>& a1, pair<int,int>&a2){
            return a1.first<a2.first || (a1.first==a2.first&&a1.second<a2.second);
        });
        vector<int> memo = vector<int>(ages.size(),-1);
        int res = 0;
        for(int i=0;i<ages.size();i++){
            for(int j=0; j<i; j++){
                if(players[i].second>=players[j].second){
                    memo[i]=max(memo[i],memo[j]+players[i].second);
                }
            }
            memo[i]=max(players[i].second,memo[i]);
            res = max(res,memo[i]);
        }
        return res;
    }
};



int main(int argc, char* argv[]){

    return 0;
}