#include <iostream>
#include <cmath>

using namespace std;

class Solution {
   public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        if (n % 3 == 1) {
            n -= 4;
            return 4 * pow(3, n / 3);
        }

        if (n % 3 == 2) {
            n -= 2;
            return 2 * pow(3, n / 3);
        }

        return pow(3, n / 3);
    }
};

int main() {}