#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;

        /*
            base case：
            dp[-1][0] = dp[i][0] = 0;
            dp[-1][1] = dp[i][1] = INT_MIN;

            状态转移方程：
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
        */

        int dp[n][2];
        memset(dp, 0, sizeof(int) * n * 2);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i] - fee;
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
            }
        }

        return dp[n - 1][0];
    }
};

int main() {}