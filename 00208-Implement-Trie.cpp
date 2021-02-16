#include <bits/stdc++.h>

using namespace std;

//class Trie {
//private:
//    bool isEnd;
//    unordered_map<char, Trie *> next;
//public:
//    /** Initialize your data structure here. */
//    Trie() : isEnd(false) {
//
//    }
//
//    /** Inserts a word into the trie. */
//    void insert(string word) {
//        Trie *root = this;
//        for (const char &c:word) {
//            if (!root->next.count(c))
//                root->next[c] = new Trie();
//            root = root->next[c];
//        }
//        root->isEnd = true;
//    }
//
//    /** Returns if the word is in the trie. */
//    bool search(string word) {
//        Trie *root = this;
//        for (const char &c:word) {
//            if (!root->next.count(c))
//                return false;
//            root = root->next[c];
//        }
//        return root->isEnd;
//    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string prefix) {
//        Trie *root = this;
//        for (const char &c:prefix) {
//            if (!root->next.count(c))
//                return false;
//            root = root->next[c];
//        }
//        return true;
//    }
//};

class Trie {
private:
    bool isEnd;
    Trie *next[26];
public:
    /** Initialize your data structure here. */
    Trie() : isEnd(false) {
        for (int i = 0; i < 26; ++i)
            next[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *root = this;
        for (const char &c:word) {
            int i = c - 'a';
            if (root->next[i] == nullptr)
                root->next[i] = new Trie();
            root = root->next[i];
        }
        root->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = this;
        for (const char &c:word) {
            int i = c - 'a';
            if (root->next[i] == nullptr)
                return false;
            root = root->next[i];
        }
        return root->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = this;
        for (const char &c:prefix) {
            int i = c - 'a';
            if (root->next[i] == nullptr)
                return false;
            root = root->next[i];
        }
        return true;
    }
};

int main(int argc, char* argv[]) {



    return 0;
}

