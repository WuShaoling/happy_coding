#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthMagicalNumber(int N, int A, int B) {
        long L = A / gcd(A, B) * B;
        long lo = 0;
        long hi = (long)1e15;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            long n = mid / A + mid / B - mid / L;
            if (n < N) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo % 1000000007;
    }

    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
};

int main() {}