#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class Solution {
//    public:
//     int rob(vector<int>& nums) {
//         if (nums.size() == 0) return 0;
//         if (nums.size == 1) return nums[1];

//         int dp[nums.size()];
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);

//         for (int i = 2; i < nums.size(); i++) {
//             nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
//         }

//         return nums[nums.size() - 1];
//     }
// };

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> path;
        helper(nums, 0, 0);
        return maxSum;
    }

    void helper(vector<int>& nums, int index, int sum) {
        if (index >= nums.size()) {
            if (sum > maxSum) maxSum = sum;
            return;
        }

        helper(nums, index + 1, sum);
        helper(nums, index + 2, sum + nums[index]);
    }

    int maxSum = 0;
};

int main() {
    Solution s;
    vector<int> nums = {114, 117, 207, 117, 235, 82,  90,  67,  143, 146,
                        53,  108, 200, 91,  80,  223, 58,  170, 110, 236,
                        81,  90,  222, 160, 165, 195, 187, 199, 114, 235,
                        197, 187, 69,  129, 64,  214, 228, 78,  188, 67,
                        205, 94,  205, 169, 241, 202, 144, 240};
    cout << s.rob(nums);
}