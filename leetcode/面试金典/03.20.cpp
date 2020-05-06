#include <iostream>
#include <stack>

using namespace std;

class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        _s.push(x);
        if (_min.empty() || (!_min.empty() && x < _min.top())) {
            _min.push(x);
        } else {
            _min.push(_min.top());
        }
    }

    void pop() {
        if (_s.empty()) return;
        _s.pop();
        _min.pop();
    }

    int top() {
        if (_s.empty()) return 0;
        return _s.top();
    }

    int getMin() {
        if (_min.empty()) return 0;
        return _min.top();
    }

   private:
    stack<int> _s;
    stack<int> _min;
};

int main() {}