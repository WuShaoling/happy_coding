#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        double res = 1.0;
        int i = n;

        while (i) {
            if (i & 1) res *= x;
            x *= x;
            i /= 2;
            cout << res << endl;
        }

        return n < 0 ? 1 / res : res;
    }
};

int main() {
    Solution s;
    cout << s.myPow(2.0, -2147483648);
}
