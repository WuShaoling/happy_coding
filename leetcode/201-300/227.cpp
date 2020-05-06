#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int calculate(string s) {
        string str;
        for (char c : s) {
            if (c != ' ') str.push_back(c);
        }

        stringstream ss(str);
        char op = '+';
        int num;
        stack<int> st;
        while (ss >> num) {
            if (op == '+') {
                st.push(num);
            } else if (op == '-') {
                st.push(-num);
            } else if (op == '*') {
                int n = st.top();
                st.pop();
                st.push(n * num);
            } else if (op == '/') {
                int n = st.top();
                st.pop();
                st.push(n / num);
            }
            ss >> op;
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main() {}