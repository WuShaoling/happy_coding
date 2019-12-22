#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();

        int res = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cur = 0;
                dfs(grid, i, j);
                if (cur > res) res = cur;
            }
        }
        return res;
    }

   private:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        if (row >= R || row < 0 || col >= C || col < 0 || grid[row][col] == 0)
            return;

        grid[row][col] = 0;
        cur++;
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
    }

    int cur = 0;
    int R, C;
};

int main() {}