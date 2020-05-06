#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1,
                      int x2, int y2) {
        double x0 = (x1 + x2) / 2.0;
        double y0 = (y1 + y2) / 2.0;

        pair<double, double> p = {fabs(x_center - x0), fabs(y_center - y0)};
        pair<double, double> q = {fabs(x2 - x0), fabs(y2 - y0)};
        pair<double, double> u = {max(p.first - q.first, 0.0),
                                  max(p.second - q.second, 0.0)};

        return sqrt(u.first * u.first + u.second * u.second) <= radius;
    }
};

int main() {}