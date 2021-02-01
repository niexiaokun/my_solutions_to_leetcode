#include <iostream>
#include <vector>


using namespace std;


//1066. 校园自行车分配 II
//
//在由 2D 网格表示的校园里有 n 位工人（worker）和 m 辆自行车（bike），n <= m。所有工人和自行车的位置都用网格上的 2D 坐标表示。
//
//我们为每一位工人分配一辆专属自行车，使每个工人与其分配到的自行车之间的曼哈顿距离最小化。
//
//p1 和 p2 之间的曼哈顿距离为 Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|。
//
//返回每个工人与分配到的自行车之间的曼哈顿距离的最小可能总和。
//
//
//
//示例 1：
//
//输入：workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
//输出：6
//解释：
//自行车 0 分配给工人 0，自行车 1 分配给工人 1 。分配得到的曼哈顿距离都是 3, 所以输出为 6 。
//
//示例 2：
//
//输入：workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
//输出：4
//解释：
//先将自行车 0 分配给工人 0，再将自行车 1 分配给工人 1（或工人 2），自行车 2 给工人 2（或工人 1）。如此分配使得曼哈顿距离的总和为 4。
//
//
//
//提示：
//
//0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
//所有工人和自行车的位置都不相同。
//1 <= workers.length <= bikes.length <= 10


//class Solution {
//private:
//    int res=INT32_MAX;
//    vector<bool> used;
//    void dfs(vector<vector<int>>& dis, int m, int n, int d, int index){  //暴力dfs超时
//        if(index==m){
//            res=min(res,d);
//            return;
//        }
//        for(int i=0;i<n;i++){
//            if(!used[i]){
//                if(d+dis[index][i]>res)
//                    continue;
//                used[i]=true;
//                d+=dis[index][i];
//                dfs(dis,m,n,d,index+1);
//                d-=dis[index][i];
//                used[i]=false;
//            }
//        }
//    }
//public:
//    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
//        int m=workers.size();
//        int n=bikes.size();
//        used=vector<bool>(m,false);
//        vector<vector<int>> dis(m,vector<int>(n));
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                dis[i][j]=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
//            }
//        }
//        dfs(dis,m,n,0,0);
//        return res;
//    }
//};


class Solution {
private:
    int m,n;
    vector<int> memo;
    int dfs(vector<vector<int>>& dis, int state, int index){
        if(index==m)
            return 0;
        if(memo[state])
            return memo[state];
        int res=INT32_MAX;
        for(int i=0;i<n;i++){
            int cur=(1<<i);
            if((cur&state)==0){
                int tmp=dis[index][i]+dfs(dis,state+cur,index+1);
                res=min(res,tmp);
            }
        }
        memo[state]=res;
        return res;
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        m=workers.size();
        n=bikes.size();
        memo=vector<int>(1<<n);
        vector<vector<int>> dis(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
            }
        }
        return dfs(dis,0,0);
    }
};


int main(int argc, char *argv[]){

    vector<vector<int>> workers{{0,0},{2,1}};
    vector<vector<int>> bikes{{1,2},{3,3}};
    cout<<Solution().assignBikes(workers,bikes)<<endl;

    workers={{0,0},{1,1},{2,0}};
    bikes={{1,0},{2,2},{2,1}};
    cout<<Solution().assignBikes(workers,bikes)<<endl;

    workers={{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}};
    bikes={{0,999},{1,999},{2,999},{3,999},{4,999},{5,999},{6,999},{7,999},{8,999},{9,999}};
    cout<<Solution().assignBikes(workers,bikes)<<endl;





    return 0;
}