#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool doTry(vector<vector<int> >& matrix, int row, int col, int len) {
    for (int x = row; x < row + len; x++) {
        for (int y = col; y < col + len; y++) {
            if (matrix[x][y] != 1) {
                return false;
            }
        }
    }
    return true;
}

class Solution {
   public:
    int countSquares(vector<vector<int> >& matrix) {
        if (matrix.size() == 0) return 0;

        int ROW = matrix.size(), COL = matrix[0].size();
        int total = 0;

        for (int row = 0; row < ROW; row++) {
            for (int col = 0; col < COL; col++) {
                if (matrix[row][col] == 0) continue;

                int range = min(ROW - row, COL - col);
                for (int i = 1; i <= range; i++) {
                    if (doTry(matrix, row, col, i)) total++;
                }
            }
        }
        return total;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > matrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << solution.countSquares(matrix);
}