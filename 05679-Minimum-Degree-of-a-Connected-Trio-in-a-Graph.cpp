#include <bits/stdc++.h>

using namespace std;

//5679. 一个图中连通三元组的最小度数
//
//        给你一个无向图，整数 n 表示图中节点的数目，edges 数组表示图中的边，其中 edges[i] = [ui, vi] ，表示 ui 和 vi 之间有一条无向边。
//
//一个 连通三元组 指的是 三个 节点组成的集合且这三个点之间 两两 有边。
//
//连通三元组的度数 是所有满足此条件的边的数目：一个顶点在三元组内，而另一个顶点不在三元组内。
//
//请你返回所有连通三元组中度数的 最小值 ，如果图中没有连通三元组，那么返回 -1 。
//
//
//
//示例 1：
//
//输入：n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
//输出：3
//解释：只有一个三元组 [1,2,3] 。构成度数的边在上图中已被加粗。
//
//示例 2：
//
//输入：n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
//输出：0
//解释：有 3 个三元组：
//1) [1,4,3]，度数为 0 。
//2) [2,5,6]，度数为 2 。
//3) [5,6,7]，度数为 2 。
//
//
//
//提示：
//
//2 <= n <= 400
//edges[i].length == 2
//1 <= edges.length <= n * (n-1) / 2
//1 <= ui, vi <= n
//        ui != vi
//        图中没有重复的边。


class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>> &edges) {
        vector<vector<bool>> g(n, vector<bool>(n, false));
        vector<int> deg(n);
        for (const vector<int> &v:edges) {
            int a = v[0] - 1, b = v[1] - 1;
            g[a][b] = g[b][a] = true;
            ++deg[a];
            ++deg[b];
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j]) {
                    for (int k = j + 1; k < n; ++k) {
                        if (g[i][k] && g[j][k]) {
                            res = min(res, deg[i] + deg[j] + deg[k] - 6);
                        }
                    }
                }
            }
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }
};


int main(int argc, char* argv[]) {

    vector<vector<int>> edges = {{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
    int n=6;
    cout<<Solution().minTrioDegree(n,edges)<<endl;

    edges={{5,2},{4,1},{4,2},{1,5}};
    n=5;
    cout<<Solution().minTrioDegree(n,edges)<<endl;
    
    n=6;
    edges={{6,5},{4,3},{5,1},{1,4},{2,3},{4,5},{2,6},{1,3}};
    cout<<Solution().minTrioDegree(n,edges)<<endl;

    return 0;
}

