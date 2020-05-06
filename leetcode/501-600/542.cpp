#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;

        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // 广度优先搜索
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int ni = p.first + dirs[d][0];
                int nj = p.second + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[p.first][p.second] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

        return dist;
    }

   private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

// class Solution {
//    public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // 如果上下左右没有0
//                 if (matrix[i][j] != 0 &&
//                     !((i + 1 < m && matrix[i + 1][j] == 0) ||
//                       (i - 1 >= 0 && matrix[i - 1][j] == 0) ||
//                       (j + 1 < n && matrix[i][j + 1] == 0) ||
//                       (j - 1 >= 0 && matrix[i][j - 1] == 0))) {
//                     matrix[i][j] = INT_MAX;
//                 }
//             }
//         }

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == 0) {
//                     dfs(matrix, m, n, i, j, 0);
//                 }
//             }
//         }
//         return matrix;
//     }

//    private:
//     void dfs(vector<vector<int>>& matrix, int m, int n, int x, int y, int
//     d)
//     {
//         if (x < 0 || x >= m || y < 0 && y >= n || matrix[x][y] < d)
//         return;

//         matrix[x][y] = d;
//         for (int i = 0; i < 4; i++) {
//             dfs(matrix, m, n, x + dir[i][0], y + dir[i][1], d + 1);
//         }
//     }

//     const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// };

int main() {
    vector<vector<int>> nums = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    Solution s;
    vector<vector<int>> ans = s.updateMatrix(nums);
    for (auto line : ans) {
        for (int i : line) cout << i << ' ';
        cout << endl;
    }
}