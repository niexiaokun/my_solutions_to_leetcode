#include <bits/stdc++.h>

using namespace std;


//1267. 统计参与通信的服务器
//
//        这里有一幅服务器分布图，服务器的位置标识在 m * n 的整数矩阵网格 grid 中，1 表示单元格上有服务器，0 表示没有。
//
//如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。
//
//请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。
//
//
//
//示例 1：
//
//输入：grid = [[1,0],[0,1]]
//输出：0
//解释：没有一台服务器能与其他服务器进行通信。
//
//示例 2：
//
//输入：grid = [[1,0],[1,1]]
//输出：3
//解释：所有这些服务器都至少可以与一台别的服务器进行通信。
//
//示例 3：
//
//输入：grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
//输出：4
//解释：第一行的两台服务器互相通信，第三列的两台服务器互相通信，但右下角的服务器无法与其他服务器通信。
//
//
//
//提示：
//
//m == grid.length
//        n == grid[i].length
//1 <= m <= 250
//1 <= n <= 250
//grid[i][j] == 0 or 1



//class Solution {
//private:
//    vector<int> fa, sz;
//    int find(int x){
//        return x==fa[x]?x:find(fa[x]);
//    }
//    void unite(int x, int y){
//        x=find(x);
//        y=find(y);
//        if(x==y)
//            return;
//        if(x<y)
//            swap(x,y);
//        fa[y]=x;
//        sz[x]+=sz[y];
//    }
//public:
//    int countServers(vector<vector<int>>& grid) {
//        int m=grid.size();
//        int n=grid[0].size();
//        fa.resize(m*n);
//        sz.resize(m*n,1);
//        for(int i=0;i<m*n;++i){
//            fa[i]=i;
//        }
//        for(int i=0;i<m;++i){
//            for(int j=0;j<n;++j){
//                for(int k=j+1;k<n;++k){
//                    if(grid[i][j]==1&&grid[i][k]==1)
//                        unite(i*n+j,i*n+k);
//                }
//            }
//        }
//        for(int j=0;j<n;++j){
//            for(int i=0;i<m;++i){
//                for(int k=i+1;k<m;++k){
//                    if(grid[i][j]==1&&grid[k][j]==1)
//                        unite(i*n+j,k*n+j);
//                }
//            }
//        }
//        unordered_set<int> g;
//        for(int i=0;i<sz.size();++i){
//            int x=find(i);
//            if(sz[x]>1)
//            g.insert(x);
//        }
//        int res = 0;
//        for(int x:g){
//            res+=sz[x];
//        }
//        return res;
//    }
//};


class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vis[i][j] = true;
                    int cnt = 0;
                    for (int x = 0; x < m; ++x) {
                        if (x == i)
                            continue;
                        if (grid[x][j] == 1) {
                            ++cnt;
                            if (!vis[x][j]) {
                                vis[x][j] = true;
                                ++res;
                            }
                        }
                    }
                    for (int y = 0; y < n; ++y) {
                        if (y == j)
                            continue;
                        if (grid[i][y] == 1) {
                            ++cnt;
                            if (!vis[i][y]) {
                                vis[i][y] = true;
                                ++res;
                            }
                        }
                    }
                    if (cnt)
                        ++res;
                }
            }
        }
        return res;
    }
};


int main(int argc, char* argv[]){



    return 0;
}