#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> SS;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                SS.push(s[i]);
            } else {
                if (SS.empty()) return false;
                if ((s[i] == ']' && SS.top() != '[') ||
                    (s[i] == ')' && SS.top() != '(') ||
                    (s[i] == '}' && SS.top() != '{')) {
                    return false;
                } else {
                    SS.pop();
                }
            }
        }

        return SS.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("()");
}