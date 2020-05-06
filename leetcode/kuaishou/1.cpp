#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    stack<char> st;
    cin >> str;

    int left = 0;
    int right = 0;
    for (char c : str) {
        if (c == '(')
            left++;
        else if (c == ')')
            right++;
    }
    int matches = 0;
    for (char c : str) {
        if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            if (!st.empty()) {
                st.pop();
                matches++;
            }
        }
    }
    cout << matches << " " << left - matches << " " << right - matches << endl;
}