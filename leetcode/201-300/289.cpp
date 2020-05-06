#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = getAlive(board, i, j);
                if (board[i][j] == 1 && (cnt == 2 || cnt == 3)) board[i][j] = 3;
                if (board[i][j] == 0 && cnt == 3) board[i][j] = 2;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }

    int getAlive(vector<vector<int>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        int dir[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                         {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
            cnt += board[newX][newY] & 1;
        }
        return cnt;
    }
};

int main() {}