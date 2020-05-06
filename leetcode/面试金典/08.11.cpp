#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int waysToChange(int n) {
        vector<int> coins = {1, 5, 10, 25};

        int dp[4][n + 1];
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;  // 可选硬币为 0
        }
        for (int i = 0; i < 4; i++) {  // 金额为 0
            dp[i][0] = 1;
        }

        for (int i = 1; i < 4; i++) {
            for (int j = 1; j <= n; j++) {
                if (j < coins[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] =
                        dp[i - 1][j] + dp[i][j - coins[i]] % 1000000007;
                }
            }
        }

        return dp[3][n];
    }
};

int main() {
    Solution s;
    cout << s.waysToChange(5);
}