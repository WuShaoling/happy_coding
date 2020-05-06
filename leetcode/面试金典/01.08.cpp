#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> rowFlag(row, 1);
        vector<int> colFlag(col, 1);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    rowFlag[i] = 0;
                    colFlag[j] = 0;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rowFlag[i] == 0 || colFlag[j] == 0) matrix[i][j] = 0;
            }
        }
    }
};

/*
[0,1,2,0]
[3,4,5,2]
[1,3,1,5]
*/
int main() {
    Solution s;
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    s.setZeroes(matrix);
}