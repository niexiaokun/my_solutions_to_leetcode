#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>
void printVec(vector<T>& v, int l, int r){
    cout<<"[ ";
    for(int i=l;i<=r;i++)
        cout<<v[i]<<" ";
    cout<<"]"<<endl;
}

class Solution {
private:
    int __merge(vector<int>& nums, vector<int>& aux, int l, int mid, int r){
        for(int i=l;i<=r;i++)
            aux[i]=nums[i];
        int i=l,j=mid+1,res=0;
        for(int k=l;k<=r;k++){
            if(i>mid)
                nums[k]=aux[j++];
            else if(j>r)
                nums[k]=aux[i++];
            else if(aux[i]<=aux[j])
                nums[k] = aux[i++];
            else{
                nums[k]=aux[j++];
                res+=mid-i+1;
            }
        }
        return res;
    }
    int __reversePairs(vector<int>& nums, vector<int>& aux, int l, int r){
        if(l>=r)
            return 0;
        int mid=(r-l)/2+l;
        int res1=__reversePairs(nums,aux,l,mid);
        int res2=__reversePairs(nums,aux,mid+1,r);
        if(nums[mid]<=nums[mid+1])
            return res1+res2;
        return res1+res2+__merge(nums,aux,l,mid,r);
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<int> aux(nums.size());
        return __reversePairs(nums,aux,0,nums.size()-1);
    }
};


int main(int argc, char *argv[]){

    vector<int> nums{1,3,2,3,1};
    cout<<Solution().reversePairs(nums)<<endl;


    return 0;
}