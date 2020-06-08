#include <cmath>
#include <iostream>

using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        bool positive = (n >= 0);
        double ans = doMyPow(x, abs((long)n));

        if (!positive) return 1.0 / ans;
        return ans;
    }

    double doMyPow(double x, long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double t = doMyPow(x, n >> 1);
        if (n & 1) return t * t * x;
        return t * t;
    }
};

int main() {
    Solution s;
    cout << s.myPow(2.00000, 10);
}
