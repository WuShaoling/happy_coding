#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[1] == b[1]) return a[0] < b[0];
                 return a[1] < b[1];
             });

        int ans = 0;
        vector<int> pre = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= pre[1]) {
                pre = intervals[i];
                continue;
            }
            ans++;
        }
        return ans;
    }
};

int main() {}