#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// typedef struct StackNode{
//     int value;
//     struct StackNode* next;
//     StackNode(int v){
//         value = v;
//         next = NULL;
//     }
// } *Stack;

class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() { _min = INT_MAX; }

    void push(int x) {
        _stack.push_back(x);
        if (x < _min) {
            _min = x;
        }
    }

    void pop() {
        if (_stack.size() != 0) {
            _stack.pop_back();
        }
        _min = INT_MAX;
        for (int i = 0; i < _stack.size(); i++) {
            if (_stack[i] < _min) {
                _min = _stack[i];
            }
        }
    }

    int top() {
        if (_stack.size() == 0) {
            return 0;
        }
        return _stack[_stack.size() - 1];
    }

    int getMin() { return _min; }

   private:
    vector<int> _stack;
    int _min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {}