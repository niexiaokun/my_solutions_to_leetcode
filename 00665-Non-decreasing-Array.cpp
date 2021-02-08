#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return true;
        int cnt = 0;
        for(int i=1;i<n;++i){
            if(nums[i]<nums[i-1]){
                if(i>=2){
                    if(nums[i-2]<=nums[i])
                        nums[i-1]=nums[i];
                    else if(i+1<n){
                        if(nums[i-1]>nums[i+1])
                            return false;
                        nums[i]=nums[i+1];
                    }
                }
                ++cnt;
                if(cnt>1)
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]){

    return 0;
}