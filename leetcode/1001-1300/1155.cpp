#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numRollsToTarget(int d, int f, int target) {
        // dp[i][j] 表示 i 个骰子抛出 target 的方法数
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));

        for (int i = 1; i <= target; i++) dp[1][i] = 1;

        for (int i = 2; i <= d; i++) {
            for (int j = i; j <= target; j++) {
                for (int k = 1; k <= f && k <= j; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000007;
                }
            }
        }

        return dp[d][target];
    }
};

int main() {}