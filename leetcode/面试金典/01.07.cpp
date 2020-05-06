#include <iostream>
#include <string>
#include <vector>
using namespace std;

void show(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;

        int row = matrix.size();
        int col = matrix[0].size();

        // 上下翻转
        for (int i = 0, j = row - 1; i < j; i++, j--) {
            for (int k = 0; k < col; k++) {
                swap(matrix[i][k], matrix[j][k]);
            }
        }

        // 对角线翻转
        for (int i = 0; i < row; i++) {
            for (int j = i; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix =
        // {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    s.rotate(matrix);
    show(matrix);
}