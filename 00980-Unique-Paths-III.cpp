#include <bits/stdc++.h>

using namespace std;

//class Solution {
//private:
//    int x=0;
//    int m,n,r1,c1,count;
//    vector<vector<bool>> vis;
//    int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//    int dfs(const vector<vector<int>>& grid, int r, int c, int cnt){
//        ++x;
//        ++cnt;
//        if(r==r1&&c==c1) {
//            if(cnt==count)
//                return 1;
//            return 0;
//        }
//        vis[r][c]=true;
//        int res = 0;
//        for(int k=0;k<4;++k){
//            int rr=r+d[k][0], cc=c+d[k][1];
//            if(rr>=0&&rr<m&&cc>=0&&cc<n&&grid[rr][cc]==0&&!vis[rr][cc])
//                res += dfs(grid,rr,cc,cnt);
//        }
//        vis[r][c]=false;
//        return res;
//    }
//public:
//    int uniquePathsIII(vector<vector<int>>& grid) {
//        int r0=-1, c0=-1;
//        m=grid.size();
//        n=grid[0].size();
//        count=0;
//        for(int i=0;i<m;++i){
//            for(int j=0;j<n;++j){
//                if(grid[i][j]==-1)
//                    continue;
//                ++count;
//                if(grid[i][j]==1){
//                    r0=i,c0=j;
//                    grid[i][j]=0;
//                }else if(grid[i][j]==2){
//                    r1=i,c1=j;
//                    grid[i][j]=0;
//                }
//            }
//        }
//        vis.resize(m,vector<bool>(n,false));
//        return dfs(grid,r0,c0,0);
//    }
//};

class Solution {
private:
    int m,n,r1,c1,count;
    int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    unordered_map<int,unordered_map<int,int>> memo;
    int dfs(const vector<vector<int>>& grid, int pos, int state, int cnt){
        ++cnt;
        int r=pos/n, c=pos%n;
        if(r==r1&&c==c1) {
            if(cnt==count)
                return 1;
            return 0;
        }
        if(memo[pos].count(state))
            return memo[pos][state];
        state |= (1<<pos);
        int res = 0;
        for(int k=0;k<4;++k){
            int rr=r+d[k][0], cc=c+d[k][1];
            int nxt = rr*n+cc;
            if(rr>=0&&rr<m&&cc>=0&&cc<n&&grid[rr][cc]==0&&(state&(1<<nxt))==0)
                res += dfs(grid,nxt,state,cnt);
        }
        memo[pos][state]=res;
        return res;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r0=-1, c0=-1;
        m=grid.size();
        n=grid[0].size();
        count=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==-1)
                    continue;
                ++count;
                if(grid[i][j]==1){
                    r0=i,c0=j;
                    grid[i][j]=0;
                }else if(grid[i][j]==2){
                    r1=i,c1=j;
                    grid[i][j]=0;
                }
            }
        }
        int st=r0*n+c0;
        return dfs(grid,st,0,0);
    }
};


int main(int argc, char* argv[]) {

    vector<vector<int>> grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout<<Solution().uniquePathsIII(grid)<<endl;
    return 0;
}

