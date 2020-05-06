#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 1;

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 1));
        if (dungeon[m - 1][n - 1] <= 0)
            dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];

        for (int i = m - 2; i >= 0; i--) {  // 最后一列
            if (dungeon[i][n - 1] < 0 || dungeon[i][n - 1] < dp[i + 1][n - 1]) {
                dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (dungeon[m - 1][i] < 0 || dungeon[m - 1][i] < dp[m - 1][i + 1]) {
                dp[m - 1][i] = dp[m - 1][i + 1] - dungeon[m - 1][i];
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int n1 = 1;
                if (dungeon[i][j] < 0 || dungeon[i][j] < dp[i + 1][j]) {
                    n1 = dp[i + 1][j] - dungeon[i][j];
                }
                int n2 = 1;
                if (dungeon[i][j] < 0 || dungeon[i][j] < dp[i][j + 1]) {
                    n2 = dp[i][j + 1] - dungeon[i][j];
                }
                dp[i][j] = min(n1, n2);
            }
        }
        return dp[0][0];
    }
};

int main() {}