#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int equalSubstring(string s, string t, int maxCost) {
//        int n=s.size();
//        map<int,int> f;
//        int sum=0;
//        int res=0;
//        for(int i=0;i<n;++i){
//            sum+=abs(s[i]-t[i]);
//            if(maxCost>=sum){
//                res=max(res,i+1);
//            } else {
//                auto p=f.lower_bound(sum-maxCost);
//                if(p!=f.end())
//                    res=max(res,i-p->second);
//            }
//            if(!f.count(sum))
//                f[sum]=i;
//        }
//        return res;
//    }
//};

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int res = 0;
        int sum = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            sum += abs(s[r] - t[r]);
            while (sum > maxCost) {
                sum -= abs(s[l] - t[l]);
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
