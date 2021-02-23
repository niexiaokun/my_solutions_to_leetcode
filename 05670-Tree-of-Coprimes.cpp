#include <bits/stdc++.h>

using namespace std;

//5670. 互质树
//
//        给你一个 n 个节点的树（也就是一个无环连通无向图），节点编号从 0 到 n - 1 ，且恰好有 n - 1 条边，每个节点有一个值。树的 根节点 为 0 号点。
//
//给你一个整数数组 nums 和一个二维数组 edges 来表示这棵树。nums[i] 表示第 i 个点的值，edges[j] = [uj, vj] 表示节点 uj 和节点 vj 在树中有一条边。
//
//当 gcd(x, y) == 1 ，我们称两个数 x 和 y 是 互质的 ，其中 gcd(x, y) 是 x 和 y 的 最大公约数 。
//
//从节点 i 到 根 最短路径上的点都是节点 i 的祖先节点。一个节点 不是 它自己的祖先节点。
//
//请你返回一个大小为 n 的数组 ans ，其中 ans[i]是离节点 i 最近的祖先节点且满足 nums[i] 和 nums[ans[i]] 是 互质的 ，如果不存在这样的祖先节点，ans[i] 为 -1 。
//
//
//
//示例 1：
//
//输入：nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
//输出：[-1,0,0,1]
//解释：上图中，每个节点的值在括号中表示。
//- 节点 0 没有互质祖先。
//- 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
//- 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0 的值是互质的(gcd(2,3) == 1)，所以节点 0 是最近的符合要求的祖先节点。
//- 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1 是离它最近的符合要求的祖先节点。
//
//示例 2：
//
//输入：nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
//输出：[-1,0,-1,0,0,0,-1]
//
//提示：
//
//nums.length == n
//1 <= nums[i] <= 50
//1 <= n <= 105
//edges.length == n - 1
//edges[j].length == 2
//0 <= uj, vj < n
//        uj != vj


//class Solution {
//private:
//    vector<int> res;
//    vector<vector<pair<int, int>>> record;
//
//    void dfs(const vector<vector<int>> &g, const vector<int> &nums, int x, int pre, int d) {
//        record[nums[x]].emplace_back(x, d);
//        for (int y:g[x]) {
//            if (y != pre) {
//                int a = INT_MIN;
//                for (int z=1;z<=50;++z) {
//                    if(__gcd(z,nums[y])==1) {
//                        if (!record[z].empty()) {
//                            auto[p, q]=record[z].back();
//                            if (q > a) {
//                                a = q;
//                                res[y] = p;
//                            }
//                        }
//                    }
//                }
//                dfs(g, nums, y, x, d + 1);
//            }
//        }
//        record[nums[x]].pop_back();
//    }
//
//public:
//    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
//        int n = nums.size();
//        vector<vector<int>> g(n);
//        for (const vector<int> &v:edges) {
//            g[v[0]].emplace_back(v[1]);
//            g[v[1]].emplace_back(v[0]);
//        }
//        record.resize(51);
//        res.resize(n, -1);
//        dfs(g, nums, 0, 0, 0);
//        return res;
//    }
//};


class Solution {
private:
    vector<int> res;
    vector<vector<int>> tmp;
    vector<vector<pair<int, int>>> record;

    void dfs(const vector<vector<int>> &g, const vector<int> &nums, int x, int pre, int d) {
        record[nums[x]].emplace_back(x, d);
        for (int y:g[x]) {
            if (y != pre) {
                int a = INT_MIN;
                for (int z:tmp[nums[y]]) {
                    if (!record[z].empty()) {
                        auto[p, q]=record[z].back();
                        if (q > a) {
                            a = q;
                            res[y] = p;
                        }
                    }
                }
                dfs(g, nums, y, x, d + 1);
            }
        }
        record[nums[x]].pop_back();
    }

public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (const vector<int> &v:edges) {
            g[v[0]].emplace_back(v[1]);
            g[v[1]].emplace_back(v[0]);
        }
        tmp.resize(51);
        record.resize(51);
        tmp[1].emplace_back(1);     //1和其他任何数都构成互质
        for (int i = 1; i <= 50; ++i) {
            for (int j = i + 1; j <= 50; ++j) {
                if (__gcd(i, j) == 1) {
                    tmp[i].emplace_back(j);
                    tmp[j].emplace_back(i);
                }
            }
        }
        res.resize(n, -1);
        dfs(g, nums, 0, 0, 0);
        return res;
    }
};


int main(int argc, char* argv[]) {

    vector<int> nums = {2, 3, 3, 2};
    vector<vector<int>> edges = {{0, 1},
                                 {1, 2},
                                 {1, 3}};
    Solution().getCoprimes(nums, edges);

    nums = {5, 6, 10, 2, 3, 6, 15};
    edges = {{0, 1},
             {0, 2},
             {1, 3},
             {1, 4},
             {2, 5},
             {2, 6}};
    Solution().getCoprimes(nums, edges);

    return 0;
}

