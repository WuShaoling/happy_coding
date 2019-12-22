#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> split(const string &str, const char pattern) {
        vector<string> res;
        stringstream input(str);
        string temp;
        while (getline(input, temp, pattern)) {
            res.push_back(temp);
        }
        return res;
    }

    string deletePreZero(string s) {
        int i = 0;
        while (s[i] == '0') i++;
        if (i == s.size()) return "";
        return s.substr(i, s.size() - i);
    }

    int compare(string s1, string s2) {
        if (s1.size() == s2.size()) {
            if (s1 == s2) return 0;
            if (s1 > s2) return 1;
            return -1;
        } else if (s1.size() > s2.size()) {
            return 1;
        } else {
            return -1;
        }
    }

    int compareVersion(string version1, string version2) {
        vector<string> s1 = split(version1, '.');
        vector<string> s2 = split(version2, '.');

        int i = 0;
        for (; i < s1.size() && i < s2.size(); i++) {
            int res = compare(deletePreZero(s1[i]), deletePreZero(s2[i]));
            if (res > 0) {
                return 1;
            } else if (res < 0) {
                return -1;
            }
        }

        for (int t = i; t < s1.size(); t++) {
            if (deletePreZero(s1[t]).size() > 0) {
                return 1;
            }
        }

        for (int t = i; t < s2.size(); t++) {
            if (deletePreZero(s2[t]).size() > 0) {
                return -1;
            }
        }

        return 0;
    }
};

int main() {
    Solution s;
    // cout << s.deletePreZero("000123");
    cout << s.compare("1", "2");
}