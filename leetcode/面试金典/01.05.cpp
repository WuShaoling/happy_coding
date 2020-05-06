#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool oneEditAway(string first, string second) {
        int diff = first.size() - second.size();
        if (diff > 1 || diff < -1) return false;

        int i = 0, j = 0, count = 0;
        while (i < first.size() && j < second.size()) {
            if (first[i] == second[j]) {
                i++, j++;
                continue;
            }

            if (diff == 0) {  // replace
                i++, j++, count++;
                continue;
            }

            if (diff > 0) {  // remove
                i++, count++;
                continue;
            }

            if (diff < 0) {  // add
                j++, count++;
                continue;
            }
        }

        return count <= 1;
    }
    // bool oneEditAway(string first, string second) {
    //     int diff = first.size() - second.size();
    //     if (diff > 1 || diff < -1) return false;

    //     int dp[first.size() + 1][second.size() + 1];
    //     for (int i = 0; i <= first.size(); i++) dp[i][0] = i;
    //     for (int i = 0; i <= second.size(); i++) dp[0][i] = i;

    //     for (int i = 1; i <= first.size(); i++) {
    //         for (int j = 1; j <= second.size(); j++) {
    //             if (first[i - 1] == second[j - 1]) {
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             } else {
    //                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
    //                 dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]) + 1;
    //             }
    //         }
    //     }
    //     return dp[first.size()][second.size()] <= 1;
    // }
};

int main() {
    Solution s;
    cout << s.oneEditAway("islander", "slander");
}
