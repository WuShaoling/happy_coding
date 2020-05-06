#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class CQueue {
   public:
    CQueue() {}

    void appendTail(int value) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(value);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deleteHead() {
        if (s1.empty()) return -1;
        int n = s1.top();
        s1.pop();
        return n;
    }

    stack<int> s1;
    stack<int> s2;
};

int main() {}