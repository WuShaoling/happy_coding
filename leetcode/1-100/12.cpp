#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string intToRoman(int num) {
        init();
        string res = "";
        int ten = 1;
        while (num > 0) {
            int n = num % 10;
            if (n >= 1 && n <= 3) {
                for (int i = 1; i <= n; i++) res = mm[ten] + res;
            } else if (n == 4) {
                res = mm[ten] + mm[5 * ten] + res;
            } else if (n == 5) {
                res = mm[5 * ten] + res;
            } else if (n >= 6 && n <= 8) {
                string t = mm[5 * ten];
                for (int i = 6; i <= n; i++) t += mm[ten];
                res = t + res;
            } else if (n == 9) {
                res = mm[ten * 1] + mm[10 * ten] + res;
            }
            num /= 10;
            ten *= 10;
        }
        return res;
    }

   private:
    void init() {
        mm[1] = "I";
        mm[5] = "V";
        mm[10] = "X";
        mm[50] = "L";
        mm[100] = "C";
        mm[500] = "D";
        mm[1000] = "M";
    }

    map<int, string> mm;
};

int main() {
    Solution s;
    cout << s.intToRoman(10);
}