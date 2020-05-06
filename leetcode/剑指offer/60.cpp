#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
   public:
    vector<double> twoSum(int n) {
        int num = n * 6;
        vector<int> dp(num + 1, 0);

        // 初始化1个骰子的情况
        for (int i = 1; i <= 6; i++) dp[i] = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> bk(num + 1, 0);
            for (int j = 6 * i; j >= i; j--) {
                dp[j] = 0;
                for (int k = 1; k <= 6 && j - k >= 0; k++) {
                    bk[j] += dp[j - k];
                }
            }
            dp = bk;
        }

        int sum = pow(6, n);
        vector<double> res;
        for (int i = n; i <= num; i++) {
            res.push_back(1.0 * dp[i] / sum);
        }
        return res;
    }

    // vector<double> twoSum(int n) {
    //     int num = n * 6;
    //     vector<vector<int>> dp(n + 1, vector<int>(num + 1, 0));

    //     for (int i = 1; i <= 6; i++) dp[1][i] = 1;
    //     for (int i = 2; i <= n; i++) {
    //         for (int j = i; j <= i * 6; j++) {
    //             // 前一个骰子抛出j-k点，当前抛出k点
    //             for (int k = 1; k <= 6 && k <= j; k++) {
    //                 dp[i][j] += dp[i - 1][j - k];
    //             }
    //         }
    //     }
    //     int sum = 0;
    //     for (int i = n; i <= num; i++) sum += dp[n][i];

    //     vector<double> res;
    //     for (int i = n; i <= num; i++) {
    //         if (dp[n][i] != 0) {
    //             res.push_back(1.0 * dp[n][i] / sum);
    //         }
    //     }
    //     return res;
    // }
};

int main() {
    Solution s;
    vector<double> res = s.twoSum(3);
    for (double d : res) cout << d << " ";
}

// [0.00463,0.01389,0.02778,0.04630,0.06944,0.09722,0.11574,0.12500,0.12500,0.11574,0.09722,0.06944,0.04630,0.02778,0.01389,0.00463]