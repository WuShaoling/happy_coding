#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<char>> ops;

// 1 2 3 4
//  + - *
void setOperator(vector<int>& path) {
    for (vector<char> op : ops) {
        stack<int> st;
        st.push(path[0]);
        int i = 1;
        for (char c : op) {
            if (c == '+') {
                st.push(path[i++]);
            } else if (c == '-') {
                st.push(-path[i++]);
            } else if (c == '*') {
                int top = st.top();
                st.pop();
                st.push(top * path[i++]);
            } else {
                int top = st.top();
                st.pop();
                st.push(top / path[i++]);
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        if (sum == 24) {
            for (int i = 0; i < 3; i++) {
                cout << path[i] << op[i];
            }
            cout << path[3] << endl;
        }
    }
}

void helper(vector<int>& nums, vector<int>& path, vector<bool>& visited) {
    if (path.size() == 4) {
        setOperator(path);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;

        path.push_back(nums[i]);
        visited[i] = true;

        helper(nums, path, visited);

        path.pop_back();
        visited[i] = false;
    }
}

void getOps(vector<char>& op_set, vector<char>& op_path,
            vector<bool> op_visited) {
    if (path.size() == 3) {
        ops.push_back(op_path);
        return;
    }

    for (int i = 0; i < op_set.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        op_path.push_back(op[i]);

        getOps(op_path, op_visited);

        op_path.pop_back();
        visited[i] = false;
    }
}

int main() {
    vector<char> op_set = {'+', '-', '*', '/'};
    vector<char> op_path;
    vector<bool> op_visited(4, false);
    getOps(op_set, op_path, op_visited);

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> path;
    vector<bool> visited(10, false);
    helper(nums, path, visited);
    cout << "Hello World!" << endl;
}