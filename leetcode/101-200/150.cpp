#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                switch (str[0]) {
                    case '+':
                        st.push(v1 + v2);
                        break;
                    case '-':
                        st.push(v1 - v2);
                        break;
                    case '*':
                        st.push(v1 * v2);
                        break;
                    case '/':
                        st.push(v1 / v2);
                        break;
                }
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};

int main() {}