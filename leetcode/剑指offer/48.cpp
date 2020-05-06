#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        map<char, int> mm;
        for (int i = 0, j = 0; j < s.size(); j++) {
            char c = s[j];
            if (mm.find(c) != mm.end()) i = max(i, mm[c]);
            res = max(res, j - i + 1);
            mm[c] = j + 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcd");
}