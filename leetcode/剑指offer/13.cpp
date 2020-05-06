#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int movingCount(int m, int n, int k) {
        int _max = max(m, n);
        for (int i = 0; i < _max; i++) mm[i] = getSum(i);

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        find(visited, m, n, k, 0, 0);
        return res;
    }

   private:
    void find(vector<vector<bool>>& visited, int m, int n, int k, int x,
              int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || mm[x] + mm[y] > k ||
            visited[x][y])
            return;

        visited[x][y] = true;
        res++;
        if (x == m - 1 && y == n - 1) {
            return;
        }

        find(visited, m, n, k, x + 1, y);
        find(visited, m, n, k, x - 1, y);
        find(visited, m, n, k, x, y + 1);
        find(visited, m, n, k, x, y - 1);
    }

    int getSum(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    map<int, int> mm;
    int res = 0;
};

int main() {}