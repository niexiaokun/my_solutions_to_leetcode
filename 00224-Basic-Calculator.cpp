#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int eval(const string& s){
        int res = 0;
        int x = 0;
        int a = 1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '-') {
                res += a * x;
                x = 0;
                a = -1;
            }else if(s[i] == '+'){
                res += a * x;
                x = 0;
                a = 1;
            }else{
                x = x * 10 + (s[i] - '0');
            }
        }
        res += a * x;
        return res;
    }
public:
    int calculate(string s) {
       int n = s.size();
       vector<char> stk;
       for(int i = 0; i < s.size(); ++i){
           if(s[i] == ' ')
               continue;
           if(s[i] == ')'){
               string str;
               while(stk.back() != '('){
                   str += stk.back();
                   stk.pop_back();
               }
               reverse(str.begin(), str.end());
               stk.pop_back();
               int x = eval(str);
               str = to_string(x);
               for(int i = 0; i < str.size(); ++i) {
                    if(str[i] == '-' && !stk.empty()){
                        if(x < 0){
                            if(*stk.rbegin() == '+')
                                *stk.rbegin() = '-';
                            else
                                *stk.rbegin() = '+';
                        }
                    }else
                        stk.emplace_back(str[i]);
               }
           } else
               stk.emplace_back(s[i]);
       }
        string str;
        for(char& c : stk)
            str += c;
        return eval(str);
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

