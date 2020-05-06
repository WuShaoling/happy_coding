#include <iostream>
#include <stack>

using namespace std;

class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        s.push(x);
        if (s_min.empty()) {
            s_min.push(x);
        } else if (s_min.top() < x) {
            s_min.push(x);
        } else {
            s_min.push(s_min.top());
        }
    }

    void pop() {
        if (s.empty()) return;
        s.pop();
        s_min.pop();
    }

    int top() {
        if (s.empty()) return -1;
        return s.top();
    }

    int min() {
        if (s_min.empty()) return -1;
        return s_min.top();
    }

   private:
    stack<int> s;
    stack<int> s_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main() {}