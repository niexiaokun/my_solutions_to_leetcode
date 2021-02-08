#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string res;
        int i = 0;
        int j = 0;
        for (int k = 0; k < m + n; ++k) {
            if (i >= m) {
                res += word2[j];
                ++j;
            } else if (j >= n) {
                res += word1[i];
                ++i;
            } else if (word1[i] > word2[j]) {
                res += word1[i];
                ++i;
            } else if (word1[i] < word2[j]) {
                res += word2[j];
                ++j;
            } else {
                res += word1[i];
                string s1 = word1.substr(i);
                string s2 = word2.substr(j);
                if (s1 > s2)
                    ++i;
                else
                    ++j;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}
