#include <bits/stdc++.h>

using namespace std;

//剑指 Offer 32 - III. 从上到下打印二叉树 III
//
//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
//
//
//
//例如:
//给定二叉树: [3,9,20,null,null,15,7],
//
//3
/// \
//  9  20
///  \
//   15   7
//
//返回其层次遍历结果：
//
//[
//[3],
//[20,9],
//[15,7]
//]
//
//
//
//提示：
//
//节点总数 <= 1000


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        int a = 1;
        deque<TreeNode *> dq;
        dq.emplace_back(root);
        while (!dq.empty()) {
            int sz = dq.size();
            vector<int> tmp;
            if (a) {
                for (int i = 0; i < sz; ++i) {
                    TreeNode *cur = dq.front();
                    dq.pop_front();
                    if (cur->left)
                        dq.emplace_back(cur->left);
                    if (cur->right)
                        dq.emplace_back(cur->right);
                    tmp.emplace_back(cur->val);
                }
            } else {
                for (int i = 0; i < sz; ++i) {
                    TreeNode *cur = dq.back();
                    dq.pop_back();
                    if (cur->right)
                        dq.emplace_front(cur->right);
                    if (cur->left)
                        dq.emplace_front(cur->left);
                    tmp.emplace_back(cur->val);
                }
            }
            res.push_back(tmp);
            a = 1 - a;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

