#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxN = 0;
        stack<int> ss;
        ss.push(-1);
        for (int i=0; i<s.size(); i++){
            if(s[i] == '('){
                ss.push(i);
            }else{
                ss.pop();
                if (ss.empty()) {
                    ss.push(i);
                } else {
                    maxN = max(maxN, i - ss.top());
                }
            }
        }
        return maxN;
    }
};

int main(){
    Solution s;
    cout << s.longestValidParentheses("(()");
}