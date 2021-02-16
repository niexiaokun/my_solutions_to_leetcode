#include <bits/stdc++.h>

using namespace std;

//765. 情侣牵手
//
//        N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交换座位。
//
//人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2, 2N-1)。
//
//这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。
//
//示例 1:
//
//输入: row = [0, 2, 1, 3]
//输出: 1
//解释: 我们只需要交换row[1]和row[2]的位置即可。
//
//示例 2:
//
//输入: row = [3, 2, 0, 1]
//输出: 0
//解释: 无需交换座位，所有的情侣都已经可以手牵手了。
//
//说明:
//
//len(row) 是偶数且数值在 [4, 60]范围内。
//可以保证row 是序列 0...len(row)-1 的一个全排列。


//class Solution {
//private:
//    int cc;
//    vector<int> fa, sz;
//
//    void init_uf(int n) {
//        fa.resize(n);
//        iota(fa.begin(), fa.end(), 0);
//        sz.resize(n, 1);
//        cc = n;
//    }
//
//    int find(int x) {
//        return x == fa[x] ? x : find(fa[x]);
//    }
//
//    void unite(int x, int y) {
//        x = find(x);
//        y = find(y);
//        if (x == y)
//            return;
//        if (x < y)
//            swap(x, y);
//        fa[y] = x;
//        sz[x] += sz[y];
//        --cc;
//    }
//
//public:
//    int minSwapsCouples(vector<int> &row) {
//        int n = row.size();
//        init_uf(n / 2);
//        for (int i = 0; i < n; i += 2) {
//            unite(row[i] / 2, row[i + 1] / 2);
//        }
//        unordered_map<int, int> f;
//        for (int i = 0; i < n / 2; ++i) {
//            ++f[find(i)];
//        }
//        int res = 0;
//        for (const auto &p:f)
//            res += p.second - 1;
//        return res;
//    }
//};

//class Solution {
//private:
//    int cnt;
//    vector<bool> vis;
//
//    void dfs(const vector<vector<int>> &g, int x) {
//        vis[x] = true;
//        ++cnt;
//        for (int y:g[x]) {
//            if (!vis[y]) {
//                dfs(g, y);
//            }
//        }
//    }
//
//public:
//    int minSwapsCouples(vector<int> &row) {
//        int n = row.size();
//        vector<vector<int>> g(n / 2);
//        for (int i = 0; i < n; i += 2) {
//            int a = row[i] / 2;
//            int b = row[i + 1] / 2;
//            if (a != b) {
//                g[a].emplace_back(b);
//                g[b].emplace_back(a);
//            }
//        }
//        vis.resize(n / 2, false);
//        int res = 0;
//        for (int i = 0; i < n / 2; ++i) {
//            cnt = 0;
//            if (!vis[i]) {
//                dfs(g, i);
//                res += cnt - 1;
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        vector<vector<int>> g(n / 2);
        for (int i = 0; i < n; i += 2) {
            int a = row[i] / 2;
            int b = row[i + 1] / 2;
            if (a != b) {
                g[a].emplace_back(b);
                g[b].emplace_back(a);
            }
        }
        int cnt = 0;
        int res = 0;
        queue<int> q;
        vector<bool> vis(n / 2, false);
        for (int i = 0; i < n / 2; ++i) {
            if (!vis[i]) {
                cnt = 0;
                q.emplace(i);
                vis[i] = true;
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    ++cnt;
                    for (int y:g[x]) {
                        if (!vis[y]) {
                            q.emplace(y);
                            vis[y] = true;
                        }
                    }
                }
                res += cnt - 1;
            }
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    vector<int> row(20);
    iota(row.begin(),row.end(),0);
    random_shuffle(row.begin(),row.end());
    cout<<Solution().minSwapsCouples(row)<<endl;

    return 0;
}

