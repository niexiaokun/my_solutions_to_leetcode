#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//    int findBottomLeftValue(TreeNode* root) {
//        queue<TreeNode*> q;
//        q.emplace(root);
//        int res;
//        while(!q.empty()){
//            int sz=q.size();
//            for(int i=0;i<sz;++i){
//                TreeNode* cur=q.front();
//                q.pop();
//                if(i==0)
//                    res=cur->val;
//                if(cur->left)
//                    q.emplace(cur->left);
//                if(cur->right)
//                    q.emplace(cur->right);
//            }
//        }
//        return res;
//    }
//};


class Solution {
private:
    int depth, res;

    void dfs(TreeNode *root, int x) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL && x > depth) {
            depth = x;
            res = root->val;
        }
        dfs(root->left, x + 1);
        dfs(root->right, x + 1);
    }

public:
    int findBottomLeftValue(TreeNode *root) {
        depth = 0;
        dfs(root, 1);
        return res;
    }
};

int main(int argc, char* argv[]){


    return 0;
}

