#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        return find(dp, s, 0, n - 1);
    }

   private:
    int find(vector<vector<int> >& dp, string& s, int begin, int end) {
        if (begin > end) return 0;
        if (begin == end) return 1;

        if (dp[begin][end] == -1) {
            if (s[begin] == s[end]) {
                dp[begin][end] = 2 + find(dp, s, begin + 1, end - 1);
            } else {
                dp[begin][end] = max(find(dp, s, begin + 1, end),
                                     find(dp, s, begin, end - 1));
            }
        }

        return dp[begin][end];
    }
    
    // int longestPalindromeSubseq(string s) {
    //     if (s.size() == 0) return 0;

    //     int n = s.size();
    //     vector<vector<int> > dp(n, vector<int>(n, 0));

    //     for (int begin = n - 1; begin >= 0; begin--) {
    //         dp[begin][begin] = 1;
    //         for (int end = begin + 1; end < n; end++) {
    //             if (s[begin] == s[end]) {
    //                 dp[begin][end] = 2 + dp[begin + 1][end - 1];
    //             } else {
    //                 dp[begin][end] =
    //                     max(dp[begin + 1][end], dp[begin][end - 1]);
    //             }
    //         }
    //     }

    //     return dp[0][n - 1];
    // }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("dddad");
}