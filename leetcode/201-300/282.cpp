#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> addOperators(string num, int target) {
        if (num.size() == 0) return {};

        ans.clear();
        this->target = target;
        this->num = num;
        dfs(num.size() - 1, 0);

        return ans;
    }

   private:
    void dfs(int n, int idx) {
        if (idx == n) {
            checkVal();
            return;
        }

        op_path.push_back('+');
        dfs(n, idx + 1);
        op_path.pop_back();

        op_path.push_back('-');
        dfs(n, idx + 1);
        op_path.pop_back();

        op_path.push_back('*');
        dfs(n, idx + 1);
        op_path.pop_back();
    }

    void checkVal() {
        int i = 0;
        st.push(num[i++] - '0');
        for (int j = 0; j < op_path.size(); j++) {
            char c = op_path[j];
            if (c == '+') {
                st.push(num[i++] - '0');
            } else if (c == '-') {
                st.push(-(num[i++] - '0'));
            } else {
                int top = st.top();
                st.pop();
                st.push(top * (num[i++] - '0'));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        if (sum == target) {
            string res = "";
            for (i = 0; i < num.size() - 1; i++) {
                res.push_back(num[i]);
                res.push_back(op_path[i]);
            }
            res.push_back(num[num.size() - 1]);
            ans.push_back(res);
        }
    }

    stack<int> st;
    int target;
    string num;
    vector<char> op_path;
    vector<string> ans;
};

int main() {
    Solution s;
    vector<string> ans = s.addOperators("123", 6);
    for (string str : ans) cout << str << endl;
}