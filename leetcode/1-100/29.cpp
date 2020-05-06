#include <iostream>

using namespace std;

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;

        int positive = 1;
        if (dividend < 0) positive = -positive;
        if (divisor < 0) positive = -positive;

        long a = (long)abs(dividend);
        long b = (long)abs(divisor);

        int res = div(a, b);
        return res * positive;
    }

    int div(long a, long b) {
        if (a < b) return 0;
        long count = 1;
        long tb = b;
        while ((tb + tb) <= a) {
            count += count;
            tb += tb;
        }
        return count + div(a - tb, b);
    }
};

int main() {}