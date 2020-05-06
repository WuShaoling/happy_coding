#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int r = 0; r < m; r++) {
                        if (matrix[r][j] != 0) {
                            matrix[r][j] = INT_MIN;
                        }
                    }
                    for (int c = 0; c < n; c++) {
                        if (matrix[i][c] != 0) {
                            matrix[i][c] = INT_MIN;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INT_MIN) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {}
