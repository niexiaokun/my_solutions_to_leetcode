#include <bits/stdc++.h>

using namespace std;

//面试题 17.15. 最长单词
//
//        给定一组单词words，编写一个程序，找出其中的最长单词，且该单词由这组单词中的其他单词组合而成。若有多个长度相同的结果，返回其中字典序最小的一项，若没有符合要求的单词则返回空字符串。
//
//示例：
//
//输入： ["cat","banana","dog","nana","walk","walker","dogwalker"]
//输出： "dogwalker"
//解释： "dogwalker"可由"dog"和"walker"组成。
//
//提示：
//
//0 <= len(words) <= 200
//1 <= len(words[i]) <= 100


class Solution {
private:
    struct Node {
        bool isWord;
        unordered_map<char, Node *> next;

        Node() {
            isWord = false;
        }
    } *root;

    unordered_set<string> memo;  //不能用unordered_map记录true和false,字符串本身会被记录进去

    bool find(const string &word) {
        if (word.empty())
            return true;
        if (memo.count(word))
            return true;
        Node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->isWord && find(word.substr(i))) {  //递归调用的条件,发现isWord==true就开始调用
                memo.insert(word);
                return true;
            }
            if (cur->next.count(word[i]))
                cur = cur->next[word[i]];
            else {                     //这里直接return false
                return false;
            }
        }
        if (cur->isWord)
            memo.insert(word);
        return cur->isWord;
    }

    void insert(const string &word) {
        Node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!cur->next.count(word[i]))
                cur->next[word[i]] = new Node();
            cur = cur->next[word[i]];
        }
        cur->isWord = true;
    }

public:
    string longestWord(vector<string> &words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
            return s1.size() < s2.size();
        });
        root = new Node();
        string res;
        for (const string &s:words) {
            if (!find(s))
                insert(s);
            else if (s.size() > res.size() || (s.size() == res.size() && s < res))
                res = s;
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    vector<string> words={"pg","ptgt","tgpppttg","tptttgg","pgttggtpt","t","ptg","ppgp","g","ptgpptpgg"};
    cout<<Solution().longestWord(words)<<endl;

    return 0;
}

