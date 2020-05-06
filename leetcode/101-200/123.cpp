#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        /*
            base case：
            dp[-1][k][0] = dp[i][0][0] = 0;
            dp[-1][k][1] = dp[i][0][1] = INT_MIN;

            状态转移方程：
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
        */

        int n = prices.size();
        if (n == 0) return 0;

        int K = 2;
        int dp[n][K + 1][2];
        memset(dp, 0, sizeof(int) * n * (K + 1) * 2);

        for (int i = 0; i < n; i++) {
            for (int k = K; k >= 1; k--) {
                if (i == 0) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                } else {
                    dp[i][k][0] =
                        max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                    dp[i][k][1] =
                        max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
                }
            }
        }

        return dp[n - 1][K][0];
    }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     if (n <= 1) return 0;

    //     int minV = prices[0];
    //     vector<int> dp1(n, 0);
    //     for (int i = 1; i < n; i++) {
    //         dp1[i] = max(dp1[i - 1], prices[i] - minV);
    //         minV = min(minV, prices[i]);
    //     }

    //     vector<int> dp2(n, 0);
    //     int maxV = prices[n - 1];
    //     for (int i = n - 2; i >= 0; i--) {
    //         dp2[i] = max(dp2[i + 1], maxV - prices[i]);
    //         maxV = max(maxV, prices[i]);
    //     }

    //     int ans = max(dp1[n - 1], dp2[0]);
    //     for (int i = 1; i < n - 1; i++) {
    //         ans = max(ans, dp1[i] + dp2[i + 1]);
    //     }

    //     return ans;
    // }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(nums);
}