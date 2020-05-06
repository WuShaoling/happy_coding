#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int maxScore(string s) {
        int rightOne = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') rightOne++;
        }

        int ans = 0;
        int leftZero = (s[0] == '0' ? 1 : 0);
        for (int i = 1; i < s.size(); i++) {
            ans = max(ans, leftZero + rightOne);
            if (s[i] == '0') {
                leftZero++;
            } else {
                rightOne--;
            }
        }

        return ans;
    }
};
