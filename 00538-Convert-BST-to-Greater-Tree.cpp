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
//private:
//    void dfs(TreeNode* root, vector<TreeNode*>& nodes){
//        if(root==NULL)
//            return;
//        dfs(root->right, nodes);
//        nodes.emplace_back(root);
//        dfs(root->left, nodes);
//    }
//public:
//    TreeNode* convertBST(TreeNode* root) {
//        vector<TreeNode*> nodes;
//        dfs(root, nodes);
//        for(int i=1;i<nodes.size();++i){
//            nodes[i]->val+=nodes[i-1]->val;
//        }
//        return root;
//    }
//};

class Solution {
private:
    int sum = 0;
public:
    TreeNode *convertBST(TreeNode *root) {
        if (root == NULL)
            return NULL;
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);
        return root;
    }
};

int main(int argc, char* argv[]) {



    return 0;
}

