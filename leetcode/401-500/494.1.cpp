#include <iostream>
#include <vector>

using namespace std;

// class Solution2 {
//    public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int sum = 0;
//         for (int num : nums) {
//             sum += num;
//         }
//         if (((sum + S) & 1) == 1) {
//             return 0;
//         }
//         int target = (sum + S) / 2;
//         if (target > sum) return 0;
//         int size = nums.size();
//         int[][] dp = new int[size][target + 1];
//         //动态规划
//         //
//         dp[0][0]这个初始化得看nums[0]的情况，如果nums[0]=0，则可以选也可以不选，如果不等于0，只能不选
//         if (nums[0] == 0) {
//             dp[0][0] = 2;
//         } else if (nums[0] != 0) {
//             dp[0][0] = 1;
//         }
//         for (int i = 1; i <= target; i++) {
//             if (nums[0] == i) {
//                 dp[0][i] = 1;
//                 break;
//             }
//         }
//         for (int i = 1; i < size; i++) {
//             for (int j = 0; j < target + 1; j++) {
//                 if (nums[i] <= j) {
//                     dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
//                 } else {
//                     dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }
//         return dp[size - 1][target];
//     }
// };

class Solution {
   public:
    /**
     *  sum(P) - sum(N) = target
     *  sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
     *  sum(P) = (target + sum(nums)) / 2
     */
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i : nums) sum += i;
        long t = (long)S + (long)sum;
        if (t % 2 == 1 || S > sum) return 0;
        S = (S + sum) / 2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(S + 1, 0));

        // 第一个元素初始化
        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (nums[0] > 0 && nums[0] <= S) dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= S; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i]) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[n - 1][S];
    }

    int findTargetSumWays2(vector<int>& nums, int S) {
        int sum = 0;
        for (int i : nums) sum += i;
        if ((S + sum) % 2 == 1 || S > sum) return 0;
        S = (S + sum) / 2;

        vector<int> dp(S + 1);
        dp[0] = 1;
        for (int i : nums) {
            for (int j = S; j >= i; j--) {
                dp[j] += dp[j - i];
            }
        }
        return dp[S];
    }

    int findTargetSumWays3(vector<int>& nums, int S) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2001, 0));
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 2000; j++) {
                if (j - nums[i] >= 0) dp[i][j] += dp[i - 1][j - nums[i]];
                if (j + nums[i] <= 2000) dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }

        return dp[n - 1][S + 1000];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(nums, 3);
}