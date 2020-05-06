#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countEval(string s, int result) {
        if (s.size() == 1) {
            if (result + '0' == s[0]) return 1;
            return 0;
        }

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' || s[i] == '1') continue;

            string left = s.substr(0, i);
            string right = s.substr(i + 1);

            if (mm.find({left, 0}) == mm.end())
                mm[{left, 0}] = countEval(left, 0);
            if (mm.find({left, 1}) == mm.end())
                mm[{left, 1}] = countEval(left, 1);
            if (mm.find({right, 0}) == mm.end())
                mm[{right, 0}] = countEval(right, 0);
            if (mm.find({right, 1}) == mm.end())
                mm[{right, 1}] = countEval(right, 1);

            int left0 = mm[{left, 0}];
            int left1 = mm[{left, 1}];
            int right0 = mm[{right, 0}];
            int right1 = mm[{right, 1}];

            if (s[i] == '&') {
                if (result == 1) {
                    res += left1 * right1;
                } else {
                    res += left0 * right0 + left1 * right0 + left0 * right1;
                }
            } else if (s[i] == '|') {
                if (result == 1) {
                    res += left0 * right1 + left1 * right0 + left1 * right1;
                } else {
                    res += left0 * right0;
                }
            } else if (s[i] == '^') {
                if (result == 1) {
                    res += left0 * right1 + left1 * right0;
                } else {
                    res += left0 * right0 + left1 * right1;
                }
            }
        }
        return res;
    }

   private:
    map<pair<string, int>, int> mm;
};

int main() {}