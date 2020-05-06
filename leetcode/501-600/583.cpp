#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = longestCommonSubsequence(word1, word2);
        return word1.size() - n + word2.size() - n;
    }

   private:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0) return 0;

        int m = text1.size();
        int n = text2.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            int pre = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = temp;
            }
        }
        return dp[n];
    }
};

/*
abc
cef
 j=1
*/

int main() {
    Solution s;
    cout << s.minDistance("park", "spake");
}