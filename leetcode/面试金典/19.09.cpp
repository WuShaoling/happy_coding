#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int getKthMagicNumber(int k) {
        if (k <= 0) return 0;

        vector<long long int> dp(k + 1, 1);
        int p3 = 0, p5 = 0, p7 = 0;
        for (int i = 1; i < k; i++) {
            dp[i] = min(min(3 * dp[p3], 5 * dp[p5]), 7 * dp[p7]);
            if (dp[i] == 3 * dp[p3]) p3++;
            if (dp[i] == 5 * dp[p5]) p5++;
            if (dp[i] == 7 * dp[p7]) p7++;
        }
        return dp[k - 1];
    }
};

int main() {}