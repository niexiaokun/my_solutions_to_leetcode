#include <bits/stdc++.h>

using namespace std;


//class Solution {
//private:
//    bool dfs(const vector<vector<int>> &graph, vector<int> &vis, int x, int color) {
//        vis[x] = color;
//        for (const int y:graph[x]) {
//            if (!vis[y]) {
//                if (!dfs(graph, vis, y, 3 - color))
//                    return false;
//            } else if (vis[y] == color)
//                return false;
//        }
//        return true;
//    }
//
//public:
//    bool isBipartite(vector<vector<int>> &graph) {
//        int n = graph.size();
//        vector<int> vis(n);
//        for(int i=0;i<n;++i){
//            if(!vis[i]){
//                if(!dfs(graph, vis, i, 1))
//                    return false;
//            }
//        }
//        return true;
//    }
//};

class Solution {
private:
    bool bfs(const vector<vector<int>> &g, vector<int> &vis, int x) {
        queue<int> q;
        q.emplace(x);
        vis[x] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const int y:g[u]) {
                if (!vis[y]) {
                    vis[y] = 3 - vis[u];
                    q.emplace(y);
                } else if (vis[u] == vis[y])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> vis(n);
        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                if (!bfs(graph, vis, i))
                    return false;
            }
        }
        return true;
    }
};


int main(int argc, char* argv[]){


    return 0;
}

