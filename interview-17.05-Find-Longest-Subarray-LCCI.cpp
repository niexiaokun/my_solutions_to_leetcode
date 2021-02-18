#include <bits/stdc++.h>

using namespace std;

//面试题 17.05.  字母与数字
//
//        给定一个放有字符和数字的数组，找到最长的子数组，且包含的字符和数字的个数相同。
//
//返回该子数组，若存在多个最长子数组，返回左端点最小的。若不存在这样的数组，返回一个空数组。
//
//示例 1:
//
//输入: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
//
//输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
//
//示例 2:
//
//输入: ["A","A"]
//
//输出: []
//
//提示：
//
//array.length <= 100000


class Solution {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        int n = array.size();
        int res = 0;
        int index;
        int cnt = 0;
        unordered_map<int, int> f;
        f[0] = -1;
        for (int i = 0; i < n; ++i) {
            if (array[i][0] >= '0' && array[i][0] <= '9')
                ++cnt;
            else
                --cnt;
            if (!f.count(cnt))
                f[cnt] = i;
            else if (i - f[cnt] > res) {
                res = i - f[cnt];
                index = f[cnt] + 1;
            }
        }
        if (res == 0)
            return {};
        vector<string> retArr(array.begin() + index, array.begin() + index + res);
        return retArr;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

