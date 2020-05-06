#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string replaceSpace(string s) {
        char str[s.size() * 2 + 1];

        int idx = 0;
        for (char c : s) {
            if (c == ' ') {
                str[idx++] = '%';
                str[idx++] = '2';
                str[idx++] = '0';
            } else {
                str[idx++] = c;
            }
        }

        return string(str, idx);
    }
};

int main() {
    Solution s;
    cout << s.replaceSpace("a b c");
}