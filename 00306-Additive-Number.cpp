#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//306. 累加数
//
//累加数是一个字符串，组成它的数字可以形成累加序列。
//
//一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
//
//给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
//
//说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
//
//示例 1:
//
//输入: "112358"
//输出: true
//解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//
//示例 2:
//
//输入: "199100199"
//输出: true
//解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
//
//进阶:
//你如何处理一个溢出的过大的整数输入?


class Solution {
private:
    string addStr(string s1, string s2){
        if(s1.size()<s2.size())
            swap(s1,s2);
        string res;
        int a=0,num;
        int t=s1.size()-s2.size();
        for(int i=s2.size()-1;i>=0;i--){
            num=s1[i+t]-'0'+s2[i]-'0'+a;
            a=num/10;
            res+=(num%10)+'0';
        }
        for(int i=t-1;i>=0;i--){
            num=s1[i]-'0'+a;
            a=num/10;
            res+=(num%10)+'0';
        }
        if(a)
            res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
    bool dfs(string s, int start, const string& pre, const string& cur, int n) {
        if(start==s.size()&&n>=3)
            return true;
        string next;
        if(n>=2){
            if(s[start]=='0'){
                if(pre!="0"||cur!="0")
                    return false;
                for(int i=start+1;i<s.size();i++)
                    if(s[i]!='0')
                        return false;
                return true;
            }
            next=addStr(pre,cur);
            if(next.size()>s.size()-start||s.substr(start,next.size())!=next)
                return false;
            return dfs(s,start+next.size(),cur,next,n+1);
        }else if(s[start]=='0')
            return dfs(s,start+1,cur,"0",n+1);
        else{
            for(int end=start;end<s.size();end++){
                next=s.substr(start,end-start+1);
                if(dfs(s,end+1,cur,next,n+1))
                    return true;
            }
        }
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        if(num.size()<3)
            return false;
        return dfs(num,0,"","", 0);
    }
};


int main(int argc, char *argv[]){

    string num="199001200";
    cout<<Solution().isAdditiveNumber(num)<<endl;

    num="121474836472147483648";
    cout<<Solution().isAdditiveNumber(num)<<endl;

    num="12303";
    cout<<Solution().isAdditiveNumber(num)<<endl;

    num="325466";
    cout<<Solution().isAdditiveNumber(num)<<endl;

    num="123456579";
    cout<<Solution().isAdditiveNumber(num)<<endl;

    return 0;
}

