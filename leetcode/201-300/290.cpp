#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &str, const char pattern) {
    vector<string> res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern)) {
        res.push_back(temp);
    }
    return res;
}

class Solution {
   public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs = split(str, ' ');
        if (pattern.size() == 0 && strs.size() == 0) return false;
        if (strs.size() != pattern.size()) return false;

        map<char, string> mm;
        map<string, bool> m2;
        map<char, string>::iterator it;
        for (int i = 0; i < pattern.size(); i++) {
            it = mm.find(pattern[i]);
            if (it != mm.end()) {  //如果找到了
                if (it->second != strs[i]) return false;
            } else {  //如果不存在映射
                if (m2.find(strs[i]) != m2.end()) return false;
                mm[pattern[i]] = strs[i];
                m2[strs[i]] = 1;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat fish");
}