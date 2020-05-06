#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class CustomStack {
   public:
    CustomStack(int maxSize) { _max_size = maxSize; }

    void push(int x) {
        if (_s.size() >= _max_size) return;
        _s.push(x);
    }

    int pop() {
        if (_s.empty()) return -1;
        int res = _s.top();
        _s.pop();
        return res;
    }

    void increment(int k, int val) {
        stack<int> top;
        while (_s.size() > k) {
            top.push(_s.top());
            _s.pop();
        }

        stack<int> bottom;
        while (!_s.empty()) {
            bottom.push(_s.top());
            _s.pop();
        }

        while (!bottom.empty()) {
            _s.push(bottom.top() + val);
            bottom.pop();
        }
        while (!top.empty()) {
            _s.push(top.top());
            top.pop();
        }
    }

    stack<int> _s;
    int _max_size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {}