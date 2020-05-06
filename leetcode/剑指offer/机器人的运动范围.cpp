#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int movingCount(int threshold, int rows, int cols) {
        if (threshold <= 0 || rows <= 0 || cols <= 0) return 0;

        int _max = max(rows, cols);
        for (int i = 0; i <= _max; i++) {
            sum_number.push_back(sumOfNumber(i));
        }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        helper(threshold, rows, cols, 0, 0, visited);
        return sum;
    }

   private:
    void helper(int threshold, int rows, int cols, int i, int j,
                vector<vector<bool>>& visited) {
        if (i >= rows || j >= cols || i < 0 || j < 0) return;
        if (visited[i][j]) return;
        if (sum_number[i] + sum_number[j] > threshold) return;

        visited[i][j] = true;
        sum++;
        helper(threshold, rows, cols, i + 1, j, visited);
        helper(threshold, rows, cols, i - 1, j, visited);
        helper(threshold, rows, cols, i, j + 1, visited);
        helper(threshold, rows, cols, i, j - 1, visited);
    }

    int sumOfNumber(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    vector<int> sum_number;
    int sum = 0;
};

int main() {
    Solution s;
    cout << s.movingCount(8, 2, 2);
}