#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class MyQueue {
   public:
    /**

    ------------  ------------
           2 3 |  | 4 5
    ------------  ------------
       s2              s1
    */

    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { s1.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!s2.empty()) {
            int n = s2.top();
            s2.pop();
            return n;
        }

        if (s1.empty()) return -1;

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int n = s2.top();
        s2.pop();
        return n;
    }

    /** Get the front element. */
    int peek() {
        if (!s2.empty()) return s2.top();
        if (s1.empty()) return -1;

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty() && s2.empty(); }

    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */