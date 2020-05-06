#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        if (land.empty() || land[0].empty()) return {};

        int m = land.size();
        int n = land[0].size();

        vector<int> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) {
                    ans.push_back(dfs(land, m, n, i, j));
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    int dfs(vector<vector<int>>& land, int m, int n, int x, int y) {
        if (x >= m || x < 0 || y >= n || y < 0 || land[x][y] != 0) return 0;

        land[x][y] = 1;
        int count = 1;
        int nextX, nextY;
        for (int i = 0; i < 8; i++) {
            nextX = x + dir[i][0];
            nextY = y + dir[i][1];
            if (nextX >= m || nextX < 0 || nextY >= n || nextY < 0 ||
                land[nextX][nextY] != 0)
                continue;
            count += dfs(land, m, n, nextX, nextY);
        }
        return count;
    }

    const int dir[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                           {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
};

int main() {}