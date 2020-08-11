#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minTime(vector<int>& time, int m) {
        // 如果题目数 <= m
        if (time.size() <= m) return 0;
        int n = time.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {       // 对于每一道题目
            for (int j = 0; j <= m; j++) {  // 对于天数
                if (j >= i) {
                    dp[i][j] = 0;
                    break;
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {999, 999, 999};
    cout << s.minTime(nums, 3);
}