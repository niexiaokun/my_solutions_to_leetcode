#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//166. 分数到小数
//
//给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
//
//如果小数部分为循环小数，则将循环的部分括在括号内。
//
//如果存在多个答案，只需返回 任意一个 。
//
//对于所有给定的输入，保证 答案字符串的长度小于 104 。
//
//
//
//示例 1：
//
//输入：numerator = 1, denominator = 2
//输出："0.5"
//
//示例 2：
//
//输入：numerator = 2, denominator = 1
//输出："2"
//
//示例 3：
//
//输入：numerator = 2, denominator = 3
//输出："0.(6)"
//
//示例 4：
//
//输入：numerator = 4, denominator = 333
//输出："0.(012)"
//
//示例 5：
//
//输入：numerator = 1, denominator = 5
//输出："0.2"
//
//
//
//提示：
//
//-2^31 <= numerator, denominator <= 2^31 - 1
//denominator != 0


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0)
            return "";
        if(numerator==0)
            return "0";
        long long num=(long long)numerator;
        long long denom=(long long)denominator;
        string ans;
        if((num>0)^(denom>0))
            ans.push_back('-');
        num=llabs(num);
        denom=llabs(denom);
        long long res=num/denom;
        ans+=to_string(res);
        res=num%denom;
        if(res==0)
            return ans;
        ans.push_back('.');
        int index=ans.size();
        int f;
        unordered_map<int,int> record;
        while(res){
            if(!record.count(res))
                record[res]=index++;
            res*=10;
            f=res/denom;
            if(f==0){
                ans.push_back('0');
                continue;
            }
            ans+=to_string(f);
            res=res%denom;
            if(record.count(res)){
                ans.insert(record[res],"(");
                ans.push_back(')');
                return ans;
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]){

    int numerator=1;
    int denominator=2;
//    cout<<Solution().fractionToDecimal(numerator,denominator)<<endl;
//
//    numerator=2;
//    denominator=1;
//    cout<<Solution().fractionToDecimal(numerator,denominator)<<endl;
//
//    numerator=2;
//    denominator=3;
//    cout<<Solution().fractionToDecimal(numerator,denominator)<<endl;
//
//    numerator=4;
//    denominator=333;
//    cout<<Solution().fractionToDecimal(numerator,denominator)<<endl;
//
//    numerator=1;
//    denominator=5;
//    cout<<Solution().fractionToDecimal(numerator,denominator)<<endl;
//
//    numerator=77;
//    denominator=45;
//    cout<<Solution().fractionToDecimal(numerator,denominator)<<endl;
//
    numerator=-1;
    denominator=-2147483648;
    cout<<Solution().fractionToDecimal(numerator,denominator)<<endl;

    return 0;
}

