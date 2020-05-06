#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        int n = matrix[0].size();
        vector<int> dp(n + 1, 0);

        int res = 0, pre = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                int temp = dp[j];
                if (matrix[i][j - 1] == '1') {
                    dp[j] = min(min(dp[j], dp[j - 1]), pre) + 1;
                    res = max(res, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }

        return res * res;
    }
    // int maximalSquare(vector<vector<char>>& matrix) {
    //     if (matrix.size() == 0) return 0;

    //     int dp[matrix.size() + 1][matrix[0].size() + 1];
    //     memset(dp, 0,
    //            sizeof(int) * (matrix.size() + 1) * (matrix[0].size() + 1));

    //     int res = 0;
    //     for (int i = 1; i <= matrix.size(); i++) {
    //         for (int j = 1; j <= matrix[0].size(); j++) {
    //             if (matrix[i - 1][j - 1] != '1') continue;
    //             dp[i][j] =
    //                 min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) +
    //                 1;
    //             res = max(dp[i][j], res);
    //         }
    //     }

    //     return res * res;
    // }
};

int main() {}