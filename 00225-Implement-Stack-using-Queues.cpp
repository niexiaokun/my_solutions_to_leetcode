#include <bits/stdc++.h>

using namespace std;

//class MyStack {
//private:
//    deque<int> dq;
//public:
//    /** Initialize your data structure here. */
//    MyStack() {
//
//    }
//
//    /** Push element x onto stack. */
//    void push(int x) {
//        dq.push_back(x);
//    }
//
//    /** Removes the element on top of the stack and returns that element. */
//    int pop() {
//        if(dq.empty())
//            return -1;
//        int x=dq.back();
//        dq.pop_back();
//        return x;
//    }
//
//    /** Get the top element. */
//    int top() {
//        if(dq.empty())
//            return -1;
//        return dq.back();
//    }
//
//    /** Returns whether the stack is empty. */
//    bool empty() {
//        return dq.empty();
//    }
//};

class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n=q.size();
        q.emplace(x);
        for(int i=0;i<n;++i){
            q.emplace(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q.empty())
            return -1;
        int x=q.front();
        q.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        if(q.empty())
            return -1;
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main(int argc, char* argv[]) {


    return 0;
}

