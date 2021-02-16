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
//    bool res;
//
//    int check(TreeNode *root) {
//        if (root == nullptr)
//            return 0;
//        int l = check(root->left);
//        int r = check(root->right);
//        if (abs(l - r) > 1)
//            res = false;
//        return max(l, r) + 1;
//    }
//
//public:
//    bool isBalanced(TreeNode *root) {
//        res = true;
//        check(root);
//        return res;
//    }
//};

class Solution {
private:
    bool check(TreeNode *root, int &h) {
        if (root == nullptr) {
            h = 0;
            return true;
        }
        int l, r;
        if (!check(root->left, l) || !check(root->right, r))
            return false;
        if (abs(l - r) > 1)
            return false;
        h = max(l, r) + 1;
        return true;
    }

public:
    bool isBalanced(TreeNode *root) {
        int h = 0;
        return check(root, h);
    }
};


int main(int argc, char* argv[]) {



    return 0;
}

