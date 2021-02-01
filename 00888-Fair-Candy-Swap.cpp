#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int x=accumulate(A.begin(),A.end(),0);
        int y=accumulate(B.begin(),B.end(),0);
        unordered_set<int> g(A.begin(),A.end());
        vector<int> res;
        for(int num:B){
            int z=num+(x-y)/2;
            if(g.count(z))
                res={z,num};
        }
        return res;
    }
};


int main(int argc, char* argv[]){

    return 0;
}