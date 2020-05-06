#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popIdx = 0;
        stack<int> st;
        for (int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);
            while (!st.empty() && popIdx < popped.size() &&
                   st.top() == popped[popIdx]) {
                st.pop();
                popIdx++;
            }
        }
        return st.empty();
    }
};
//          i
// 1,2,3,4,5  12
//       i
// 4,3,5,1,2
int main() {
    Solution s;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 1, 2};
    cout << s.validateStackSequences(pushed, popped);
}