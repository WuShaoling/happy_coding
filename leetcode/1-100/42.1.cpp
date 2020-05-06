#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int n = height.size();

        vector<int> right(n);
        right[n - 1] = 0;
        int rightMax = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
        }

        int leftMax = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            leftMax = max(leftMax, height[i - 1]);
            int minH = min(leftMax, right[i]);
            if (minH > height[i]) {
                ans += minH - height[i];
            }
        }
        return ans;
    }
};

int main() {}