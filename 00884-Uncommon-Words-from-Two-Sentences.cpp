#include <bits/stdc++.h>

using namespace std;


//884. 两句话中的不常见单词
//
//        给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//
//返回所有不常用单词的列表。
//
//您可以按任何顺序返回列表。
//
//
//
//示例 1：
//
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet","sour"]
//
//示例 2：
//
//输入：A = "apple apple", B = "banana"
//输出：["banana"]
//
//
//
//提示：
//
//0 <= A.length <= 200
//0 <= B.length <= 200
//A 和 B 都只包含空格和小写字母。



//class Solution {
//public:
//    vector<string> uncommonFromSentences(string A, string B) {
//        unordered_map<string, int> f1, f2;
//        int j = 0;
//        for (int i = 0; i < A.size(); ++i) {
//            if (A[i] == ' ') {
//                ++f1[A.substr(j, i - j)];
//                j = i + 1;
//            }
//        }
//        ++f1[A.substr(j)];
//        j = 0;
//        for (int i = 0; i < B.size(); ++i) {
//            if (B[i] == ' ') {
//                ++f2[B.substr(j, i - j)];
//                j = i + 1;
//            }
//        }
//        ++f2[B.substr(j)];
//        vector<string> res;
//        for (const auto &p:f1) {
//            if (p.second == 1 && !f2.count(p.first))
//                res.emplace_back(p.first);
//        }
//        for (const auto &p:f2) {
//            if (p.second == 1 && !f1.count(p.first))
//                res.emplace_back(p.first);
//        }
//        return res;
//    }
//};

//class Solution {
//private:
//    struct Node{
//        int cnt = 0;
//        unordered_map<char, Node*> next;
//    };
//    void addWord(Node* root, const string& s){
//        Node* cur = root;
//        for(int i=0;i<s.size();++i){
//            if(!cur->next.count(s[i]))
//                cur->next[s[i]]=new Node;
//            cur = cur->next[s[i]];
//        }
//        ++cur->cnt;
//    }
//    int findWord(Node* root, const string& s){
//        Node* cur = root;
//        for(int i=0;i<s.size();++i){
//            if(!cur->next.count(s[i]))
//                return 0;
//            cur = cur->next[s[i]];
//        }
//        return cur->cnt;
//    }
//public:
//    vector<string> uncommonFromSentences(string A, string B) {
//        Node* rootA = new Node;
//        Node* rootB = new Node;
//        int j=0;
//        for(int i=0;i<A.size();++i){
//            if(A[i]==' '){
//                addWord(rootA, A.substr(j,i-j));
//                j=i+1;
//            }
//        }
//        addWord(rootA, A.substr(j));
//        j=0;
//        for(int i=0;i<B.size();++i){
//            if(B[i]==' '){
//                addWord(rootB, B.substr(j,i-j));
//                j=i+1;
//            }
//        }
//        addWord(rootB, B.substr(j));
//        j=0;
//        string t;
//        vector<string> res;
//        for(int i=0;i<A.size();++i){
//            if(A[i]==' '){
//                t=A.substr(j,i-j);
//                if(findWord(rootA,t)==1&&findWord(rootB,t)==0)
//                    res.emplace_back(t);
//                j=i+1;
//            }
//        }
//        t=A.substr(j);
//        if(findWord(rootA,t)==1&&findWord(rootB,t)==0)
//            res.emplace_back(t);
//        j=0;
//        for(int i=0;i<B.size();++i){
//            if(B[i]==' '){
//                t=B.substr(j,i-j);
//                if(findWord(rootB,t)==1&&findWord(rootA,t)==0)
//                    res.emplace_back(t);
//                j=i+1;
//            }
//        }
//        t=B.substr(j);
//        if(findWord(rootB,t)==1&&findWord(rootA,t)==0)
//            res.emplace_back(t);
//        return res;
//    }
//};

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> f;
        int j=0;
        for(int i=0;i<A.size();++i){
            if(A[i]==' '){
                ++f[A.substr(j,i-j)];
                j=i+1;
            }
        }
        ++f[A.substr(j)];
        j=0;
        for(int i=0;i<B.size();++i){
            if(B[i]==' '){
                ++f[B.substr(j,i-j)];
                j=i+1;
            }
        }
        ++f[B.substr(j)];
        vector<string> res;
        for(const auto& p: f){
            if(p.second==1)
                res.emplace_back(p.first);
        }
        return res;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
