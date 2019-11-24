//
// Created by 吴绍岭 on 2019-04-13.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (s.size() == 0)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ret = s.substr(0, 1);
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i + 1 < n) {
                dp[i][i + 1] = (s[i] == s[i + 1]);
            }
        }
        printMatrix(dp);

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j + i < n; j++) {
                if (s[j] == s[j + i])
                    dp[j][j + i] = dp[j + 1][i + j - 1];
                else
                    dp[j][j + i] = false;
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j + i < n; j++) {
                if (dp[j][j + i])
                    return s.substr(j, i + 1);
            }
        }
        return ret;
    }


    void printMatrix(const vector<vector<bool>> &dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp.size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("babac");
}
