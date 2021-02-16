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
private:
    TreeNode *dfs(const string &s, int l, int r) {
        if (l > r)
            return NULL;
        int v = 0;
        int a = 1;
        int i = l;
        if (s[i] == '-') {
            a = -1;
            ++i;
        }
        while (i <= r && s[i] != '(') {
            v = v * 10 + s[i] - '0';
            ++i;
        }
        v = a * v;
        TreeNode *root = new TreeNode(v);
        if (i == r + 1)
            return root;
        int cnt = 1;
        int j = i + 1;
        while (j <= r) {
            if (s[j] == '(')
                ++cnt;
            else if (s[j] == ')')
                --cnt;
            if (cnt == 0)
                break;
            ++j;
        }
        root->left = dfs(s, i + 1, j - 1);
        root->right = dfs(s, j + 2, r - 1);
        return root;
    }

public:
    TreeNode *str2tree(string s) {
        int n = s.size();
        return dfs(s, 0, n - 1);
    }
};

int main(int argc, char* argv[]) {

    string s="4(2(3)(1))(6(5))";
    Solution().str2tree(s);

    s="4(2(3)(1))(6(5)(7))";
    Solution().str2tree(s);

    s="-4(2(3)(1))(6(5)(7))";
    Solution().str2tree(s);

    s="";
    Solution().str2tree(s);

    return 0;
}

