#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<char> > &grid) {

        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 'X') {
                    f.push_back(-1);
                } else {
                    f.push_back(i * col + j);
                }
            }
        }
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            f[py] = px;
        }
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        } else {
            f[x] = find(f[x]);
            return f[x];
        }
    }

    vector<int> getGroups() {
        vector<int> res;
        for (int i = 0; i < f.size(); i++) {
            if (f[i] == -1) {
                continue;
            }
            if (i == find(i)) {
                res.push_back(i);
            }
        }
        return res;
    }

    void setX(int groupNum, vector<vector<char> > &board) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (f[i * col + j] == groupNum) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    bool hasEdgePoint(int groupNum) {
        for (int i = 0; i < f.size(); i++) {
            if (f[i] == groupNum && isOnEdge(i)) {
                return true;
            }
        }
        return false;
    }

    bool isOnEdge(int num) {
        if ((num % col == 0) ||
            ((num + 1) % col == 0) ||
            (num >= 0 && num < col) ||
            (num >= col * (row - 1) && num < col * row)) {
            return true;
        }
        return false;
    }

private:
    vector<int> f;
    int row;
    int col;
};

class Solution {
public:
    void solve(vector<vector<char> > &board) {

        if (board.size() == 0) {
            return;
        }

        UnionFind uf(board);

        // 对O分组
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (board[i][j] == 'X')
                    continue;

                if (j != col - 1 && board[i][j + 1] == 'O') {
                    uf.merge(i * col + j, i * col + j + 1);
                }

                if (i != row - 1 && board[i + 1][j] == 'O') {
                    uf.merge(i * col + j, (i + 1) * col + j);
                }
            }
        }

        // 判断组是否含有边界点
        vector<int> group = uf.getGroups();
        for (int i = 0; i < group.size(); i++) {
            if (!uf.hasEdgePoint(group[i])) {
                uf.setX(group[i], board);
            }
        }
    }
};


int main() {
    Solution solution;

    vector<vector<char> > v = {{'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O'},
                               {'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X'},
                               {'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O'},
                               {'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
                               {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X'},
                               {'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X'},
                               {'O', 'X', 'O', 'O', 'X', 'O', 'X', 'X'},
                               {'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'}};

    solution.solve(v);
}