#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double h = hour * 30 + minutes * 30.0 / 60.0;
        double m = 6.0 * minutes;

        double res = fabs(h - m);
        if (res > 180) res = 360 - res;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.angleClock(3, 15);
}