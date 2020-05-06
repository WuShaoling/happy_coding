#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int left, int right) {
        if (left > right) return 0;
        if (left == right) return nums[left];

        int mid = left + (right - left) / 2;
        int leftMax = helper(nums, left, mid);
        int rightMax = helper(nums, mid + 1, right);
        int crossMax = getCrossMax(nums, left, right, mid);

        return max(crossMax, max(leftMax, rightMax));
    }

    int getCrossMax(vector<int>& nums, int left, int right, int mid) {
        if (left > right) return 0;
        if (left == right) return nums[left];

        int leftMax = INT_MIN;
        int cur = 0;
        for (int i = mid; i >= left; i--) {
            cur += nums[i];
            leftMax = max(leftMax, cur);
        }

        int rightMax = INT_MIN;
        cur = 0;
        for (int i = mid + 1; i <= right; i++) {
            cur += nums[i];
            rightMax = max(rightMax, cur);
        }

        return leftMax + rightMax;
    }
};

int main() {}