#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long ab = lcm(a, b);
        long ac = lcm(a, c);
        long bc = lcm(b, c);
        long abc = lcm(ab, c);
        long left = min(a, min(b, c));
        long right = 2 * 1e9;
        while (left < right) {
            // 求中间的数
            long m = left + (right - left) / 2;
            // 求中间的数是第几个丑数
            int count =
                m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
            if (count < n) {
                left = m + 1;
            } else {
                right = m;
            }
        }
        return left;
    }

    long lcm(long a, long b) { return a * (b / gcd(a, b)); }

    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
};

int main() {}