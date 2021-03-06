#include <bits/stdc++.h>

using namespace std;

//1008. 前序遍历构造二叉搜索树
//
//        返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
//
//(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right。）
//
//题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树。
//
//
//
//示例：
//
//输入：[8,5,1,7,10,12]
//输出：[8,5,10,1,7,null,12]
//
//
//
//提示：
//
//1 <= preorder.length <= 100
//1 <= preorder[i] <= 10^8
//preorder 中的值互不相同


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
    TreeNode *buildbst(vector<int> &preorder, int l, int r) {
        if (l > r)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[l]);
        if (l == r)
            return root;
        int i = l + 1;
        while (i <= r && preorder[i] < preorder[l])
            ++i;
        root->left = buildbst(preorder, l + 1, i - 1);
        if (i <= r)
            root->right = buildbst(preorder, i, r);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int n = preorder.size();
        if (n == 0)
            return nullptr;
        return buildbst(preorder, 0, n - 1);
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

