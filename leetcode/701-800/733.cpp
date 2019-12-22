#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int newColor,
             int oldColor) {
        if (row >= image.size() || row < 0 || col >= image[0].size() ||
            col < 0 || image[row][col] != oldColor ||
            image[row][col] == newColor) {
            return;
        }

        image[row][col] = newColor;
        dfs(image, row + 1, col, newColor, oldColor);  // 下
        dfs(image, row - 1, col, newColor, oldColor);  // 上
        dfs(image, row, col - 1, newColor, oldColor);  // 左
        dfs(image, row, col + 1, newColor, oldColor);  // 上
    }
};

int main() {
    Solution s;
    vector<vector<int>> image = {{0, 0, 0}, {0, 1, 1}};
    s.floodFill(image, 1, 1, 1);
}