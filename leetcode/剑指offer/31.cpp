#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0) return true;

        int index = 0;
        stack<int> s;

        for (int pop : popped) {
            if (!s.empty() && s.top() == pop) {
                s.pop();
                continue;
            }

            // 在 pushed 中查找
            while (index < pushed.size() && pushed[index] != pop) {
                s.push(pushed[index]);
                index++;
            }
            if (index == pushed.size()) return false;
            index++;
        }

        return true;
    }
};

int main() {}