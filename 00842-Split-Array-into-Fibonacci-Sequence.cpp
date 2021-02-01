#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;


//842. 将数组拆分成斐波那契序列
//
//给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。
//
//形式上，斐波那契式序列是一个非负整数列表 F，且满足：
//
//0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
//F.length >= 3；
//对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
//
//另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
//
//返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。
//
//
//
//示例 1：
//
//输入："123456579"
//输出：[123,456,579]
//
//示例 2：
//
//输入: "11235813"
//输出: [1,1,2,3,5,8,13]
//
//示例 3：
//
//输入: "112358130"
//输出: []
//解释: 这项任务无法完成。
//
//示例 4：
//
//输入："0123"
//输出：[]
//解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
//
//示例 5：
//
//输入: "1101111"
//输出: [110, 1, 111]
//解释: 输出 [11,0,11,11] 也同样被接受。
//
//
//
//提示：
//
//1 <= S.length <= 200
//字符串 S 中只含有数字。


namespace utils{
    template <typename T>
    void printVec(const vector<T>& nums){
        if(nums.empty()){
            cout<<"[]"<<endl;
            return;
        }
        cout<<"[ ";
        for(const T& u:nums)
            cout<<u<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVec(const vector<T>& nums, int l, int r){
        if(l>r)
            return;
        cout<<"[ ";
        for(int i=l;i<=r;i++)
            cout<<nums[i]<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVvec(const vector<vector<T>>& nums){
        if(nums.empty())
            return;
        cout<<"["<<endl;
        for(const vector<T>& v:nums) {
            cout<<"[ ";
            for (const T &u:v)
                cout << u << " ";
            cout<<"]"<<endl;
        }
        cout<<"]"<<endl;
    }
}


class Solution {
private:
    int convertInt(const string& s){
        if(s.size()>10)
            return -1;
        int num=0;
        if(s.size()<10||s[0]<'2'){
            for(int i=0;i<s.size();i++)
                num=num*10+s[i]-'0';
            return num;
        }else if(s[0]=='2'){
            for(int i=1;i<s.size();i++)
                num=num*10+s[i]-'0';
            if(num>INT32_MAX%1000000000)
                return -1;
            return (s[0]-'0')*1000000000+num;
        }else
            return -1;
    }

    bool dfs(string s, int start, int pre, int cur, vector<int>& res) {
        if (start == s.size() && res.size() >= 3)
            return true;
        int next;
        string nextStr;
        if (pre != -1 && cur != -1) {
            if (s[start] == '0'){
                if(pre!=0||cur!=0)
                    return false;
                for(int i=start+1;i<s.size();i++){
                    if(s[i]!='0')
                        return false;
                }
                res.resize(s.size(),0);
                return true;
            }
            if(cur>INT32_MAX-pre)
                return false;
            next = pre + cur;
            nextStr = to_string(next);
            if (nextStr.size() > s.size() - start || s.substr(start, nextStr.size()) != nextStr)
                return false;
            res.emplace_back(next);
            if (dfs(s, start + nextStr.size(), cur, next, res))
                return true;
            res.pop_back();
        } else if (s[start] == '0') {
            res.emplace_back(0);
            if (dfs(s, start + 1, cur, 0, res))
                return true;
            else
                res.pop_back();
        } else
            for (int t = 1; t <= 10; t++) {
                if (start + t > s.size())
                    break;
                nextStr = s.substr(start, t);
                next = convertInt(nextStr);
                if (next == -1)
                    break;
                if (cur != -1 && next > INT32_MAX - cur)
                    break;
                res.emplace_back(next);
                if (dfs(s, start + t, cur, next, res))
                    return true;
                res.pop_back();
            }

        return false;
    }
public:
    vector<int> splitIntoFibonacci(string s) {
        vector<int> res;
        dfs(s,0,-1,-1,res);
        return res;
    }
};




int main(int argc, char *argv[]){

    string s="123456579";
    utils::printVec(Solution().splitIntoFibonacci(s));

    s="11235813";
    utils::printVec(Solution().splitIntoFibonacci(s));

    s="112358130";
    utils::printVec(Solution().splitIntoFibonacci(s));

    s="0123";
    utils::printVec(Solution().splitIntoFibonacci(s));

    s="0000";
    utils::printVec(Solution().splitIntoFibonacci(s));

    s="539834657215398346785398346991079669377161950407626991734534318677529701785098211336528511";
    utils::printVec(Solution().splitIntoFibonacci(s));

    s="199001200";
    utils::printVec(Solution().splitIntoFibonacci(s));

    s="121474836472147483648";
    utils::printVec(Solution().splitIntoFibonacci(s));

    return 0;
}