#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
//    bool checkSubPath(ListNode *head, TreeNode *root) {
//        if (head == NULL)
//            return true;
//        if (root == NULL)
//            return false;
//        return head->val == root->val &&
//               (checkSubPath(head->next, root->left) || checkSubPath(head->next, root->right));
//    }
//
//    void dfs(TreeNode *root, vector<TreeNode *> &nodeLists) {
//        if (root == NULL)
//            return;
//        dfs(root->left, nodeLists);
//        dfs(root->right, nodeLists);
//        nodeLists.emplace_back(root);
//    }
//
//public:
//    bool isSubPath(ListNode *head, TreeNode *root) {
//        vector<TreeNode *> subTreeList;
//        dfs(root, subTreeList);
//        for (TreeNode *node:subTreeList) {
//            if (checkSubPath(head, node))
//                return true;
//        }
//        return false;
//    }
//};

class Solution {
private:
    bool checkSubPath(ListNode *head, TreeNode *root) {
        if (head == NULL)
            return true;
        if (root == NULL)
            return false;
        return head->val == root->val &&
               (checkSubPath(head->next, root->left) || checkSubPath(head->next, root->right));
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root) {
        if (root == NULL)
            return false;
        return checkSubPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

int main(int argc, char* argv[]){

    return 0;
}
