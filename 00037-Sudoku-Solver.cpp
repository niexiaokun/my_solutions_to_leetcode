#include <iostream>
#include <vector>
#include <memory>
#include <cstring>

using namespace std;

class Solution {
private:
    bool rows[9][9];
    bool cols[9][9];
    bool blks[3][3][9];
    bool isValid;
    vector<tuple<int,int>> spaces;
    void dfs(vector<vector<char>>& board,int pos){
        if(pos==spaces.size()){
            isValid=true;
            return;
        }

        int r,c;
        tie(r,c)=spaces[pos];
        for(int i=1;i<=9&&!isValid;i++){
            if(!rows[r][i-1]&&!cols[c][i-1]&&!blks[r/3][c/3][i-1]){
                rows[r][i-1]=cols[c][i-1]=blks[r/3][c/3][i-1]=true;
                board[r][c]=i+'0';
                dfs(board,pos+1);
                rows[r][i-1]=cols[c][i-1]=blks[r/3][c/3][i-1]=false;
            }
        }
        return;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows,false,sizeof(rows));
        memset(cols,false,sizeof(cols));
        memset(blks,false,sizeof(blks));
        isValid=false;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c!='.'){
                    rows[i][c-'0'-1]=cols[j][c-'0'-1]=blks[i/3][j/3][c-'0'-1]=true;
                }
                else
                    spaces.emplace_back(make_tuple(i,j));
            }
        }
        dfs(board,0);
        return;
    }
};

int main(int argc, char* argv[]){

    vector<vector<char>> board({
                                       {'5', '3', '.', '.', '7', '.', '.', '.', '.',},
                                       { '6', '.', '.', '1', '9', '5', '.', '.', '.', },
                                       { '.', '9', '8', '.', '.', '.', '.', '6', '.', },
                                       { '8', '.', '.', '.', '6', '.', '.', '.', '3', },
                                       { '4', '.', '.', '8', '.', '3', '.', '.', '1', },
                                       { '7', '.', '.', '.', '2', '.', '.', '.', '6', },
                                       { '.', '6', '.', '.', '.', '.', '2', '8', '.', },
                                       { '.', '.', '.', '4', '1', '9', '.', '.', '5', },
                                       { '.', '.', '.', '.', '8', '.', '.', '7', '9', },
                               });
    Solution().solveSudoku(board);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}