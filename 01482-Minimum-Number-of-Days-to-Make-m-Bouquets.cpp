#include <bits/stdc++.h>
#include <semaphore.h>
#include <thread>

using namespace std;


class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long x = (long long)m * k;
        if(x > (long long)n)
            return -1;
        int lo = 1, hi = 1e9;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            int cnt = 0;
            int p1 = 0;
            int i = 0;
            while(i < n){
                while(i < n && bloomDay[i] <= mid)
                    ++i;
                cnt += (i - p1) / k;
                while(i < n && bloomDay[i] > mid)
                    ++i;
                p1 = i;
            }
            cnt += (i - p1) / k;
            if(cnt >= m)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};



int main(int argc, char* argv[]){


    return 0;
}