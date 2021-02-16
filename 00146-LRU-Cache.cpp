#include <bits/stdc++.h>

using namespace std;

class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> hashLinkList;
    list<pair<int, int>> linkList;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (hashLinkList.count(key)) {
            int value = hashLinkList[key]->second;
            linkList.erase(hashLinkList[key]);
            auto it = linkList.insert(linkList.end(), make_pair(key, value));
            hashLinkList[key] = it;
            return value;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (hashLinkList.count(key)) {
            linkList.erase(hashLinkList[key]);
            auto it = linkList.insert(linkList.end(), make_pair(key, value));
            hashLinkList[key] = it;
        } else {
            if (hashLinkList.size() == capacity) {
                auto it = linkList.begin();
                hashLinkList.erase(it->first);
                linkList.erase(it);
            }
            auto it = linkList.insert(linkList.end(), make_pair(key, value));
            hashLinkList[key] = it;
        }
    }
};

int main(int argc, char* argv[]) {



    return 0;
}

