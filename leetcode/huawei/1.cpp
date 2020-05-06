#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &str, const char pattern) {
    vector<string> res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern)) {
        if (temp.size() == 0) continue;

        // 排除空格
        int count = 0;
        for (char c : temp)
            if (c == ' ') count++;
        if (count == temp.size()) continue;

        res.push_back(temp);
    }
    return res;
}

bool check(string str) {
    // 拆分
    vector<string> strs = split(str, ' ');
    if (strs.size() == 0) return true;

    // 去除其它字符
    for (string str : strs) {
        if (str.size() == 1) {
            if (str[0] < 'a' || str[0] > 'z') {
                return false;
            }
        } else if (str.size() == 2) {
            if (str != "OR") return false;
        } else if (str.size() == 3) {
            if (str != "AND" && str != "NOT") return false;
        } else {
            return false;
        }
    }

    // 开头
    if (strs[0].size() != 1 && strs[0] != "NOT") return false;
    // 结尾
    if (strs[strs.size() - 1].size() != 1) return false;

    // 顺序判断
    for (int i = 1; i < strs.size(); i++) {
        string str = strs[i];
        if (str.size() == 1) {
            if (strs[i - 1].size() == 1) return false;
        } else {
            if (str == "NOT") {
                if (str == strs[i - 1]) return false;
            } else if (str == "AND") {
                if (strs[i - 1].size() != 1) return false;
            } else if (str == "OR") {
                if (strs[i - 1].size() != 1) return false;
            }
        }
    }

    return true;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (check(line))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}