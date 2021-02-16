#include <bits/stdc++.h>

using namespace std;

//155. 最小栈
//
//        设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) —— 将元素 x 推入栈中。
//pop() —— 删除栈顶的元素。
//top() —— 获取栈顶元素。
//getMin() —— 检索栈中的最小元素。
//
//
//
//示例:
//
//输入：
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//输出：
//[null,null,null,null,-3,null,0,-2]
//
//解释：
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.
//
//提示：
//
//pop、top 和 getMin 操作总是在 非空栈 上调用。


//class MinStack {
//private:
//    stack<int> nums;
//    stack<int> aux;
//    int cur;
//public:
//    /** initialize your data structure here. */
//    MinStack() {
//        cur=INT_MAX;
//        aux.emplace(cur);
//    }
//
//    void push(int x) {
//        nums.emplace(x);
//        cur=min(cur,x);
//        aux.emplace(cur);
//    }
//
//    void pop() {
//        if(nums.empty())
//            return;
//        nums.pop();
//        aux.pop();
//        if(nums.empty())
//            cur=INT_MAX;
//        else
//            cur=aux.top();
//    }
//
//    int top() {
//        if(nums.empty())
//            return -1;
//        return nums.top();
//    }
//
//    int getMin() {
//        if(nums.empty())
//            return -1;
//        return aux.top();
//    }
//};


//class MinStack {
//private:
//    stack<int> nums;
//    stack<int> aux;
//public:
//    /** initialize your data structure here. */
//    MinStack() {
//        aux.emplace(INT_MAX);
//    }
//
//    void push(int x) {
//        nums.emplace(x);
//        aux.emplace(min(aux.top(),x));
//    }
//
//    void pop() {
//        if(nums.empty())
//            return;
//        nums.pop();
//        aux.pop();
//    }
//
//    int top() {
//        if(nums.empty())
//            return -1;
//        return nums.top();
//    }
//
//    int getMin() {
//        if(nums.empty())
//            return -1;
//        return aux.top();
//    }
//};

class MinStack {
private:
    stack<long> diff;
    long minval;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        long tt;
        if(diff.empty()){
            minval=x;
            tt=0;
        }else{
            tt=(long)x-minval;
            if(tt<0)
                minval=x;
        }
        diff.emplace(tt);
    }

    void pop() {
        if(diff.empty())
            return;
        long tt=diff.top();
        diff.pop();
        if(tt<0)
            minval-=tt;
    }

    int top() {
        if(diff.empty())
            return -1;
        long tt=diff.top();
        if(tt<0)
            return minval;
        else
            return minval+tt;
    }

    int getMin() {
        if(diff.empty())
            return -1;
        return minval;
    }
};

int main(int argc, char* argv[]) {

    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout<<obj->getMin()<<" ";
    obj->pop();
    cout<<obj->top()<<" ";
    cout<<obj->getMin()<<endl;
    delete obj;
    return 0;
}

