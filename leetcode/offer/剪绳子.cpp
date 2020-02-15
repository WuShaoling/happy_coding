#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int cutRope(int number) {
        if (number <= 0) return 0;

        if (number <= 3) return number;

        if (number % 3 == 0) {
            int n = number / 3;
            return pow(3, n);
        } else if (number % 3 == 1) {
            int t = number - 4;
            int n = t / 3;
            return pow(3, n) * 4;
        } else if (number % 3 == 2) {
            int t = number - 2;
            int n = t / 3;
            return pow(3, n) * 2;
        }
        return 0;
    }
};

int main() {}