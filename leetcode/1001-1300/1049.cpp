#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i : stones) sum += i;

        int capacity = sum / 2;

        vector<int> dp(capacity + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            int stone = stones[i];
            for (int j = capacity; j >= capacity - stone; j--) {
                dp[j] = max(dp[j - 1], dp[j - stone] + stone);
            }
        }
        return sum - dp[capacity] * 2;
    }
};

// class Solution {
//    public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int sum = 0;
//         for (int i : stones) sum += i;

//         int capacity = sum / 2;

//         vector<vector<int>> dp(stones.size(), vector<int>(capacity + 1, 0));
//         for (int i = 0; i <= capacity; i++) {  // 如果背包大于等于重量，价值
//             if (i >= stones[0]) dp[0][i] = stones[0];
//         }
//         for (int i = 0; i < stones.size(); i++) {  // 容量为0，最大价值为0
//             dp[i][0] = 0;
//         }
//         for (int i = 1; i < stones.size(); i++) {
//             int stone = stones[i];
//             for (int j = 1; j <= capacity; j++) {
//                 if (j >= stone) {
//                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stone] +
//                     stone);
//                 } else {
//                     dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }
//         return sum - dp[stones.size() - 1][capacity] * 2;
//     }
// };

int main() {}