#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int balancedStringSplit(string s) {
        if (s.size() == 0) return 0;

        int count = 0;
        int R = 0, L = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') R++;
            if (s[i] == 'L') L++;
            if (R == L) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    cout << s.balancedStringSplit("RLRRRLLRLL") << endl;
}