#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, backtrack(grid, m, n, i, j));
                }
            }
        }
        return ans;
    }

    int backtrack(vector<vector<int>>& grid, int m, int n, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;

        int backup = grid[x][y];
        grid[x][y] = 0;

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nextX = dir[i][0] + x;
            int nextY = dir[i][1] + y;
            if (isArea(m, n, nextX, nextY))
                ans = max(ans, backtrack(grid, m, n, nextX, nextY));
        }

        grid[x][y] = backup;
        return ans + backup;
    }

    bool isArea(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main() {}