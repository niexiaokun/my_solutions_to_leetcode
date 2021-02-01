#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//772. 基本计算器 III
//
//实现一个基本的计算器来计算简单的表达式字符串。
//
//表达式字符串只包含非负整数， +, -, *, / 操作符，左括号 ( ，右括号 )和空格 。整数除法需要向下截断。
//
//你可以假定给定的字符串总是有效的。所有的中间结果的范围为 [-2147483648, 2147483647]。
//
//进阶：你可以在不使用内置库函数的情况下解决此问题吗？
//
//
//
//示例 1：
//
//输入：s = "1 + 1"
//输出：2
//
//示例 2：
//
//输入：s = " 6-4 / 2 "
//输出：4
//
//示例 3：
//
//输入：s = "2*(5+5*2)/3+(6/2+8)"
//输出：21
//
//示例 4：
//
//输入：s = "(2+6* 3+5- (3*14/7+2)*5)+3"
//输出：-12
//
//示例 5：
//
//输入：s = "0"
//输出：0
//
//
//
//提示：
//
//1 <= s <= 104
//s 由整数、'+'、'-'、'*'、'/'、'('、')' 和 ' ' 组成
//        s 是一个 有效的 表达式



class Solution {
public:
    int calculate(string s) {
        vector<pair<int,long>> f;
        vector<pair<int,char>> g;
        long num=0;
        char sign='+';

        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(sign=='+')
                    f.emplace_back(1,num);
                else if(sign=='-')
                    f.emplace_back(-1,num);
                else if(sign=='*')
                    f[f.size()-1].second*=num;
                else if(sign=='/')
                    f[f.size()-1].second/=num;
                num=0;
                int j=g.back().first;
                char c=g.back().second;
                g.pop_back();
                for(int i=j;i<f.size();i++)
                    num+=f[i].first*f[i].second;
                while(f.size()>j) f.pop_back();
                if(c=='+')
                    f.emplace_back(1,num);
                else if(c=='-')
                    f.emplace_back(-1,num);
                else if(c=='*')
                    f[f.size()-1].second*=num;
                else if(c=='/')
                    f[f.size()-1].second/=num;
                num=0;
                sign=')';
            }else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
                if(sign=='+')
                    f.emplace_back(1,num);
                else if(sign=='-')
                    f.emplace_back(-1,num);
                else if(sign=='*')
                    f[f.size()-1].second*=num;
                else if(sign=='/')
                    f[f.size()-1].second/=num;
                sign=s[i];
                num=0;
            }else if(s[i]=='(') {
                g.emplace_back(f.size(),sign);
                sign='+';
            }else if(s[i]!=' '){
                num=num*10+(s[i]-'0');
            }
        }
        if(num) {
            if(sign=='+')
                f.emplace_back(num,1);
            else if(sign=='-')
                f.emplace_back(num,-1);
            else if(sign=='*')
                f[f.size()-1].second*=num;
            else if(sign=='/')
                f[f.size()-1].second/=num;
        }

        int sum=0;
        for(int i=0;i<f.size();i++)
            sum+=f[i].first*f[i].second;
        return sum;
    }
};



int main(int argc, char *argv[]){

    string s=" 6-4 / 2 ";
    cout<<s<<endl;
    cout<<Solution().calculate(s)<<endl;

    s="2*(5+5*2)/3+(6/2+8)";
    cout<<s<<endl;
    cout<<Solution().calculate(s)<<endl;


    vector<string> aa={"34","34443","34444","34445"};
    sort(aa.begin(),aa.end());
    return 0;
}