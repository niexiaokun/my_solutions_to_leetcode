#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum=accumulate(colsum.begin(),colsum.end(),0);
        if(sum!=upper+lower)
            return {};
        int rowSum1=0;
        int rowSum2=0;
        vector<vector<int>>matrix(2,vector<int>(colsum.size(),0));
        for(int i=0; i<colsum.size(); i++){
            if(colsum[i]==2){
                matrix[0][i]=1;
                matrix[1][i]=1;
                rowSum1++;
                rowSum2++;
            }
        }
        if(rowSum1==upper&&rowSum2==lower)
            return matrix;
        if(rowSum1>upper||rowSum2>lower)
            return {};
        for(int i=0; i<colsum.size(); i++){
            if(colsum[i]==1){
                if(rowSum1<upper) {
                    matrix[0][i] = 1;
                    rowSum1++;
                }else if(rowSum2<lower){
                    matrix[1][i] = 1;
                    rowSum2++;
                }else{
                    return {};
                }
            }
        }
        if(rowSum1<upper||rowSum2<lower)
            return {};

        return matrix;
    }
};

int main(int argc, char* argv[]){

//    vector<int> colsum{2,0,2,1,1,2,2,0,1,1,1,0,0,0,0,2,1,2,2,2,1,1,0,0,0,0,1,2,1,0,1,0,2,0,0,0,0,2,1,1,2,1,1,0,0,1,0,0,1,1,2,0,1,1,1,2,1,0,0,1,1,1,2,2,1,0,0,1,1,1,0,2,1,2,1,0,1,2,0,2,2,1,0,1,1,1,2,0,0,0,1,2,2,0,0,1,1,2,1,2};
//    int uppper = 53;
//    int lower = 82;
//    vector<vector<int>>res = Solution().reconstructMatrix(uppper,lower,colsum);


    string s="0P";
    s[1]+=32;
    cout<<s<<endl;

    return 0;
}