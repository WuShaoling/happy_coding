#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void _split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;

    while (std::getline(ss, item, delim)) {
        if (item.size() != 0) elems.push_back(item);
    }
}

class Solution {
   public:
    string simplifyPath(string path) {
        vector<string> elems;
        _split(path, '/', elems);

        stack<string> _s;
        for (int i = 0; i < elems.size(); i++) {
            if (elems[i] == ".") {
                continue;
            } else if (elems[i] == "..") {
                if (!_s.empty()) {
                    _s.pop();
                }
            } else {
                _s.push(elems[i]);
            }
        }

        string res = "";
        while (!_s.empty()) {
            res = "/" + _s.top() + res;
            _s.pop();
        }

        return res == "" ? "/" : res;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/../");
}