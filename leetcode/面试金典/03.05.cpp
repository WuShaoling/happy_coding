#include <iostream>
#include <stack>

using namespace std;

class SortedStack {
   public:
    SortedStack() {}

    void push(int val) {
        stack<int> t;
        while (!s.empty() && s.top() < val) {
            t.push(s.top());
            s.pop();
        }
        s.push(val);
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
    }

    void pop() {
        if (s.empty()) return;
        s.pop();
    }

    int peek() {
        if (s.empty()) return -1;
        return s.top();
    }

    bool isEmpty() { return s.empty(); }

   private:
    stack<int> s;
};

int main() {}