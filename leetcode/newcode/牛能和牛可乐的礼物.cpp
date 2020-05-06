#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxPresent(vector<int>& presentVec) {
        int size = presentVec.size();

        int sum = 0;
        for (int i = 0; i < size; i++) sum += presentVec[i];

        vector<int> dp(sum / 2 + 1, 0);
        for (int i = 0; i < size; i++) {
            for (int j = sum / 2; j >= presentVec[i]; j--) {
                dp[j] = max(dp[j], dp[j - presentVec[i]] + presentVec[i]);
            }
        }

        int res = 2 * dp[sum / 2] - sum;
        return res >= 0 ? res : -res;
    }
    /**
     *
     * @param presentVec int整型vector 每个礼物的价值
     * @return int整型
     */
    int maxPresent2(vector<int>& presentVec) {
        int n = presentVec.size();
        int sum = 0;
        for (int num : presentVec) sum += num;
        int target = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int c = 1; c <= target; c++) {
                dp[i][c] = dp[i - 1][c];
                if (presentVec[i - 1] <= c) {
                    dp[i][c] =
                        max(dp[i - 1][c], dp[i - 1][c - presentVec[i - 1]] +
                                              presentVec[i - 1]);
                }
            }
        }
        return abs(dp[n][target] * 2 - sum);
    }
};

// i   j
// 1 2 3
//     3

int main() {
    Solution s;
    vector<int> nums = {41, 467, 334, 0, 169, 224, 478, 358, 462, 464, 205};
    cout << s.maxPresent2(nums);
}