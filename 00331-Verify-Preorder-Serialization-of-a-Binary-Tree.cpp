#include <bits/stdc++.h>

using namespace std;


//331. 验证二叉树的前序序列化
//
//        序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
//
//      _9_
//     /    \
//    3      2
//   / \    / \
//  4    1 #   6
// / \  / \   / \
//#  # #   # #   #
//
//例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。
//
//给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。
//
//每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。
//
//你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。
//
//示例 1:
//
//输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
//输出: true
//
//示例 2:
//
//输入: "1,#"
//输出: false
//
//示例 3:
//
//输入: "9,#,#,1"
//输出: false



class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if (n == 0)
            return false;
        if (preorder[0] == '#')
            return n == 1;
        vector<pair<int, int>> stk;
        int num = 0;
        int i = 0;
        while (i < n) {
            if (preorder[i] == '#' || preorder[i] == ',')
                break;
            num = num * 10 + (preorder[i] - '0');
            ++i;
        }
        stk.emplace_back(num, 2);
        char c = '#';
        while (!stk.empty() && i < n) {
            if (preorder[i] >= '0' && preorder[i] <= '9') {
                if (!stk.empty())
                    num = num * 10 + (preorder[i] - '0');
            } else if (preorder[i] == ',') {
                if (c != '#') {
                    stk.emplace_back(num, 2);
                }
                num = 0;
            } else {
                --stk.rbegin()->second;
                while (stk.rbegin()->second == 0) {
                    stk.pop_back();
                    if (!stk.empty())
                        --stk.rbegin()->second;
                    else
                        break;
                }
            }
            c = preorder[i];
            ++i;
        }
        return stk.empty() && i == n;
    }
};



int main(int argc, char *argv[]){

    return 0;
}

