#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res = max(res, count(s, i, i));
            res = max(res, count(s, i, i + 1));
        }
        return res;
    }

    int count(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left + 1;
    }
};
