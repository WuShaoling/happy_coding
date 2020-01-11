#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string freqAlphabets(string s) {
        string res = "";
        int i = s.size() - 1;
        char c;
        for (; i >= 2; i--) {
            if (s[i] == '#') {
                c = 'j' - 10 + (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                i -= 2;
            } else {
                c = 'a' + s[i] - '1';
            }
            res = c + res;
        }
        for (; i >= 0; i--) {
            c = 'a' + s[i] - '1';
            res = c + res;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.freqAlphabets(
        "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#");
}