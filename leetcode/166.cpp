#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        if (denominator == 1) {
            return std::to_string(numerator);
        }
        if (denominator == 0) {
            return "";
        }

        



    }
};

int main() {}