#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(int max_k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        if (max_k > n / 2) return maxProfitWithoutK(prices);

        int dp[n][max_k + 1][2];
        memset(dp, 0, sizeof(int) * n * 2 * (max_k + 1));

        for (int i = 0; i < n; i++) {
            for (int k = max_k; k >= 1; k--) {
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

        return dp[n - 1][max_k][0];
    }

    /*
        base case：
        dp[-1][k][0] = dp[i][0][0] = 0;
        dp[-1][k][1] = dp[i][0][1] = INT_MIN;

        状态转移方程：
        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
    */

    int maxProfitWithoutK(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        memset(dp, 0, sizeof(int) * n * 2);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][0];
    }
};

int main() {}