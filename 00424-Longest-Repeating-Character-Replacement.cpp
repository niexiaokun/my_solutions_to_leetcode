#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//424. 替换后的最长重复字符
//
//给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
//
//注意:
//字符串长度 和 k 不会超过 10^4。
//
//示例 1:
//
//输入:
//s = "ABAB", k = 2
//
//输出:
//4
//
//解释:
//用两个'A'替换为两个'B',反之亦然。
//
//示例 2:
//
//输入:
//s = "AABABBA", k = 1
//
//输出:
//4
//
//解释:
//将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
//子串 "BBBB" 有最长重复字母, 答案为 4。


//class Solution {
//public:
//    int characterReplacement(string s, int k) {
//        if(s.empty())
//            return 0;
//        unordered_map<char,int> mp;
//        int l=0,ans=0,maxcnt=0;
//        for(int r=0;r<s.size();r++){
//            mp[s[r]]++;
//            if(mp[s[r]]>maxcnt)
//                maxcnt=mp[s[r]];
//            if(r-l+1<=maxcnt+k)
//                ans=max(ans,r-l+1);
//            else{
//                mp[s[l]]--;
//                l++;
//            }
//        }
//        return ans;
//    }
//};


class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty())
            return 0;
        vector<int> mp(26);
        int l=0,ans=0,maxcnt=0;
        int index;
        for(int r=0;r<s.size();r++){
            index=s[r]-'A';
            mp[index]++;
            if(mp[index]>maxcnt)
                maxcnt=mp[index];
            if(r-l+1<=maxcnt+k)
                ans=max(ans,r-l+1);
            else{
                mp[s[l]-'A']--;
                l++;
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]){

    string s="ABAB";
    int k=2;
    cout<<Solution().characterReplacement(s,k)<<endl;

    s="AABABBA";
    k=1;
    cout<<Solution().characterReplacement(s,k)<<endl;

    return 0;
}