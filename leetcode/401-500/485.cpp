#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxOne = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                dp[i] = 0;
            } else {
                dp[i] = dp[i - 1] + 1;
                maxOne = max(maxOne, dp[i]);
            }
        }

        return maxOne;
    }
};

int main() {}