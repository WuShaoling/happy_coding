#include <iostream>
#include <map>
#include <string>
using namespace std;

// struct item {
//     int numerator;
//     int denominator;
//     item(int num, int den) {
//         numerator = num;
//         denominator = den;
//     }
// };

class Solution {
   public:
    string fractionToDecimal(int numerator, int denominator) {
        // int n = 0;
        // while (numerator < denominator) {
        //     n++;
        //     numerator *= 10;
        // }
        char c[100];

        double t = (double)numerator / (double)denominator;
        if (t * denominator == 1.0 * numerator) {
            sprintf(c, "%g", numerator * 1.0 / denominator);
        }

        // int num = numerator;
        // int den = denominator;
        // while (num < den) num *= 10;
        // if (num % den == 0) {
        //     sprintf(c, "%g", numerator * 1.0 / denominator);
        // }

        // string cur = "";
        // while (1) {
        //     while (numerator < denominator) {
        //         numerator *= 10;
        //     }

        //     string key = to_string(numerator) + "/" + to_string(denominator);
        //     if (mm.find(key) != mm.end()) {  // 出现循环
        //         // TODO
        //     }

        //     int mod = numerator % denominator;
        //     if (mod == 0) {  //除尽了，返回结果
        //         cur += to_string(numerator / denominator);
        //         return hanlerDot(num, den, cur);
        //     }

        //     numerator = mod;
        // }
        return string(c);
    }

    // string hanlerDot(int numerator, int denominator, string cur) {
    //     int n = 0;
    //     while (numerator < denominator) {
    //         n++;
    //         numerator *= 10;
    //         cur = "0" + cur;
    //     }

    //     return "";
    // }

    map<string, bool> mm;
};

int main() {
    Solution s;
    cout << s.fractionToDecimal(10, 4);
}