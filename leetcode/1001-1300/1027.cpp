#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        int base = 10000;
        vector<vector<int>> dp(n, vector<int>(20001, 1));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j];
                if (diff < 0) diff = base - diff;
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> A = {20, 1, 15, 3, 10, 5, 8};
    cout << s.longestArithSeqLength(A);
}