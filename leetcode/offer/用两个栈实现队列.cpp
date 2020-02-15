#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    void push(int node) {
        // 插入 stack2，然后写到 stack1

        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack2.push(node);

        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int n = stack1.top();
        stack1.pop();
        return n;
    }

   private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {}

// 3 2 1
// 1 2 3 4
// 4 3 2 1