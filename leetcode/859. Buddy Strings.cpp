#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length() || A.length() < 2) {
            return false;
        }
        int change = 0;
        for (int i = 0, j = A.length() - 1; i < j; i++, j--) {
            while (i < j && A[i] == B[i]) i++;
            while (i < j && A[j] == B[j]) j--;
            if (A[i] == B[i] && A[j] == B[j]) {
                break;
            }
            if (A[i] == B[j] && A[j] == B[i]) {
                change++;
            } else {
                return false;
            }
        }
        if (change > 1) {
            return false;
        } else if (change == 1) {
            return true;
        } else {
            for (int i = 0; i < A.length(); i++) {
                for (int j = i + 1; j < A.length(); j++) {
                    if (A[i] == A[j] && B[i] == B[j] && A[i] == B[i]) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.buddyStrings("bcaaa", "abcaa") << endl;
    cout << solution.buddyStrings("", "cd") << endl;
    cout << solution.buddyStrings("ab", "") << endl;
    cout << solution.buddyStrings("a", "b") << endl;
    cout << solution.buddyStrings("ab", "cd") << endl;
    cout << solution.buddyStrings("ab", "ab") << endl;
    cout << solution.buddyStrings("aa", "aa") << endl;
    cout << solution.buddyStrings("ab", "ba") << endl;
    cout << solution.buddyStrings("abab", "abab") << endl;
    cout << solution.buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
}
