#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return palindrome == "a" ? "" : "a";

        int mid = n / 2;
        for (int i = 0; i < mid; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        return "";
    }
};

int main() {
    Solution s;
    cout << s.breakPalindrome("aaaaa");
}