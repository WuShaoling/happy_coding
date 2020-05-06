#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 10;
const int target = 24;
vector<char> operators = {'+', '-', '*', '/'};

vector<vector<char>> operator_combinations;
void get_result(vector<int>& path) {
    for (vector<char> line : operator_combinations) {
        stack<int> st;
        st.push(path[0]);
        int i = 1;
        for (char c : line) {
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
        if (sum == target) {
            for (int i = 0; i < 3; i++) cout << path[i] << line[i];
            cout << path[3] << endl;
        }
    }
}

void get_operator_combinations(vector<bool>& visited, vector<char>& path) {
    if (path.size() == 3) {
        operator_combinations.push_back(path);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (visited[i]) continue;

        path.push_back(operators[i]);
        visited[i] = true;

        get_operator_combinations(visited, path);

        visited[i] = false;
        path.pop_back();
    }
}

void get_number_combinations(vector<bool>& visited, vector<int>& path) {
    if (path.size() == 4) {
        get_result(path);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        path.push_back(i);
        visited[i] = true;

        get_number_combinations(visited, path);

        visited[i] = false;
        path.pop_back();
    }
}

int main() {
    vector<bool> operator_visited(4, false);
    vector<char> operator_path;
    get_operator_combinations(operator_visited, operator_path);

    vector<bool> nums_visited(11, false);
    vector<int> nums_path;
    get_number_combinations(nums_visited, nums_path);
}
