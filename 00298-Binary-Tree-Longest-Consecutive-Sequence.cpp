#include <bits/stdc++.h>

using namespace std;

//298. 二叉树最长连续序列
//
//        给你一棵指定的二叉树，请你计算它最长连续序列路径的长度。
//
//该路径，可以是从某个初始结点到树中任意结点，通过「父 - 子」关系连接而产生的任意路径。
//
//这个最长连续的路径，必须从父结点到子结点，反过来是不可以的。
//
//示例 1：
//
//输入:
//
//      1
//       \
//        3
//       / \
//      2   4
//           \
//            5
//
//输出: 3
//
//解析: 当中，最长连续序列是 3-4-5，所以返回结果为 3
//
//示例 2：
//
//输入:
//
//     2
//      \
//       3
//      /
//     2
//    /
//   1
//
//输出: 2
//
//解析: 当中，最长连续序列是 2-3。注意，不是 3-2-1，所以返回 2。


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans{};

    int dfs(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int res = 1;
        if (root->left) {
            int l = dfs(root->left);
            if (root->val + 1 == root->left->val)
                res += l;
        }
        if (root->right) {
            int r = dfs(root->right);
            if (root->val + 1 == root->right->val)
                res = max(res, r + 1);
        }
        ans = max(ans, res);
        return res;
    }

public:
    int longestConsecutive(TreeNode *root) {
        dfs(root);
        return ans;
    }
};

int main(int argc, char *argv[]){

    return 0;
}

