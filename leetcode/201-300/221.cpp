#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        int dp[matrix.size() + 1][matrix[0].size() + 1];
        memset(dp, 0,
               sizeof(int) * (matrix.size() + 1) * (matrix[0].size() + 1));

        int res = 0;
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                if (matrix[i - 1][j - 1] != '1') continue;
                dp[i][j] =
                    min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                res = max(dp[i][j], res);
            }
        }

        return res * res;
    }
};

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         for (int i = 0; i < matrix.size(); i++) {
//             for (int j = 0; j < matrix[i].size(); j++) {
//                 helper(matrix, i, j);
//             }
//         }
//         return _max*_max;
//     }

// private:
//     void helper(vector<vector<char>>& mat, int row, int col) {
//         int curRow = row;
//         int curCol = col;

//         while (curRow < mat.size() && curCol < mat[0].size()) {
//             // 添加新的列
//             for (int i = row; i <= curRow; i++) {
//                 if(mat[i][curCol] != '1') return;
//             }
//             // 添加新的行
//             for (int i = col; i < curCol; i++) {
//                 if( mat[curRow][i] != '1') return;
//             }
//             if (curRow - row + 1 > _max) _max = curRow - row + 1;
//             curRow++;
//             curCol++;
//         }
//     }

//     int _max = 0;
// };

int main() {}