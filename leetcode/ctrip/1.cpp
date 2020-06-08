#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& str, const char pattern) {
    vector<string> res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern)) {
        if (temp.empty()) continue;
        res.push_back(temp);
    }
    return res;
}

bool cmp(const vector<string>& v1, const vector<string>& v2) {
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] < v2[i]) {
            return true;
        } else if (v1[i] > v2[i]) {
            return false;
        }
    }
    return false;
}

// (A,B);(A,C);(C,B);(C,D);(D,B);
vector<vector<string>> ans;
void dfs(vector<vector<int>>& g, vector<bool> visited, vector<char> path,
         int index) {
    if (visited[index] || path.size() > 5) return;
    if (path.size() == 5) {
        if (path.back() == 'B') {
            vector<string> temp;
            for (char c : path) {
                string st;
                st.push_back(c);
                temp.push_back(st);
            }
            ans.push_back(temp);
        }
        return;
    }

    path.push_back('A' + index);

    if (index == 1) {
        vector<string> temp;
        for (char c : path) {
            string st;
            st.push_back(c);
            temp.push_back(st);
        }
        ans.push_back(temp);
        return;
    }

    visited[index] = true;
    for (int nei : g[index]) {
        dfs(g, visited, path, nei);
    }
    visited[index] = false;
}

void my_sort() {
    map<int, vector<vector<string>>> mm;
    for (vector<string> line : ans) {
        mm[line.size()].push_back(line);
    }
    ans.clear();
    for (auto& it : mm) {
        vector<vector<string>> line = it.second;
        sort(line.begin(), line.end(), cmp);
        for (auto ll : line) ans.push_back(ll);
    }
}

vector<vector<string>> answer(string inputStr) {
    ans.clear();

    vector<string> arr = split(inputStr, ';');

    // 构建临接数组
    vector<vector<int>> g(26);
    for (string str : arr) {
        int src = str[1] - 'A';
        int dest = str[3] - 'A';
        g[src].push_back(dest);
    }

    vector<char> path;
    vector<bool> visited(26, false);
    dfs(g, visited, path, 0);

    my_sort();
    return ans;
}

int main() {
    vector<vector<string>> res;

    string _inputStr;
    getline(cin, _inputStr);

    res = answer(_inputStr);
    if (res.empty()) {
        cout << "EMPTY" << endl;
        return 0;
    }
    for (int res_i = 0; res_i < res.size(); res_i++) {
        if (res_i == 0) {
            cout << "[";
        }
        for (int res_j = 0; res_j < res[res_i].size(); res_j++) {
            if (res_j == 0) {
                cout << "[";
            }
            cout << res[res_i][res_j];
            if (res_j < res[res_i].size() - 1) {
                cout << ",";
            } else {
                cout << "]";
            }
        }
        if (res_i < res.size() - 1) {
            cout << ",";
        } else {
            cout << "]";
        }
    }

    return 0;
}

// (A,D);(D,B);(A,C);(C,B);
// (A,B);(A,E);(E,F);(F,B);(A,C);(C,D);(D,B);
// (A,B);(A,B);