#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int> >& points) {
        if (points.size() == 0) return 0;
        if (points.size() == 1) return 1;

        int ret = 0;
        for (int i = 1; i < points.size(); i++) {
            vector<int> p1 = points[i - 1];
            vector<int> p2 = points[i];
            if (p1[0] - p2[0] == 0) {
                ret += abs(p1[1] - p2[1]);
            } else if (p1[1] - p2[1] == 0) {
                ret += abs(p1[0] - p2[0]);
            } else {
                ret += max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]));
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int> > points = {{3,2}, {-2,2}};
    cout << s.minTimeToVisitAllPoints(points);
}