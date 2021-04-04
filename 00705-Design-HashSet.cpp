#include <bits/stdc++.h>

using namespace std;

//705. 设计哈希集合
//
//        不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
//
//实现 MyHashSet 类：
//
//void add(key) 向哈希集合中插入值 key 。
//bool contains(key) 返回哈希集合中是否存在这个值 key 。
//void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
//
//
//
//示例：
//
//输入：
//["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
//[[], [1], [2], [1], [3], [2], [2], [2], [2]]
//输出：
//[null, null, null, true, false, null, true, null, false]
//
//解释：
//MyHashSet myHashSet = new MyHashSet();
//myHashSet.add(1);      // set = [1]
//myHashSet.add(2);      // set = [1, 2]
//myHashSet.contains(1); // 返回 True
//myHashSet.contains(3); // 返回 False ，（未找到）
//myHashSet.add(2);      // set = [1, 2]
//myHashSet.contains(2); // 返回 True
//myHashSet.remove(2);   // set = [1]
//myHashSet.contains(2); // 返回 False ，（已移除）
//
//
//
//提示：
//
//0 <= key <= 106
//最多调用 104 次 add、remove 和 contains 。
//
//
//
//进阶：你可以不使用内建的哈希集合库解决此问题吗？


class MyHashSet {
private:
    constexpr static int base = 769;
    vector<list<int>> data;

    constexpr static int hash(int x) {
        return x % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(base);
    }

    void add(int key) {
        int x = hash(key);
        for (auto it = data[x].begin(); it != data[x].end(); ++it) {
            if (*it == key)
                return;
        }
        data[x].push_back(key);
    }

    void remove(int key) {
        int x = hash(key);
        auto it = data[x].begin();
        for (; it != data[x].end(); ++it) {
            if (*it == key)
                break;
        }
        if (it == data[x].end())
            return;
        data[x].erase(it);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int x = hash(key);
        auto it = data[x].begin();
        for (; it != data[x].end(); ++it) {
            if (*it == key)
                break;
        }
        return it != data[x].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


int main(int argc, char *argv[]){

    return 0;
}

