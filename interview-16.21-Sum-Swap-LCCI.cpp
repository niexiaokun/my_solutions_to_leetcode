#include <bits/stdc++.h>

using namespace std;

//面试题 16.21. 交换和
//
//        给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。
//
//返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。
//
//示例:
//
//输入: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
//输出: [1, 3]
//
//示例:
//
//输入: array1 = [1, 2, 3], array2 = [4, 5, 6]
//输出: []
//
//提示：
//
//1 <= array1.length, array2.length <= 100000


class Solution {
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2) {
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        int delta = accumulate(array1.begin(), array1.end(), 0) - accumulate(array2.begin(), array2.end(), 0);
        vector<int> res;
        if (delta & 1)
            return res;
        for (int x:array1) {
            int y = x - delta / 2;
            int index = lower_bound(array2.begin(), array2.end(), y) - array2.begin();
            if (index != array2.size() && array2[index] == y)
                return {x, x - delta / 2};
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

