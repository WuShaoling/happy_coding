#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (k >= m + n - 3) return m + n - 2;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = dfs(grid, visited, k, 0, m, n, 0, 0);

        return ans == INT_MAX ? -1 : ans;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int k,
            int covered, int m, int n, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return INT_MAX;

        if (x == m - 1 && y == n - 1) return covered;

        if (grid[x][y] == 1) {
            if (k > 0)
                k--;
            else
                return INT_MAX;
        }

        visited[x][y] = true;
        int ans = INT_MAX;
        ans = min(ans, dfs(grid, visited, k, covered + 1, m, n, x + 1, y));
        ans = min(ans, dfs(grid, visited, k, covered + 1, m, n, x - 1, y));
        ans = min(ans, dfs(grid, visited, k, covered + 1, m, n, x, y + 1));
        ans = min(ans, dfs(grid, visited, k, covered + 1, m, n, x, y - 1));
        visited[x][y] = false;

        return ans;
    }
};

/*

12
34

*/
