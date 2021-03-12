#include <bits/stdc++.h>

using namespace std;

//187. 重复的DNA序列
//
//        所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。
//
//编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
//
//
//
//示例 1：
//
//输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//输出：["AAAAACCCCC","CCCCCAAAAA"]
//
//示例 2：
//
//输入：s = "AAAAAAAAAAAAA"
//输出：["AAAAAAAAAA"]
//
//
//
//提示：
//
//0 <= s.length <= 105
//s[i] 为 'A'、'C'、'G' 或 'T'


//class Solution {
//private:
//    struct Node {
//        int val;
//        unordered_map<char, Node *> next;
//
//        Node() : val(0) {}
//    } *node;
//
//    void insert(const string &s) {
//        Node *root = node;
//        for (const char &c : s) {
//            if (root->next[c] == nullptr)
//                root->next[c] = new Node();
//            root = root->next[c];
//        }
//        ++root->val;
//    }
//
//    bool find(const string &s) {
//        Node *root = node;
//        for (const char &c : s) {
//            if (!root->next.count(c))
//                return false;
//            root = root->next[c];
//        }
//        return root->val == 1;
//    }
//
//public:
//    vector<string> findRepeatedDnaSequences(string s) {
//        int n = s.size();
//        vector<string> res;
//        if (n < 10)
//            return res;
//        node = new Node();
//        for (int i = 0; i + 10 <= n; ++i) {
//            string word = s.substr(i, 10);
//            if (find(word))
//                res.emplace_back(word);
//            insert(word);
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;
        if (n < 10)
            return res;
        unordered_map<string, int> f;
        for (int i = 0; i + 10 <= n; ++i) {
            string word = s.substr(i, 10);
            if (f.count(word) && f[word] == 1)
                res.emplace_back(word);
            ++f[word];
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

