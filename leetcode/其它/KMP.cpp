#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;

        vector<int> next = getNext(needle);
        int m = haystack.size(), n = needle.size(), i = 0, j = 0;
        while (i < m && j < n) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        return (j == n) ? i - j : -1;
    }

    vector<int> getNext(string p) {
        vector<int> next(p.size());
        next[0] = -1;
        int j = 0, k = -1;
        while (j < p.size() - 1) {
            if (k == -1 || p[j] == p[k]) {
                ++k;
                ++j;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
        return next;
    }
};

int main() {
    Solution s;
    cout << s.strStr("hell0", "aab");
}
