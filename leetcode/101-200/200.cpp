#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
            grid[x][y] == '0')
            return;

        grid[x][y] = '0';

        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
};

// class UnionFind {
//    public:
//     UnionFind(vector<vector<char> >& grid) {
//         int row = grid.size();
//         int col = grid[0].size();

//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == '0') {
//                     f.push_back(-1);
//                 } else {
//                     f.push_back(i * col + j);
//                 }
//             }
//         }
//     }

//     void merge(int x, int y) {
//         int px = find(x);
//         int py = find(y);

//         if (px != py) {
//             f[py] = px;
//         }
//     }

//     int find(int x) {
//         if (f[x] == x) {
//             return x;
//         } else {
//             f[x] = find(f[x]);
//             return f[x];
//         }
//     }

//     int getGroup() {
//         int res = 0;
//         for (int i = 0; i < f.size(); i++) {
//             if (f[i] == i) {
//                 res++;
//             }
//         }
//         return res;
//     }

//    private:
//     vector<int> f;
// };

// class Solution {
//    public:
//     int numIslands(vector<vector<char> >& grid) {
//         if (grid.size() == 0) {
//             return 0;
//         }

//         UnionFind uf(grid);

//         int row = grid.size();
//         int col = grid[0].size();

//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == '0') continue;

//                 // 判断右侧是否连接
//                 // 如果不是最后一列且右侧是连接的
//                 if (j != col - 1 && grid[i][j + 1] == '1') {
//                     uf.merge(i * col + j, i * col + j + 1);
//                 }

//                 // 判断下侧是否连接
//                 // 如果不是最后一行且下侧是连接的
//                 if (i != row - 1 && grid[i + 1][j] == '1') {
//                     uf.merge(i * col + j, (i + 1) * col + j);
//                 }
//             }
//         }

//         return uf.getGroup();
//     }
// };

int main() {
    Solution solution;

    vector<vector<char>> v = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };

    cout << solution.numIslands(v) << endl;
}