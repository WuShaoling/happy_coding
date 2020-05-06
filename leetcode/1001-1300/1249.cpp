#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        int pos[100010] = {0};
        stack<int> _stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                _stack.push(i);
            } else if (s[i] == ')') {
                if (_stack.empty()) {
                    pos[i] = 1;
                } else {
                    _stack.pop();
                }
            }
        }
        while (!_stack.empty()) {
            pos[_stack.top()] = 1;
            _stack.pop();
        }

        char res[100010] = {0};
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (pos[i] == 0) {
                res[cur++] = s[i];
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    
    string ss = "a)b(c)d";
    
    cout << s.minRemoveToMakeValid(ss) << endl;
}