#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        string str;
        cin >> str;

        stack<char> stk;
        for (char c : str) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        cout << (stk.empty() ? "Yes" : "No") << endl;
    }
}