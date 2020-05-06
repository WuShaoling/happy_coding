#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MyStack {
   public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int n = q.size();
        while (n > 1) {
            q.push(q.front());
            q.pop();
            n--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q.empty()) return -1;
        int n = q.front();
        q.pop();
        return n;
    }

    /** Get the top element. */
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }

   private:
    queue<int> q;
};

// 1 2 3 top
// 3 2 1 top
// 3 2 1 4

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {}