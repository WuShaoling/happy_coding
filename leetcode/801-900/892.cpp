#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                // 计算上方的
                if (i == 0) {
                    res += grid[i][j];
                } else if (grid[i][j] > grid[i - 1][j]) {
                    res += grid[i][j] - grid[i - 1][j];
                }

                // 计算下方的
                if (i == grid.size() - 1) {
                    res += grid[i][j];
                } else if (grid[i][j] > grid[i + 1][j]) {
                    res += grid[i][j] - grid[i + 1][j];
                }

                // 计算左面的
                if (j == 0) {
                    res += grid[i][j];
                } else if (grid[i][j] > grid[i][j - 1]) {
                    res += grid[i][j] - grid[i][j - 1];
                }

                // 计算右面的
                if (j == grid[0].size() - 1) {
                    res += grid[i][j];
                } else if (grid[i][j] > grid[i][j + 1]) {
                    res += grid[i][j] - grid[i][j + 1];
                }
                res += 2;
            }
        }
        return res;
    }
};

int main() {}