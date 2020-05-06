#include <string>
#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//    public:
//     int strStr(string haystack, string needle) {
//         if (needle.empty()) return 0;
//         if (haystack.empty()) return -1;

//         vector<int> next = getNext(needle);
//         for (int i : next) cout << i << " ";
//         cout << endl;

//         int i = 0, j = 0;
//         while (i < haystack.size() && j < needle.size()) {
//             if (j == -1 || haystack[i] == needle[j]) {
//                 ++i;
//                 ++j;
//             } else {
//                 j = next[j];
//             }
//         }
//         return (j == needle.size()) ? i - j : -1;
//     }

//     vector<int> getNext(const string& needle) {
//         vector<int> next(needle.size());
//         next[0] = -1;
//         int j = 0, k = -1;
//         while (j < needle.size() - 1) {
//             if (k == -1 || needle[j] == needle[k]) {
//                 j++;
//                 k++;
//                 next[j] = k;
//             } else {
//                 k = next[k];
//             }
//         }
//         return next;
//     }
// };

class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        return kmp(haystack, needle);
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

    int kmp(string s, string p) {
        int m = s.size(), n = p.size(), i = 0, j = 0;

        vector<int> next = getNext(p);
        while (i < m && j < n) {
            if (j == -1 || s[i] == p[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        return (j == n) ? i - j : -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("hell0", "ll");
}