#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dfs(const vector<vector<int>>& g, const vector<int>& quiet, int x, vector<int>& res){
        if(res[x] != -1)
            return res[x];
        int tx = x;
        for(const int y:g[x]){
            int z = dfs(g, quiet, y, res);
            if(quiet[z] < quiet[tx]){
                tx = z;
            }
        }
        res[x] = tx;
        return tx;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> g(n);
        for(const vector<int>& v:richer){
            g[v[1]].emplace_back(v[0]);
        }
        vector<int> res(n, -1);
        for(int i=0; i < n; ++i){
            dfs(g, quiet, i, res);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {


    return 0;
}

