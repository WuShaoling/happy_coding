#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<int> ans;
        bottomToUp(0, 0, matrix.size(), matrix[0].size(), matrix, ans);
        return ans;
    }

    void bottomToUp(int x, int y, int row, int col, vector<vector<int>>& matrix,
                    vector<int>& ans) {
        if (x < 0 || x >= row || y < 0 || y >= col) return;
        while (x >= 0 && y < col) {
            ans.push_back(matrix[x][y]);
            x--, y++;
        }
        x++, y--;
        if (y + 1 < col) {  // 优先向右移动
            y++;
        } else if (x + 1 < row) {  // 否则向下移动
            x++;
        } else {
            return;
        }
        upTobottom(x, y, row, col, matrix, ans);
    }

    void upTobottom(int x, int y, int row, int col, vector<vector<int>>& matrix,
                    vector<int>& ans) {
        if (x < 0 || x >= row || y < 0 || y >= col) return;
        while (x < row && y >= 0) {
            ans.push_back(matrix[x][y]);
            x++, y--;
        }
        x--, y++;
        if (x + 1 < row) {  // 优先向下移动
            x++;
        } else if (y + 1 < col) {  // 向右移动
            y++;
        } else {
            return;
        }
        bottomToUp(x, y, row, col, matrix, ans);
    }
};

/*
00
10 01
20 11 02
21 12
22

1 2 3
4 5 6
7 8 9

1 2 3 4
5 6 7 8

2 3

2
3

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
*/

int main() {
    Solution s;
    // vector<vector<int>> matrix = {
    //     {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    vector<vector<int>> matrix = {{1, 2, 3, 4}};
    vector<int> ans = s.findDiagonalOrder(matrix);
    for (int i : ans) cout << i << " ";
}