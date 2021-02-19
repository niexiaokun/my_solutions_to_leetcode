#include <bits/stdc++.h>

using namespace std;

//面试题 04.03. 特定深度节点链表
//
//        给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。
//
//
//
//示例：
//
//输入：[1,2,3,4,5,null,7,8]
//
//         1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//   /
//  8
//
//输出：[[1],[2,3],[4,5,7],[8]]


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        vector<ListNode *> res;
        if (tree == NULL)
            return res;
        queue<TreeNode *> q;
        q.emplace(tree);
        while (!q.empty()) {
            int sz = q.size();
            TreeNode *cur = q.front();
            q.pop();
            ListNode *head = new ListNode(cur->val);
            ListNode *p = head;
            if (cur->left)
                q.emplace(cur->left);
            if (cur->right)
                q.emplace(cur->right);
            for (int i = 1; i < sz; ++i) {
                cur = q.front();
                q.pop();
                p->next = new ListNode(cur->val);
                p = p->next;
                if (cur->left)
                    q.emplace(cur->left);
                if (cur->right)
                    q.emplace(cur->right);
            }
            res.emplace_back(head);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

