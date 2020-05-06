#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string findLongestWord(string s, vector<string> &d) {
        string res = "";

        for (string str : d) {
            if (find(s, str)) {
                if (str.size() > res.size() ||
                    (str.size() == res.size() && str < res))
                    res = str;
            }
        }

        return res;
    }

    bool find(string &s, string &substr) {
        int sp = 0, subp = 0;
        while (sp < s.size() && subp < substr.size()) {
            if (s[sp] == substr[subp]) {
                sp++;
                subp++;
            } else {
                sp++;
            }
        }
        return subp == substr.size();
    }
};

int main() {}