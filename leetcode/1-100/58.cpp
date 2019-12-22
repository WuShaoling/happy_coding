#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;

        while (n >= 0 && s[n] == ' ') n--;
        if (n == -1) return 0;

        int end = n;
        while (n >= 0 && s[n] != ' ') n--;

        // cout << end << n << endl;
        return end - n;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("c   ");
}