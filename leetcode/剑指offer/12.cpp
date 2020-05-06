#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (find(board, visited, i, j, m, n, word, 0)) return true;
                }
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, vector<vector<bool>>& visited, int x,
              int y, int m, int n, string word, int index) {
        if (index == word.size()) return true;

        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
            board[x][y] != word[index])
            return false;
        visited[x][y] = true;
        if (find(board, visited, x + 1, y, m, n, word, index + 1)) {
            return true;
        }
        if (find(board, visited, x - 1, y, m, n, word, index + 1)) {
            return true;
        }
        if (find(board, visited, x, y + 1, m, n, word, index + 1)) {
            return true;
        }
        if (find(board, visited, x, y - 1, m, n, word, index + 1)) {
            return true;
        }
        visited[x][y] = false;
        return false;
    }
};

int main() {}
