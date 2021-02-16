#include <bits/stdc++.h>

using namespace std;

//1042. 不邻接植花
//
//        有 n 个花园，按从 1 到 n 标记。另有数组 paths ，其中 paths[i] = [xi, yi] 描述了花园 xi 到花园 yi 的双向路径。在每个花园中，你打算种下四种花之一。
//
//另外，所有花园 最多 有 3 条路径可以进入或离开.
//
//你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
//
//以数组形式返回 任一 可行的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1、2、3、4 表示。保证存在答案。
//
//
//
//示例 1：
//
//输入：n = 3, paths = [[1,2],[2,3],[3,1]]
//输出：[1,2,3]
//解释：
//花园 1 和 2 花的种类不同。
//花园 2 和 3 花的种类不同。
//花园 3 和 1 花的种类不同。
//因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2] 和 [3,2,1]
//
//示例 2：
//
//输入：n = 4, paths = [[1,2],[3,4]]
//输出：[1,2,1,2]
//
//示例 3：
//
//输入：n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
//输出：[1,2,3,4]
//
//
//
//提示：
//
//1 <= n <= 104
//0 <= paths.length <= 2 * 104
//paths[i].length == 2
//1 <= xi, yi <= n
//        xi != yi
//        每个花园 最多 有 3 条路径可以进入或离开



class Solution {
private:
    vector<bool> vis;

    void dfs(const vector<vector<int>> &g, vector<vector<int>> &colors, int x, vector<int> &res) {
        vis[x] = true;
        int i = 0;
        for (; i < 4; ++i) {
            if (colors[x][i]) {
                res[x] = colors[x][i];
                colors[x][i] = 0;
                break;
            }
        }
        for (int y:g[x]) {
            if (!vis[y]) {
                colors[y][i] = 0;
            }
        }
        for (int y:g[x]) {
            if (!vis[y]) {
                dfs(g, colors, y, res);
            }
        }
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector<vector<int>> g(n);
        for (const vector<int> &v:paths) {
            g[v[0] - 1].emplace_back(v[1] - 1);
            g[v[1] - 1].emplace_back(v[0] - 1);
        }
        vector<vector<int>> colors(n, {1, 2, 3, 4});
        vis.resize(n, false);
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
            if (!vis[i]) {
                dfs(g, colors, i, res);
            }
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

