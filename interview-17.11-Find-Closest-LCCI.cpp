#include <bits/stdc++.h>

using namespace std;

//面试题 17.11. 单词距离
//
//        有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?
//
//示例：
//
//输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
//输出：1
//
//提示：
//
//words.length <= 100000


class Solution {
public:
    int findClosest(vector<string> &words, string word1, string word2) {
        int n = words.size();
        vector<int> v1, v2;
        for (int i = 0; i < n; ++i) {
            if (words[i] == word1)
                v1.emplace_back(i);
            else if (words[i] == word2)
                v2.emplace_back(i);
        }
        int i = 0, j = 0;
        int res = words.size();
        while (i < v1.size() && j < v2.size()) {
            res = min(res, abs(v1[i] - v2[j]));
            if (v1[i] < v2[j])
                ++i;
            else
                ++j;
        }
        return res;
    }
};


int main(int argc, char* argv[]) {


    return 0;
}

