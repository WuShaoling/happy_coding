#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int closedIsland(vector<vector<int> >& grid) {
        if (grid.size() == 0) return 0;

        int row = grid.size();
        int col = grid[0].size();

        // 初始化
        father = new int[row * col];
        land = new bool[row * col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int index = i * col + j;
                if (grid[i][j] == 1)
                    father[index] = -1;
                else
                    father[index] = index;
                land[index] = false;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    // 判断右侧是否连接
                    // 如果不是最后一列且右侧是连接的
                    if (j != col - 1 && grid[i][j + 1] == 0) {
                        merge(i * col + j, i * col + j + 1);
                    }

                    // 判断下侧是否连接
                    // 如果不是最后一行且下侧是连接的
                    if (i != row - 1 && grid[i + 1][j] == 0) {
                        merge(i * col + j, (i + 1) * col + j);
                    }
                }
            }
        }

        // 去除所有含边缘节点的组
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                land[find(i)] = true;
            }
        }
        for (int i = 0; i < col; i++) {
            if (grid[row - 1][i] == 0) {
                land[find((row - 1) * col + i)] = true;
            }
        }
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 0) {
                land[find(i * col)] = true;
            }
        }
        for (int i = 0; i < row; i++) {
            if (grid[i][col - 1] == 0) {
                land[find(i * col + (col - 1))] = true;
            }
        }

        int res = 0;
        for (int i = 0; i < row * col; i++) {
            if (father[i] != -1 && father[i] == i && !land[i]) {
                res++;
            }
        }

        return res;
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            father[py] = px;
        }
    }

    int find(int x) {
        if (father[x] == x) {
            return x;
        } else {
            father[x] = find(father[x]);
            return father[x];
        }
    }

   private:
    int* father;
    bool* land;
};

int main() {
    Solution s;
    vector<vector<int> > grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                                 {1, 0, 0, 0, 0, 1, 1, 0},
                                 {1, 0, 1, 0, 1, 1, 1, 0},
                                 {1, 0, 0, 0, 0, 1, 0, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 0}};
    cout << s.closedIsland(grid) << endl;
}