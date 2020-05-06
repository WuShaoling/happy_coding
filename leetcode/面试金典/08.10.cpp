#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        if (image[sr][sc] == newColor) return;

        int oldColor = image[sr][sc];
        fill(image, sr, sc, oldColor, newColor);
        return image;
    }

    void fill(vector<vector<int>>& image, int sr, int sc, int oldColor,
              int newColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
            image[sr][sc] == newColor || image[sr][sc] != oldColor)
            return;

        image[sr][sc] = newColor;
        fill(image, sr + 1, sc, oldColor, newColor);
        fill(image, sr - 1, sc, oldColor, newColor);
        fill(image, sr, sc + 1, oldColor, newColor);
        fill(image, sr, sc - 1, oldColor, newColor);
    }
};

int main() {}