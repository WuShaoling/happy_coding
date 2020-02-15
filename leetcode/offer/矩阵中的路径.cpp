#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        if (rows == 0 || cols == 0) return false;

        vector<vector<bool>> flag(rows, vector<bool>(cols, false));
        len = strlen(str);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (find(matrix, rows, cols, str, flag, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

   private:
    bool find(char* matrix, int rows, int cols, char* str,
              vector<vector<bool>>& flag, int m, int n, int index) {
        if (index >= strlen(str)) return true;

        if (m >= rows || m < 0 || n >= cols || n < 0 || flag[m][n] ||
            matrix[m * cols + n] != str[index])
            return false;

        flag[m][n] = true;
        if (find(matrix, rows, cols, str, flag, m + 1, n, index + 1))
            return true;
        if (find(matrix, rows, cols, str, flag, m - 1, n, index + 1))
            return true;
        if (find(matrix, rows, cols, str, flag, m, n + 1, index + 1))
            return true;
        if (find(matrix, rows, cols, str, flag, m, n - 1, index + 1))
            return true;
        flag[m][n] = false;

        return false;
    }

    int len = 0;
};

int main() {
    Solution s;
    char* board = "ABCESFCSADEE";
    char* str = "ABCCED";
    cout << s.hasPath(board, 3, 4, str);
}

// ABCE
// SFCS
// ADEE