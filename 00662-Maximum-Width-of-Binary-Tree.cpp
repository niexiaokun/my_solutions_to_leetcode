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

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);
        int res = 0;
        while (!q.empty()) {
            int x = -1, y = -1;
            for (int i = q.size(); i > 0; --i) {
                auto[cur, j]=q.front();
                q.pop();
                if (x == -1)
                    x = j;
                y = j;
                if (cur->left)
                    q.emplace(cur->left, (j - x) * 2 + 1);  //防止溢出 long long 也会溢出 如果测试用例很大
                if (cur->right)
                    q.emplace(cur->right, (j - x) * 2 + 2);
            }
            res = max(res, y - x + 1);
        }
        return res;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

