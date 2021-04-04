#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int k = 0;

    string dfs(const string &s, int index) {
        string res;
        if (index == s.size())
            return res;
        int num = 0;
        while (index < s.size() && s[index] != '[') {
            if (s[index] >= '0' && s[index] <= '9')
                num = num * 10 + s[index] - '0';
            else if (s[index] == ']') {
                k = index;
                return res;
            } else
                res += s[index];
            ++index;
        }
        if (index == s.size())
            return res;
        string ss = dfs(s, index + 1);
        for (int i = 0; i < num; ++i)
            res += ss;
        ss = dfs(s, k + 1);
        res += ss;
        return res;
    }

public:
    string decodeString(string s) {
        return dfs(s, 0);
    }
};

//class Solution {
//private:
//    string dfs(string& s, int l, int r){
//        string res;
//        int cnt = 0;
//        int num = 0;
//        int j = 0;
//        for(int i = l; i <= r; ++i){
//            if(cnt == 0 && s[i] >= '0' && s[i] <= '9'){
//                num = num * 10 + (s[i] - '0');
//            }else if(s[i] == '['){
//                if(cnt == 0)
//                    j = i + 1;
//                ++cnt;
//            }else if(s[i] == ']'){
//                --cnt;
//                if(cnt == 0){
//                    string tmp = dfs(s, j, i-1);
//                    for(int k = 0; k < num; ++k)
//                        res += tmp;
//                    num = 0;
//                }
//            }else if(num == 0){
//                res += s[i];
//            }
//        }
//        return res;
//    }
//public:
//    string decodeString(string s) {
//        int n = s.size();
//        return dfs(s, 0, n-1);
//    }
//};

int main(int argc, char* argv[]) {



    return 0;
}

