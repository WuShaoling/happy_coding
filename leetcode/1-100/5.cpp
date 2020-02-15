#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        if (s == "") return s;
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = find(s, i, i);
            int len2 = find(s, i, i + 1);
            int len = max(len1, len2);
            if (len > max_len) {
                start = i - (len - 1) / 2;
                max_len = len;
            }
        }
        return s.substr(start, max_len);
    }

    int find(const string& s, int left, int right) {
        int L = left;
        int R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};
//   i
// 012345
// abccba
int main() {}