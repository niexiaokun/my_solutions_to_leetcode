#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


//767. 重构字符串
//
//给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
//
//若可行，输出任意可行的结果。若不可行，返回空字符串。
//
//示例 1:
//
//输入: S = "aab"
//输出: "aba"
//
//示例 2:
//
//输入: S = "aaab"
//输出: ""
//
//注意:
//
//S 只包含小写字母并且长度在[1, 500]区间内。



//class Solution {
//public:
//    string reorganizeString(string S) {
//        unordered_map<char,int> mp;
//        int maxCount=0;
//        for(char& c:S) {
//            mp[c]++;
//            maxCount=max(maxCount,mp[c]);
//        }
//        if(maxCount>(S.size()+1)/2)
//            return "";
//        auto comp=[&](const char& c1, const char& c2){
//            return mp[c1]<mp[c2];
//        };
//        priority_queue<char,vector<char>, decltype(comp)> pq(comp);
//        for(auto& p:mp)
//            pq.emplace(p.first);
//        string res;
//        while(pq.size()>1){
//            char c1=pq.top(); pq.pop();
//            char c2=pq.top(); pq.pop();
//            res+=c1; res+=c2;
//            mp[c1]--; mp[c2]--;
//            if(mp[c1]>0)
//                pq.emplace(c1);
//            if(mp[c2]>0)
//                pq.emplace(c2);
//        }
//        if(pq.size()>0)
//            res+=pq.top();
//        return res;
//    }
//};


class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char,int> mp;
        int maxCount=0;
        for(char& c:S) {
            mp[c]++;
            maxCount=max(maxCount,mp[c]);
        }
        if(maxCount>(S.size()+1)/2)
            return "";
        vector<pair<char,int>> v;
        for(auto& p:mp)
            v.emplace_back(p);
        sort(v.begin(),v.end(),[](const pair<char,int>& p1, const pair<char,int>& p2){
           return p1.second>p2.second;
        });
        string res(S.size(),' ');
        int j=0;
        for(auto& u:v){
            while(u.second>0){
                res[j]=u.first;
                u.second--;
                j+=2;
                if(j>=res.size()) j=1;
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]){

    string S="aab";
    cout<<Solution().reorganizeString(S)<<endl;

    S="aaab";
    cout<<Solution().reorganizeString(S)<<endl;

    S="bbbbaaaaababaababab";
    cout<<Solution().reorganizeString(S)<<endl;

    S="abbabbaaab";
    cout<<Solution().reorganizeString(S)<<endl;

    return 0;
}