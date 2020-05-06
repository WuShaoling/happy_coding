#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
   public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> t;
        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s.empty()) return -1;
        int res = s.top();
        s.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (s.empty()) return -1;
        int res = s.top();
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s.empty(); }

   private:
    stack<int> s;
};

int main() {}