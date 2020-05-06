#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days[days.size() - 1];

        vector<int> dp(n + 1, 0);
        for (int i : costs) dp[i] = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (dp[i] == 0) {
                dp[i] = dp[i - 1];
            } else {
                int n1 = dp[i - 1] + costs[0];
                int n2 = costs[1];
                if (i >= 7) n2 += dp[i - 7];
                int n3 = costs[2];
                if (i >= 30) n3 += dp[i - 30];
            }
        }
        return dp[n];
    }
};

int main() {}