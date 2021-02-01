#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//454. 四数相加 II
//
//给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
//
//为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
//
//例如:
//
//输入:
//A = [ 1, 2]
//B = [-2,-1]
//C = [-1, 2]
//D = [ 0, 2]
//
//输出:
//2
//
//解释:
//两个元组如下:
//1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


//class Solution {
//public:
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//        int n=A.size();
//        if(n==0)
//            return 0;
//        unordered_map<int,int> mp1;
//        for(int i=0;i<n;i++)
//            for(int j=0;j<n;j++)
//                mp1[0-A[i]-B[j]]++;
//        unordered_map<int,int> mp2;
//        for(int i=0;i<n;i++)
//            for(int j=0;j<n;j++)
//                mp2[C[i]+D[j]]++;
//        int res=0;
//        for(auto& p:mp1){
//            if(mp2.count(p.first)) {
////                cout<<p.second<<" "<<mp2[p.first]<<endl;
//                res += p.second * mp2[p.first];
////                mp2.erase(p.first);
//            }
//        }
//        return res;
//    }
//};


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n=A.size();
        if(n==0)
            return 0;
        unordered_map<int,int> mp1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mp1[0-A[i]-B[j]]++;
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(mp1.count(C[i]+D[j]))
                    res+=mp1[C[i]+D[j]];

        return res;
    }
};


int main(int argc, char *argv[]){

    vector<int> A{-1,-1};
    vector<int> B{-1,1};
    vector<int> C{-1,1};
    vector<int> D{1,-1};

    cout<<Solution().fourSumCount(A,B,C,D)<<endl;

    return 0;
}