#include <iostream>
#include <vector>


using namespace std;



//132. 分割回文串 II
//
//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回符合要求的最少分割次数。
//
//示例:
//
//输入: "aab"
//输出: 1
//解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。


class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> f(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            f[i][i]=true;
        for(int t=2;t<=n;t++){
            for(int l=0;l+t<=n;l++){
                int r=l+t-1;
                if(s[l]==s[r]){
                    if(t==2)
                        f[l][r]=true;
                    else
                        f[l][r]=f[l+1][r-1];
                }
            }
        }
        vector<int> dp(n,n-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            if(!f[0][i]) {
                for (int j = i; j > 0; j--) {
                    if(f[j][i]){
                        dp[i]=min(dp[i],1+dp[j-1]);
                    }
                }
            }else
                dp[i]=0;
        }
        return dp[n-1];
    }
};



int main(int argc, char *argv[]){

    string s="aababb";
    cout<<s<<endl;
    cout<<Solution().minCut(s)<<endl;

    s="cabababcbc";
    cout<<s<<endl;
    cout<<Solution().minCut(s)<<endl;

    return 0;
}