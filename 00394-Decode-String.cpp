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

int main(int argc, char* argv[]) {



    return 0;
}

