#include <bits/stdc++.h>

using namespace std;

//1740. 找到二叉树中的距离
//
//        给定一棵二叉树的根节点 root 以及两个整数 p 和 q ，返回该二叉树中值为 p 的结点与值为 q 的结点间的 距离 。
//
//两个结点间的 距离 就是从一个结点到另一个结点的路径上边的数目。
//
//
//
//示例 1：
//
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
//输出：3
//解释：在 5 和 0 之间有 3 条边：5-3-1-0
//
//示例 2：
//
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
//输出：2
//解释：在 5 和 7 之间有 2 条边：5-2-7
//
//示例 3：
//
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
//输出：0
//解释：一个结点与它本身之间的距离为 0
//
//
//
//提示：
//
//树中结点个数的范围在 [1, 104].
//0 <= Node.val <= 109
//树中所有结点的值都是唯一的.
//p 和q 是树中结点的值.


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
//    int findDistance(TreeNode *root, int p, int q) {
//        if (p == q)
//            return 0;
//        unordered_map<int, int> f;
//        f[root->val] = root->val;
//        queue<TreeNode *> que;
//        que.emplace(root);
//        int cnt = 0;
//        while (!que.empty()) {             //bfs找到到根节点的路径,然后去掉公共部分
//            TreeNode *cur = que.front();
//            que.pop();
//            if (cur->val == p || cur->val == q)
//                ++cnt;
//            if (cnt == 2)
//                break;
//            if (cur->left) {
//                f[cur->left->val] = cur->val;
//                que.emplace(cur->left);
//            }
//            if (cur->right) {
//                f[cur->right->val] = cur->val;
//                que.emplace(cur->right);
//            }
//        }
//        vector<int> v1, v2;
//        while (p != f[p]) {
//            v1.emplace_back(p);
//            p = f[p];
//        }
//        v1.emplace_back(p);
//        while (q != f[q]) {
//            v2.emplace_back(q);
//            q = f[q];
//        }
//        v2.emplace_back(q);
//        if (v1.size() > v2.size())
//            swap(v1, v2);
//        int m = v1.size();
//        int n = v2.size();
//        int i = m - 1, j = n - 1;
//        while (i >= 0 && j >= 0) {
//            if (v1[i] != v2[j])
//                break;
//            --i, --j;
//        }
//        if (i == -1)       //两种情况, 同侧和两侧
//            return j - i;
//        return m + j;
//    }
//};


class Solution {
private:
    TreeNode *lca(TreeNode *root, int p, int q) {  //先找到最近公共祖先
        if (root == NULL)
            return NULL;
        if (root->val == p || root->val == q)
            return root;
        TreeNode *left = lca(root->left, p, q);
        TreeNode *right = lca(root->right, p, q);
        if (left && right)
            return root;
        else if (left)
            return left;
        else
            return right;
    }

    bool dfs(TreeNode *root, int x, int &d) {  //找到最近公共祖先,进行dfs
        if (root == NULL)
            return false;
        if (root->val == x)
            return true;
        ++d;
        if (dfs(root->left, x, d))
            return true;
        if (dfs(root->right, x, d))
            return true;
        --d;
        return false;
    }

public:
    int findDistance(TreeNode *root, int p, int q) {
        if (p == q)
            return 0;
        TreeNode *node = lca(root, p, q);
        int dis1 = 0, dis2 = 0;
        dfs(node, p, dis1);
        dfs(node, q, dis2);
        return dis1 + dis2;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

