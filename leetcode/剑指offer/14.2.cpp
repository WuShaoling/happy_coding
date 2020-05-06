#include <iostream>
#include <cmath>

using namespace std;

class Solution {
   public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        if (n % 3 == 1) {
            long t = 4 * qPow(3, (n - 4) / 3);
            return t % mod;
        }

        if (n % 3 == 2) {
            long t = 2 * qPow(3, (n - 2) / 3);
            return t % mod;
        }

        return qPow(3, n / 3);
    }

   private:
    long qPow(int x, int n) {
        long base = x;
        long res = 1;
        while (n) {
            if (n & 1) res = (res * base) % mod;
            base %= mod;
            base = (base * base) % mod;
            n >>= 1;
        }
        return res % mod;
    }

    int mod = 1000000007;
};

int main() {
    Solution s;
    cout << s.cuttingRope(120);
}