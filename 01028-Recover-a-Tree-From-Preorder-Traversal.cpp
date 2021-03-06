#include <bits/stdc++.h>

using namespace std;

//1028. 从先序遍历还原二叉树
//
//        我们从二叉树的根节点 root 开始进行深度优先搜索。
//
//在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。
//
//如果节点只有一个子节点，那么保证该子节点为左子节点。
//
//给出遍历输出 S，还原树并返回其根节点 root。
//
//
//
//示例 1：
//
//输入："1-2--3--4-5--6--7"
//输出：[1,2,5,3,4,6,7]
//
//示例 2：
//
//输入："1-2--3---4-5--6---7"
//输出：[1,2,5,3,null,6,null,4,null,7]
//
//示例 3：
//
//输入："1-401--349---90--88"
//输出：[1,401,null,349,88,90]
//
//
//
//提示：
//
//原始树中的节点数介于 1 和 1000 之间。
//每个节点的值介于 1 和 10 ^ 9 之间。


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
    TreeNode *buildTree(string &s, int l, int r, int k) {
        if (l > r)
            return nullptr;
        int i = l;
        int num = 0;
        while (i <= r && s[i] != '-') {
            num = num * 10 + s[i] - '0';
            ++i;
        }
        TreeNode *root = new TreeNode(num);
        if (i > r)
            return root;
        while (i <= r && s[i] == '-')
            ++i;
        int j = i;
        int cnt = 0;
        while (i <= r) {
            while (i <= r && s[i] == '-') {
                ++cnt;
                ++i;
            }
            if (cnt == k)
                break;
            cnt = 0;
            ++i;
        }
        if (i > r) {
            root->left = buildTree(s, j, r, k + 1);
            return root;
        }
        root->left = buildTree(s, j, i - cnt - 1, k + 1);
        root->right = buildTree(s, i, r, k + 1);
        return root;
    }

public:
    TreeNode *recoverFromPreorder(string s) {
        int n = s.size();
        if (n == 0)
            return nullptr;
        return buildTree(s, 0, n - 1, 1);
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

