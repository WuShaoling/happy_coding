#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            if (!checkRow(board, row)) return false;
        }

        for (int col = 0; col < 9; col++) {
            if (!checkCol(board, col)) return false;
        }

        if (!checkGrid(board)) return false;

        return true;
    }

    bool checkRow(vector<vector<char>>& board, int row) {
        int flag[10] = {0};
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') continue;

            int n = board[row][col] - '0';
            if (flag[n] != 0) return false;
            flag[n] = 1;
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int col) {
        int flag[10] = {0};
        for (int row = 0; row < 9; row++) {
            if (board[row][col] == '.') continue;

            int n = board[row][col] - '0';
            if (flag[n] != 0) return false;
            flag[n] = 1;
        }
        return true;
    }

    bool checkGrid(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int flag[10] = {0};
                for (int a = i; a < i + 3; a++) {
                    for (int b = j; b < j + 3; b++) {
                        if (board[a][b] == '.') continue;
                        
                        int n = board[a][b] - '0';
                        if (flag[n] != 0) return false;
                        flag[n] = 1;
                    }
                }
            }
        }
        return true;
    }
};

int main();