#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> p(primes.size(), 0);
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < primes.size(); j++)
                dp[i] = min(dp[i], dp[p[j]] * primes[j]);

            for (int j = 0; j < primes.size(); j++)
                if (dp[p[j]] * primes[j] == dp[i]) p[j]++;
        }
        // for (int i : dp) cout << i << " ";
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    vector<int> primes = {2, 7, 13, 19};
    cout << s.nthSuperUglyNumber(12, primes);
}