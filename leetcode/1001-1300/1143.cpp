#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Solution {
//    public:
//     int longestCommonSubsequence(string text1, string text2) {
//         if (text1.size() == 0 || text2.size() == 0) return 0;

//         int m = text1.size();
//         int n = text2.size();

//         int dp[n + 1];
//         for (int i = 0; i <= n; i++) dp[i] = 0;

//         for (int i = 1; i <= m; i++) {
//             int pre = 0;
//             for (int j = 1; j <= n; j++) {
//                 int temp = dp[j];
//                 if (text1[i - 1] == text2[j - 1]) {
//                     dp[j] = pre + 1;
//                 } else {
//                     dp[j] = max(pre, dp[j - 1]);
//                 }
//                 pre = temp;
//             }
//         }
//         return dp[n];
//     }
// };

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0) return 0;

        int m = text1.size();
        int n = text2.size();

        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++) dp[i][0] = 0;
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {}