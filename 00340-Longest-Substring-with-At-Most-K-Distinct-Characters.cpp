#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


//340. 至多包含 K 个不同字符的最长子串
//
//给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。
//
//示例 1:
//
//输入: s = "eceba", k = 2
//输出: 3
//解释: 则 T 为 "ece"，所以长度为 3。
//
//示例 2:
//
//输入: s = "aa", k = 1
//输出: 2
//解释: 则 T 为 "aa"，所以长度为 2。

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty())
            return 0;
        unordered_map<char,int> mp;
        int l=0,ans=0,cnt=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            if(mp[s[r]]==1)
                cnt++;
            if(cnt<=k)
                ans=max(ans,r-l+1);
            else{
                mp[s[l]]--;
                if(mp[s[l]]==0)
                    cnt--;
                l++;
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]){

    string s="eceba";
    int k=2;
    cout<<Solution().lengthOfLongestSubstringKDistinct(s,k)<<endl;

    return 0;
}