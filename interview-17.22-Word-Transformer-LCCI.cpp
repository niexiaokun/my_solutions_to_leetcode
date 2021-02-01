#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


//面试题 17.22. 单词转换
//
//给定字典中的两个词，长度相等。写一个方法，把一个词转换成另一个词， 但是一次只能改变一个字符。每一步得到的新词都必须能在字典中找到。
//
//编写一个程序，返回一个可能的转换序列。如有多个可能的转换序列，你可以返回任何一个。
//
//示例 1:
//
//输入:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//
//输出:
//["hit","hot","dot","lot","log","cog"]
//
//示例 2:
//
//输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//输出: []
//
//解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。


namespace utils{
    template <typename T>
    void printVec(const vector<T>& nums){
        if(nums.empty()){
            cout<<"[]"<<endl;
            return;
        }
        cout<<"[ ";
        for(const T& u:nums)
            cout<<u<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVec(const vector<T>& nums, int l, int r){
        if(l>r)
            return;
        cout<<"[ ";
        for(int i=l;i<=r;i++)
            cout<<nums[i]<<" ";
        cout<<"]"<<endl;
    }

    template <typename T>
    void printVvec(const vector<vector<T>>& nums){
        if(nums.empty())
            return;
        cout<<"["<<endl;
        for(const vector<T>& v:nums) {
            cout<<"[ ";
            for (const T &u:v)
                cout << u << " ";
            cout<<"]"<<endl;
        }
        cout<<"]"<<endl;
    }
}


class Solution {
private:
    unordered_map<string,unordered_set<string>> matchwordList;
    bool matchword(string& s1,string& s2){
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                cnt++;
        }
        return cnt==1;
    }
    void bfs(string beginWord, string endWord, vector<string>& wordList, unordered_map<string,string>& mp){
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            string cur=q.front();
            q.pop();
//            for(string& word:wordList){
//                if(matchword(cur,word)&&mp[word].empty()){
//                    mp[word]=cur;
//                    if(word==endWord)
//                        return;
//                    q.push(word);
//                }
//            }
            for(const string& word:matchwordList[cur]){
                if(mp[word].empty()){
                    mp[word]=cur;
                    if(word==endWord)
                        return;
                    q.push(word);
                }
            }
        }
    }
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,string> mp;
        for(string& s:wordList)
            mp[s]="";
        if(!mp.count(endWord))
            return {};
        if(beginWord==endWord)
            return {beginWord};

        for(int i=0;i<wordList.size();i++){
            if(matchword(wordList[i],beginWord))
                matchwordList[beginWord].insert(wordList[i]);
            for(int j=i+1;j<wordList.size();j++)
                if(matchword(wordList[i],wordList[j])){
                    matchwordList[wordList[i]].insert(wordList[j]);
                    matchwordList[wordList[j]].insert(wordList[i]);
                }
        }

        mp[beginWord]=beginWord;
        bfs(beginWord,endWord,wordList,mp);
        if(mp[endWord].empty())
            return {};
        vector<string> res;
        string cur=endWord;
        res.emplace_back(cur);
        while(mp[cur]!=beginWord){
            res.emplace_back(mp[cur]);
            cur=mp[cur];
        }
        res.emplace_back(beginWord);
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(int argc, char *argv[]){

    string beginWord="hit";
    string endWord="cog";
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    utils::printVec(Solution().findLadders(beginWord,endWord,wordList));

    beginWord="hit";
    endWord="cog";
    wordList={"hot","dot","dog","lot","log"};
    utils::printVec(Solution().findLadders(beginWord,endWord,wordList));

    beginWord="hot";
    endWord="dog";
    wordList={"hot","dog"};
    utils::printVec(Solution().findLadders(beginWord,endWord,wordList));

    return 0;
}