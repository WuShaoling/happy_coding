#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if (len == 0) {
            if (amount == 0) return 1;
            return 0;
        }

        vector<vector<int>> dp(len, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = coins[0]; i <= amount; i += coins[0]) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i]) {
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }

        return dp[len - 1][amount];
    }
};

int main() {
    Solution s;
    vector<int> coins = {10};
    cout << s.change(10, coins);
}