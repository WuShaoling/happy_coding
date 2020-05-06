#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

        sort(points.begin(), points.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int preEnd = points[0][1], ans = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > preEnd) {
                ans++;
                preEnd = points[i][1];
            }
        }

        return ans;
    }
};

int main() {}