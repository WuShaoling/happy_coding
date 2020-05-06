#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int ans = 1;
        int preX = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++) {
            if (preX < pairs[i][0]) {
                preX = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }

    // int findLongestChain(vector<vector<int>>& pairs) {
    //     sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
    //         if (a[0] == b[0]) return a[1] < b[1];
    //         return a[0] < b[0];
    //     });

    //     vector<int> dp(pairs.size(), 1);

    //     for (int i = 1; i < pairs.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (pairs[j][1] < pairs[i][0]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //             }
    //         }
    //     }

    //     int res = 0;
    //     for (int i = 0; i < pairs.size(); i++) {
    //         res = max(res, dp[i]);
    //     }

    //     return res;
    // }
};

int main() {}