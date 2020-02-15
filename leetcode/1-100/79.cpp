#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<bool>> flag(board.size(),
                                          vector<bool>(board[0].size(), false));
                if (find(board, word, flag, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool find(vector<vector<char>>& board, string word,
              vector<vector<bool>>& flag, int m, int n, int index) {
        if (index >= word.size()) return true;

        if (m >= board.size() || m < 0 || n >= board[0].size() || n < 0 ||
            flag[m][n] || board[m][n] != word[index])
            return false;

        flag[m][n] = true;
        if (find(board, word, flag, m + 1, n, index + 1)) return true;
        if (find(board, word, flag, m - 1, n, index + 1)) return true;
        if (find(board, word, flag, m, n + 1, index + 1)) return true;
        if (find(board, word, flag, m, n - 1, index + 1)) return true;
        flag[m][n] = false;
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'a', 'a', 'a', 'a'},
                                  {'a', 'a', 'a', 'a'},
                                  {'a', 'a', 'a', 'a'},
                                  {'a', 'a', 'a', 'a'},
                                  {'a', 'a', 'a', 'b'}};

    cout << s.exist(board, "aaaaaaaaaaaaaaaaaaaa");
}
