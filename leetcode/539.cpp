#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

        int _min = 60 * 24 + 5;
        for (int i = 1; i < timePoints.size(); i++) {
            int _diff = diff(timePoints[i - 1], timePoints[i]);
            if (_diff < _min) _min = _diff;
        }

        int e = diff(timePoints[timePoints.size() - 1], "23:59") +
                diff("00:00", timePoints[0]) + 1;

        return e < _min ? e : _min;
    }

   private:
    int diff(string a, string b) {
        int am = ((a[0] - '0') * 10 + (a[1] - '0')) * 60 + (a[3] - '0') * 10 +
                 (a[4] - '0');
        int bm = ((b[0] - '0') * 10 + (b[1] - '0')) * 60 + (b[3] - '0') * 10 +
                 (b[4] - '0');
        return bm - am;
    }
};

int main() {
    Solution s;
    vector<string> timePoints = {"00:02", "00:00", "23:59"};
    cout << s.findMinDifference(timePoints);
}