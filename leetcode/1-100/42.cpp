#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int n = height.size();

        vector<int> rightMax(height.size());
        rightMax[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }

        int leftMax = 0;
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            leftMax = max(leftMax, height[i - 1]);
            int lowBound = min(leftMax, rightMax[i]);
            if (height[i] < lowBound) {
                res += (lowBound - height[i]);
            }
        }
        return res;
    }
};
//       5 0
// 1 2 3 4 5

int main() {
    Solution s;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(v);
}