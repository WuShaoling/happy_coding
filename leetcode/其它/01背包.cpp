#include <iostream>
#include <vector>

using namespace std;

class Knapsack {
   public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                      int capacity) {
        int n = weights.size();
        int dp[n + 1][capacity + 1];

        // 如果背包容量为0，不管有多少件物品，价值都为0
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        // 如果选择0件物品，不管有大的背包，价值都为0
        for (int i = 0; i <= capacity; i++) dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {             // 对于每一个物品
            for (int c = 1; c <= capacity; c++) {  // 对于每一种容量
                // 如果当前物品的重量小于等于背包容量
                if (weights[i - 1] <= c) {
                    dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - weights[i - 1]] +
                                                     profits[i - 1]);
                } else {
                    dp[i][c] = dp[i - 1][c];
                }
            }
        }

        return dp[n][capacity];

        // int w = weights.size();
        // int dp[w][capacity + 1];

        // for (int c = 0; c <= capacity; c++) {
        //     if (weights[0] <= capacity)
        //         dp[0][c] = profits[0];
        //     else
        //         dp[0][c] = 0;
        // }

        // for (int i = 1; i < w; i++) {
        //     for (int c = 1; c <= capacity; c++) {
        //         if (weights[i] <= c) {  // 如果物品的重量小于等于背包容量
        //             dp[i][c] = max(dp[i - 1][c],
        //                            dp[i - 1][c - weights[i]] + profits[i]);
        //         } else {
        //             dp[i][c] = dp[i - 1][c];
        //         }
        //     }
        // }

        // return dp[n - 1][capacity];
    }
};

int main(int argc, char *argv[]) {
    Knapsack ks;
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    int maxProfit = ks.solveKnapsack(profits, weights, 6);
    cout << "Total knapsack profit ---> " << maxProfit << endl;
    maxProfit = ks.solveKnapsack(profits, weights, 7);
    cout << "Total knapsack profit ---> " << maxProfit << endl;
}