#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        int num = sqrt(n);
        vector<vector<int>> dp(num + 1, vector<int>(n + 1, n));
        dp[0][0] = 1;
        for (int i = 0; i <= num; i++) {
            for (int j = 0; j <= n; j++) {
            }
        }

        // cout << INT_MAX << endl;
        // cout << (int)sqrt(INT_MAX) << endl;
        // cout << ((long)46340 * 46340) << endl;
        return 0;
    }
};

int main() {
    Solution s;
    s.numSquares(17);
}
