#include <bits/stdc++.h>

using namespace std;

//354. 俄罗斯套娃信封问题
//
//        给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
//
//请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
//
//说明:
//不允许旋转信封。
//
//示例:
//
//输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//输出: 3
//解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。


class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {  //最长上升子序列问题
        int n = envelopes.size();
        if (n == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &e1, const vector<int> &e2) -> bool {
            return e1[0] == e2[0] ? e1[1] > e2[1] : e1[0] < e2[0];
        });
        vector<int> dp = {envelopes[0][1]};
        int res = 1;
        for (int i = 1; i < n; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it != dp.end())
                *it = envelopes[i][1];
            else
                dp.emplace_back(envelopes[i][1]);
        }
        return dp.size();
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

