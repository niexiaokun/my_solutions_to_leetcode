#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

//347. 前 K 个高频元素
//
//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//
//
//示例 1:
//
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//
//示例 2:
//
//输入: nums = [1], k = 1
//输出: [1]
//
//
//
//提示：
//
//你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
//你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
//题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
//你可以按任意顺序返回答案。

namespace utils{
    template <typename T>
    void printVec(const vector<T>& v){
        if(v.empty()){
            cout<<"[]"<<endl;
            return;
        }
        cout<<"[ ";
        for(const T& num:v)
            cout<<num<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVvec(const vector<vector<T>>& v){
        if(v.empty())
            return;
        cout<<"["<<endl;
        for(const vector<T>& u:v)
            printVec(u);
        cout<<"]"<<endl;
    }
}


//class Solution {
//    using PIL=pair<int,int>;
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        auto f=[](const PIL& p1, const PIL& p2){
//            return p1.second>p2.second;
//        };
//        priority_queue<PIL,vector<PIL>, decltype(f)> pq(f);
//        unordered_map<int,int> mp;
//        for(int num:nums)
//            mp[num]++;
//        for(auto& p:mp){
//            if(pq.size()<k)
//                pq.push(p);
//            else if(pq.size()==k&&p.second>pq.top().second){
//                pq.pop();
//                pq.push(p);
//            }
//        }
//        vector<int> res;
//        while(!pq.empty()){
//            res.emplace_back(pq.top().first);
//            pq.pop();
//        }
//        return res;
//    }
//};


class Solution {
private:
    using PIL=pair<int,int>;
//    void findK(vector<PIL>& nums, int l, int r, int k){
//        while(l<r){
//            swap(nums[l],nums[rand()%(r-l+1)+l]);
//            int v=nums[l].second;
//            int i=l,j=r+1;
//            while(true){
//                while(i+1<=r&&nums[++i].second>v);
//                while(j-1>=l&&nums[--j].second<v);
//                if(i>=j)
//                    break;
//                swap(nums[i],nums[j]);
//            }
//            swap(nums[l],nums[j]);
//            if(j+1==k)
//                return;
//            else if(j+1>k)
//                r=j-1;
//            else
//                l=j+1;
//        }
//        return;
//    }
    void findK(vector<PIL>& nums, int l, int r, int k){
        while(l<r){
            swap(nums[l],nums[rand()%(r-l+1)+l]);
            int v=nums[l].second;
            auto iter=partition(nums.begin()+l,nums.begin()+r+1,[&](const PIL& p){
               return p.second>v;
            });
            int j=iter-nums.begin();
            if(j==k)
                return;
            else if(j>k)
                r=j-1;
            else if(j==l)
                l=j+1;
            else
                l=j;
        }
        return;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        srand(time(NULL));
        unordered_map<int,int> mp;
        for(int num:nums)
            mp[num]++;
        vector<PIL> arr;
        for(auto& p:mp)
            arr.push_back(p);
        findK(arr,0,arr.size()-1,k);
        vector<int> res;
        for(int i=0;i<k;i++)
            res.emplace_back(arr[i].first);
        return res;
    }
};



int main(int argc, char *argv[]){


    vector<int> nums{2,2,3,3,3,3,4,1,5,5,1,1,1};
    int k=2;
    utils::printVec(Solution().topKFrequent(nums,k));

    nums={2,3,4,1,4,0,4,-1,-2,-1};
    k=2;
    utils::printVec(Solution().topKFrequent(nums,k));

    nums={1,2};
    k=2;
    utils::printVec(Solution().topKFrequent(nums,k));

    nums={1,1,1,2,2,2,3,3,3};
    k=3;
    utils::printVec(Solution().topKFrequent(nums,k));

    nums={5,-3,9,1,7,7,9,10,2,2,10,10,3,-1,3,7,-9,-1,3,3};
    k=3;
    utils::printVec(Solution().topKFrequent(nums,k));

    nums={3,2,4,5,1,2,3,4,3,4,5,7,1,2};
    nums={2,2,2,2,2,2};
    auto iter=partition(nums.begin(),nums.begin()+nums.size(),bind2nd(greater<int>(),2));
    utils::printVec(nums);
    cout<<iter-nums.begin()<<endl;

    return 0;
}
