#include <iostream>
#include <vector>

using namespace std;

class MyStack {
   public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) { _queue.push_back(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (_queue.empty()) {
            return 0;
        }
        int t = _queue[_queue.size() - 1];
        _queue.pop_back();
        return t;
    }

    /** Get the top element. */
    int top() {
        if (_queue.empty()) {
            return 0;
        }
        int t = _queue[_queue.size() - 1];
        return t;
    }

    /** Returns whether the stack is empty. */
    bool empty() { return _queue.empty(); }

   private:
    vector<int> _queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack* obj = new MyStack();
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
}