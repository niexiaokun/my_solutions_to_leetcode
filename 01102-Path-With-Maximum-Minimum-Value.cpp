#include <bits/stdc++.h>

using namespace std;

//1102. 得分最高的路径
//
//        给你一个 R 行 C 列的整数矩阵 A。矩阵上的路径从 [0,0] 开始，在 [R-1,C-1] 结束。
//
//路径沿四个基本方向（上、下、左、右）展开，从一个已访问单元格移动到任一相邻的未访问单元格。
//
//路径的得分是该路径上的 最小 值。例如，路径 8 →  4 →  5 →  9 的值为 4 。
//
//找出所有路径中得分 最高 的那条路径，返回其 得分。
//
//
//
//示例 1：
//
//输入：[[5,4,5],[1,2,6],[7,4,6]]
//输出：4
//解释：
//得分最高的路径用黄色突出显示。
//
//示例 2：
//
//输入：[[2,2,1,2,2,2],[1,2,2,2,1,2]]
//输出：2
//
//示例 3：
//
//输入：[[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
//输出：3
//
//
//
//提示：
//
//1 <= R, C <= 100
//0 <= A[i][j] <= 10^9



//class Solution {
//private:
//    int m, n;
//    int d[4][2] = {{1,  0},
//                   {0,  1},
//                   {-1, 0},
//                   {0,  -1}};
//    vector<vector<bool>> vis;
//    unordered_map<int, unordered_map<int, int>> memo;
//
//    int dfs(const vector<vector<int>> &nums, int pos, int pre) {  //dfs加记忆化超时
//        int r = pos / n, c = pos % n;
//        if (r == m - 1 && c == n - 1)
//            return min(pre, nums[r][c]);
//        if (memo[pos].count(pre))
//            return memo[pos][pre];
//        vis[r][c] = true;
//        int res = INT_MIN;
//        for (int k = 0; k < 4; ++k) {
//            int rr = r + d[k][0];
//            int cc = c + d[k][1];
//            if (rr >= 0 && rr < m && cc >= 0 && cc < n && !vis[rr][cc]) {
//                res = max(res, dfs(nums, rr * n + cc, min(pre, nums[r][c])));
//            }
//        }
//        vis[r][c] = false;
//        memo[pos][pre] = res;
//        return res;
//    }
//
//public:
//    int maximumMinimumPath(vector<vector<int>> &nums) {
//        m = nums.size();
//        n = nums[0].size();
//        vis = vector<vector<bool>>(m, vector<bool>(n, false));
//        return dfs(nums, 0, INT_MAX);
//    }
//};

class Solution {
private:
    vector<int> fa, sz;
    void init_uf(int n){
        fa.resize(n);
        iota(fa.begin(),fa.end(),0);
        sz.resize(n,1);
    }
    int find(int x){
        return fa[x]==x?x:find(fa[x]);
    }
    void unite(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y)
            return;
        if(x<y)
            swap(x,y);
        fa[y]=x;
        sz[x]+=sz[y];
    }
    bool isConnected(int x, int y){
        return find(x)==find(y);
    }
public:
    int maximumMinimumPath(vector<vector<int>>& nums) {
        int m=nums.size();
        int n=nums[0].size();
        if(m==1&&n==1)
            return nums[0][0];
        init_uf(m*n);
        vector<pair<int,int>> pos;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                pos.emplace_back(i,j);
            }
        }
        sort(pos.begin(),pos.end(),[&](const pair<int,int>& a, const pair<int,int>& b){
            return nums[a.first][a.second]>nums[b.first][b.second];
        });
        int d[4][2] = {{1,  0},
                       {0,  1},
                       {-1, 0},
                       {0,  -1}};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<pos.size();++i){
            int a=pos[i].first;
            int b=pos[i].second;
            vis[a][b]=true;
            int p=a*n+b;
            int x=-1,y=-1,v=-1;
            for(int k=0;k<4;++k){
                int r=a+d[k][0], c=b+d[k][1];
                if(r>=0&&r<m&&c>=0&&c<n){
                    if(vis[r][c]&&nums[r][c]>=nums[a][b])
                        unite(p,r*n+c);
                    if(nums[r][c]>v){
                        x=r;
                        y=c;
                        v=nums[r][c];
                    }
                }
            }
            unite(p,x*n+y);
            vis[x][y]=true;
            if(isConnected(0,m*n-1))
                return nums[a][b];
        }
        return -1;
    }
};


int main(int argc, char* argv[]) {

    vector<vector<int>> nums={{5,4,5},{1,2,6},{7,4,6}};
    cout<<Solution().maximumMinimumPath(nums)<<endl;

    nums={{2,2,1,2,2,2},{1,2,2,2,1,2}};
    cout<<Solution().maximumMinimumPath(nums)<<endl;

    nums={{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}};
    cout<<Solution().maximumMinimumPath(nums)<<endl;

    return 0;
}

