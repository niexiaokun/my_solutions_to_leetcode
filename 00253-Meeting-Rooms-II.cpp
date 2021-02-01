#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//253. 会议室 II
//
//给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，
// 为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。
//
//示例 1:
//
//输入: [[0, 30],[5, 10],[15, 20]]
//输出: 2
//
//示例 2:
//
//输入: [[7,10],[2,4]]
//输出: 1



class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& v1, vector<int>& v2){
            return v1[0]<v2[0];
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=pq.top())
                pq.pop();
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};

int main(int argc, char *argv[]){

    vector<vector<int>> intervals{{0, 30},{5, 10},{15, 20}};
    cout<<Solution().minMeetingRooms(intervals)<<endl;

    intervals={{7,10},{2,4}};
    cout<<Solution().minMeetingRooms(intervals)<<endl;

    intervals={{2,15},{36,45},{9,29},{16,23},{4,9}};
    cout<<Solution().minMeetingRooms(intervals)<<endl;

    return 0;
}