#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    int calculate(string s) {
        istringstream in(s);
        int val;
        char op = '+';
        stack<int> st;
        while (in >> val) {
            if (op == '+') {
                st.push(val);
            } else if (op == '-') {
                st.push(-val);
            } else if (op == '*') {
                int top = st.top();
                st.pop();
                st.push(top * val);
            } else if (op == '/') {
                int top = st.top();
                st.pop();
                st.push(top / val);
            }
            in >> op;
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main() {}