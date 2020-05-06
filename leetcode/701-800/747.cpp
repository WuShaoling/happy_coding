#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max1Idx = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                max1Idx = i;
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }

        if (max2 * 2 <= max1) {
            return max1Idx;
        }
        return -1;
    }
};
