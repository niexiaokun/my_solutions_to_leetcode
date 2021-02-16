#include <bits/stdc++.h>

using namespace std;

//class Solution {
//    bool check(unordered_map<char,int>& x1, unordered_map<char,int>& x2){
//        if(x1.size()!=x2.size())
//            return false;
//        for(const auto& p:x2){
//            if(x1.count(p.first)&&x1[p.first]==p.second)
//                continue;
//            else
//                return false;
//        }
//        return true;
//    }
//public:
//    bool checkInclusion(string s1, string s2) {
//        int m=s1.size();
//        int n=s2.size();
//        if(m>n)
//            return false;
//        unordered_map<char,int> f;
//        for(const char& c:s1)
//            f[c]++;
//        unordered_map<char,int> g;
//        for(int i=0;i<m;++i)
//            g[s2[i]]++;
//        if(check(f,g))
//            return true;
//        for(int i=m;i<n;++i){
//            g[s2[i]]++;
//            g[s2[i-m]]--;
//            if(g[s2[i-m]]==0)
//                g.erase(s2[i-m]);
//            if(check(f,g))
//                return true;
//        }
//        return false;
//    }
//};

class Solution {
private:
    bool check(const vector<int> &x1, const vector<int> &x2) {
        for (int i = 0; i < 26; ++i) {
            if (x1[i] != x2[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n)
            return false;
        vector<int> tmp1(26);
        for (const char &c : s1)
            tmp1[c - 'a']++;
        vector<int> tmp2(26);
        for (int i = 0; i < m; ++i) {
            tmp2[s2[i] - 'a']++;
        }
        if (check(tmp1, tmp2))
            return true;
        for (int i = m; i < n; ++i) {
            tmp2[s2[i] - 'a']++;
            tmp2[s2[i - m] - 'a']--;
            if (check(tmp1, tmp2))
                return true;
        }
        return false;
    }
};


int main(int argc, char* argv[]) {



    return 0;
}

