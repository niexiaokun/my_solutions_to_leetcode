#include <bits/stdc++.h>

using namespace std;

//703. 数据流中的第 K 大元素
//
//        设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
//
//请实现 KthLargest 类：
//
//KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
//int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
//
//
//
//示例：
//
//输入：
//["KthLargest", "add", "add", "add", "add", "add"]
//[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
//输出：
//[null, 4, 5, 5, 8, 8]
//
//解释：
//KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
//kthLargest.add(3);   // return 4
//kthLargest.add(5);   // return 5
//kthLargest.add(10);  // return 5
//kthLargest.add(9);   // return 8
//kthLargest.add(4);   // return 8
//
//
//提示：
//
//1 <= k <= 104
//0 <= nums.length <= 104
//-104 <= nums[i] <= 104
//-104 <= val <= 104
//最多调用 add 方法 104 次
//        题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素



//class KthLargest {
//private:
//    priority_queue<int,vector<int>,greater<int>> pq;
//    int m, sz;
//public:
//    KthLargest(int k, vector<int>& nums) {
//        sz=0;
//        m=k;
//        while(sz<k&&sz<nums.size()){
//            pq.emplace(nums[sz]);
//            ++sz;
//        }
//        for(int i=k;i<nums.size();++i){
//            if(nums[i]>pq.top()){
//                pq.pop();
//                pq.emplace(nums[i]);
//            }
//        }
//    }
//
//    int add(int val) {
//        if(sz<m)
//            pq.emplace(val);
//        else if(val>pq.top()){
//            pq.pop();
//            pq.emplace(val);
//        }
//        ++sz;
//        return pq.top();
//    }
//};

class KthLargest {
private:
    vector<int> heap;
    int m, sz;

    void shiftup(int i) {
        int v = heap[i];
        int j = (i - 1) / 2;
        while (i > 0 && v < heap[j]) {
            heap[i] = heap[j];
            i = j;
            j = (i - 1) / 2;
        }
        heap[i] = v;
    }

    void shiftdown(int i) {
        int v = heap[i];
        int j = i * 2 + 1;
        while (j < heap.size()) {
            if (j + 1 < heap.size() && heap[j + 1] < heap[j])
                ++j;
            if (v > heap[j]) {
                heap[i] = heap[j];
                i = j;
                j = i * 2 + 1;
            } else
                break;
        }
        heap[i] = v;
    }

    void insert(int v) {
        int i = heap.size();
        heap.emplace_back(v);
        shiftup(i);
        ++sz;
    }

    void replace(int v) {
        heap[0] = v;
        shiftdown(0);
    }

public:
    KthLargest(int k, vector<int> &nums) {
        m = k;
        sz = 0;
        while (sz < k && sz < nums.size())
            insert(nums[sz]);
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > heap[0])
                replace(nums[i]);
        }
    }

    int add(int val) {
        if (sz < m) {
            insert(val);
        } else if (val > heap[0])
            replace(val);
        return heap[0];
    }
};


int main(int argc, char* argv[]) {



    return 0;
}

