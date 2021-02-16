#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        int n = chars.size();
        int j = 0;
        int cnt = 1;
        vector<char> tmp;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i < n && chars[i] == chars[i - 1]) {
                ++cnt;
            } else {
                int k = cnt;
                int cnt1 = 1;
                while (k) {
                    ++cnt1;
                    tmp.emplace_back('0' + k % 10);
                    k /= 10;
                }
                if (cnt1 <= cnt) {
                    chars[j++] = chars[i - 1];
                    while (!tmp.empty()) {
                        chars[j++] = tmp.back();
                        tmp.pop_back();
                    }
                    res += cnt1;
                } else {
                    tmp.clear();
                    for (int x = 0; x < cnt; ++x)
                        chars[j++] = chars[i - 1];
                    res += cnt;
                }
                cnt = 1;
            }
        }
        return res;
    }
};



int main(int argc, char* argv[]) {

    vector<char> chars={'a','a','b','b','c','c','c'};
    cout<<Solution().compress(chars)<<endl;

    chars={'a','a','a','b','b','a','a'};
    cout<<Solution().compress(chars)<<endl;

    chars={'a','b','c','d','e','f','g','g','g','g','g','g','g','g','g','g','g','g','a','b','c'};
    cout<<Solution().compress(chars)<<endl;

    return 0;
}

