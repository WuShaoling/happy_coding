#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int Row = matrix.size();
        int Col = matrix[0].size();

        vector<int> cols[Col];
        for (int row = 0; row < Row; row++) {
            int min_value = INT_MAX, min_col = 0;
            for (int col = 0; col < Col; col++) {
                if (matrix[row][col] < min_value) {
                    min_value = matrix[row][col];
                    min_col = col;
                }
            }
            cols[min_col].push_back(row);
        }
        vector<int> res;

        // 对于每一列
        for (int col = 0; col < Col; col++) {
            vector<int> rows = cols[col];

            cout << col << ": ";
            for (int x : rows) cout << x << " ";
            cout << endl;

            if (!rows.empty()) {
                int max_value = INT_MIN, max_row = 0;
                for (int row = 0; row < Row; row++) {
                    if (matrix[row][col] > max_value) {
                        max_value = matrix[row][col];
                        max_row = row;
                    }
                }
                if (find(rows.begin(), rows.end(), max_row) != rows.end()) {
                    res.push_back(matrix[max_row][col]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    s.luckyNumbers(matrix);
}

/*

[1,10,4,2],
[9,3,8,7],
[15,16,17,12]

*/