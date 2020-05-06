#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
class Solution {
   public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int stateCount = 1 << n;

        vector<set<int>> s(41);
        for (int i = 0; i < n; ++i)
            for (int hat : hats[i]) s[hat].insert(i);

        vector<ll> dp(stateCount);
        dp[0] = 1;
        for (int i = 1; i <= 40; ++i) {
            vector<ll> ndp(dp);
            for (int state = stateCount - 1; state >= 0; --state) {
                for (int person : s[i]) {
                    if (state & (1 << person)) continue;
                    int nxt = state + (1 << person);
                    ndp[nxt] += dp[state];
                    ndp[nxt] %= MOD;
                }
            }
            swap(dp, ndp);
        }

        return dp[stateCount - 1];
    }

   private:
    const ll MOD = 1e9 + 7;
};

int main() {
    Solution s;
    // vector<vector<int>> hats = {
    //     {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    // vector<vector<int>> hats = {
    //     {1, 2, 3}, {2, 3, 5, 6}, {1, 3, 7, 9}, {1, 8, 9}, {2, 5, 7}};
    // vector<vector<int>> hats = {{3, 5, 1}, {3, 5}};
    // vector<vector<int>> hats = {{3, 4}, {4, 5}, {5}};
    vector<vector<int>> hats = {
        {4, 15, 16, 26, 28},
        {1,  2,  3,  4,  6,  7,  8,  10, 13, 14, 15, 16,
         17, 18, 19, 21, 22, 24, 25, 27, 28, 29, 30},
        {1,  2,  3,  4,  5,  7,  9,  10, 11, 12, 14, 15,
         17, 18, 19, 20, 21, 22, 23, 24, 25, 28, 29, 30},
        {2, 3, 6, 7, 14, 16, 17, 18, 19, 20, 21, 24, 25, 27, 28, 29},
        {1, 10},
        {1,  5,  6,  7,  8,  9,  10, 11, 13, 14,
         15, 16, 19, 20, 21, 22, 24, 25, 27, 28},
        {2, 5, 10, 14, 16, 19, 21, 22, 23, 27, 30}};
    cout << s.numberWays(hats);
}