#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size() + 1;
        int n = word2.size() + 1;

        int dp[m][n];
        dp[0][0] = 0;
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + 1;
        for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int m = min(dp[i - 1][j], dp[i][j - 1]);
                    m = min(m, dp[i - 1][j - 1]);
                    dp[i][j] = m + 1;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
int main() {
    Solution s;
    cout << s.minDistance("islander", "slander");
}