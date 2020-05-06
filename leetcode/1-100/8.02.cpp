#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> res;

        int row = obstacleGrid.size();
        if (row == 0) return res;
        int col = obstacleGrid[0].size();
        if (col == 0) return res;

        // 起点或终点是障碍，不可能到达
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1)
            return res;

        int dp[row + 1][col + 1];
        dp[0][0] = 1;
        // 初始化首列
        for (int i = 1; i < row; i++) {
            if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i - 1][0];
        }
        // 初始化首行
        for (int i = 1; i < col; i++) {
            if (obstacleGrid[0][i] == 1) dp[0][i] = 0;
            else dp[0][i] = dp[0][i - 1];
        }
        // 求路径
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else { // 无需保存和，保存最大的即可
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 到达终点的路径为0，直接返回
        if (dp[row - 1][col - 1] == 0) return res;

        // 从终点反推回起点
        int r = row - 1, c = col - 1;
        while (r != 0 || c != 0) {
            res.push_back({r, c});

            int up = 0;
            if (r > 0) up = dp[r - 1][c];

            int left = 0;
            if (c > 0) left = dp[r][c - 1];

            if (up >= left)
                r--;
            else
                c--;
        }
        res.push_back({0, 0});
        // 注意路径反转
        reverse(res.begin(), res.end());
        return res;
    }
};

// class Solution {
//    public:
//     vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid)
//     {
//         int row = obstacleGrid.size();
//         if (row == 0) return res;
//         int col = obstacleGrid[0].size();
//         find(obstacleGrid, row, col, 0, 0);
//         return res;
//     }

//     bool find(vector<vector<int>>& obstacleGrid, int row, int col, int r,
//               int c) {
//         if (r >= row || c >= col || obstacleGrid[r][c] == 1) return false;

//         res.push_back({r, c});

//         if (r == row - 1 && c == col - 1) return true;

//         if (c + 1 < col && obstacleGrid[r][c + 1] == 0) {
//             if (find(obstacleGrid, row, col, r, c + 1)) return true;
//         }

//         if (r + 1 < row && obstacleGrid[r + 1][c] == 0) {
//             if (find(obstacleGrid, row, col, r + 1, c)) return true;
//         }

//         res.pop_back();
//         return false;
//     }

//     vector<vector<int>> res;
// };

int main() {}