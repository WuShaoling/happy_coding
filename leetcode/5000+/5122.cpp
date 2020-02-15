#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] == -1 && intervals[i][1] == -1) continue;
            for (int j = 0; j < intervals.size(); j++) {
                if (intervals[j][0] == -1 && intervals[j][1] == -1) continue;
                if (j == i) continue;
                if (intervals[i][0] <= intervals[j][0] &&
                    intervals[i][1] >= intervals[j][1]) {
                    intervals[j][0] = -1;
                    intervals[j][1] = -1;
                }
            }
        }
        int res = 0;
        for (vector<int> v : intervals) {
            cout << v[0] << " " << v[1] << endl;
            if (v[0] != -1 && v[1] != -1) res++;
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    s.removeCoveredIntervals(intervals);
}