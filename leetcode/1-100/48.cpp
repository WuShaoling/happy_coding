#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        // 上下翻转
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;

        for (int i = 0, j = row - 1; i < j; i++, j--) {
            for (int k = 0; k < col; k++) {
                swap(matrix[i][k], matrix[j][k]);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

/*

789
456
123

*/

int main() {}