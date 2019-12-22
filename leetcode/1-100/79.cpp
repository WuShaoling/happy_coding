#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        Row = board.size();
        Col = board[0].size();
        for (int i = 0; i < Row; i++) {
            vector<bool> t;
            for (int j = 0; j < Col; j++) t.push_back(false);
            visited.push_back(t);
        }

        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (helper(board, i, j, 0, word)) return true;
            }
        }

        return false;
    }

   private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool helper(vector<vector<char>>& board, int row, int col, int index,
                string word) {
        if (index >= word.size()) return true;

        if (row < 0 || row >= Row || col < 0 || col >= Col ||
            visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            if (helper(board, row + dir[i][0], col + dir[i][1], index + 1,
                       word))
                return true;
        }
        visited[row][col] = false;
        return false;
    }

    int Row = 0, Col = 0;
    vector<vector<bool>> visited;
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'a'}};
    cout << s.exist(board, "a");
}