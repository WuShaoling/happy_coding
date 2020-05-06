#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int movingCount(int m, int n, int k) {
        ans = 0;
        getSum(max(m, n));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        find(m, n, k, 0, 0, visited);
        return ans;
    }

   private:
    void find(int m, int n, int k, int x, int y,
              vector<vector<bool>>& visited) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
            sum[x] + sum[y] > k) {
            return;
        }

        ans++;
        visited[x][y] = true;
        find(m, n, k, x + 1, y, visited);
        find(m, n, k, x - 1, y, visited);
        find(m, n, k, x, y + 1, visited);
        find(m, n, k, x, y - 1, visited);
    }

    void getSum(int n) {
        for (int i = 0; i < n; i++) {
            int temp = 0;
            int t = i;
            while (t) {
                temp += t % 10;
                t /= 10;
            }
            sum.push_back(temp);
        }
    }
    int ans = 0;
    vector<int> sum;
};

int main() {}