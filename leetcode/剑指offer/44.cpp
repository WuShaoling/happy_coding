#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int findNthDigit(int n) {
        long nn = n;
        long base = 9;
        long digits = 1;
        while (nn - base * digits > 0) {
            nn -= base * digits;
            digits++;
            base *= 10;
        }

        long number = 1;
        for (int i = 1; i < digits; i++) number *= 10;

        int idx = nn % digits;
        if (idx == 0) {
            number += nn / digits - 1;
            return number % 10;
        } else {
            number += nn / digits;
            return to_string(number)[idx - 1] - '0';
        }
    }
};

// n = 5
//         9
// 123456789 10 11 12 13 ... 99
int main() {
    Solution s;
    cout << s.findNthDigit(10) << endl;
}