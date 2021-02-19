#include <bits/stdc++.h>

using namespace std;

//面试题 17.18. 最短超串
//
//        假设你有两个数组，一个长一个短，短的元素均不相同。找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。
//
//返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。若不存在，返回空数组。
//
//示例 1:
//
//输入:
//big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7]
//small = [1,5,9]
//输出: [7,10]
//
//示例 2:
//
//输入:
//big = [1,2,3]
//small = [4]
//输出: []
//
//提示：
//
//big.length <= 100000
//1 <= small.length <= 10000


//class Solution {
//public:
//    vector<int> shortestSeq(vector<int> &big, vector<int> &small) {
//        int n = big.size();
//        int lo = 0;
//        int hi = n;
//        unordered_map<int, int> smallMap;
//        for (int x:small)
//            ++smallMap[x];
//        int m = smallMap.size();
//        int index = -1;
//        int cnt = 0;
//        while (lo < hi) {
//            int mid = (lo + hi) / 2;
//            bool flag = false;
//            unordered_map<int, int> f;
//            cnt = 0;
//            for (int i = 0; i < mid; ++i) {
//                if (smallMap.count(big[i])) {
//                    ++f[big[i]];
//                    if (f[big[i]] == smallMap[big[i]])
//                        ++cnt;
//                }
//            }
//            if (cnt >= m) {
//                hi = mid;
//                index = 0;
//                continue;
//            }
//            for (int i = mid; i < n; ++i) {
//                if (smallMap.count(big[i - mid])) {
//                    if (f[big[i - mid]] == smallMap[big[i - mid]])
//                        --cnt;
//                    --f[big[i - mid]];
//                }
//                if (smallMap.count(big[i])) {
//                    ++f[big[i]];
//                    if (f[big[i]] == smallMap[big[i]])
//                        ++cnt;
//                }
//                if (cnt >= m) {
//                    flag = true;
//                    index = i - mid + 1;
//                    break;
//                }
//            }
//            if (flag)
//                hi = mid;
//            else
//                lo = mid + 1;
//        }
//        if (index == -1) {
//            unordered_map<int, int> f;
//            cnt = 0;
//            for (int x:big) {
//                ++f[x];
//                if (f[x] == smallMap[x])
//                    ++cnt;
//            }
//            if (cnt >= m)
//                return {0, n - 1};
//            return {};
//        }
//        return {index, index + lo - 1};
//    }
//};


class Solution {
public:
    vector<int> shortestSeq(vector<int> &big, vector<int> &small) {
        int n = big.size();
        unordered_map<int, int> smallMap;
        for (int x:small)
            ++smallMap[x];
        int m = smallMap.size();
        unordered_map<int, int> f;
        int cnt = 0;
        int i = 0;
        int len = INT_MAX;
        int index = -1;
        for (int j = 0; j < n; ++j) {
            if (smallMap.count(big[j])) {
                ++f[big[j]];
                if (f[big[j]] == smallMap[big[j]])
                    ++cnt;
            }
            while (cnt == m) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    index = i;
                }
                if (smallMap.count(big[i])) {
                    if (f[big[i]] == smallMap[big[i]])
                        --cnt;
                    --f[big[i]];
                }
                ++i;
            }
        }
        if (index == -1)
            return {};
        return {index, index + len - 1};
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

