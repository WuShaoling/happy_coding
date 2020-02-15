#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        char str[s.size() + 1];
        sprintf(str, "%s", s.c_str());

        int fast = 0;
        int slow = 0;
        while (true) {
            while (slow < s.size() && str[slow] == ' ') slow++;
            fast = slow;
            while (fast < s.size() && str[fast] != ' ') fast++;
            if (fast == slow) break;

            for (int i = slow, j = fast - 1; i < j; i++, j--) {
                char t = str[i];
                str[i] = str[j];
                str[j] = t;
            }
            
            slow = fast;
        }
        return string(str);
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("ab ab ") + "-";
}