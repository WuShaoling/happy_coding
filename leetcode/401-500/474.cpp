#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.size() == 0) return 0;

        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(int) * (m + 1) * (n + 1));

        for (string str : strs) {
            int zero = 0, one = 0;
            countZreoAndOne(str, zero, one);
            for (int j = m; j >= zero; j--) {
                for (int k = n; k >= one; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }

        return dp[m][n];
    }

    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     int len = strs.size();
    //     if (len == 0) return 0;

    //     int dp[len + 1][m + 1][n + 1];
    //     memset(dp, 0, sizeof(int) * (len + 1) * (m + 1) * (n + 1));

    //     for (int i = 1; i <= len; i++) {
    //         int zero = 0, one = 0;
    //         countZreoAndOne(strs[i - 1], zero, one);
    //         for (int j = 0; j <= m; j++) {
    //             for (int k = 0; k <= n; k++) {
    //                 dp[i][j][k] = dp[i - 1][j][k];
    //                 if (j >= zero && k >= one) {
    //                     dp[i][j][k] = max(dp[i - 1][j][k],
    //                                       dp[i - 1][j - zero][k - one] + 1);
    //                 }
    //             }
    //         }
    //     }

    //     return dp[len][m][n];
    // }

    void countZreoAndOne(string str, int& zero, int& one) {
        for (char c : str) {
            if (c == '0')
                zero++;
            else
                one++;
        }
    }
};

int main() {}