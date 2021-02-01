#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//159. 至多包含两个不同字符的最长子串
//
//给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t ，并返回该子串的长度。
//
//示例 1:
//
//输入: "eceba"
//输出: 3
//解释: t 是 "ece"，长度为3。
//
//示例 2:
//
//输入: "ccaabbb"
//输出: 5
//解释: t 是 "aabbb"，长度为5。


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())
            return 0;
        unordered_map<char,int> mp;
        int l=0,ans=0,cnt=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            if(mp[s[r]]==1)
                cnt++;
            if(cnt<=2)
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
    cout<<Solution().lengthOfLongestSubstringTwoDistinct(s)<<endl;

    s="ccaabbb";
    cout<<Solution().lengthOfLongestSubstringTwoDistinct(s)<<endl;

    return 0;
}