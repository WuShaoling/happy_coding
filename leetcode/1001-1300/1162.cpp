#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) q.push({i, j});
            }
        }

        int x = -1, y = -1;
        bool hasOcean = false;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = dir[i][0] + x;
                int newY = dir[i][1] + y;
                if (newX >= m || newX < 0 || newY < 0 || newY >= n ||
                    grid[newX][newY] != 0)
                    continue;
                grid[newX][newY] = grid[x][y] + 1;
                q.push({newX, newY});
                hasOcean = true;
            }
        }

        if (!hasOcean || x == -1 || y == -1) return -1;
        return grid[x][y];
    }
};

int main() {}