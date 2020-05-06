#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        while (!q.empty()) {
            vector<int> point = q.front();
            q.pop();
            int x = point[0];
            int y = point[1];
            int minute = point[2];
            res = minute;
            if (x > 0 && grid[x - 1][y] == 1) {  // 上面的
                grid[x - 1][y] = 2;
                q.push({x - 1, y, minute + 1});
            }
            if (x < m - 1 && grid[x + 1][y] == 1) {  // 下面的
                grid[x + 1][y] = 2;
                q.push({x + 1, y, minute + 1});
            }
            if (y > 0 && grid[x][y - 1] == 1) {  // 左面的
                grid[x][y - 1] = 2;
                q.push({x, y - 1, minute + 1});
            }
            if (y < n - 1 && grid[x][y + 1] == 1) {  // 右面的
                grid[x][y + 1] = 2;
                q.push({x, y + 1, minute + 1});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
    // int orangesRotting(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int res = 0;
    //     while (true) {
    //         int count = 0;
    //         vector<vector<bool>> newRotting(m, vector<bool>(n, false));
    //         for (int i = 0; i < m; i++) {
    //             for (int j = 0; j < n; j++) {
    //                 if (grid[i][j] == 1) {
    //                     if (j > 0 && grid[i][j - 1] == 2 &&
    //                         !newRotting[i][j - 1]) {
    //                         grid[i][j] = 2;
    //                         count++;
    //                         newRotting[i][j] = true;
    //                         continue;
    //                     }
    //                     if (j < n - 1 && grid[i][j + 1] == 2 &&
    //                         !newRotting[i][j + 1]) {
    //                         grid[i][j] = 2;
    //                         count++;
    //                         newRotting[i][j] = true;
    //                         continue;
    //                     }
    //                     if (i > 0 && grid[i - 1][j] == 2 &&
    //                         !newRotting[i - 1][j]) {
    //                         grid[i][j] = 2;
    //                         count++;
    //                         newRotting[i][j] = true;
    //                         continue;
    //                     }
    //                     if (i < m - 1 && grid[i + 1][j] == 2 &&
    //                         !newRotting[i + 1][j]) {
    //                         grid[i][j] = 2;
    //                         count++;
    //                         newRotting[i][j] = true;
    //                         continue;
    //                     }
    //                 }
    //             }
    //         }
    //         // cout << count << endl;
    //         if (count == 0) break;
    //         res++;
    //     }
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == 1) return -1;
    //         }
    //     }
    //     return res;
    // }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << s.orangesRotting(v);
}