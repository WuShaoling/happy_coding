#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    int numEnclaves(vector<vector<int>>& A) {
        ROW = A.size();
        COL = A[0].size();

        for (int row = 1; row < ROW - 1; row++) dfs(A, row, 0);  // 第一列
        for (int row = ROW - 2; row > 0; row--) dfs(A, row, COL - 1);  // 最后一列
        for (int col = COL - 1; col >= 0; col--) dfs(A, ROW - 1, col); // 最后一行
        for (int col = 0; col < COL; col++) dfs(A, 0, col);  // 第一行

        int res = 0;
        for (vector<int> v : A)
            for (int vv : v)
                if (vv == 1) res++;
        return res;
    }

   private:
    void dfs(vector<vector<int>>& A, int row, int col) {
        if (row >= ROW || col >= COL || row < 0 || col < 0) return;
        if (A[row][col] == 1) {
            A[row][col] = 0;
            dfs(A, row, col + 1);  // 右面
            dfs(A, row + 1, col);  // 下面
            dfs(A, row, col - 1);  // 左面
            dfs(A, row - 1, col);  // 上面
        }
    }

    int ROW;
    int COL;
};

int main() {
    Solution s;
    vector<vector<int>> A = {
        {0, 0, 0, 1, 1, 1, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 0, 1, 0, 0}, {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};
    cout << s.numEnclaves(A);
}