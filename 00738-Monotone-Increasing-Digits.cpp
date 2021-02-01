#include <iostream>
#include <vector>


using namespace std;


//738. 单调递增的数字
//
//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//
//（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
//
//示例 1:
//
//输入: N = 10
//输出: 9
//
//示例 2:
//
//输入: N = 1234
//输出: 1234
//
//示例 3:
//
//输入: N = 332
//输出: 299
//
//说明: N 是在 [0, 10^9] 范围内的一个整数。


class Solution {
public:
    virtual int monotoneIncreasingDigits(int N) {
        string s=to_string(N);
        int i=1;
        while(i<s.size()&&s[i-1]<=s[i]) i++;
        if(i==s.size()) return  N;
        while(i>0&&s[i-1]>s[i]){
            s[i-1]--;;
            i--;
        }
        while(++i<s.size()) s[i]='9';
        return stoi(s);
    }
};


int main(int argc, char *argv[]){

    int N=9;
//    cout<<Solution().monotoneIncreasingDigits(N)<<endl;
//
//    N=1234;
//    cout<<Solution().monotoneIncreasingDigits(N)<<endl;
//
    N=332;
    cout<<Solution().monotoneIncreasingDigits(N)<<endl;

    N=13512;
    cout<<Solution().monotoneIncreasingDigits(N)<<endl;


    return 0;
}