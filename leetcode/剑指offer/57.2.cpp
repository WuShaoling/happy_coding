#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if (target <= 2) return res;

        int left = 1;
        int right = 2;
        while (right < target) {
            int n = right - left + 1;
            long sum = (long)(left + right) * n / 2;
            if (sum > target) {
                left++;
            } else if (sum < target) {
                right++;
            } else {
                // cout << left << " " << right << endl;
                vector<int> line;
                for (int i = left; i <= right; i++) {
                    line.push_back(i);
                }
                res.push_back(line);
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.findContinuousSequence(100000);
    for (auto line : res) {
        for (auto i : line) cout << i << ',';
        cout << endl;
    }
}