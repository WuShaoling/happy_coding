#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    // res = max(res, bfs(grid, visited, m, n, i, j));
                    res = max(res, dfs(grid, visited, m, n, i, j));
                }
            }
        }
        return res;
    }

   private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m,
            int n, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
            grid[x][y] == 0) {
            return 0;
        }

        int res = 1;
        visited[x][y] = true;

        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            res += dfs(grid, visited, m, n, x + d[i][0], y + d[i][1]);
        }
        return res;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m,
            int n, int x, int y) {
        // 第一个位置都不满足，直接返回
        if (visited[x][y] || grid[x][y] == 0) return 0;

        int res = 0;

        queue<pair<int, int>> q;
        // 初始化第一个节点
        q.push({x, y});
        visited[x][y] = true;
        res++;

        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            // 分别找4个方向的点
            for (int i = 0; i < 4; i++) {
                int a = t.first + d[i][0];
                int b = t.second + d[i][1];
                if (a >= 0 && a < m && b >= 0 && b < n && !visited[a][b] &&
                    grid[a][b] == 1) {
                    q.push({a, b});
                    visited[a][b] = true;
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {}