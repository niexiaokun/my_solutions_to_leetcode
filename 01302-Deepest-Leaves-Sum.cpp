#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        int res = 0;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            res = 0;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *cur = q.front();
                q.pop();
                res += cur->val;
                if (cur->left)
                    q.emplace(cur->left);
                if (cur->right)
                    q.emplace(cur->right);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
